#ifndef TRUCK_H
#define TRUCK_H

#include "Product.h"
#include <string>

class Truck {
public:
    int id;
    double capacity;
    double currentLoad;
    std::string location;

    Truck(int id, double capacity, std::string location);
    bool loadProduct(Product& product);
    void deliver();
    void display();
};

#endif // TRUCK_H