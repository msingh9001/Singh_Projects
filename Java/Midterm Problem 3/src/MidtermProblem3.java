public class MidtermProblem3 {
    public static void main(String[] args) {
    
    int counter1 = 0;
    int sum = 0;
    int[] array1 = new int[9];
    for(int i = 0; i < array1.length; i++) {
        array1[i] = (int)(Math.random() * 16 + 1);
        }
    System.out.printf("Generated numbers are:[ ");
    
    while(counter1 < 9)
    {
        System.out.print(array1[counter1]);
        System.out.print(" ");
        counter1++;
    }
    System.out.print("]");
    
    for(int j: array1)
    {
        sum += j;
    }
    
    double average = sum/9;
    System.out.printf("\nTotal:%d     Average:%.2f", sum, average);
    
    int k = 0;
    int counter2 = 0;
    while(k < 9)
    {
        if(array1[k] > average)
        {
            counter2++;
        }
        k++;
    }
    System.out.printf("\nNumbers above the average: %d", counter2);
    
    int altSum = array1[0] - array1[1] + array1[2] - array1[3] + array1[4] - array1[5] + array1[6] - array1[7] + array1[8];
    System.out.printf("\nAlternating Sum:%d\n", altSum);
    }
}