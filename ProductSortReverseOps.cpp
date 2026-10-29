#include "ProductSortReverseOps.h"
#include "ProductSwapOps.h"

void ProductSortReverseOps::Sort(CircularProductList& list) {
    if (list.count < 2) return;
    ProductNode* current = list.head->next;
    for (int i = 0; i < list.count - 1; i++) {
        ProductNode* nextNode = current->next;
        for (int j = i + 1; j < list.count; j++) {
            if (current->productID > nextNode->productID) {
                ProductSwapOps::SwapData(current, nextNode);
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    }
}

void ProductSortReverseOps::Reverse(CircularProductList& list) {
    if (list.count < 2) return;
    ProductNode* oldTail = list.head;
    ProductNode* oldFirst = list.head->next;
    ProductNode* previous = oldTail;
    ProductNode* current = oldFirst;

    while (current != oldTail) {
        ProductNode* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    oldTail->next = previous;
    list.head = oldFirst;
}