#include <string>
#include <iostream>
#include "Warehouse.hpp"

using namespace std;

void MainMenu();

int main() {
    MainMenu();
}

void MainMenu() {
    Warehouse warehouse;
    int userChoice;
    
    do {

        cout << "Main Menu\n 1) Create Order\n 2) Recieve Delivery\n 3) Fill Order\n 4) Print orders\n 5) Print inventory\n 6) Exit Program\n Choice: ";
        cin >> userChoice;
        
        switch (userChoice) {
            case 1:
                // Create Order
                warehouse.AddOrderToStack();
                
                break;
            case 2:
                // Recieve Delivery
                warehouse.AddDeliveryToStack();
                
                break;
            case 3:
                // Fill order
                warehouse.FillOrder();

                break;
            case 4:
                // Print orders in stack
                warehouse.PrintOrders();
                
                break;
            case 5:
                // Print inventory
                warehouse.PrintInventory();
                
                break;
        }
        
    } while (userChoice != 6);
}

/*
*****TEST_PLAN*****
 1) Testing for negative numbers or zero input.
 
 -2
 0
 -100
 AddToOrderStack() PASSED
 
 0, 1.00
 -9, -25.00
 -24, -0
 AddToInventoryStack() PASSED
 
 Errors are delt with by looping the submenu again until a correct input is inserted.

 2) Testing for positive number input
 
 10
 2
 4
 AddToOrderStack() PASSED
 
 4, 2.00
 1, 5
 11, 2.25
 AddToInventoryStack() Passed
 
 Results:
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 1

 How many items ordered? -2

 How many items ordered? 0

 How many items ordered? -100

 How many items ordered? 10
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 1

 How many items ordered? 2
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 1

 How many items ordered? 4
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 2

 How many items in delivery? 0

 Cost per item? 1.00

 How many items in delivery? -9

 Cost per item? -25

 How many items in delivery? -24

 Cost per item? -0

 How many items in delivery? 4

 Cost per item? 2.00
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 2

 How many items in delivery? 1

 Cost per item? 5
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 2

 How many items in delivery? 11

 Cost per item? 2.25
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 5
 Program ended with exit code: 0
 
 3) Testing error message when trying to print an empty OrderStack
 PrintOrders() Passed
 Error message indicates that there are no orders to print
 
 4) Testing all orders are printed correctly (Even updated QTY missing)
 PrintOrders() PASSED
 
 5) Attempting to fill order when both stacks are empty (OrderStack/InventoryStack)
 FillOrder() PASSED
 Error message indicates that both stacks are empty
 
 6) Attempting to fill order when OrderStack has x > 0 amount of orders and InventoryStack is empty
 FillOrder() PASSED
 Error message indicates that there is no invnetory to fill the order
 
 7) Attempting to fill order when InventoryStack has x > 0 amount of deliveries and OrderStack is empty
 FillOrder() PASSED
 Error message idicates that there are no orders to fill
 
 8) Attempting to fill order when Delvivery QTY is < than Order QTY and each stack has only one node
 FillOrder() PASSED
 Order goes back on top of stack with QTY remaining updated
 Delivery pops off stack
 
 9) Attempting to fill order when Delvivery QTY is > than Order QTY and each stack has only one node
 FillOrder() PASSED
 Delivery goes back on top of stack with QTY updated
 Order pops off stack
 
 10) Attempting to fill order with Order QTY remaining updated and InventoryStack has one node with a Delivery QTY equal to Order QTY remaining
 FillOrder() PASSED
 Order pops off stack
 Delivery pops off stack
 
 11) Attempting to fill a new order over the order that went back on the stack (InventoryStack has plenty of inventory now)
 FillOrder() PASSED
 New Order is filled and pops off stack
 2 Deliveries are pop off stack
 
 12) Attempting to fill old order that was partially filled (Inventory has plenty of inventory now)
 FillOrder() PASSED
 Old Order is filled and pops off stack
 1 Delivery pops off stack
 
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 4

 No orders to print

 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 1

 How many items ordered? 10
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 4
 Order#      Amount Ordered      Qty Remaining
      1                  10                 10
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 3

 Orders are empty or inventory is empty
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 2

 How many items in delivery? 3

 Cost per item? 2.99
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 2

 How many items in delivery? 2

 Cost per item? 3.50
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 3
 Inventory is out of stock/n Order is going back in stack
 Order Number: 1
 Qty to Ordered: 10
 Shipped this Shipment: 5
 Qty to be Shipped: 5
 Total cost to the Warehouse: 15.97
 Total cost to the Customer: 23.96
 Profit this Shipment: 7.99

 Shipment Details:
 Delivery #    Qty Shipped     Unit Price    Cost to the Warehouse    Cost to the Customer
          1              3           2.99                     8.97                   13.46
          2              2           3.50                     7.00                   10.50

 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 4
 Order#      Amount Ordered      Qty Remaining
      1                  10                  5
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 1

 How many items ordered? 2
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 3

 Orders are empty or inventory is empty
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 4
 Order#      Amount Ordered      Qty Remaining
      2                   2                  2
      1                  10                  5
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 2

 How many items in delivery? 4

 Cost per item? 2
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 2

 How many items in delivery? 3

 Cost per item? 1.25
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 3
 Sending Order# 2 to shipping!
 Order Number: 2
 Qty to Ordered: 2
 Shipped this Shipment: 2
 Qty to be Shipped: 0
 Total cost to the Warehouse: 2.50
 Total cost to the Customer: 3.75
 Profit this Shipment: 1.25

 Shipment Details:
 Delivery #    Qty Shipped     Unit Price    Cost to the Warehouse    Cost to the Customer
          4              2           1.25                     2.50                    3.75

 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 4
 Order#      Amount Ordered      Qty Remaining
      1                  10                  5
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 3
 Sending Order# 1 to shipping!
 Order Number: 1
 Qty to Ordered: 10
 Shipped this Shipment: 5
 Qty to be Shipped: 0
 Total cost to the Warehouse: 8.50
 Total cost to the Customer: 12.75
 Profit this Shipment: 4.25

 Shipment Details:
 Delivery #    Qty Shipped     Unit Price    Cost to the Warehouse    Cost to the Customer
          3              3           2.00                     6.00                    9.00
          4              2           1.25                     2.50                    3.75

 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 4

 No orders to print

 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Fill Order
  4) Print orders
  5) Exit Program
  Choice: 5
 Program ended with exit code: 0
 
*/
