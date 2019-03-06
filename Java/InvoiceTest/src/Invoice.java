public class Invoice {
    public String partNumber;
    public String partDescription;
    public int quantity;
    public double price;
    
    public Invoice(String partNumber, String partDescription, int quantity, double price)
    {
        this.partNumber = partNumber;
        this.partDescription = partDescription;
        this.quantity = quantity;

        if (price > 0)
        {
            this.price = price;
        }
    }
    
    public void setPartNumber(String partNumber)
   {
      this.partNumber = partNumber; 
   } 
    
    public String getPartNumber()
   {
      return partNumber; 
   } 
    
     public void setPartDescription(String partDescription)
   {
      this.partDescription = partDescription; 
   }  
    public String getPartDescription()
   {
      return partDescription; 
   } 
    
     public void setQuantity(int quantity)
   {
      this.quantity = quantity; 
   } 
    public int getQuantity()
   {
      return quantity; 
   } 
    
     public void setPrice(double price)
   {
      this.price = price; 
   }  
    public double getPrice()
   {
      return price; 
   }
   
    public double getInvoiceAmount()
    {
        double invoiceAmount;
        invoiceAmount = quantity * price;
        return invoiceAmount;
    }
}
