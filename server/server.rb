require 'socket'
require_relative 'requestParser'
require_relative 'response'
include RequestParser
include PrepareResponse

server = TCPServer.new('localhost', 8080)

def handle_connection(client)
  request = client.readpartial(2048)
  request = RequestParser.parse(request)

  puts request
  puts

  response = PrepareResponse.prepare(request)
  response.send(client)
end

loop do
  Thread.fork(server.accept) do |client| 
    handle_connection(client)
    client.close
  end
end
