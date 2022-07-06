import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/**
 *  This file can be used to create very simple animations.  Just fill in
 *  the definition of drawFrame with the code to draw one frame of the 
 *  animation, and possibly change a few of the values in the rest of
 *  the program as noted below. Note that if you change the name of the
 *  class, you must also change the name in the main() routine!
 */
public class Animation extends JPanel implements ActionListener {

    /**
     * Draws one frame of an animation. This subroutine is called re
     * second and is responsible for redrawing the entire drawing area.  The
     * parameter g is used for drawing. The frameNumber starts at zero and
     * increases by 1 each time this subroutine is called.  The parameters width
     * and height give the size of the drawing area, in pixels.  
     * The sizes and positions of the rectangles that are drawn depend
     * on the frame number, giving the illusion of motion.
     */
    public void drawFrame(Graphics g, int frameNumber, int width, int height) {
        
    	g.setColor(Color.CYAN);
    	g.fillRect(0, 0, width, height);
    	//Street
    	g.setColor(Color.GRAY);
    	g.fillRect(0, height - 52, width, height);
    	g.setColor(Color.YELLOW);
    	g.fillOval(0, 0, 80, 80);
    	g.drawLine(0, height - 23, width, height - 23);
    	g.drawLine(0, height - 27, width, height - 27);
    	
    	
    	//Blue Car
    	g.setColor(Color.BLACK);
    	g.fillOval(width-250 + 100 - frameNumber, height - 50-30, 50, 50);
    	g.fillOval(width-250 + 250 - frameNumber, height - 50-30, 50, 50);
    	g.setColor(Color.GRAY);
    	g.fillOval(width-250 + 105 - frameNumber, height - 45-30, 40, 40);
    	g.fillOval(width-250 + 255 - frameNumber, height - 45-30, 40, 40);
    	g.setColor(Color.BLUE);
    	g.fillRect(width-250 + 150 - frameNumber, height- 50-30, 100, 25);
    	g.fillRect(width-250 + 100 - frameNumber, height - 75-30, 200, 25);
    	g.drawLine(width-250 + 125 - frameNumber, height - 75-30, width- 250 + 150 - frameNumber, height - 125-30);
    	g.drawLine(width-250 + 275 - frameNumber, height - 75-30, width-250 + 250 - frameNumber, height - 125-30);
    	g.drawLine(width-250 + 150 - frameNumber, height - 125-30, width-250 + 250 - frameNumber, height -125-30);
    	
    	//Red Car
    	g.setColor(Color.BLACK);
    	g.fillOval(0 + frameNumber, height - 50, 50, 50);
    	g.fillOval(150 + frameNumber, height - 50, 50, 50);
    	g.setColor(Color.GRAY);
    	g.fillOval(5 + frameNumber, height - 45, 40, 40);
    	g.fillOval(155 + frameNumber, height - 45, 40, 40);
    	g.setColor(Color.RED);
    	g.fillRect(50 + frameNumber, height- 50, 100, 25);
    	g.fillRect(0 + frameNumber, height - 75, 200, 25);
    	g.drawLine(25 + frameNumber, height - 75, 50 + frameNumber, height - 125);
    	g.drawLine(175 + frameNumber, height - 75, 150 + frameNumber, height - 125);
    	g.drawLine(50 + frameNumber, height - 125, 150 + frameNumber, height -125);
    	
    	
    	
    	g.setColor(Color.BLACK);
        g.drawString( "Frame number " + frameNumber, width - 125, height - 425);


        
    

    }
    
    //------ Implementation details: DO NOT EXPECT TO UNDERSTAND THIS ------
    
    
    public static void main(String[] args) {
        
        /* NOTE:  The string in the following statement goes in the title bar
         * of the window.
         */
        JFrame window = new JFrame("Simple Animation");
        
        /*
         * NOTE: If you change the name of this class, you must change
         * the name of the class in the next line to match!
         */
        Animation drawingArea = new Animation();
        
        drawingArea.setBackground(Color.WHITE);
        window.setContentPane(drawingArea);

        /* NOTE:  In the next line, the numbers 600 and 450 give the
         * initial width and height of the drawing array.  You can change
         * these numbers to get a different size.
         */
        drawingArea.setPreferredSize(new Dimension(600,450));

        window.pack();
        window.setLocation(100,50);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        
        /*
         * Note:  In the following line, you can change true to
         * false.  This will prevent the user from resizing the window,
         * so you can be sure that the size of the drawing area will
         * not change.  It can be easier to draw the frames if you know
         * the size.
         */
        window.setResizable(true);
        
        /* NOTE:  In the next line, the number 20 gives the time between
         * calls to drawFrame().  The time is given in milliseconds, where
         * one second equals 1000 milliseconds.  You can increase this number
         * to get a slower animation.  You can decrease it somewhat to get a
         * faster animation, but the speed is limited by the time it takes
         * for the computer to draw each frame. 
         */
        Timer frameTimer = new Timer(20,drawingArea);

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
