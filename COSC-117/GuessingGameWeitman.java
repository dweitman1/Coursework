 
/*Project 1
 *Daniel Weitman
 *COSC 117
 *9/7/17
 *
 * 
 */
import java.util.Scanner;

public class GuessingGameWeitman {
	public static void main(String[] args) {

		Scanner Input = new Scanner(System.in);
		int min = 0;
		int max = 0;
		double randNum;
		int randNum1;
		int guess = 0;
		int counter;
		int EMH;
		int difficulty = 0;
		int again;

		do { // repeats the program at the end at user's discretion
			counter = 0;// Resets counter for # of guesses

			/*
			 * Asks for the user to specify the range in which the random number will exist
			 * inside of and repeats until valid integers are entered
			 */
			do {
				System.out.println("Enter the minimum for the range");
				min = Input.nextInt();
			} while (min < 1 || min == 0);

			do {
				System.out.println("Enter the maximum for the range");
				max = Input.nextInt();
			} while (max <= min);

			/*
			 * Asks the user which difficulty they would like to play on and repeats until
			 * they give a valid corresponding integer
			 */
			do {
				System.out.println("Choose difficulty:\n" + "(1) Easy-20 Guesses\n" + "(2) Medium-10 Guesses\n"
						+ "(3) Hard-5 Guesses");
				EMH = Input.nextInt();
			} while (EMH != 1 && EMH != 2 && EMH != 3);

			if (EMH == 1) {
				difficulty = 19;
			} else if (EMH == 2) {
				difficulty = 9;
			} else if (EMH == 3) {
				difficulty = 4;
			}

			// Asks the user for an initial guess and records in temporarily in 'guess'
			// variable
			System.out.println("Enter your guess");
			guess = Input.nextInt();

			// Ensures that the initial guess fits inside of their range
			while (guess < min || guess > max) {
				System.out.println("That wasn't within the specified range! Try again");
				guess = Input.nextInt();
			}
			// Generates the random number
			randNum = Math.random() * max;
			randNum1 = (min + (int) randNum);
			// Loop for generating new random numbers if it does not fall inside user
			// specified range
			while (randNum1 > max || randNum1 < min) {
				randNum = Math.random() * max;
				randNum1 = (min + (int) randNum);

			}

			/*
			 * Loop that asks the user for their guesses and notifies the user if guessed
			 * integer was higher or lower than the random number they are supposed to be
			 * guessing. Additionally, the loop will end if the user exceeds the number of
			 * guesses permitted by the difficulty they selected earlier. The variable
			 * 'counter' inside of the loop will also count how many guesses the user takes
			 * unless it is outside of the range they specified.
			 */
			do {

				if (guess > randNum1 && guess <= max && guess >= min) {
					System.out.println("Guess too high, guess again");
					guess = Input.nextInt();
					counter += 1;
				} else if (guess < randNum1 && guess <= max && guess >= min) {

					System.out.println("Guess too low, guess again");
					guess = Input.nextInt();
					counter += 1;
				} else if (guess < min || guess > max) {
					System.out.println("That wasn't wasn't within the specified range! Guess again");
					guess = Input.nextInt();
				}
			} while (guess != randNum1 && counter < (difficulty));

			/*
			 * Notifies the user if they won or lost the game depending on whether or not
			 * the were able to guess the correct number in the number of tries permitted by
			 * their difficulty choice. Additionally, if they win or lose the program will
			 * ask if they want to play again by entering the corresponding integer to 'yes'
			 * or 'no'
			 */
			if (counter < difficulty + 1 && guess == randNum1) {
				System.out.println("You won in " + (counter + 1) + " guess(es) with your guess of " + randNum1 + "\n"
						+ "Play again?\n" + "(1) Yes\n" + "(2) No");
				again = Input.nextInt();
			} else {
				System.out.println("You lost. The actual number was " + randNum1 + "\n" + "Play again?\n" + "(1) Yes\n"
						+ "(2) No");
				again = Input.nextInt();
			}
			/*
			 * User validation to ensure that they enter an integer the corresponds to 'yes'
			 * or 'no' being '1' and '2' respectively.
			 */
			while (again != 1 && again != 2) {
				System.out.println("Play again?\n" + "(1) Yes\n" + "(2) No");
				again = Input.nextInt();
			}
			/*
			 * Repeats entire program if the user enters the integer '1' which corresponds
			 * to 'yes' when prompted the question 'play again?'.
			 */

		} while (again == 1);

		Input.close();
	}

}
