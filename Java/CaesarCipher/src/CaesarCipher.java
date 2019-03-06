import java.util.Scanner;

public class CaesarCipher {
   public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.printf("Please enter code to be encrypted:");
    String plainText = in.nextLine();
    String encryptedCode = "";
    int i = 0, j = 0, key;
    char[] characters = {'@', 'A', 'B', 'C', 'D', 'E', 'F','G','H','I','J','K','L',
        'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};

    plainText = plainText.toUpperCase();
    char[] plainTextChar = plainText.toCharArray();
    while(i != plainText.length()) {
        while(j < 37){  
            if(plainTextChar[i] == characters[j]){
                key = (((13*j)+5)%37);
                encryptedCode += encryptedCode.concat(Character.toString(characters[key]));
            }
            j++;
        }
        i++;
    }
    System.out.println(encryptedCode);
    }  
}