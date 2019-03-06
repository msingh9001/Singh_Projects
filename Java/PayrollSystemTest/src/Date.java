public class Date
{
   private int month;
   private int day;
   private int year;
 
   public Date( int theMonth, int theDay, int theYear )
   {
      month = theMonth;
      year = theYear;
      day = checkDay( theDay );
   } 
 
   public void setMonth(int theMonth)
   {
       month = theMonth;
   }
 
   public int getMonth()
   {
      if ( month > 0 && month <= 12 )
         return month;
      return 0;
   } 
   
   private int checkDay( int testDay )
   {
      int daysPerMonth[] =
         { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 
      if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
         return testDay;
 
      if ( month == 2 && testDay == 29 && ( year % 400 == 0 ||
           ( year % 4 == 0 && year % 100 != 0 ) ) )
         return testDay;
 
      return 0;
   }
   
    @Override
    
   public String toString()
   {
      return String.format( "%d/%d/%d", month, day, year );
   }
}