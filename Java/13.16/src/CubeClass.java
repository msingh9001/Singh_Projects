import java.awt.*;
import java.awt.geom.*;
import javax.swing.*;

    public class CubeClass extends JFrame
    {
                public CubeClass()
                {
                            super("Drawing 2D Cube");
                            setSize(400,400);
                            setVisible(true);
                }
                public void paint(Graphics g)
                {
                            super.paint(g);

                            int xPoint[]={100,200,200,100,100,130,230,230,130,130};
                            int yPoint[]={100,100,200,200,100,70,70,170,170,70};

                            Graphics2D g2d =(Graphics2D)g;
                            g2d.setColor(Color.red);


                            GeneralPath cube = new GeneralPath();

                            cube.moveTo(xPoint[0],yPoint[0]);
                            for( int i=1;i<xPoint.length;i++) 
                            cube.lineTo(xPoint[i],yPoint[i]);
                            cube.closePath();
                            g2d.draw(cube);
                            g2d.draw(new Line2D.Double(130,170,100,200));
                            g2d.draw(new Line2D.Double(230,70,200,100));
                            g2d.draw(new Line2D.Double(230,170,200,200));

                }
    }