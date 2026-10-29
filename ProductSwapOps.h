#ifndef PRODUCT_SWAP_OPS_H
#define PRODUCT_SWAP_OPS_H

#include "CircularProductList.h"

class ProductSwapOps {
public:
    static void SwapData(ProductNode* a, ProductNode* b);
    static void Swap(CircularProductList& list, int index1, int index2);
};

#endif