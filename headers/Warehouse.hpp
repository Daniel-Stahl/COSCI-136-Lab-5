#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "OrderStack.hpp"
#include "InventoryStack.hpp"

using namespace std;

class Warehouse {
public:
    void AddOrderToStack();
    void AddDeliveryToStack();
    void CheckInput(int input);
    void CheckInput(double input);
    void FillOrder();
    bool IsOrderFilled(OrderStackNode* orderNode) const;
    void PrintOrderDetails(OrderStackNode* orderNode, vector<Deliveries> delivery, int totalShipped, double warehouseCost, double customerCost);
    void PrintOrders();
    void PrintInventory();
    void EmptyStacks();
    ~Warehouse();
    
private:
    OrderStack orderStack;
    InventoryStack inventoryStack;
};
