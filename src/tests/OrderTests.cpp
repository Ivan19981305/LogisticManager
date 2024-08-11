#include <iostream>
#include <vector>
#include "Product.h"
#include "Warehouse.h"
#include "Truck.h"
#include "Order.h"
#include "OrderTests.h"
#include "Graph.h" 

void runTests(){
    testSuccessfulDelivery();
    std::cout << "\n";
    testUnsuccessfulDelivery();
    std::cout << "\n";
    testPartiallyFulfilledOrder();
    std::cout << "\n";
    testEmptyOrder();
    std::cout << "\n";
    testDeliveryRoute();
    std::cout << "\n";
    testDeliveryRouteWithObstacles();
    std::cout << "\n";
}

void testSuccessfulDelivery() {
    std::cout << "Running testSuccessfulDelivery\...n";
    Warehouse warehouse(1, "123 Main St");
    Product product1(101, "Widget", 1.5, 100);
    Product product2(102, "Gadget", 2.0, 50);
    warehouse.addProduct(product1);
    warehouse.addProduct(product2);

    Truck truck1(1, 10.0, "789 Pine St"); // Достаточная грузоподъемность
    Truck truck2(2, 5.0, "456 Elm St");

    Order order1(1, "1000 Delivery Rd");
    order1.products.emplace_back(product1, 3); // 3 Widgets
    order1.products.emplace_back(product2, 2); // 2 Gadgets
    order1.display();

    // Список грузовиков для выполнения заказа
    std::vector<Truck*> trucks;
    trucks.push_back(&truck1);
    trucks.push_back(&truck2);
    
    // Обработка заказа с использованием метода processOrder
    if (!order1.processOrder(trucks)) {
        std::cout << "Failed to fulfill the order due to insufficient truck capacity.\n";
    }

    // Вывод информации
    warehouse.displayInventory();
    truck1.display();
    truck2.display();
}

void testUnsuccessfulDelivery() {
    std::cout << "Running testUnsuccessfulDelivery...";
    Warehouse warehouse(2, "456 Main St");
    Product product1(201, "Thingamajig", 3.0, 80);
    Product product2(202, "Doohickey", 4.0, 40);
    warehouse.addProduct(product1);
    warehouse.addProduct(product2);

    Truck truck1(1, 3.0, "789 Pine St"); // Низкая грузоподъемность
    Truck truck2(2, 4.0, "456 Elm St"); // Низкая грузоподъемность

    Order order2(2, "2000 Delivery Rd");
    order2.products.emplace_back(product1, 4); // 4 Thingamajigs
    order2.products.emplace_back(product2, 2); // 2 Doohickeys
    order2.display();

    // Список грузовиков для выполнения заказа
    std::vector<Truck*> trucks;
    trucks.push_back(&truck1);
    trucks.push_back(&truck2);
    
    // Обработка заказа с использованием метода processOrder
    if (!order2.processOrder(trucks)) {
        std::cout << "Failed to fulfill the order due to insufficient truck capacity.\n";
    }

    // Вывод информации
    warehouse.displayInventory();
    truck1.display();
    truck2.display();
}

void testEmptyOrder() {
    std::cout << "Running testEmptyOrder...\n";
    Order order(3, "3000 Empty Rd");
    std::vector<Truck*> trucks; 
    
    // Заказ без товаров должен быть выполнен успешно
    if (!order.processOrder(trucks)) {
        std::cout << "ERROR: Empty order should be fulfilled successfully.\n";
    }
}

void testPartiallyFulfilledOrder() {
    std::cout << "Running testPartiallyFulfilledOrder...\n";
    Warehouse warehouse(3, "789 Storage Ln");
    Product product1(301, "Heavy Item", 5.0, 10); // Тяжелый товар
    warehouse.addProduct(product1);

    Truck truck1(3, 7.0, "123 Shipping St"); // Грузовик с недостаточной вместимостью

    Order order(4, "4000 Partial Rd");
    order.products.emplace_back(product1, 2); // 2 тяжелых товара (10 тонн общий вес)
    order.display();

    std::vector<Truck*> trucks;
    trucks.push_back(&truck1);

    // Заказ не должен быть выполнен полностью из-за недостаточной вместимости
    if (order.processOrder(trucks)) {
        std::cout << "ERROR: Order should not be fulfilled completely.\n";
    }

    warehouse.displayInventory(); 
    truck1.display();
}

void testDeliveryRoute() { 
    std::cout << "Running testDeliveryRoute...\n";

    // Создаем тестовый граф
    Graph g(5); 
    g.addEdge(0, 1, 10); 
    g.addEdge(0, 3, 30);
    g.addEdge(0, 4, 100);
    g.addEdge(1, 2, 50);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 60);

    // Создаем продукты
    Product product1(1, "Product A", 2.5, 10);
    Product product2(2, "Product B", 1.0, 20);

    // Создаем склад и добавляем продукты
    Warehouse warehouse(4, "Test Warehouse"); 
    warehouse.addProduct(product1);
    warehouse.addProduct(product2);

    // Создаем грузовик
    Truck truck(4, 10.0, "Truck Depot");

    // Создаем заказ и добавляем продукты 
    Order order(4, "Test Delivery"); 
    order.products.emplace_back(product1, 2);  // 2 единицы Product A
    order.products.emplace_back(product2, 5);  // 5 единиц Product B

    // Запускаем обработку заказа 
    std::vector<Truck*> trucks = {&truck};
    order.processOrder(trucks, g); 

    // Проверяем, что маршрут рассчитан верно 
    std::vector<int> expectedRoute = {0, 1, 2, 4}; 
    if (order.deliveryRoute != expectedRoute) { 
        std::cout << "ERROR: Incorrect delivery route calculated.\n"; 
    } 
}

void testDeliveryRouteWithObstacles() {
    std::cout << "Running testDeliveryRouteWithObstacles...\n";
    
    // Создаем тестовый граф С ПРЕПЯТСТВИЕМ
    Graph g(5); 
    g.addEdge(0, 1, 10);
    g.addEdge(0, 3, 30);
    g.addEdge(1, 2, 50);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 60); // Этот путь есть
    // g.addEdge(0, 4, 100); // Этого пути НЕТ!

    // Создаем продукты
    Product product1(1, "Product A", 2.5, 10);
    Product product2(2, "Product B", 1.0, 20);

    // Создаем склад и добавляем продукты
    Warehouse warehouse(4, "Test Warehouse"); 
    warehouse.addProduct(product1);
    warehouse.addProduct(product2);

    // Создаем грузовик
    Truck truck(4, 10.0, "Truck Depot");

    // Создаем заказ и добавляем продукты 
    Order order(4, "Test Delivery"); 
    order.products.emplace_back(product1, 2);  // 2 единицы Product A
    order.products.emplace_back(product2, 5);  // 5 единиц Product B


    // Запускаем обработку заказа 
    std::vector<Truck*> trucks = {&truck};
    order.processOrder(trucks, g); 

    // Проверяем, что маршрут рассчитан верно 
    std::vector<int> expectedRoute = {0, 3, 4}; // Ожидаем путь в объезд
    if (order.deliveryRoute != expectedRoute) { 
        std::cout << "ERROR: Incorrect delivery route calculated with obstacles.\n"; 
    } 
}