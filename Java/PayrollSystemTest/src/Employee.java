public abstract class Employee
{
   private String firstName;
   private String lastName;
   private String socialSecurityNumber;
   private Date birthday;
 
   public Employee( String first, String last, String ssn , Date DayOfBirth)
   {
      firstName = first;
      lastName = last;
      socialSecurityNumber = ssn;
      birthday = DayOfBirth;
   }
 
   public void setFirstName( String first )
   {
      firstName = first;
   } 
   
   public String getFirstName()
   {
      return firstName;
   }
   
   public void setLastName( String last )
   {
      lastName = last;
   }
   
   public String getLastName()
   {
      return lastName;
   }
   
   public void setSocialSecurityNumber( String ssn )
   {
      socialSecurityNumber = ssn;
   }
 
   public String getSocialSecurityNumber()
   {
      return socialSecurityNumber;
   }
   
   public void setBirthday(Date DayOfBirth)
   {
       birthday = DayOfBirth;
   }
   
   public Date getBirthday()
   {
       return birthday;
   }
 
    @Override
    
   public String toString()
   {
      return String.format( "%s %s\nsocial security number: %s\nbirthday: %s\n",
         getFirstName(), getLastName(), getSocialSecurityNumber(), getBirthday());
   } 
   
   public abstract double earnings();
}