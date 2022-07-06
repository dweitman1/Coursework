import java.util.Scanner;

/* Project 2 
 * Daniel Weitman
 * COSC 117
 * 10/17/17
 * Program for a two player tic-tac-toe (TTT) game. Player X goes first and first player
 * to get three of their symbols in a row wins. A tie occurs if neither achieves it in the
 * cumulative nine turns.
 */
public class TicTacToeWeitman {
	public static void main(String[] args) {
		Scanner Input = new Scanner(System.in);
		String array[][] = new String[3][3];
		int row = 0;
		int column = 0;
		String player;
		// Used for determining player turn & draw condition
		for (int counter = 0; counter <= 9; counter++) {
			for (int i = 0; i < array.length; i++) {
				if (i > 0) {// Begins a new row for the TTT board
					System.out.println(" ");
				}
				for (int j = 0; j < array.length; j++) {
					if (counter == 0) {
						array[i][j] = "_";// Defines initial array as underscores
					}
					System.out.print(array[i][j]);// Prints array/board after each turn
					System.out.print(" ");
				}
			}
			System.out.println("");
			// Win conditions for rows of same symbol
			if (array[0][0] == "X" && array[0][1] == "X" && array[0][2] == "X") {
				System.out.println("Player " + (array[0][0]) + " wins");
				break;
			} else if (array[0][0] == "O" && array[0][1] == "O" && array[0][2] == "O") {
				System.out.println("Player " + (array[0][0]) + " wins");
				break;
			} else if (array[1][0] == "X" && array[1][1] == "X" && array[1][2] == "X") {
				System.out.println("Player " + (array[1][0]) + " wins");
				break;
			} else if (array[1][0] == "O" && array[1][1] == "O" && array[1][2] == "O") {
				System.out.println("Player " + (array[1][0]) + " wins");
				break;
			} else if (array[2][0] == "X" && array[2][1] == "X" && array[2][2] == "X") {
				System.out.println("Player " + (array[2][0]) + " wins");
				break;
			} else if (array[2][0] == "O" && array[2][1] == "O" && array[2][2] == "O") {
				System.out.println("Player " + (array[2][0]) + " wins");
				break;
			}
			// Win conditions for columns of same symbol
			else if (array[0][0] == "X" && array[1][0] == "X" && array[2][0] == "X") {
				System.out.println("Player " + (array[0][0]) + " wins");
				break;
			} else if (array[0][0] == "O" && array[1][0] == "O" && array[2][0] == "O") {
				System.out.println("Player " + (array[0][0]) + " wins");
				break;
			} else if (array[0][1] == "X" && array[1][1] == "X" && array[2][1] == "X") {
				System.out.println("Player " + (array[0][1]) + " wins");
				break;
			} else if (array[0][1] == "O" && array[1][1] == "O" && array[2][1] == "O") {
				System.out.println("Player " + (array[0][1]) + " wins");
				break;
			} else if (array[0][2] == "X" && array[1][2] == "X" && array[2][2] == "X") {
				System.out.println("Player " + (array[0][2]) + " wins");
				break;
			} else if (array[0][2] == "O" && array[1][2] == "O" && array[2][2] == "O") {
				System.out.println("Player " + (array[0][2]) + " wins");
				break;
			}
			// Win conditions for diagonal of same symbol
			else if (array[0][0] == "X" && array[1][1] == "X" && array[2][2] == "X") {
				System.out.println("Player " + (array[0][0]) + " wins");
				break;
			} else if (array[0][2] == "O" && array[1][1] == "O" && array[2][0] == "O") {
				System.out.println("Player " + (array[0][2]) + " wins");
				break;
			}
			// Determines which player's turn it is
			if (counter % 2 == 0) {
				player = "X";
			} else {
				player = "O";
			}
			do {// Loops when spot is taken to make sure symbol doesn't change
				// Makes sure code is only performed if turns < 9
				if (counter != 9) {
					System.out.println("Player " + player + "'s turn.");
					// Makes sure the row is within the 1-3 range
					do {
						System.out.print("Enter row (1-3): ");
						// Ensures an integer is entered
						while (!Input.hasNextInt()) {
							System.out.println("Not an option");
							System.out.print("Enter row (1-3): ");
							Input.next();
						}
						row = Input.nextInt() - 1;
						if (row < 0 || row > 2) {// Messages if column is outside of 1-3
							System.out.println("Not an option");
						}
					} while (row < 0 || row > 2);
					// Makes sure the column is within the 1-3 range
					do {
						System.out.print("Enter column (1-3): ");
						// Ensures an integer is entered
						while (!Input.hasNextInt()) {
							System.out.println("Not an option");
							System.out.print("Enter column (1-3): ");
							Input.next();
						}
						column = Input.nextInt() - 1;
						if (column < 0 || column > 2) {// Messages if row is outside of 1-3
							System.out.println("Not an option");
						}
					} while (column < 0 || column > 2);
					// Messages if spot is taken
					if (array[row][column] == "X" || array[row][column] == "O") {
						System.out.println("Spot taken try again");
					}
				} else {// Condition for draw when 9 turns is reached
					System.out.println("Draw.");
					break;
				}
			} while (array[row][column] == "X" || array[row][column] == "O");

			// Assigns the element in the array the user specified
			if (player == "X") {
				array[row][column] = "X";
			} else if (player == "O") {
				array[row][column] = "O";
			}
		}
		Input.close();
	}
}
