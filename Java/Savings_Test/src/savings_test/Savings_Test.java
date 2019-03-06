package savings_test;
public class Savings_Test {
    public static void main(String[] args) {
         Savings_Account account1 = new Savings_Account( 2000);
   	 Savings_Account account2 = new Savings_Account( 3000);
         System.out.println(" \t\tAccount1 \tAccount2");
         System.out.printf("Base \t\t%.02f\t\t%.02f%n", account1.getSavingsBalence(),account2.getSavingsBalence());
   	
   	 for(int counter = 1; counter <= 12; counter++)
         {
            Savings_Account.modifyInterestRate(.04);
            System.out.printf("Month %d \t%.2f\t\t%.2f%n",
            counter,account1.calcTotal(),account2.calcTotal());
         }
          Savings_Account.modifyInterestRate(.05);
          System.out.printf("Month 13 \t%.2f\t\t%.2f%n",
          account1.calcTotal(),account2.calcTotal());
    }
}
