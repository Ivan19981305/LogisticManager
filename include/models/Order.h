#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <iostream>
#include <vector>
#include <utility> // Для std::pair
#include "Truck.h"
#include "Product.h"

class Order {
public:
    int id;
    std::string deliveryLocation;
    std::vector<std::pair<Product, int>> products; // Вектор пар продуктов и их количеств

    Order(int id, std::string deliveryLocation);
    void display();
    bool processOrder(std::vector<Truck*>& trucks);
};

#endif // ORDER_H