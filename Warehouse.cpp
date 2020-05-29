#include "Warehouse.hpp"

void Warehouse::AddOrderToStack() {
    Order newOrder;
    
    int numOfItems = 0;
    
    do {
        cout << "\nHow many items ordered? ";
        cin >> numOfItems;
        
        if (numOfItems <= 0) {
            cout << "\nError: Orders must have items higher than 0, please try again.\n";
        }
        
    } while (numOfItems <= 0);
    
    newOrder.SetOrder(numOfItems);
    orderStack.Push(newOrder);
    OrderStackNode* orderNode = orderStack.Peek();
    
    if (!orderStack.IsEmpty() && !orderStack.IsFull(orderNode)) {
        FillOrder();
    } else {
        cout << "Cant fill order" << endl;
    }
}

void Warehouse::AddDeliveryToStack() {
    Deliveries newDelivery;
    int itemRecieved = 0;
    double itemCost = 0.0;
        
        while (itemRecieved <= 0) {
            cout << "\nHow many items in delivery? ";
            cin >> itemRecieved;
            CheckInput(itemRecieved);
        }
        
        
        while (itemCost <= 0.0) {
            cout << "\nCost per item? ";
            cin >> itemCost;
            CheckInput(itemCost);
        }
    
    newDelivery.SetDeliveries(itemRecieved, itemCost);
    inventoryStack.Push(newDelivery);
    FillOrder();
    
}

void Warehouse::CheckInput(int input) {
    if (input <= 0) {
        cout << "\nError: Items recieved must be higher than 0, please try again.\n";
    }
}
    
void Warehouse::CheckInput(double input) {
    if (input <= 0.0) {
        cout << "\nError: Item cost must be higher than 0, please try again.\n";
    }
}

void Warehouse::FillOrder() {
    if (!orderStack.IsEmpty() && !inventoryStack.IsEmpty()) {
        OrderStackNode* orderNode = orderStack.Peek();
        InventoryStackNode* deliveryNode = inventoryStack.Peek();
        InventoryStackNode tempDeliveryNode;
        int totalShipped = 0;
        double warehouseCost = 0;
        double customerCost = 0;
        vector<Deliveries>usedDeliveries;
        
        while(!orderStack.IsEmpty() && !inventoryStack.IsEmpty()) {
            int qtyMissing = orderNode->order.GetQtyNotFilled();
            int deliveryItems = deliveryNode->delivery.GetDeliveryItems();
            int orderID = orderNode->order.GetOrderID();
            tempDeliveryNode = *deliveryNode;
            
            if (qtyMissing >= deliveryItems) {
                qtyMissing = qtyMissing - deliveryItems;
                orderNode->order.SetQtyNotFilled(qtyMissing);
                inventoryStack.Pop();
            } else if (qtyMissing < deliveryItems) {
                deliveryItems = deliveryItems - qtyMissing;
                deliveryNode->delivery.SetDeliveryItems(deliveryItems);
                orderNode->order.SetQtyNotFilled(0);
                tempDeliveryNode.delivery.SetDeliveryItems(qtyMissing);
            }

            usedDeliveries.push_back(tempDeliveryNode.delivery);
            
            totalShipped += tempDeliveryNode.delivery.GetDeliveryItems();
            warehouseCost += tempDeliveryNode.delivery.GetCostPerItem() * tempDeliveryNode.delivery.GetDeliveryItems();
            customerCost += ((tempDeliveryNode.delivery.GetCostPerItem() * .5) + tempDeliveryNode.delivery.GetCostPerItem()) * tempDeliveryNode.delivery.GetDeliveryItems();
            
            if (!IsOrderFilled(orderNode) && !inventoryStack.IsEmpty()) {
                deliveryNode = inventoryStack.Peek();
                deliveryItems = deliveryNode->delivery.GetDeliveryItems();
            } else if (IsOrderFilled(orderNode)) { //
                cout << "Sending Order# " << orderID << " to shipping!\n";
                orderStack.Pop();
                PrintOrderDetails(orderNode, usedDeliveries, totalShipped, warehouseCost, customerCost);
                orderNode = orderStack.Peek();
                totalShipped = 0;
                warehouseCost = 0;
                customerCost = 0;
                usedDeliveries.clear();
                deliveryNode = inventoryStack.Peek();
            } else {
                PrintOrderDetails(orderNode, usedDeliveries, totalShipped, warehouseCost, customerCost);
            }
        }
    } else {
        cout << "\nOrders are empty or inventory is empty\n";
    }
}

