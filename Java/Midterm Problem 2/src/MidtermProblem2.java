import java.util.Scanner;
public class MidtermProblem2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.printf("Enter number of rows: ");
        int rows = input.nextInt();
        System.out.printf("Enter number of columns: ");
        int columns = input.nextInt();
      
        printStarMatrix(rows, columns);
        
    }
    
    public static void printStarMatrix(int rows, int columns)
    {
        String asterisk = "*";
        for(int a = 0; a < rows; a++) 
        {
            System.out.println("");
            for (int b = 0; b <= columns; b++) 
            {
                System.out.print("*");
            }
        }
        System.out.println("");
    }
    
    public static String printBorder(int rows, int columns, String character)
    {
        String border = character;
       
        return border;
    }
}
