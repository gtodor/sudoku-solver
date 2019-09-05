require 'net/http'
require 'uri'
require 'json'

difficulty = ARGV[0]

if !["easy", "medium", "hard", "expert"].include? difficulty
  puts "Usage: ruby sudokuExamples.rb [easy|medium|hard|expert]";
  return
end

file = File.open("#{difficulty}.txt", 'w')

# use sudoku.com api to gather examples of sudoku with their solution
uri = URI("https://sudoku.com/api/getLevel/#{difficulty}")

Net::HTTP::start(uri.host, uri.port, :use_ssl => uri.scheme == 'https') do |http|
  request = Net::HTTP::Get.new uri

  for i in 1..100 do
    p i
    response = http.request request
    parsed = JSON.parse response.body
    sudoku = parsed['desc'][0]
    solution = parsed['desc'][1]
    file.puts sudoku
    file.puts solution
  end
end

file.close
