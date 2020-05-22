#include "Warehouse.hpp"

void Warehouse::AddOrderToStack() {
    Order newOrder;
    int numOfItems;
    
    cout << "\nHow many items ordered? ";
    cin >> numOfItems;
    
    newOrder.SetOrder(numOfItems);
    orderStack.Push(newOrder);
}

void Warehouse::AddDeliveryToStack() {
    Deliveries newDelivery;
    int itemRecieved;
    double itemCost;
    
    cout << "\nHow many items in delivery? ";
    cin >> itemRecieved;
    
    cout << "\nCost per item? ";
    cin >> itemCost;
    
    newDelivery.SetDeliveries(itemRecieved, itemCost);
    inventoryStack.Push(newDelivery);
}



void Warehouse::FillOrder() {
    if (!orderStack.IsEmpty() && !inventoryStack.IsEmpty()) {
        OrderStackNode* orderNode = orderStack.Peek();
        InventoryStackNode* deliveryNode = inventoryStack.Peek();
        InventoryStackNode* tempDeliveryNode;
        InventoryStackNode* deliveryHead = nullptr;
        int qtyMissing = orderNode->order.GetQtyNotFilled();
        int deliveryItems = deliveryNode->delivery.GetDeliveryItems();
        int orderID = orderNode->order.GetOrderID();
        int totalShipped = 0;
        double warehouseCost = 0;
        double customerCost = 0;
        
        while(!IsOrderFilled(orderNode) && !inventoryStack.IsEmpty()) {
            InventoryStackNode* tempHead = new InventoryStackNode;
            tempDeliveryNode = deliveryNode;
            
            if (qtyMissing >= deliveryItems) {
                qtyMissing = qtyMissing - deliveryItems;
                orderNode->order.SetQtyNotFilled(qtyMissing);
                inventoryStack.Pop();
            } else if (qtyMissing < deliveryItems) {
                deliveryNode->delivery.SetDeliveryItems(deliveryItems - qtyMissing);
                orderNode->order.SetQtyNotFilled(0);
                tempDeliveryNode->delivery.SetDeliveryItems(qtyMissing);
            }
            
            tempHead->delivery = tempDeliveryNode->delivery;
            tempHead->next = deliveryHead;
            deliveryHead = tempHead;
            totalShipped += tempDeliveryNode->delivery.GetDeliveryItems();
            warehouseCost += tempDeliveryNode->delivery.GetCostPerItem() * tempDeliveryNode->delivery.GetDeliveryItems();
            customerCost += ((tempDeliveryNode->delivery.GetCostPerItem() * .5) + tempDeliveryNode->delivery.GetCostPerItem()) * tempDeliveryNode->delivery.GetDeliveryItems();
            
            if (!IsOrderFilled(orderNode) && !inventoryStack.IsEmpty()) {
                deliveryNode = inventoryStack.Peek();
                deliveryItems = deliveryNode->delivery.GetDeliveryItems();
            } else if(IsOrderFilled(orderNode)) {
                cout << "Sending Order# " << orderID << " to shipping!\n";
                orderStack.Pop();
            } else {
                cout << "Inventory is out of stock/n Order is going back in stack\n";
            }
        }
        
        PrintOrderDetails(orderNode, deliveryHead, totalShipped, warehouseCost, customerCost);
    } else {
        cout << "\nOrders are empty or inventory is empty\n";
    }
}

bool Warehouse::IsOrderFilled(OrderStackNode* orderNode) const {
    if (orderNode->order.GetQtyNotFilled() == 0)
        return true;
    return false;
}

void Warehouse::PrintOrderDetails(OrderStackNode* orderNode, InventoryStackNode* deliveryHead, int totalShipped, double warehouseCost, double customerCost) {
    
    cout << "Order Number: " << orderNode->order.GetOrderID() << "\nQty to Ordered: " << orderNode->order.GetOrderItems() << "\nShipped this Shipment: " << totalShipped << "\nQty to be Shipped: " << orderNode->order.GetQtyNotFilled() << "\nTotal cost to the Warehouse: " << warehouseCost << "\nTotal cost to the Customer: " << customerCost << "\nProfit this Shipment: " << customerCost - warehouseCost << "\n";
    
    cout << "\nShipment Details:\n" << "Delivery #" << setw(15) << "Qty Shipped" << setw(15) << "Unit Price" << setw(25) << "Cost to the Warehouse" << setw(25) << setw(25) << "Cost to the Customer\n";
    
    while (deliveryHead != nullptr) {
        cout << right << setw(10) << deliveryHead->delivery.GetDeliveryID() << setw(15) << deliveryHead->delivery.GetDeliveryItems() << setw(15) << deliveryHead->delivery.GetCostPerItem() << setw(25) << deliveryHead->delivery.GetCostPerItem() * deliveryHead->delivery.GetDeliveryItems() << setw(24) << ((deliveryHead->delivery.GetCostPerItem() * .5) + deliveryHead->delivery.GetCostPerItem()) * deliveryHead->delivery.GetDeliveryItems() << "\n";
        
        deliveryHead = deliveryHead->next;
    }
    
    cout << "\n";
}

void Warehouse::PrintOrders() {
    OrderStackNode* node = orderStack.Peek();
    
    if (node != nullptr) {
        while (node != nullptr) {
            cout << "Order ID: " << node->order.GetOrderID() << "\n";
            
            node = node->next;
        }
    } else {
        cout << "No orders to print\n";
    }
}
