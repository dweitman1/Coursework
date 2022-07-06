
import java.util.Scanner;
public class AddingTwoNumbers {
	public static void main(String[]args) {
		Scanner Input = new Scanner(System.in);
		int num1;
		int num2;
		
		System.out.println("Enter first integer: ");
		while (!Input.hasNextInt()) {
			System.out.println("Enter first integer: ");
			Input.next();
		}
		num1 = Input.nextInt();
		
		System.out.println("Enter second integer: ");
		while (!Input.hasNextInt()) {
			System.out.println("Enter second integer: ");
			Input.next();
		}
		num2 = Input.nextInt();
		if(num1 > 0) {
		for(int i = 0; i < num1; i++) {
			num2++;	
		}
		System.out.println("The sum is: " + num2);
		}
		else if(num1 < 0 && num2 < 0) {
			for(int i = 0; i > num1; i--) {
				num2--;
			}
			System.out.println("The sum is: " + num2);
		}
		else {
			for(int i = 0; i < num2; i++) {
				num1++;
			}
			System.out.println("The sum is: " + num1);	
		}	
		Input.close();
	}
}
