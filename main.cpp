#include <iostream>
#include "CircularProductList.h"
#include "ProductInsertOps.h"
#include "ProductRemoveOps.h"
#include "ProductSwapOps.h"
#include "ProductSortReverseOps.h"
#include "ProductPrintOps.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main() {
    CircularProductList flashSale;
    Stack cartStack;
    Queue orderQueue;

    ProductInsertOps::InsertAt(flashSale, ProductInsertOps::CreateProduct(202, "Mechanical Keyboard", 75.00), 0);
    ProductInsertOps::InsertAt(flashSale, ProductInsertOps::CreateProduct(201, "Wireless Mouse", 25.50), 1);
    ProductInsertOps::InsertAt(flashSale, ProductInsertOps::CreateProduct(203, "Gaming Headset", 45.99), 2);

    cout << "=== INITIAL ONLINE SHOPPING FLASH SALE ROTATION ===";
    ProductPrintOps::Print(flashSale);

    ProductSortReverseOps::Sort(flashSale);
    cout << "\n=== AFTER SORTING PRODUCTS BY ID ===";
    ProductPrintOps::Print(flashSale);

    ProductSortReverseOps::Reverse(flashSale);
    cout << "\n=== AFTER REVERSING COLLECTION ===";
    ProductPrintOps::Print(flashSale);

    return 0;
}