bool Warehouse::IsOrderFilled(OrderStackNode* orderNode) const {
    if (orderNode->order.GetQtyNotFilled() == 0)
        return true;
    return false;
}

void Warehouse::PrintOrderDetails(OrderStackNode* orderNode, vector<Deliveries> delivery, int totalShipped, double warehouseCost, double customerCost) {
    int x = 0;
    int delSize = delivery.size();
    
    cout << "Order Number: " << orderNode->order.GetOrderID() << "\nQty to Ordered: " << orderNode->order.GetOrderItems() << "\nShipped this Shipment: " << totalShipped << "\nQty to be Shipped: " << orderNode->order.GetQtyNotFilled() << "\nTotal cost to the Warehouse: " << fixed << setprecision(2) << warehouseCost << "\nTotal cost to the Customer: " << customerCost << "\nProfit this Shipment: " << customerCost - warehouseCost << "\n";
    
    cout << "\nShipment Details:\n" << "Delivery #" << setw(15) << "Qty Shipped" << setw(15) << "Unit Price" << setw(25) << "Cost to the Warehouse" << setw(25) << setw(25) << "Cost to the Customer\n";
    
    while (x < delSize) {
        cout << right << setw(10) << delivery.at(x).GetDeliveryID() << setw(15) << delivery.at(x).GetDeliveryItems() << setw(15) << fixed << setprecision(2) << delivery.at(x).GetCostPerItem() << setw(25) << delivery.at(x).GetCostPerItem() * delivery.at(x).GetDeliveryItems() << setw(24) << ((delivery.at(x).GetCostPerItem() * .5) + delivery.at(x).GetCostPerItem()) * delivery.at(x).GetDeliveryItems() << "\n";
        
        x++;
    }
    
    cout << "\n";
}

void Warehouse::PrintOrders() {
    OrderStackNode* node = orderStack.Peek();
    
    if (node != nullptr) {
        cout << "\nOrder#" << setw(20) <<"Amount Ordered" << setw(20) << "Qty Remaining\n";
        
        while (node != nullptr) {
            cout << right << setw(6) << node->order.GetOrderID() << setw(20) << node->order.GetOrderItems() << setw(19) << node->order.GetQtyNotFilled() << "\n";
            
            node = node->next;
        }
        
        cout << "\n";
    } else {
        cout << "\nNo orders to print\n" << endl;
    }
}

void Warehouse::PrintInventory() {
    InventoryStackNode* node = inventoryStack.Peek();
    
    if (node != nullptr) {
        cout << "\nDelivery#" << setw(20) <<"QTY" << setw(20) <<"Cost\n";
        
        while (node != nullptr) {
            cout << right << setw(9) << node->delivery.GetDeliveryID() << setw(20) << node->delivery.GetDeliveryItems() << setw(20) << fixed << setprecision(2) << node->delivery.GetCostPerItem() << "\n";
            
            node = node->next;
        }
        
        cout << "\n";
    } else {
        cout << "\nNo inventory to print\n" << endl;
    }
}

void Warehouse::EmptyStacks() {
    if (!orderStack.IsEmpty()) {
        OrderStackNode* tempOrderHead = orderStack.Peek();
        
        while (tempOrderHead != nullptr) {
            tempOrderHead = tempOrderHead->next;
            orderStack.Pop();
        }
    }

    if (!inventoryStack.IsEmpty()) {
        InventoryStackNode* tempInventoryHead = inventoryStack.Peek();

        while (tempInventoryHead != nullptr) {
            tempInventoryHead = tempInventoryHead->next;
            inventoryStack.Pop();
        }
    }
}

Warehouse::~Warehouse() {
    EmptyStacks();
}
