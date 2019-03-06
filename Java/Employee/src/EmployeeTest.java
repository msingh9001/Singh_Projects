public class EmployeeTest {
    private String firstName;
    private String lastName;
    private double monthlySalary;
    
    public EmployeeTest(String firstName, String lastName, double monthlySalary)
    {
        this.firstName = firstName;
        this.lastName = lastName;
        
        if (monthlySalary > 0.0)
      {
       this.monthlySalary = monthlySalary; 
      }
      if (monthlySalary <= 0.0)
      {
          this.monthlySalary = 0.0;
      }
      }
    
    public void setFirstName(String firstName)
   {
      this.firstName = firstName; 
   } 
    public String getFirstName()
   {
      return firstName; 
   } 
    
    public void setLastName(String lastName)
   {
      this.lastName = lastName; 
   } 
      public String getLastName()
   {
      return lastName; 
   } 
      
      public void setMonthlySalary(double monthlySalary)
   {
      this.monthlySalary = monthlySalary;
   } 
      public double getMonthlySalary()
   {
      return monthlySalary;
   }  
}
