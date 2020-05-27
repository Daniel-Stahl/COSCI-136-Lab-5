#include "OrderStack.hpp"

OrderStack::OrderStack() {};

bool OrderStack::IsEmpty() const {
    return head == nullptr;
}

bool OrderStack::IsFull(OrderStackNode* node) const {
    if (!node) {
        return true;
    } else {
        return false;
    }
}

void OrderStack::Push(Order newOrder) {
    OrderStackNode* newHead = new (std::nothrow) OrderStackNode;
    
    if (!IsFull(newHead)) {
        newHead->order = newOrder;
        newHead->next = head;
        head = newHead;
    } else {
        cout << "Cant add anymore orders to the stack, low on memory\n";
    }
}

void OrderStack::Pop() {
    if (!IsEmpty()) {
        OrderStackNode* topNode = head;
        head = topNode->next;
        delete topNode;
    } else {
        cout << "Stack is empty\n";
    }
};

OrderStackNode* OrderStack::Peek() {
    if (IsEmpty()) {
        return nullptr;
    } else {
        return head;
    }
};
