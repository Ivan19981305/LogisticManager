#include "Warehouse.h"

Warehouse::Warehouse(int id, std::string location) : id(id), location(location) {}

void Warehouse::addProduct(Product product) {
    inventory.push_back(product);
}

void Warehouse::removeProduct(int productId, int quantity) {
    for (auto& product : inventory) {
        if (product.id == productId && product.quantity >= quantity) {
            product.quantity -= quantity;
            if (product.quantity == 0) {
                // Можно реализовать логику удаления товара, если необходимо
            }
            break;
        }
    }
}

void Warehouse::displayInventory() {
    std::cout << "Warehouse at: " << location << std::endl;
    for (auto& product : inventory) {
        product.display();
    }
}