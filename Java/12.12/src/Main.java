import javax.swing.JFrame;
public class Main
{
    
   public static void main (String[] args)
   {
	  JFrame frame = new JFrame ("Fahrenheit");
	  frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);

	  FahrenheitPanel panel = new FahrenheitPanel();

	  frame.getContentPane().add(panel);
	  frame.pack();
	  frame.setVisible(true);
   }
}
