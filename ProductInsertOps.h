#ifndef PRODUCT_INSERT_OPS_H
#define PRODUCT_INSERT_OPS_H

#include "CircularProductList.h"

class ProductInsertOps {
public:
    static ProductNode* CreateProduct(int id, string name, double price);
    static void Insert(CircularProductList& list, ProductNode* product);
    static void InsertAt(CircularProductList& list, ProductNode* product, int index);
};

#endif