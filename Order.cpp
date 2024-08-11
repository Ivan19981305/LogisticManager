#include "Order.h"

Order::Order(int id, int productId, int quantity, std::string deliveryLocation)
    : id(id), productId(productId), quantity(quantity), deliveryLocation(deliveryLocation) {}

void Order::display() {
    std::cout << "Order ID: " << id << ", Product ID: " << productId
              << ", Quantity: " << quantity << ", Delivery Location: " 
              << deliveryLocation << std::endl;
}
