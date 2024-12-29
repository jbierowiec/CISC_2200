#include "ItemType.h"
#include "SortedListByArray.h"
// #include "SortedType.h"

void PrintList(SortedListByArray &list)
{
    // Pre condition: The list has been initialized.
    // Post condition : Each component in list has been written.
    //
    int size;
    ItemType item;

    list.ResetList();
    size = list.GetLength();

    // CHANGING THE COUNTER TO 0 WILL OUTPUT THE 0 BUT AT THE END NOT FIRST

    // CHANGING THE SIZE TO SIZE + 1 WILL OUTPUT THE 0 BUT AT THE END NOT FIRST

    for (int counter = 1; counter <= size; counter++)
    {
        list.GetNextItem(item);
        item.Print();
    }
}

int main()
{
    // calls for the respective lists

    UnsortedListByArray list1;
    UnsortedListByArray list2;

    // intializes each int value for list1
    ItemType a;
    a.Initialize(1);
    list1.InsertItem(a);

    ItemType b;
    b.Initialize(0);
    list1.InsertItem(b);

    ItemType g;
    g.Initialize(10);
    list1.InsertItem(g);

    ItemType f;
    f.Initialize(3);
    list1.InsertItem(f);

    // Intializes each int value for list2
    ItemType c;
    c.Initialize(12);
    list2.InsertItem(c);

    ItemType d;
    d.Initialize(2);
    list2.InsertItem(d);
    ItemType i;

    i.Initialize(5);
    list2.InsertItem(i);

    // calls upon SortedListByArray and organizes them into a sorted array
    SortedListByArray Test;
    Test.MergeList(list1, list2);
    cout << "After merging the two lists we got the sorted list L: " << endl;
    PrintList(Test);

    return 0;
}
