import java.util.Scanner;
public class TempreaturConversions {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int cont = 0;
        int CorF;
        int CInput;
        int FInput;
        
        while(cont != -1)
        {
            System.out.printf("Please enter 0 for a Celcius input or 1 for a Fahrenheit input: ");
            CorF = input.nextInt();
            
            if(CorF == 0)
            {
                System.out.printf("Please input Celcius value: ");
                CInput = input.nextInt();
                    
                System.out.printf("%d degrees Celcius is %.2f degrees Fahrenheit", CInput, FConversion(CInput));
            }
            
            if(CorF == 1)
            {
                System.out.printf("Please input Fahrenheit value: ");
                FInput = input.nextInt();
                    
                System.out.printf("%d degrees Fahrenheit is %.2f degrees Celcius", FInput, CConversion(FInput));
            }
            
            if(CorF != 0 && CorF != 1)
            {
                System.out.printf("\nThat is an invalid value\n");
                continue;
            }
            
            System.out.printf("Type -1 to quit or any other number to convert another value: ");
            cont = input.nextInt();
        }
        
    }  
    
    public static double FConversion(double CInput)
    {
        double fConversion = (9.0/5.0 * CInput) + 32;
        return fConversion;
    }
    
    public static double CConversion(double FInput)
    {
        double cConversion = (FInput - 32) * (9.0/5.0);
        return cConversion;
    }
}
