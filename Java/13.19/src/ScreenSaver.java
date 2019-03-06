import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.Timer;
import java.util.Random;
import javax.swing.JPanel;
import javax.swing.Timer;


public class ScreenSaver extends JPanel implements ActionListener {

    private final int delay = 99999999;
    private  final Timer timer;

    public ScreenSaver() {

        timer = new Timer (1000, this);
        timer.start();

        }

@Override
    public void paintComponent(Graphics g) {
         super.paintComponent(g);
        int x;
        int y; 
        int x1;
        int y1;
        for (int i = 1; i <= 100; i++) {
            x=(int)(Math.random()* 300);
            y=(int)(Math.random()* 300);
            x1=(int)(Math.random()* 300);
            y1=(int)(Math.random()* 300);

            g.setColor(new Color((float) Math.random(), (float) Math.random(),
                    (float) Math.random()));

            g.drawLine(x, y, x1, y1);
            for(int j = 1; j < delay; j++);
        }
    }
    @Override
    public void actionPerformed(ActionEvent  actionEvent) {
        repaint();

    }
}