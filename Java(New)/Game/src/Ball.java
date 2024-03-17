import java.awt.Color;
import java.awt.Graphics;

public class Ball {
    private int x;
    private int y;
    private int diameter;
    private int velocityY;
    private Color color;
    private boolean released;
    private Rectangle playerRect;

    public Ball(Rectangle playerRect, int diameter, Color color) {
        this.playerRect = playerRect;
        this.x = playerRect.getX() + playerRect.getWidth() / 2;
        this.y = playerRect.getY();
        this.diameter = diameter;
        this.color = color;
        this.velocityY = 3; // Adjust the falling speed as needed
        this.released = false;
    }

    public void moveWithPlayer(Rectangle playerRect) {
    if (!released) {
        this.x = playerRect.getX() + playerRect.getWidth() / 2 - diameter / 2; // Center the ball on the moving rectangle
        this.y = playerRect.getY();
    }
    }


    public Color getColor() {
        return color;
    }

    public boolean isReleased() {
        return released;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getDiameter() {
        return diameter;
    }

    public void move() {
        if (released) {
            y += velocityY;
        }
    }

    public boolean intersects(Rectangle rect) {
        return x + diameter >= rect.getX() && x <= rect.getX() + rect.getWidth() &&
               y + diameter >= rect.getY() && y <= rect.getY() + rect.getHeight();
    }

    public void reset() {
        released = false;
        x = playerRect.getX() + playerRect.getWidth() / 2 - diameter / 2; // Center the ball on the moving rectangle
        y = playerRect.getY();
    }

    public void release(int x, int y) {
        this.x = x;
        this.y = y;
        released = true;
    }

    public void draw(Graphics g) {
        g.setColor(color);
        g.fillOval(x, y, diameter, diameter);
    }
}
