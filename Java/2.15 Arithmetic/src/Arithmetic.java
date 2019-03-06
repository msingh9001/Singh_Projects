import java.util.Scanner;
public class Arithmetic {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.printf("Please enter an integer: ");
        int x = input.nextInt();
        System.out.printf("Please enter another integer: ");
        int y = input.nextInt();
        
        int a = x + y;
        int b = x - y;
        int c = x * y;
        int d = x / y;
        
        System.out.printf("The sum is %d, the difference is %d, the product is %d, and the quotient is %d.\n"
        ,a, b, c, d);
    }
}
