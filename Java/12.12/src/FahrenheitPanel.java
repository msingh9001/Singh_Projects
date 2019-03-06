import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class FahrenheitPanel extends JPanel
{
   private JLabel inputLabel, outputLabel, resultLabel,commentLabel, comment;
   private JTextField fahrenheit;

   public FahrenheitPanel()
   {
	  inputLabel = new JLabel ("Enter Fahrenheit temperature:");
	  outputLabel = new JLabel ("Temperature in Celsius: ");
	  resultLabel = new JLabel ("---");


	  fahrenheit = new JTextField (5);
	  fahrenheit.addActionListener (new TempListener());

	  add (inputLabel);
	  add (fahrenheit);
	  add (outputLabel);
	  add (resultLabel);


	  setPreferredSize (new Dimension(300, 75));
	  setBackground (Color.WHITE);
   }

   private class TempListener implements ActionListener
   {
	  public void actionPerformed (ActionEvent event)
	  {
		 int fahrenheitTemp, celsiusTemp;

		 String text = fahrenheit.getText();

		 fahrenheitTemp = Integer.parseInt (text);
		 celsiusTemp = (fahrenheitTemp-32) * 5/9;

		 resultLabel.setText (Integer.toString (celsiusTemp));
    }
}

   public static void main (String[] args)
	  {
		 JFrame frame = new JFrame ("Fahrenheit to Celsius Converter");
		 frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);

		 FahrenheitPanel panel = new FahrenheitPanel();

		 frame.getContentPane().add(panel);
		 frame.pack();
		 frame.setVisible(true);
   }
}