import javax.swing.JPanel;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.ActionListener;
import javax.swing.Timer;

public class Game extends JPanel implements ActionListener {
    private Rectangle playerRect;
    private Rectangle autoRect;
    private Ball ball;
    private int score;

    public Game() {
        playerRect = new Rectangle(50, 50, 100, 20);
        autoRect = new Rectangle(350, 500, 50, 10);
        autoRect.setVelocityX(5);
        ball = new Ball(playerRect, 10, Color.RED);
        score = 0;

        Timer timer = new Timer(10, this);
        timer.start();
        addKeyListener(new GameKeyListener(playerRect, ball));
        setFocusable(true);
    }

    public void keyPressed(KeyEvent e) {
        int keyCode = e.getKeyCode();
        if (keyCode == KeyEvent.VK_A) {
            playerRect.moveLeft();
            ball.moveWithPlayer(playerRect);
        } else if (keyCode == KeyEvent.VK_D) {
            playerRect.moveRight();
            ball.moveWithPlayer(playerRect);
        } else if (keyCode == KeyEvent.VK_SPACE) {
            if (!ball.isReleased()) {
                ball.release(playerRect.getX() + playerRect.getWidth() / 2, playerRect.getY());
            }
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.BLACK);
        g.fillRect(0, 0, getWidth(), getHeight());
        playerRect.draw(g);
        autoRect.draw(g);
        ball.draw(g);
        g.setColor(Color.WHITE);
        g.drawString("Score: " + score, getWidth() - 100, 20);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        playerRect.move(); // Update player rectangle position
        autoRect.move();   // Update auto rectangle position

        // Ensure autoRect bounces off the walls
        if (autoRect.getX() <= 0 || autoRect.getX() + autoRect.getWidth() >= getWidth()) {
            autoRect.reverseDirection();
        }

        ball.move(); // Move the ball
        if (ball.getY() >= getHeight()) {
            ball.reset();
        } else if (ball.intersects(autoRect)) {
            score++;
            ball.reset();
        }
    
        repaint();

        
    }
}
