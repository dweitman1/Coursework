/*Daniel Weitman
 * Project 3
 * COSC 117
 * 11/27/17
 */
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/**
 * This file can be used to create very simple animations. Just fill in the
 * definition of drawFrame with the code to draw one frame of the animation, and
 * possibly change a few of the values in the rest of the program as noted
 * below. Note that if you change the name of the class, you must also change
 * the name in the main() routine!
 */
public class LifeGame extends JPanel implements ActionListener {

	/**
	 * Draws one frame of an animation. This subroutine is called re second and is
	 * responsible for redrawing the entire drawing area. The parameter g is used
	 * for drawing. The frameNumber starts at zero and increases by 1 each time this
	 * subroutine is called. The parameters width and height give the size of the
	 * drawing area, in pixels. The sizes and positions of the rectangles that are
	 * drawn depend on the frame number, giving the illusion of motion.
	 */

	public boolean array[][] = new boolean[52][52];

	/**
	 * Function to initialize the boolean array with true and false values 20%
	 * probability to start as an alive cell. Called from main.
	 */
	public void setGrid() {
		for (int i = 0; i < array.length; i++) {
			for (int j = 0; j < array.length; j++) {
				if (Math.random() > .8) {
					array[i][j] = true;
				} else {
					array[i][j] = false;
				}
			}
		}
	}

	/**
	 * Draws a grid, and draws a black rectangle representing each alive cell Calls
	 * updateCells function to move onto the next stage of alive and dead cells
	 * 
	 * @param g
	 * @param frameNumber
	 * @param width
	 * @param height
	 */
	public void drawFrame(Graphics g, int frameNumber, int width, int height) {
		// two for loops to draw vertical and horizontal lines for a grid
		for (int i = 0; i < height; i += height / 52) {
			g.drawLine(0, i, width, i);
		}
		for (int i = 0; i < width; i += width / 52) {
			g.drawLine(i, 0, i, height);
		}

		for (int i = 0; i < array.length; i++) {
			for (int j = 0; j < array.length; j++) {

				if (array[i][j] == true) {// If a cells has a true value on current iteration paints a rectangle
					g.fillRect(width / 52 * (i), height / 52 * (j), width / 52, height / 52);
				}

			}
		}
		// Calls updateCells function and sets its return value into array
		array = updateCells();
	}

	/**
	 * alters array with new alive and dead cells based on neighbors
	 * 
	 * @return
	 */
	public boolean[][] updateCells() {
		boolean next[][] = new boolean[52][52];
		int counter;// int for determining # of alive neighboring cells
		int live = 3;// Dynamically change born and survive cell type 1
		int living = 2;// Dynamically change other survive cell type 2

		for (int i = 0; i < array.length; i++) {
			for (int j = 0; j < array.length; j++) {
				counter = 0;// Resets counter for each cell checked

				if (i == 0 || j == 0 || i == 51 || j == 51) {
					array[i][j] = false;// Creates a border of dead cells to avoid out of bounds error
				} else {

					if (array[i - 1][j - 1] == true) {// Checks first for alive neighbor
						counter++;
					}
					if (array[i - 1][j + 0] == true) {// Checks second for alive neighbor
						counter++;
					}
					if (array[i - 1][j + 1] == true) {// Checks third for alive neighbor
						counter++;
					}
					if (array[i + 0][j - 1] == true) {// Checks fourth for alive neighbor
						counter++;
					}
					if (array[i + 0][j + 1] == true) {// Checks fifth for alive neighbor
						counter++;
					}
					if (array[i + 1][j - 1] == true) {// Checks sixth for alive neighbor
						counter++;
					}
					if (array[i + 1][j + 0] == true) {// Checks seventh for alive neighbor
						counter++;
					}
					if (array[i + 1][j + 1] == true) {// Checks eighth for alive neighbor
						counter++;
					}

					if (counter == live) {
						next[i][j] = true;// Live condition sets to true
					} else if (counter == living && array[i][j] == true) {
						next[i][j] = true;// Live condition sets to true
					} else {
						next[i][j] = false;// Die condition sets to false
					}
				}
			}
		}
		return next;// Returns altered array back into drawFrame function
	}

	// ------ Implementation details: DO NOT EXPECT TO UNDERSTAND THIS ------

	public static void main(String[] args) {

		/*
		 * NOTE: The string in the following statement goes in the title bar of the
		 * window.
		 */
		JFrame window = new JFrame("Game of Life");

		/*
		 * NOTE: If you change the name of this class, you must change the name of the
		 * class in the next line to match!
		 */
		LifeGame drawingArea = new LifeGame();

		drawingArea.setBackground(Color.WHITE);
		window.setContentPane(drawingArea);
		drawingArea.setGrid();//Sets grid before other functions can alter the array
		/*
		 * NOTE: In the next line, the numbers 600 and 450 give the initial width and
		 * height of the drawing array. You can change these numbers to get a different
		 * size.
		 */
		drawingArea.setPreferredSize(new Dimension(520, 468));

		window.pack();
		window.setLocation(100, 50);
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		/*
		 * Note: In the following line, you can change true to false. This will prevent
		 * the user from resizing the window, so you can be sure that the size of the
		 * drawing area will not change. It can be easier to draw the frames if you know
		 * the size.
		 */
		window.setResizable(true);

		/*
		 * NOTE: In the next line, the number 20 gives the time between calls to
		 * drawFrame(). The time is given in milliseconds, where one second equals 1000
		 * milliseconds. You can increase this number to get a slower animation. You can
		 * decrease it somewhat to get a faster animation, but the speed is limited by
		 * the time it takes for the computer to draw each frame.
		 */
		Timer frameTimer = new Timer(100, drawingArea);

		window.setVisible(true);
		frameTimer.start();
	} // end main
	private int frameNum;
	public void actionPerformed(ActionEvent evt) {
		frameNum++;
		repaint();
	}
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		drawFrame(g, frameNum, getWidth(), getHeight());
	}
}