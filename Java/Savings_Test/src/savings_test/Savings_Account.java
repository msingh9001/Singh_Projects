package savings_test;
public class Savings_Account 
{
    static double interestRates()
    {
        throw new UnsupportedOperationException("");
    }
    
    private double savingsBalence;
    static double interestRates;
    
    public Savings_Account(double savingsBalence)
    {
   	 if(savingsBalence > 0)
            this.savingsBalence = savingsBalence;    
    }
    
    public void setSavingsBalence(double savingsBalence)
    {
   	 if(savingsBalence > 0)
            this.savingsBalence = savingsBalence;
    }
    
    public double getSavingsBalence() {
            return savingsBalence;
    }
    
    public static double getInterestRates()
    {
   	 return interestRates;
    }
    
    public static void modifyInterestRate(double rate)
    {
        interestRates = rate;
    }
    
    public double calculateMonthlyInterest()
	{
        double calculateMonthlyInterest = (getSavingsBalence()* getInterestRates())/12;
        savingsBalence += calculateMonthlyInterest;
    	return calculateMonthlyInterest;
	}
    
    public double calcTotal() 
    {
   	 double calcTotal = calculateMonthlyInterest() + getSavingsBalence();
   	 return calcTotal; 
    }
    
    public String Balence() 
    {
   	 return String.format("%f", calcTotal());
    }
}
