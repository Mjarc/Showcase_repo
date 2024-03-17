import java.awt.Color;
import java.awt.Graphics;

public class Rectangle {
    private int x;
    private int y;
    private int width;
    private int height;
    private int velocityX;

    public Rectangle(int x, int y, int width, int height) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        this.velocityX = 0;
    }

    public void setVelocityX(int velocityX) {
        this.velocityX = velocityX;
    }

    public void reverseDirection() {
        velocityX = -velocityX; // Reverse the direction of movement
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public void moveLeft() {
        velocityX = -5;
    }

    public void moveRight() {
        velocityX = 5;
    }

    public void move() {
        x += velocityX; // Move the rectangle horizontally
    
        // Ensure the rectangle bounces off the walls
        if (x <= 0 || x + width >= 800) { // Assuming game window width is 800
            velocityX = -velocityX; // Reverse direction when hitting the walls
        }
    }

    public void draw(Graphics g) {
        g.setColor(Color.WHITE);
        g.fillRect(x, y, width, height);
    }
}
