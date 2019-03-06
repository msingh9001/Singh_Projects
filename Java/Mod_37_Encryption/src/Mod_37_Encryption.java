//@author Mandeep Singh

import java.util.Scanner;

public class Mod_37_Encryption {
    public static void main(String[] args) {
        System.out.printf("Welcome to the mod 37 encryption program. \nDue to some technical issues,"
                + " we ask that you enter each character of your secret code at a time.\n"
                + "We are sorry for the inconvenience and will fix this issue shortly.\n"
                + "Sincerely,\nGoogle Devs\n\n");
        
        Scanner in = new Scanner(System.in);
        
        String plainText = "";//Variable that determines whether to continue or break loop
        String encryptedCode = "";
          
        while(!"-1".equals(plainText)){
            
            System.out.printf("Please enter your character to be encrypted(-1 to exit):");
            plainText = in.nextLine();
            int i = 0, j = 0, key;
            
            //A character array of all possible inputs
            char[] characters = {'@', 'A', 'B', 'C', 'D', 'E', 'F','G','H','I','J','K','L',
                'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};

            plainText = plainText.toUpperCase();//We make everything uppercase
            char[] plainTextChar = plainText.toCharArray();//Put the input into a character array
            
            while(i != plainText.length()) {
                while(j < 37){  
                    if(plainTextChar[i] == characters[j]){
                        key = (((13*j)+5)%37);
                        encryptedCode = encryptedCode.concat(Character.toString(characters[key]));
                    }
                    j++;
                }
                i++;
            }
        }
        System.out.printf(encryptedCode);
        System.out.printf("\n");
    }
}                    