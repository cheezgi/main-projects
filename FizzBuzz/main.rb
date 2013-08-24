#write a program that prints the numbers 1...100.
#but for the multiples of three, print "fizz" and
#for the multiples of five, print "buzz". if the
#number is a multiple of both three and five, print
#"fizzbuzz"

100.times(){ |i|
	
	#i hate to have to do this...
	i += 1
	
	if i % 3 == 0 then print "fizz" end
	if i % 5 == 0 then print "buzz" end
	if i % 3 != 0 && i % 5 != 0 then print i end
	
	print "\n"
}



















