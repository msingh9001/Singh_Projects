import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.Timer;

public class Main {
     public static void main(String args[])
        { 
         JFrame frame = new JFrame( "ScreenSaver");

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
          
          ScreenSaver Test1 = new ScreenSaver();

          frame.add(Test1);
          frame.setSize(300,300);
          frame.setVisible(true);
        }

}