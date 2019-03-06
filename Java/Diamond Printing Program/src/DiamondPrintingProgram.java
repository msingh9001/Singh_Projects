public class DiamondPrintingProgram {
    public static void main(String[] args) {
 int size = 9;

    for (int i = 1; i < size; i += 2) {
        for (int j = size; j >= i; j -= 2) {
            System.out.print(" ");
        }
        for (int k = 1; k <= i; k++) {
            System.out.print("*");
        }
        System.out.println();
    }

    for (int i = 1; i <= size; i += 2) {
        for (int j = 1; j <= i; j += 2) {
            System.out.print(" ");
        }
        for (int k = size; k >= i; k--) {
            System.out.print("*");
        }
        System.out.println();
        }
    }   
}
