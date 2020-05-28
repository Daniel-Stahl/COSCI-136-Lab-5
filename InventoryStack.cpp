#include "InventoryStack.hpp"

InventoryStack::InventoryStack() {};

bool InventoryStack::IsEmpty() const {
    return head == nullptr;
};

bool InventoryStack::IsFull(InventoryStackNode* node) const {
    if (!node) {
        return true;
    } else {
        return false;
    }
};

void InventoryStack::Push(Deliveries newDelivery) {
    InventoryStackNode* newHead = new (std::nothrow) InventoryStackNode;
    if (!IsFull(newHead)) {
        newHead->delivery = newDelivery;
        newHead->next = head;
        head = newHead;
    } else {
        cout << "Cant add anymore to the inventory, low on memory\n";
        delete newHead;
    }
};

void InventoryStack::Pop() {
    if (!IsEmpty()) {
        InventoryStackNode* topNode = head;
        head = topNode->next;
        delete topNode;
    } else {
       cout << "Inventory is empty\n";
    }
};

InventoryStackNode* InventoryStack::Peek() {
    if (IsEmpty()) {
        return nullptr;
    } else {
        return head;
    }
};
