package test_rectangle;
public class Rectangle {
    private double length ;
    private double width ;

    public void setLength( double length)
    {
        if (length < 0 || length > 20)
        {
            throw new IllegalArgumentException("For input length:0.0");
        }
        this.length = length;
    }
    public void setWidth(double width)
    {
    if ( width <0 || width > 20)
    {
        throw new IllegalArgumentException("For input width:0.0");
    }
    this.width = width;
    }
     
    public double getLength()
    {
    return length;
    } 
     
         
    public double getWidth()
    {
    return width;
    } 
         
    public double getPerimeter()
    {
        return (length + width)*2 ;
    }
       
    public double getArea()
    {
        return length * width ;
    }
       
    public String Calculations1() {
   	 return String.format("%n%.2f is the perimeter %n%.2f is the area",
         getPerimeter(), getArea());
                                     }
    public String Calculations() {
   	 return String.format("%.2f is the length %n%.2f is the width %n%.2f is the perimeter %n%.2f is the area%n",
         getLength(), getWidth(),getPerimeter(), getArea());
                                 }
}