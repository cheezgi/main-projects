puts "Please enter a number:"
number = gets.chomp.to_i
tmp = 2 * (number - 3)
tmp2 = number - 1 #2 temp variables because I'm not sure if you can do math
for i in 4..tmp2  #in a for statement
	tmp = tmp + number - i
end
puts tmp
