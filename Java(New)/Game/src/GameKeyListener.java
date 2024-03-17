import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class GameKeyListener extends KeyAdapter {
    private Rectangle playerRect;
    private Ball ball;

    public GameKeyListener(Rectangle playerRect, Ball ball) {
        this.playerRect = playerRect;
        this.ball = ball;
    }

    @Override
    public void keyPressed(KeyEvent e) {
        int keyCode = e.getKeyCode();
        if (keyCode == KeyEvent.VK_A) {
            playerRect.moveLeft();
        } else if (keyCode == KeyEvent.VK_D) {
            playerRect.moveRight();
        } else if (keyCode == KeyEvent.VK_SPACE) {
            if (!ball.isReleased()) {
                ball.release(playerRect.getX() + playerRect.getWidth() / 2, playerRect.getY());
            }
        }
    }
}
