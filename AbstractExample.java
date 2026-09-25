abstract class Shape{
    abstract double calculateArea();
}
class rectangle extends Shape{
    private double base;
    private double height;
    
    rectangle( double base , double height ){
        this.base = base;
        this.height = height;
    }
    @Override
    double calculateArea(){
        return base*height; 
    }
}
class triangle extends Shape{
    private double base;
    private double height;

    triangle( double base , double height ){
        this.base = base;
        this.height = height;
    }
    @Override
    double calculateArea(){
        return base*height*0.5;
    }

}
public class AbstractExample{
    public static void main(String[] args) {
        Shape Rectangle = new rectangle( 4 , 5 );
        Shape Triangle = new triangle( 4 , 8 );

        System.out.println("Area of Rectangle :" + Rectangle.calculateArea());
        System.out.println("Area of Triangle : " + Triangle.calculateArea());
    }
}
