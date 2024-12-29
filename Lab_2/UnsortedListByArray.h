#ifndef UNSORTEDLISTBYARRAY_H
#define UNSORTEDLISTBYARRAY_H

#include "ItemType.h"

class UnsortedListByArray
// declares a class data type
{
public:
  UnsortedListByArray();

  void MakeEmpty(); // 8 public member functions
  void InsertItem(ItemType item);
  void DeleteItem(ItemType item);

  bool IsFull() const;
  bool IsEmpty() const;
  int GetLength() const; // returns length of list
  void RetrieveItem(ItemType &item, bool &found);

  void ResetList();
  void GetNextItem(ItemType &item);

  void SplitList(ItemType item, UnsortedListByArray &listOne, UnsortedListByArray &listTwo);
  bool NewInsertItem(ItemType newItem);
  void DeleteAllItems(ItemType item);

protected:
  int length;
  ItemType info[MAX_ITEM];
  int currentPos = -1;
};

#endif
