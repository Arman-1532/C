import java.util.ArrayList;
import java.util.List;

class Product {
    private int serialNumber;
    private String title;
    private double cost;
    private int quantity;

    public Product(int serialNumber, String title, double cost, int quantity) {
        this.serialNumber = serialNumber;
        this.title = title;
        this.cost = cost;
        this.quantity = quantity;
    }

    public int getSerialNumber() {
        return serialNumber;
    }

    public String getTitle() {
        return title;
    }

    public void exhibitDetails() {
        System.out.println("Serial Number: " + serialNumber + " Title: " + title + " Cost: " + cost + " Quantity: " + quantity);
    }

    public void adjustPrice(double newCost) {
        this.cost = newCost;
    }

    public void modifyQuantity(int newQuantity) {
        this.quantity = newQuantity;
    }
}

class ElectricProduct extends Product {
    private String brand;
    private int warrantyPeriod;

    public ElectricProduct(String brand, int warrantyPeriod, int serialNumber, String title, double cost, int quantity) {
        super(serialNumber, title, cost, quantity);
        this.brand = brand;
        this.warrantyPeriod = warrantyPeriod;
    }

    public String getBrand() {
        return brand;
    }

    public void exhibitDetails() {
        super.exhibitDetails();
        System.out.println("Brand: " + brand + " Warranty Period: " + warrantyPeriod + " Months");
    }

    public void adjustWarrantyPeriod(int newWarrantyPeriod) {
        this.warrantyPeriod = newWarrantyPeriod;
    }
}

class OutfitProduct extends Product {
    private String size;
    private String shade;

    public OutfitProduct(String title, int serialNumber, double cost, int quantity, String size, String shade) {
        super(serialNumber, title, cost, quantity);
        this.size = size;
        this.shade = shade;
    }

    public void exhibitDetails() {
        super.exhibitDetails();
        System.out.println("Size: " + size + " Shade: " + shade);
    }
}

class GroceryProduct extends Product {
    private String expiryDate;
    private double storageTemperature;

    public GroceryProduct(int serialNumber, String title, double cost, int quantity, String expiryDate, double storageTemperature) {
        super(serialNumber, title, cost, quantity);
        this.expiryDate = expiryDate;
        this.storageTemperature = storageTemperature;
    }

    public void exhibitDetails() {
        super.exhibitDetails();
        System.out.println("Expiry Date: " + expiryDate + " Storage Temperature: " + storageTemperature);
    }
}

class Warehouse {
    private List<Product> items;

    public Warehouse() {
        this.items = new ArrayList<>();
    }

    public void includeItem(Product item) {
        this.items.add(item);
    }

    public void discardItem(int serialNumber) {
        items.removeIf(item -> item.getSerialNumber() == serialNumber);
    }

    public List<Product> searchByTitle(String title) {
        List<Product> results = new ArrayList<>();
        for (Product item : items) {
            if (item.getTitle().equals(title)) {
                results.add(item);
            }
        }
        return results;
    }

    public List<Product> searchByBrand(String brand) {
        List<Product> results = new ArrayList<>();
        for (Product item : items) {
            if (item instanceof ElectricProduct) {
                ElectricProduct electronicProduct = (ElectricProduct) item;
                if (electronicProduct.getBrand().equals(brand)) {
                    results.add(item);
                }
            }
        }
        return results;
    }
}

public class Shop {
    public static void main(String[] args) {
        Warehouse warehouse = new Warehouse();

        ElectricProduct gadget = new ElectricProduct("Dell",  24 , 1, "Laptop", 1000, 10);
        OutfitProduct attire = new OutfitProduct("T-shirt", 2, 20, 50, "M", "Blue");
        GroceryProduct groceries = new GroceryProduct(3, "Milk", 2, 100, "5.10.24", 4);

        warehouse.includeItem(gadget);
        warehouse.includeItem(attire);
        warehouse.includeItem(groceries);

        for (Product item : warehouse.searchByTitle("Milk")) {
            item.exhibitDetails();
        }

        warehouse.discardItem(1);
    }
}