fn main() {
	let mut count = 1;
	while count <= 100 {
		if count % 3 == 0 {
			print("fizz");
		}
		if count % 5 == 0 {
			print("buzz");
		}
		if count % 3 != 0 && count % 5 != 0 {
			print!("{}", count);
		}
		print("\n");
		count += 1;
	}
}
