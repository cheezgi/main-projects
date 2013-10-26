puts "Please enter a number:"
number = gets.chomp.to_i
tmp = 2 * (number - 3)
tmp2 = number - 1
for i in 4..tmp2
	tmp = tmp + number - i
end
puts tmp