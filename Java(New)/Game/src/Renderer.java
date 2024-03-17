import java.awt.Color;
import java.awt.Graphics;

public class Renderer {
    public void drawRectangle(Graphics g, Rectangle rect, Color color) {
        g.setColor(color);
        g.fillRect(rect.getX(), rect.getY(), rect.getWidth(), rect.getHeight());
    }

    public void drawBall(Graphics g, Ball ball) {
        g.setColor(ball.getColor());
        g.fillOval(ball.getX(), ball.getY(), ball.getDiameter(), ball.getDiameter());
    }
}

