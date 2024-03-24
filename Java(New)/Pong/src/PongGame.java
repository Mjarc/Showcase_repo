import java.awt.*;
import java.awt.event.*;

public class PongGame extends Frame implements KeyListener, Runnable {

    private static final int WIDTH = 1000;
    private static final int HEIGHT = 800;
    private static final int PLAYER_WIDTH = 20;
    private static final int PLAYER_HEIGHT = 100;
    private static final int BALL_SIZE = 20;
    private static final int PLAYER_SPEED = 5;
    private static final double BALL_SPEED_MULTIPLIER = 0.8; 

    private int player1Y = HEIGHT / 2 - PLAYER_HEIGHT / 2;
    private int player2Y = HEIGHT / 2 - PLAYER_HEIGHT / 2;

    private int ballX = WIDTH / 2 - BALL_SIZE / 2;
    private int ballY = HEIGHT / 2 - BALL_SIZE / 2;
    private int ballVelX, ballVelY;

    private boolean gameRunning = true;
    private boolean player1Up = false, player1Down = false;
    private boolean player2Up = false, player2Down = false;

    public PongGame() {
        setSize(WIDTH, HEIGHT);
        setTitle("Pong Game");
        addKeyListener(this);
        setVisible(true);

        int angle = (int) (Math.random() * 4); 
        switch (angle) {
            case 0 -> { ballVelX = (int)(BALL_SPEED_MULTIPLIER * PLAYER_SPEED); ballVelY = (int)(BALL_SPEED_MULTIPLIER * PLAYER_SPEED); }
            case 1 -> { ballVelX = -(int)(BALL_SPEED_MULTIPLIER * PLAYER_SPEED); ballVelY = (int)(BALL_SPEED_MULTIPLIER * PLAYER_SPEED); }
            case 2 -> { ballVelX = (int)(BALL_SPEED_MULTIPLIER * PLAYER_SPEED); ballVelY = -(int)(BALL_SPEED_MULTIPLIER * PLAYER_SPEED); }
            case 3 -> { ballVelX = -(int)(BALL_SPEED_MULTIPLIER * PLAYER_SPEED); ballVelY = -(int)(BALL_SPEED_MULTIPLIER * PLAYER_SPEED); }
        }

        Thread t = new Thread(this);
        t.start();
    }

    public void paint(Graphics g) {
   
        g.fillRect(50, player1Y, PLAYER_WIDTH, PLAYER_HEIGHT); 
        g.fillRect(WIDTH - 50 - PLAYER_WIDTH, player2Y, PLAYER_WIDTH, PLAYER_HEIGHT); 

        g.fillOval(ballX, ballY, BALL_SIZE, BALL_SIZE);

        if (!gameRunning) {
            g.setColor(Color.RED);
            g.setFont(new Font("Arial", Font.BOLD, 30));
            if (ballX <= 0)
                g.drawString("Player 2 Wins!", WIDTH / 2 - 130, HEIGHT / 2);
            else
                g.drawString("Player 1 Wins!", WIDTH / 2 - 130, HEIGHT / 2);
        }
    }

    public void keyPressed(KeyEvent e) {
        int keyCode = e.getKeyCode();
        switch (keyCode) {
            case KeyEvent.VK_A -> player1Up = true;
            case KeyEvent.VK_D -> player1Down = true;
            case KeyEvent.VK_J -> player2Up = true;
            case KeyEvent.VK_L -> player2Down = true;
        }
    }

    public void keyReleased(KeyEvent e) {
        int keyCode = e.getKeyCode();
        switch (keyCode) {
            case KeyEvent.VK_A -> player1Up = false;
            case KeyEvent.VK_D -> player1Down = false;
            case KeyEvent.VK_J -> player2Up = false;
            case KeyEvent.VK_L -> player2Down = false;
        }
    }

    public void keyTyped(KeyEvent e) {}

    public void run() {
        while (gameRunning) {

            if (player1Up && player1Y > 0) player1Y -= PLAYER_SPEED;
            if (player1Down && player1Y < HEIGHT - PLAYER_HEIGHT) player1Y += PLAYER_SPEED;
            if (player2Up && player2Y > 0) player2Y -= PLAYER_SPEED;
            if (player2Down && player2Y < HEIGHT - PLAYER_HEIGHT) player2Y += PLAYER_SPEED;

            ballX += ballVelX;
            ballY += ballVelY;

            if (ballY <= 0 || ballY >= HEIGHT - BALL_SIZE) ballVelY = -ballVelY;

            if (ballX <= 50 + PLAYER_WIDTH && ballY + BALL_SIZE >= player1Y && ballY <= player1Y + PLAYER_HEIGHT)
                ballVelX = -ballVelX;

            if (ballX + BALL_SIZE >= WIDTH - 50 - PLAYER_WIDTH && ballY + BALL_SIZE >= player2Y && ballY <= player2Y + PLAYER_HEIGHT)
                ballVelX = -ballVelX;

            if (ballX <= 0 || ballX >= WIDTH - BALL_SIZE) gameRunning = false;

            repaint();

            try {
                Thread.sleep(15); 
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        new PongGame();
    }
}
