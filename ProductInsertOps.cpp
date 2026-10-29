#include "ProductInsertOps.h"

ProductNode* ProductInsertOps::CreateProduct(int id, string name, double price) {
    ProductNode* prod = new ProductNode;
    prod->productID = id;
    prod->productName = name;
    prod->price = price;
    prod->next = nullptr;
    return prod;
}

void ProductInsertOps::Insert(CircularProductList& list, ProductNode* product) {
    if (product == nullptr) return;
    if (list.head == nullptr) {
        list.head = product;
        product->next = product;
    } else {
        product->next = list.head->next;
        list.head->next = product;
    }
    list.count++;
}

void ProductInsertOps::InsertAt(CircularProductList& list, ProductNode* product, int index) {
    if (product == nullptr) return;
    if (list.count == 0) {
        list.head = product;
        product->next = product;
        list.count++;
        return;
    }

    if (index < 0) index = list.NormalizeIndex(index);
    if (index > list.count) index = list.count;

    if (index == 0) {
        Insert(list, product);
        return;
    }

    if (index == list.count) {
        product->next = list.head->next;
        list.head->next = product;
        list.head = product;
        list.count++;
        return;
    }

    ProductNode* previous = list.GetNodeAt(index - 1);
    product->next = previous->next;
    previous->next = product;
    list.count++;
}