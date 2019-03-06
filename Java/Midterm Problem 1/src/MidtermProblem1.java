import java.util.Scanner;
public class MidtermProblem1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int courses = 1;
        int units= 0;
        int totalUnits = 0;
        int gradePoints;
        int grade; 
        int totalGradePoints= 0;
        
        while(units != -1)
        {
            System.out.printf("Enter course %d units(-1 to exit): ", courses);
           units= input.nextInt();
            if(units != -1)
            {
             
             totalUnits = units + totalUnits;  
            
            System.out.printf("Enter grade point (A-4.0, B-3.0, C-2.0, D-1.0, F-0.0): ");
            gradePoints = input.nextInt();
            grade = gradePoints * units;
            totalGradePoints = totalGradePoints + grade;
            
            courses++;
            }
            else
            {
                break;
            }
        }
        double GPA = totalGradePoints / totalUnits;
        
        if(courses == 1)
        {
            System.out.printf("No Courses Entered\n");
        }
        
        if(courses != 1)
        {
            System.out.printf("\nTotal Number of Courses:%d     Total Units:%d     Total Grade Points:%d     GPA:%.2f\n", 
                    courses - 1, totalUnits, totalGradePoints, GPA);
        }       
    }  
}
