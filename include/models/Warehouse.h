#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Product.h"
#include <vector>
#include <string>

class Warehouse {
private:
    std::vector<Product> inventory;

public:
    int id;
    std::string location;

    Warehouse(int id, std::string location);
    void addProduct(Product product);
    void removeProduct(int productId, int quantity);
    void displayInventory();
};

#endif // WAREHOUSE_H