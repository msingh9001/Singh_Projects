import java.util.Scanner;
public class FindLargestNumber {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int counter = 0;
        int largest = 0;
        
        while(counter < 10)
        {
            System.out.printf("Please Enter a number: ");
            int number = input.nextInt();                        
            if(largest < number)
            {
                largest = number;
            }
            counter++;
        }
        System.out.printf("The largest number is %d \n", largest);
    }
}
