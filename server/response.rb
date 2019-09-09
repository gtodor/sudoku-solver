require './sudoku-solvr'
require 'json'

class Response
  def initialize(code:, data: "")
    @response =
      "HTTP/1.1 #{code}\r\n" +
      "Content-Length: #{data.size}\r\n" +
      "Content-Type: application/json\r\n" +
      "\r\n"+
      "#{data}\r\n"
  end

  def send(client)
    client.write(@response)
  end
end

module PrepareResponse
  def prepare(request)
    if request.fetch(:path) == "/sudoku_solver/api/solve"
      sudoku = request.fetch(:sudoku)
      if sudoku.size != 81
        data = {:error => "Sudoku input not correct"}.to_json
        return send_error_sudoku_init(data)
      end
      
      sudoku_arr = sudoku.each_char.map {|c| c.to_i}
      solver = SudokuSolver.new
      result = solver.solve(sudoku_arr)
      if result.size != 81
        data = {:error => "Sudoku does not have a solution"}.to_json
        return send_error_no_solution(data)
      end
      solution = {:solution => result}
      return send_ok_response(solution.to_json)
    else
      return send_error
    end
  end

  def send_ok_response(data)
    Response.new(code: 200, data: data)
  end

  def send_error
    Response.new(code: 404)
  end

  def send_error_sudoku_init(data)
    Response.new(code: 200, data: data)
  end

  def send_error_no_solution(data)
    Response.new(code: 200, data: data)
  end
end
