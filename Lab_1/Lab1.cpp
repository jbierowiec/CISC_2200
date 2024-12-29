#include <iostream>
#include <string>
#include "ItemType.h"
#include "UnsortedListByArray.h"

using namespace std;

void PrintList(UnsortedListByArray &list)
// Pre:  list has been initialized.
// Post: Each component in list has been written.
//
{
  int length;
  ItemType item;
  list.ResetList();
  length = list.GetLength();
  for (int counter = 1; counter <= length; counter++)
  {
    list.GetNextItem(item);
    item.Print();
  }
}

int main()
{
  // initialization of variables
  ItemType x;
  int tempLength = 0;
  UnsortedListByArray list;
  UnsortedListByArray listOne, listTwo;
  string items;

  ItemType val1;
  val1.Initialize("This");
  listOne.InsertItem(val1);

  ItemType val2;
  val2.Initialize("is");
  listOne.InsertItem(val2);

  ItemType val3;
  val3.Initialize("a");
  listOne.InsertItem(val3);

  ItemType val4;
  val4.Initialize("is");
  listOne.InsertItem(val4);

  ItemType val5;
  val5.Initialize("is");
  listOne.InsertItem(val5);

  ItemType val6;
  val6.Initialize("Hat");
  listOne.InsertItem(val6);

  ItemType val7;
  val7.Initialize("OK");
  listOne.InsertItem(val6);

  ItemType test;
  test.Initialize("J");

  // asks the user to enter a list of strings
  cout << "Please type a sequence of strings with a word repeated at least three" << endl
       << "times, please use white space as the delimiter: (Enter -1 to quit): ";

  // The most amount of items in the list has been limited to 10
  // The only exception is when it is not constant
  while (items != "-1")
  {
    cin >> items;
    if (items != "-1")
    {
      x.Initialize(items);
      list.InsertItem(x);
      tempLength++;
    }
  }

  // outputs for list inputted
  cout << "You typed: " << endl;
  PrintList(list);

  // old insert item function is called
  list.InsertItem(val5);
  cout << endl;
  cout << "Call the old insert item function: " << endl;
  cout << endl;
  cout << "The list created: " << endl;

  PrintList(list);
  cout << endl;

  cout << "Call the old DeleteItem function: " << endl;
  cout << "After delete the repeated word" << endl;

  // old delete item function is called
  list.DeleteItem(val5);
  PrintList(list);
  cout << endl;
  cout << "Call the new DeleteAllItems function: " << endl;
  cout << "After delete all repeated words" << endl;

  // delete all items function is called
  list.DeleteAllItems(val4);
  PrintList(list);
  cout << endl;
  cout << "Call the new insert item function to insert all new items into a new list" << endl;
  cout << "again: " << endl;
  cout << "The list created: " << endl;

  // new insert item is called
  list.NewInsertItem(val2);
  PrintList(list);
  cout << endl;
  cout << "The long list is" << endl;

  // delete item function and inserting two new items into the list
  list.DeleteItem(val2);
  list.NewInsertItem(val6);
  list.NewInsertItem(val7);

  PrintList(list);
  cout << endl;

  cout << "Split with J" << endl;
  cout << "After split with item :J" << endl;

  listOne.MakeEmpty();

  // split list function called
  list.SplitList(test, listOne, listTwo);

  // prints the split list for listOne
  cout << "list one is : " << endl;
  PrintList(listOne);

  cout << endl;

  // prints the split list for listTwo
  cout << "list two is : " << endl;
  PrintList(listTwo);

  cout << endl;
  cout << "After split, original list is : " << endl;

  // prints the list
  PrintList(list);

  return 0;
}