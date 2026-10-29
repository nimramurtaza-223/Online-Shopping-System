#include "ProductRemoveOps.h"

ProductNode* ProductRemoveOps::Remove(CircularProductList& list) {
    if (list.IsEmpty()) return nullptr;
    ProductNode* first = list.head->next;
    if (first == list.head) {
        list.head = nullptr;
    } else {
        list.head->next = first->next;
    }
    first->next = nullptr;
    list.count--;
    return first;
}

ProductNode* ProductRemoveOps::RemoveAt(CircularProductList& list, int index) {
    if (list.IsEmpty()) return nullptr;
    index = list.NormalizeIndex(index);
    if (index == 0) return Remove(list);

    ProductNode* previous = list.GetNodeAt(index - 1);
    ProductNode* target = previous->next;
    previous->next = target->next;

    if (target == list.head) {
        list.head = previous;
    }
    target->next = nullptr;
    list.count--;
    return target;
}