#include "CircularProductList.h"
#include "ProductInsertOps.h"
#include "ProductRemoveOps.h"

CircularProductList::CircularProductList() {
    head = nullptr;
    count = 0;
}

CircularProductList::CircularProductList(const CircularProductList& other) {
    head = nullptr;
    count = 0;
    if (other.head == nullptr) return;

    ProductNode* current = other.head->next;
    for (int i = 0; i < other.count; i++) {
        ProductNode* copy = ProductInsertOps::CreateProduct(current->productID, current->productName, current->price);
        ProductInsertOps::InsertAt(*this, copy, count);
        current = current->next;
    }
}

CircularProductList& CircularProductList::operator=(const CircularProductList& other) {
    if (this == &other) return *this;

    while (IsNotEmpty()) {
        ProductNode* removed = ProductRemoveOps::Remove(*this);
        delete removed;
    }

    if (other.head == nullptr) return *this;

    ProductNode* current = other.head->next;
    for (int i = 0; i < other.count; i++) {
        ProductNode* copy = ProductInsertOps::CreateProduct(current->productID, current->productName, current->price);
        ProductInsertOps::InsertAt(*this, copy, count);
        current = current->next;
    }
    return *this;
}

CircularProductList::~CircularProductList() {
    while (IsNotEmpty()) {
        ProductNode* removed = ProductRemoveOps::Remove(*this);
        delete removed;
    }
}

bool CircularProductList::IsEmpty() const {
    return count == 0;
}

bool CircularProductList::IsNotEmpty() const {
    return count > 0;
}

int CircularProductList::GetCount() const {
    return count;
}

int CircularProductList::NormalizeIndex(int index) {
    if (count == 0) return 0;
    return ((index % count) + count) % count;
}

ProductNode* CircularProductList::GetNodeAt(int index) {
    if (head == nullptr) return nullptr;
    ProductNode* current = head->next;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}