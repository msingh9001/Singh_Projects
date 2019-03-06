package test_rectangle;
import java.util.Scanner;
public class Test_Rectangle {
    public static void main(String[] args) {
         Scanner input = new Scanner(System.in);
         
   	 Rectangle test_rectangle = new Rectangle();
   	 
   	 System.out.printf("%s",test_rectangle.Calculations());
   	 
   	 int count = 1;
   	 
   	 while(count !=3) {
   		 System.out.println("1) Enter 1 to Input Length");
   		 System.out.println("2) Enter 2 to Input Width");
   		 System.out.println("3) Enter 3 to Exit");
   		 
   		 count = input.nextInt();
   		 
   		 if(count != 3) {
   			 switch(count)
                         {
                            case 1:
   				 System.out.println("Enter a value for the length:");
   				 int length = input.nextInt();
   				 test_rectangle.setLength(length);
   				 break;
   				 
                            case 2:
   				 System.out.println("Enter a value for the width");
   				 int width = input.nextInt();
   				 test_rectangle.setWidth(width);
   				 break;
   				 
                            case 3:
   				 break;	 
   			 }
   			 
   			 System.out.printf("%s%n",test_rectangle.Calculations1());
   		 }
         }
    }   
}



/*public void setInterestRates(int interestRates)
    {
   	 if(interestRates > 0)
   		 Savings_Account.interestRates = interestRates;
    }*/