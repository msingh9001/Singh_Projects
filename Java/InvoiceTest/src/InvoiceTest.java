import java.util.Scanner;

public class InvoiceTest {

    public static void main(String[] args) {
        
        Invoice invoice1 = new Invoice("", "", 0, 0.0);
        
        Scanner input = new Scanner(System.in);
        
        String partNumber;
        String partDescription;
        int quantity;
        double price;
        
        System.out.printf("Enter part number: ");
        partNumber = input.nextLine();
        invoice1.setPartNumber(partNumber);
        
        System.out.printf("%nEnter part description: ");
        partDescription = input.nextLine();
        invoice1.setPartDescription(partDescription);
        
        System.out.printf("%nEnter quantity: ");
        quantity = input.nextInt();

        if (quantity > 0)
        {
            invoice1.setQuantity(quantity);
        }
        
        System.out.printf("%nEnter price per part: ");
        price = input.nextDouble();

        if (price > 0)
        {
            invoice1.setPrice(price);
        }
        
        System.out.printf("%n The total price of %d %s %s is $%.2f\n",
                invoice1.getQuantity(), invoice1.getPartNumber(), invoice1.getPartDescription() ,invoice1.getInvoiceAmount());
    } 
}
