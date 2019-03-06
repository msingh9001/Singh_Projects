public class Employee {

    public static void main(String[] args) {
        
        EmployeeTest employee1 = new EmployeeTest("Robert", "Johnson", 2000);
        EmployeeTest employee2 = new EmployeeTest("Frank", "Hendrickson", 2750);
        
        double yearlySalary1 = employee1.getMonthlySalary() * 12;
        double yearlySalary2 = employee2.getMonthlySalary() * 12;
        
        double raise1 = yearlySalary1 * 1.10;
        double raise2 = yearlySalary2 * 1.10;
        
        System.out.printf("%s %s's monthly salary is $%.2f\n", employee1.getFirstName(), employee1.getLastName(),
                employee1.getMonthlySalary());
        System.out.printf("%s %s's monthly salary is $%.2f\n", employee2.getFirstName(), employee2.getLastName(),
                employee2.getMonthlySalary());
        
        System.out.printf("%s %s's yearly salary is $%.2f\n", 
                employee1.getFirstName(), employee1.getLastName(), yearlySalary1);
        System.out.printf("%s %s's yearly salary is $%.2f\n", 
                employee1.getFirstName(), employee1.getLastName(), yearlySalary2);
        
        System.out.printf("After a 10 percent raise, %s %s's yearly salary is $%.2f\n", 
                employee1.getFirstName(), employee1.getLastName(), raise1);
        System.out.printf("After a 10 percent raise, %s %s's yearly salary is $%.2f\n", 
                employee1.getFirstName(), employee1.getLastName(), raise2);
    }
    
}