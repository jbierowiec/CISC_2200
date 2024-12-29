#include "UnsortedListByArray.h"

UnsortedListByArray::UnsortedListByArray()
{
  length = 0;
}

// returns if the array is full
bool UnsortedListByArray::IsFull() const
{
  return (length == MAX_ITEM);
}
// returns to check the current length of the array
int UnsortedListByArray::GetLength() const
{
  return length;
}

// sets the length to zero if the array is empty again
bool UnsortedListByArray::IsEmpty() const
{
  return (length == 0);
}

void UnsortedListByArray::InsertItem(ItemType item)
// Post: item is in the list.
{
  info[length] = item;
  length++;
}

/*
bool UnsortedListByArray::InsertItem(ItemType item)
{
    //Checks if list is full
    if(IsFull()) {
        return false;
    }

    //loops through the list to check for duplicates
    for(int i = 0; i < length; i++)
    {
        if (info[i].ComparedTo(item) == EQUAL)
            return false;
    }
    //Puts the inputed item and extends the length by 1
    info[length] = item;
    length++;
    return true;
}
*/

// this new insert item function will be called when a new item is inserted into the list
bool UnsortedListByArray::NewInsertItem(ItemType newItem)
{
  if (IsFull())
  {
    return false;
  }
  for (int i = 0; i < length; i++)
  {
    if (info[i].ComparedTo(newItem) == EQUAL)
    {
      return false;
    }
  }
  info[length] = newItem;
  length++;
  return true;
}

// this function will be called to delete all items that appear more than once in the sequence
void UnsortedListByArray::DeleteAllItems(ItemType item)
{
  int originalLength = length;
  for (int i = 0; i < originalLength; i++)
  {
    if (info[i].ComparedTo(item) == EQUAL)
    {
      DeleteItem(item);
    }
  }
}

// this will be called when the function calls to split the list into two separate lists
void UnsortedListByArray::SplitList(ItemType item, UnsortedListByArray &listOne, UnsortedListByArray &listTwo)
{
  for (int i = 0; i < length; i++)
  {
    // First checks any items that are compared to see which one is Less
    // If the item(s) are less it will be put into listOne
    if (info[i].ComparedTo(item) == LESS)
    {
      listOne.NewInsertItem(info[i]);
    }
    // Any item not put in listOne will automatically be put in listTwo
    else
    {
      listTwo.NewInsertItem(info[i]);
    }
  }
  return;
}

void UnsortedListByArray::RetrieveItem(ItemType &item, bool &found)
// Pre Condition: The key member items are initialized.
// Post Condition: If the items are found and the key matches with key in the list and a copy of that element has been stored in item;
// If none are met the item is unchanged
{
  bool moreToSearch;
  int location = 0;
  found = false;
  moreToSearch = (location < length);
  while (moreToSearch && !found)
  {
    switch (item.ComparedTo(info[location]))
    {
    case LESS:
    case GREATER:
      location++;
      moreToSearch = (location < length);
      break;
    case EQUAL:
      found = true;
      item = info[location];
      break;
    }
  }
}

void UnsortedListByArray::DeleteItem(ItemType item)
// Pre Condition: The item's key has been inititalized. In addition only one element in the list has a key that matches item.
// Post Condition: Nothing left in the list contains the key of the item
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL)
    location++;
  // moves the element into position where the original item was located

  info[location] = info[length - 1];
  length--; // decreases the length of the list to avoid data leaks
}

void UnsortedListByArray::MakeEmpty()
// Pre Condition :  N/A
// Post Condition: The list is empty
{
  length = 0;
}

void UnsortedListByArray::ResetList()
// Pre Condition: The list has been successfully inititalized.
// Post condition: Current item position is prior to first element.
{
  currentPos = -1;
}

void UnsortedListByArray::GetNextItem(ItemType &item)
// Pre Condition: The list has been initialized and current position of the item is defined.
//  Element at current position is not last in list.
// Post Condition: Current position is updated to next position. Item is a copy of the element at current position.
{
  currentPos++;
  item = info[currentPos];
}
