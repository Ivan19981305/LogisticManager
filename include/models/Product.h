#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product {
public:
    int id;
    std::string name;
    double weight;
    int quantity;

    Product(int id, std::string name, double weight, int quantity);
    void display();
};

#endif // PRODUCT_H