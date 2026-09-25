import java.util.ArrayList;
import java.util.Scanner;

public class CustomerInfoProcessor {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Please enter the customer information string: ");
        String customerInfo = scanner.nextLine();
 
        String[] infoArray = customerInfo.split(",");
        
        ArrayList<String> infoList = new ArrayList<>();
        for (String info : infoArray) {
            infoList.add(info.trim());
        }
        
        String name = infoList.get(0);
        String email = infoList.get(1);
        String phoneNumber = infoList.get(2);
        
        phoneNumber = phoneNumber.replace(" ", "");
        
        String formattedString = String.format("Customer Name: %s\nEmail Address: %s\nPhone Number: %s", name, email, phoneNumber);
        
        System.out.println(formattedString);
        
        scanner.close();
    }
}