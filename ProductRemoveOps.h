#ifndef PRODUCT_REMOVE_OPS_H
#define PRODUCT_REMOVE_OPS_H

#include "CircularProductList.h"

class ProductRemoveOps {
public:
    static ProductNode* Remove(CircularProductList& list);
    static ProductNode* RemoveAt(CircularProductList& list, int index);
};

#endif