
#pragma once
#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <string>
#include <iostream>
using namespace std;

const int  MAX_ITEM = 5;
enum  RelationType { LESS, EQUAL, GREATER };

class  ItemType {
public:
    ItemType() {}

    RelationType ComparedTo(ItemType  otherItem) const {
        if (value < otherItem.value)
            return LESS;
        else if (value > otherItem.value)
            return GREATER;
        else
            return EQUAL;
    }

    void Print() const {
        cout << value << " ";
    }

    void Initialize(int value) {
        this->value = value;
    }

    int getVal() const {
        return value;
    }

private:
    int value;
};
#endif
