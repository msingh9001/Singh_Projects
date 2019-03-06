import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ClassChooserTest{

    String[] classList = {"","Class1","Class2","Class3"};
    JComboBox c = new JComboBox(classList);
    
    public ClassChooserTest(){
        frame();
    }
    
    public void frame()
    {
        JFrame f = new JFrame();
        f.setVisible(true);
        f.setSize(400, 400);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        JPanel p = new JPanel();
        p.add(c);
        
        f.add(p);
    }
    public static void main(String[] args) {
       
        new ClassChooserTest();
    }

}
