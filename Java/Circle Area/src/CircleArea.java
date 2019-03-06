import java.util.Scanner;
public class CircleArea {
    public static void main(String[] args) {
     Scanner input = new Scanner(System.in);
     double radius = 0;
     
     while (radius != -1) {
        
        System.out.println("\nEnter the radius value. Enter -1 to quit: ");
        radius = input.nextDouble();
        if (radius > 0 ) {
            System.out.printf("The area of the circle is %.2f", circleArea(radius));
        }
     }
    }
public static double circleArea(double radius)
     {
        double area = Math.PI * Math.pow(radius, 2);
        return area;
     }
}