#include "SortedListByArray.h"

SortedListByArray::SortedListByArray()
{
  length = 0;
}

bool SortedListByArray::IsFull() const
{
  return (length == MAX_ITEM);
}

int SortedListByArray::GetLength() const
{
  return length;
}

bool SortedListByArray::IsEmpty() const
{
  return (length == 0);
}

void SortedListByArray::InsertItem(ItemType item)
{
  bool moreToSearch;
  int location = 0;
  moreToSearch = (location < length);
  while (moreToSearch)
  {
    switch (item.ComparedTo(info[location]))
    {
    case LESS:
      moreToSearch = false;
      break;
    case GREATER:
      location++;
      moreToSearch = (location < length);
      break;
    }
  }

  for (int index = length; index > location; index--)
    info[index] = info[index - 1];

  info[location] = item;
  length++;
}

void SortedListByArray::RetrieveItem(ItemType &item, bool &found)
// Pre condition:  Key member(s) of item is initialized.
// Post condition: If found, item's key matches an element's key in the
// list and a copy of that element has been stored in item;  otherwise, item is unchanged.
{
  int midPoint;
  int first = 0;
  int last = length - 1;

  bool moreToSearch = (first <= last);
  found = false;
  while (moreToSearch && !found)
  {
    midPoint = (first + last) / 2;
    switch (item.ComparedTo(info[midPoint]))
    {
    case LESS:
      last = midPoint - 1;
      moreToSearch = (first <= last);
      break;
    case GREATER:
      first = midPoint + 1;
      moreToSearch = (first <= last);
      break;
    case EQUAL:
      found = true;
      item = info[midPoint];
      break;
    }
  }
}

void SortedListByArray::DeleteItem(ItemType item)
// Pre Condition: item’s key has been inititalized.
// One and only one element in the list has a key that matches item’s.
// Post Condition: No element in the list has a key that matches item’s.
{
  int location = 0;
  while (item.ComparedTo(info[location]) != EQUAL)
    location++;

  for (int index = location + 1; index < length; index++)
    info[index - 1] = info[index];

  length--;
}

void SortedListByArray::MakeEmpty()
// Pre Condition:  N/A
// Post Condition: the list is empty
{
  length = 0;
}

void SortedListByArray::ResetList()
// Pre Condition:  List has been inititalized.
// Post Condition: Current position is prior to first element.
{
  currentPos = -1;
}

void SortedListByArray::GetNextItem(ItemType &item)
// Pre Condition:  List has been initialized. Current position is
//       defined.
//       Element at current position is not last in list.
// Post Condition: Current position is updated to next position.
// 	  item is a copy of element at current position.
{
  currentPos++;
  item = info[currentPos];
}

void SortedListByArray::MergeList(UnsortedListByArray &listOne, UnsortedListByArray &listTwo)

{

  listOne.ResetList();
  listTwo.ResetList();

  ItemType temp;
  listOne.GetNextItem(temp);
  info[0] = temp;
  length++;
  int index;
  for (int i = 1; i < listOne.GetLength(); i++)
  {
    listOne.GetNextItem(temp);
    bool moreToSearch;
    bool found = false;
    int first = 0, last = length - 1;
    int midpoint = (first + last) / 2;

    moreToSearch = (first <= last);
    while (moreToSearch && !found)
    {
      midpoint = (first + last) / 2;
      switch (temp.ComparedTo(info[midpoint]))
      {
      case LESS:
        last = midpoint - 1;
        break;
      case GREATER:
        first = midpoint + 1;
        break;
      case EQUAL:
        found = true;
        break;
      }
      moreToSearch = (first <= last);
    }
    if (!found)
    {
      index = last + 1;
      for (int j = length; j > index; j--)
      {
        info[j] = info[j - 1];
      }
      info[index] = temp;
      length++;
    }
  }
  for (int i = 0; i < listTwo.GetLength(); i++)
  {
    listTwo.GetNextItem(temp);
    bool moreToSearch;
    bool found = false;
    int first = 0, last = length - 1;
    int midpoint = (first + last) / 2;
    moreToSearch = (first <= last);
    while (moreToSearch && !found)
    {
      midpoint = (first + last) / 2;
      switch (temp.ComparedTo(info[midpoint]))
      {
      case LESS:
        last = midpoint - 1;
        break;
      case GREATER:
        first = midpoint + 1;
        break;
      case EQUAL:
        found = true;
        index = midpoint;
        break;
      }
      moreToSearch = (first <= last);
    }

    if (!found)
    {

      index = last + 1;
      for (int j = length; j > index; j--)
      {
        info[j] = info[j - 1];
      }
      info[index] = temp;
      length++;
    }
  }
  cout << "The length of the two lists merged together is: " << length << endl;
}
