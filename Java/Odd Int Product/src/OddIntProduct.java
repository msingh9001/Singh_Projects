public class OddIntProduct {
    public static void main(String[] args) {     
        int product = 1;

        for (int count = 1; count <= 15; count += 2 )
        {
            product *= count;
        }
        System.out.printf("%d\n",product);
    }
}
