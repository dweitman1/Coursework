import java.util.Scanner;

public class FibonacciWithATwist {
	public static void main(String[] args) {
		Scanner Input = new Scanner(System.in);

		int next = 1;
		int last = 1;
		int print;
		int terms;
		int i = 0;
		int eSum = 0;
		int oSum = 0;
		System.out.println("How many numbers in the Fibonacci sequence do you want to show?");
		
		do {
		while (!Input.hasNextInt()) {
			System.out.println("Enter a positive integer!");
			Input.next();
		}
		terms = Input.nextInt();
		if(terms < 1) {
			System.out.println("Enter a positive integer!");
		}
		} while (terms < 1);

		do {
			i++;
			
			if(i == 1 || i == 2) {
				print = 1;
			}
			else {
			print = next + last;
		}
			
			if(i != terms) {
			System.out.print(print + ", ");
			} else {
				System.out.print(print);
			}
			
			
			if(print % 2 == 0) {
				eSum = eSum + print;
			} else {
				oSum = oSum + print;
			}

			last = next;
			next = print;

		} while (i < terms);
		System.out.println(" ");
		System.out.println("Sum of even terms: " + eSum);
		System.out.println("Sum of odd terms: " + oSum);
		
		Input.close();
	}

}

