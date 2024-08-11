#include "Product.h"

Product::Product(int id, std::string name, double weight, int quantity)
    : id(id), name(name), weight(weight), quantity(quantity) {}

void Product::display() {
    std::cout << "Product ID: " << id << ", Name: " << name
              << ", Weight: " << weight << ", Quantity: " << quantity << std::endl;
}