#include "ProductPrintOps.h"
#include <iostream>

using namespace std;

void ProductPrintOps::Print(const CircularProductList& list) {
    if (list.IsEmpty()) {
        cout << "No featured products in rotation.\n";
        return;
    }
    ProductNode* current = list.head->next;
    cout << "\nIndex\tID\tProduct Name\t\tPrice\n";
    cout << "---------------------------------------------------\n";
    for (int i = 0; i < list.count; i++) {
        cout << i << "\t" << current->productID << "\t" << current->productName << "\t\t$" << current->price << endl;
        current = current->next;
    }
    cout << "Total featured products: " << list.count << endl;
    cout << "---------------------------------------------------\n";
}