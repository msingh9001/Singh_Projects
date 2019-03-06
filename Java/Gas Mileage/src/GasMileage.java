import java.util.Scanner;
public class GasMileage {
    public static void main(String[] args) {
     Scanner input = new Scanner(System.in);
     
     int miles = 0;
     int gallons;
     double localMPG;
     double totalMPG;
     double totalMiles = 0;
     double totalGallons = 0;
     
     while(miles != -1)
     {
         System.out.printf("Please enter miles: ");
         miles = input.nextInt();
         if(miles != -1)
         {
             totalMiles += miles;
             
             System.out.printf("\nPlease enter gallons: ");
             gallons = input.nextInt();
             totalGallons += gallons; 
             
             localMPG = miles/gallons;
             System.out.printf("\nThe MPG for this trip is %.2f\n", localMPG);
         }
     }
     totalMPG = totalMiles/totalGallons;
     System.out.printf("\nThe total MPG so far is %.2f\n", totalMPG);
    }
}
