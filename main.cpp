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

        cout << "Main Menu\n 1) Create Order\n 2) Recieve Delivery\n 3) Print orders & inventory\n 4) Exit Program\n Choice: ";
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
                // Print orders and inventory
                warehouse.PrintOrders();
                warehouse.PrintInventory();
                
                break;
        }
        
    } while (userChoice != 4);
}

/*
*****TEST_PLAN*****
 
 Order input -3 = Error
 Order input 0 = Error
 Order input -100 = Error
 
 Order input 5 = Order ID#: 1, QTY: 5
 Delivery input -0 = Error
 Delivery input 0 = Error
 Delivery input -43 = Error
 Delivery input 3 = Good!
 Delivery Cost -1 = Error
 Delivery cost -43 = Error
 Delivery cost 2 = Good!
 Delivery ID#: 1, QTY: 3, Cost: 2
 
 Order Filled Result:
 Order#: 1, QTY: 5 Shipped: 3, Remaining: 2
 Delivery# 1 popped
 
 Print orders and inventory:
 Order#1 QTY: 5, Remaining: 2
 Inventory empty
 
 Adding an order
 Order input 2 = Order ID#: 2, QTY: 2
 
 Print orders and inventory:
 Order#: 2 QTY: 2, Remaining: 2 (Top of stack)
 Order#: 1 QTY: 5, Remaining: 2
 
 Adding Delivery
 Delivery input 5, 3 = Delivery ID#: 2 QTY: 5
 
 Order Filled Result:
 Order#: 2, QTY: 2, Shipped: 2, Remaining: 0
 Delivery#: 2, QTY Shipped: 2
 Order# 2 popped
 
 Order#: 1, QTY: 5, Shipped: 2, Remaining: 0
 Delivery#: 2, QTY Shipped: 2
 Order# 1 popped
 
 Print orders and inventory:
 Orders Empty
 Delivery#2 QTY: 1, cost: 3
 
 *****OUTPUT*****
 
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Print orders & inventory
  4) Exit Program
  Choice: 1

 How many items ordered? -3

 Error: Orders must have items higher than 0, please try again.

 How many items ordered? 0

 Error: Orders must have items higher than 0, please try again.

 How many items ordered? -100

 Error: Orders must have items higher than 0, please try again.

 How many items ordered? 5

 Orders are empty or inventory is empty
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Print orders & inventory
  4) Exit Program
  Choice: 2

 How many items in delivery? -0

 Error: Items recieved must be higher than 0, please try again.

 How many items in delivery? 0

 Error: Items recieved must be higher than 0, please try again.

 How many items in delivery? -43

 Error: Items recieved must be higher than 0, please try again.

 How many items in delivery? 3

 Cost per item? -1

 Error: Item cost must be higher than 0, please try again.

 Cost per item? -43

 Error: Item cost must be higher than 0, please try again.

 Cost per item? 2

 How many items in delivery? 3

 Cost per item? 2
 Order Number: 1
 Qty to Ordered: 5
 Shipped this Shipment: 3
 Qty to be Shipped: 2
 Total cost to the Warehouse: 6.00
 Total cost to the Customer: 9.00
 Profit this Shipment: 3.00

 Shipment Details:
 Delivery #    Qty Shipped     Unit Price    Cost to the Warehouse    Cost to the Customer
          1              3           2.00                     6.00                    9.00

 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Print orders & inventory
  4) Exit Program
  Choice: 3

 Order#      Amount Ordered      Qty Remaining
      1                   5                  2


 No inventory to print

 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Print orders & inventory
  4) Exit Program
  Choice: 1

 How many items ordered? 2

 Orders are empty or inventory is empty
 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Print orders & inventory
  4) Exit Program
  Choice: 3

 Order#      Amount Ordered      Qty Remaining
      2                   2                  2
      1                   5                  2

 No inventory to print

 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Print orders & inventory
  4) Exit Program
  Choice: 2

 How many items in delivery? 5

 Cost per item? 3
 Sending Order# 2 to shipping!
 Order Number: 2
 Qty to Ordered: 2
 Shipped this Shipment: 2
 Qty to be Shipped: 0
 Total cost to the Warehouse: 6.00
 Total cost to the Customer: 9.00
 Profit this Shipment: 3.00

 Shipment Details:
 Delivery #    Qty Shipped     Unit Price    Cost to the Warehouse    Cost to the Customer
          2              2           3.00                     6.00                    9.00

 Sending Order# 1 to shipping!
 Order Number: 1
 Qty to Ordered: 5
 Shipped this Shipment: 2
 Qty to be Shipped: 0
 Total cost to the Warehouse: 6.00
 Total cost to the Customer: 9.00
 Profit this Shipment: 3.00

 Shipment Details:
 Delivery #    Qty Shipped     Unit Price    Cost to the Warehouse    Cost to the Customer
          2              2           3.00                     6.00                    9.00

 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Print orders & inventory
  4) Exit Program
  Choice: 3

 No orders to print


 Delivery#                 QTY               Cost
         2                   1                3.00

 Main Menu
  1) Create Order
  2) Recieve Delivery
  3) Print orders & inventory
  4) Exit Program
  Choice: 4
 Program ended with exit code: 0
 
 
 
*/
