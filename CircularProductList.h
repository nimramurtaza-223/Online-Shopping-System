#ifndef CIRCULAR_PRODUCT_LIST_H
#define CIRCULAR_PRODUCT_LIST_H

#include <string>
using namespace std;

struct ProductNode {
    int productID;
    string productName;
    double price;
    ProductNode* next;
};

class CircularProductList {
private:
    ProductNode* head;
    int count;

public:
    CircularProductList();
    CircularProductList(const CircularProductList& other);
    CircularProductList& operator=(const CircularProductList& other);
    ~CircularProductList();

    bool IsEmpty() const;
    bool IsNotEmpty() const;
    int GetCount() const;
    int NormalizeIndex(int index);
    ProductNode* GetNodeAt(int index);

    friend class ProductInsertOps;
    friend class ProductRemoveOps;
    friend class ProductSwapOps;
    friend class ProductSortReverseOps;
    friend class ProductPrintOps;
};

#endif