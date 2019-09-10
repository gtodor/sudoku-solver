require 'socket'
require_relative 'requestParser'
require_relative 'response'
include RequestParser
include PrepareResponse

port = ENV["PORT"]
logfile = File.open("logs.txt", "w")
logfile.puts "using port #{port}"

server = TCPServer.new('localhost', port)

def handle_connection(client, logfile)
  request = client.readpartial(2048)
  request = RequestParser.parse(request)

  logfile.puts
  logfile.puts request
  logfile.puts

  response = PrepareResponse.prepare(request)
  logfile.puts "############################################################"
  response.send(client)
end

loop do
  Thread.fork(server.accept) do |client| 
    handle_connection(client, logfile)
    client.close
  end
end

logfile.close
