#include <iostream>
#include "OrderTests.h"
#include "Graph.h" 

int main() {
    testSuccessfulDelivery();  // Запуск теста с успешной доставкой

    std::cout << std::endl;

    testUnsuccessfulDelivery(); // Запуск теста с неуспешной доставкой

    return 0;
}