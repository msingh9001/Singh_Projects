import java.util.Scanner;
public class LargestNumber {
    public static void main(String[] args) {
        int number;
        int largest = 0;
        int saleFigure = 1;
        
        Scanner input = new Scanner(System.in);
        
        int counter = 0;
        while(counter < 10)
        {
            System.out.printf("\nPlease enter sale figure%d: ", saleFigure);
            number = input.nextInt();
            
            if(number > largest)
            {
            largest = number;
            }
            counter++;
            saleFigure++;
        }
        System.out.printf("\nThe largest number is %d\n", largest);
    }
}
