import java.util.Scanner;
public class LineApplication {
    public static void main(String[] args) {
       Scanner input = new Scanner(System.in);
    
    int num1= 0;
    int num2= 0;
    int num3= 0;
    int num4= 0;
    int num5 =0;
    int number;
    
    for (int counter = 1; counter <= 5; counter++) {
        System.out.println("Enter an Integer:");
        number = input.nextInt();
         switch (counter) {
         case 1:
             num1 = number;
             break;
             
         case 2:
             num2 = number;
             break;
         case 3:
             num3 = number;
             break;
         case 4:
             num4 = number;
             break;
         case 5:
             num5 = number;
             break;
         }
        
    }     
        
             for (int asterisk = 1 ; asterisk <= num1; asterisk++) {
                 System.out.print("*");
             }
             System.out.println();
             for (int asterisk = 1 ; asterisk <= num2; asterisk++) {
                 System.out.print("*");
             }
             System.out.println();
             for (int asterisk = 1 ; asterisk <= num3; asterisk++) {
                 System.out.print("*");
             }
             System.out.println();
             for (int asterisk = 1 ; asterisk <= num4; asterisk++) {
                 System.out.print("*");
             }
             System.out.println();
             for (int asterisk = 1 ; asterisk <= num5; asterisk++) {
                 System.out.print("*");
             }
             System.out.println();
    }
}
