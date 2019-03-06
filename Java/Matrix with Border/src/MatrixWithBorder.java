import java.util.Scanner;
public class MatrixWithBorder {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.printf("Please enter a border character: ");
        String character = input.nextLine();

        int counter = 0;
        
        while(counter < 4)
        {
            System.out.print(character);
            counter++;
        }
        for(int count = 0; counter < 4 && counter != 1 && counter != 2; count++)
                {
                    System.out.print(character); 
                }
        
        while(counter < 8)
        {
            System.out.print(character);
            counter++;
        }
    }
    
}
