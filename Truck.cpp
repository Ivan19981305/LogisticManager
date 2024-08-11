#include "Truck.h"
#include <iostream>

Truck::Truck(int id, double capacity, std::string location)
    : id(id), capacity(capacity), location(location), currentLoad(0) {}

bool Truck::loadProduct(Product& product) {
    if (currentLoad + product.weight <= capacity) {
        currentLoad += product.weight;
        product.quantity--; // Уменьшаем количество товара
        return true;
    }
    return false;
}

void Truck::deliver() {
    std::cout << "Delivering from Truck ID: " << id << " to " << location << std::endl;
    currentLoad = 0; // Сбрасываем загрузку после доставки
}

void Truck::display() {
    std::cout << "Truck ID: " << id << ", Capacity: " << capacity
              << ", Current Load: " << currentLoad << ", Location: " << location << std::endl;
}