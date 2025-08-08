import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class MenuItem {
    private String name;
    private String description;
    private double price;

    public MenuItem(String name, String description, double price) {
        this.name = name;
        this.description = description;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public String getDescription() {
        return description;
    }

    public double getPrice() {
        return price;
    }

    @Override
    public String toString() {
        return name + " - " + description + " - $" + price;
    }
}

class Restaurant {
    private String name;
    private List<MenuItem> menu;

    public Restaurant(String name) {
        this.name = name;
        this.menu = new ArrayList<>();
    }

    public void addMenuItem(MenuItem item) {
        menu.add(item);
    }

    public List<MenuItem> getMenu() {
        return menu;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return name;
    }
}

public class RestaurantCatalog {
    public static void main(String[] args) {
        List<Restaurant> restaurants = new ArrayList<>();

        // Create some restaurants
        Restaurant restaurant1 = new Restaurant("Tasty Bites");
        restaurant1.addMenuItem(new MenuItem("Burger", "Classic beef burger", 9.99));
        restaurant1.addMenuItem(new MenuItem("Pizza", "Margherita pizza", 12.99));

        Restaurant restaurant2 = new Restaurant("Spice Delight");
        restaurant2.addMenuItem(new MenuItem("Curry", "Spicy chicken curry", 11.99));
        restaurant2.addMenuItem(new MenuItem("Rice", "Steamed Basmati rice", 4.99));

        restaurants.add(restaurant1);
        restaurants.add(restaurant2);

        Scanner scanner = new Scanner(System.in);

        System.out.println("Welcome to the Restaurant Catalog!");

        while (true) {
            System.out.println("Select a restaurant or enter 'q' to quit:");
            for (int i = 0; i < restaurants.size(); i++) {
                System.out.println((i + 1) + ". " + restaurants.get(i));
            }

            String choice = scanner.nextLine();

            if (choice.equals("q")) {
                System.out.println("Thank you for using the Restaurant Catalog. Goodbye!");
                break;
            }

            try {
                int restaurantIndex = Integer.parseInt(choice) - 1;
                if (restaurantIndex >= 0 && restaurantIndex < restaurants.size()) {
                    Restaurant selectedRestaurant = restaurants.get(restaurantIndex);
                    System.out.println("Menu for " + selectedRestaurant.getName() + ":");
                    List<MenuItem> menu = selectedRestaurant.getMenu();
                    for (MenuItem item : menu) {
                        System.out.println(item);
                    }
                } else {
                    System.out.println("Invalid restaurant choice. Please try again.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Please enter a number or 'q' to quit.");
            }
        }

        scanner.close();
    }
}
