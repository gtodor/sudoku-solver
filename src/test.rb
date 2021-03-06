require 'sudoku_solver'

arr= [0,0,4,0,0,1,2,0,0,
      0,0,1,0,0,6,0,3,0,
      0,2,0,0,9,0,0,7,1,
      0,1,0,0,0,0,0,0,0,
      6,0,0,7,0,9,0,0,3,
      0,0,0,0,0,0,0,4,0,
      5,7,0,0,1,0,0,6,0,
      0,3,0,6,0,0,5,0,0,
      0,0,2,3,0,0,7,0,0];
sudoku = SudokuSolver.new
result = sudoku.solve(arr)

for i in 0..8 do
    for j in 0..8 do
        print "#{result[i*9+j]} "
    end
    puts
end
