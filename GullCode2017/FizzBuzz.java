
public class FizzBuzz {
	public static void main(String[] args) {
		int array[] = new int[100];
	
		for (int i = 0; i < array.length; i++) {
			array[i] = i + 1;
		}
		for (int i = 0; i < array.length; i++) {
			if (array[i] % 4 == 0 && array[i] % 3 == 0) {
				System.out.println("FizzBuzz");
			} else if (array[i] % 4 == 0) {
				System.out.println("Buzz");
			} else if (array[i] % 3 == 0) {
				System.out.println("Fizz");
			} else {
				System.out.println(array[i]);
			}
		}
	}
}
