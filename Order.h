#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <iostream>

class Order {
public:
    int id;
    int productId;
    int quantity;
    std::string deliveryLocation;

    Order(int id, int productId, int quantity, std::string deliveryLocation);
    void display();
};

#endif // ORDER_H