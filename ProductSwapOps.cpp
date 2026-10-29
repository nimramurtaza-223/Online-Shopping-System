#include "ProductSwapOps.h"
#include <utility>

void ProductSwapOps::SwapData(ProductNode* a, ProductNode* b) {
    swap(a->productID, b->productID);
    swap(a->productName, b->productName);
    swap(a->price, b->price);
}

void ProductSwapOps::Swap(CircularProductList& list, int index1, int index2) {
    if (list.IsEmpty()) return;
    index1 = list.NormalizeIndex(index1);
    index2 = list.NormalizeIndex(index2);
    if (index1 == index2) return;

    ProductNode* first = list.GetNodeAt(index1);
    ProductNode* second = list.GetNodeAt(index2);
    if (first != nullptr && second != nullptr) {
        SwapData(first, second);
    }
}