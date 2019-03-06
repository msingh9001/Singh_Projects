import java.util.Scanner;
public class SalaryCalculator {
    public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    
    int ask= 1;
    int employeeNumber = 0;

    while(ask != 0)
        {
        int hoursWorked;
        double hourlyWage; 
        
        System.out.println("Please enter number of hours worked: ");
        hoursWorked = input.nextInt();
        System.out.println("Please enter hourly wage: ");
        hourlyWage = input.nextInt();
        
        double grossPay;
        int overtime;
        double overtimeWage;
        
        if(hoursWorked > 40)
            {
            overtime = hoursWorked - 40;
            overtimeWage = hourlyWage * 1.5;
            grossPay = (40 * hourlyWage) + (overtime * overtimeWage);
            }
        else
        {
            grossPay = hoursWorked * hourlyWage;
        }
        
        System.out.printf("Employee%d's gross pay is $%.2f\n", ++employeeNumber, grossPay);
        System.out.println("Would you like to calculate the next employee's data?(1 yes or 0 no): ");
        ask = input.nextInt();
        }
    } 
}
