require 'socket'
require_relative 'requestParser'
require_relative 'response'
include RequestParser
include PrepareResponse

port = ENV["PORT"]

puts "using port #{port}"

server = TCPServer.new('0.0.0.0', port)

def handle_connection(client)
  request = client.readpartial(2048)
  request = RequestParser.parse(request)

  puts
  puts request
  puts

  response = PrepareResponse.prepare(request)
  puts "############################################################"
  response.send(client)
end

loop do
  Thread.fork(server.accept) do |client|
    begin
      handle_connection(client)
    rescue EOFError
    end
    client.close
  end
end
