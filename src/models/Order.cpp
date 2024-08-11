#include "Order.h"

Order::Order(int id, std::string deliveryLocation)
    : id(id), deliveryLocation(deliveryLocation) {}

void Order::display() {
    std::cout << "Order ID: " << id << ", Delivery Location: " << deliveryLocation << std::endl;
    std::cout << "Products in order:" << std::endl;
    for (const auto& productPair : products) {
        std::cout << " - Product: " << productPair.first.name << ", Quantity: " << productPair.second << std::endl;
    }
}

bool Order::processOrder(std::vector<Truck*>& trucks) {
    double currentVolume = 0;

    // Проходим по каждому продукту в заказе
    for (const auto& productPair : products) {
        const Product& product = productPair.first;
        int quantity = productPair.second;
        double totalWeight = quantity * product.weight;

        // Пробуем загрузить грузовики
        for (Truck* truck : trucks) {
            if (currentVolume < totalWeight) {
                while (truck->loadProduct(const_cast<Product&>(product))) {
                    std::cout << "Loaded product " << product.name << " onto Truck ID: " << truck->id << std::endl;
                    currentVolume += product.weight; // Обновляем загруженную массу
                    if (currentVolume >= totalWeight) break; // Заказ выполнен
                }
                truck->deliver(); // Доставка
            }
        }

        // Проверяем, был ли выполнен заказ для этого продукта
        if (currentVolume < totalWeight) {
            std::cout << "Unable to fulfill the order for product: " << product.name << " (Not enough truck capacity.)" << std::endl;
            return false; // Заказ не выполнен
        }
    }

    std::cout << "Order fulfilled successfully." << std::endl;
    return true; // Заказ выполнен
}

bool Order::processOrder(std::vector<Truck*>& trucks, Graph& g) { 
    // Предполагаем, что первый и последний город в маршруте - это склад и место доставки
    int startCity = 0;  // Индекс склада
    int endCity = 4;    // Индекс места доставки
  
    deliveryRoute = g.shortestPath(startCity, endCity);
  
    // Выводим маршрут 
    std::cout << "Delivery route: ";
    for (int city : deliveryRoute) {
        std::cout << city << " ";
    }
    std::cout << std::endl;

    return true;
}