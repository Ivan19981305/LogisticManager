#include <iostream>
#include <vector>
#include <string>

class Product {
public:
    int id;
    std::string name;
    double weight;
    int quantity;

    Product(int id, std::string name, double weight, int quantity)
        : id(id), name(name), weight(weight), quantity(quantity) {}

    void display() {
        std::cout << "Product ID: " << id << ", Name: " << name
                  << ", Weight: " << weight << ", Quantity: " << quantity << std::endl;
    }
};

class Warehouse {
private:
    std::vector<Product> inventory;
public:
    int id;
    std::string location;

    Warehouse(int id, std::string location) : id(id), location(location) {}

    void addProduct(Product product) {
        inventory.push_back(product);
    }

    void removeProduct(int productId, int quantity) {
        for (auto &product : inventory) {
            if (product.id == productId && product.quantity >= quantity) {
                product.quantity -= quantity;
                if (product.quantity == 0) {
                    // Remove product from inventory (optional)
                }
                break;
            }
        }
    }

    void displayInventory() {
        std::cout << "Warehouse at: " << location << std::endl;
        for (const auto &product : inventory) {
            product.display();
        }
    }
};

class Truck {
public:
    int id;
    double capacity;
    double currentLoad;
    std::string location;

    Truck(int id, double capacity, std::string location)
        : id(id), capacity(capacity), location(location), currentLoad(0) {}

    bool loadProduct(Product &product) {
        if (currentLoad + product.weight <= capacity) {
            currentLoad += product.weight;
            product.quantity--; // Reduce product quantity
            return true;
        }
        return false;
    }

    void deliver() {
        // Delivery logic here (for illustration)
        std::cout << "Delivering from Truck ID: " << id << " to " << location << std::endl;
        currentLoad = 0; // Reset load after delivering
    }

    void display() {
        std::cout << "Truck ID: " << id << ", Capacity: " << capacity 
                  << ", Current Load: " << currentLoad << ", Location: " << location << std::endl;
    }
};

class Order {
public:
    int id;
    int productId;
    int quantity;
    std::string deliveryLocation;

    Order(int id, int productId, int quantity, std::string deliveryLocation)
        : id(id), productId(productId), quantity(quantity), deliveryLocation(deliveryLocation) {}

    void display() {
        std::cout << "Order ID: " << id << ", Product ID: " << productId
                  << ", Quantity: " << quantity << ", Delivery Location: " << deliveryLocation << std::endl;
    }
};

int main() {
    // Пример использования
    Warehouse warehouse(1, "123 Main St");
    Product product1(101, "Widget", 1.5, 100);
    warehouse.addProduct(product1);
    
    Warehouse warehouse2(2, "456 Elm St");
    Product product2(102, "Gadget", 2.0, 50);
    warehouse2.addProduct(product2);

    Truck truck(1, 10.0, "789 Pine St");

    Order order1(1, 101, 5, "1000 Delivery Rd");
    order1.display();
    
    // Процесс выполнения заказа
    warehouse.removeProduct(order1.productId, order1.quantity);
    if (truck.loadProduct(product1)) {
        truck.deliver();
    }

    // Вывод информации
    warehouse.displayInventory();
    truck.display();

    return 0;
}