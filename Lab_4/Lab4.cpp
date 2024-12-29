#include <iostream>
#include "ItemType.h"
#include "TreeType.h"

using namespace std;
void printingOrders(TreeType& Tree,OrderType order) 
{
	ItemType input;
	bool finished = false;
	for (int i = 0; i < Tree.GetLength(); i++)
	{
		Tree.GetNextItem(input, order, finished);
		input.Print();
	}
}

int main()
{
	ItemType First;
	First.Initialize('F');
	ItemType Second;
	Second.Initialize('N');
	ItemType Third;
	Third.Initialize('R');
	ItemType Fourth;
	Fourth.Initialize('D');
	ItemType Fifth;
	Fifth.Initialize('G');
	ItemType Sixth;
	Sixth.Initialize('C');

	TreeType Tree;
	TreeType swapTree;

	Tree.InsertItem(First);
	cout << "The first item 'F' is inserted" << endl;
	cout << "After inserting the first item in the tree, the tree looks like: " << endl;
	Tree.Print();
	cout << "Inserting Node: N" << endl;
	Tree.InsertItem(Second);
	cout << "Inserting Node: R" << endl;
	Tree.InsertItem(Third);
	cout << "Inserting Node: D" << endl;
	Tree.InsertItem(Fourth);
	cout << "Inserting Node: G" << endl;
	Tree.InsertItem(Fifth);
	cout << "Inserting Node: C" << endl;
	Tree.InsertItem(Sixth);
	cout << "After inserting five items into the tree: " << endl;
	Tree.Print();
	cout << "The tree has " << Tree.GetLength() << " elements." << endl;
	
	cout << "Showing the tree(post-order): "<<endl;
	Tree.ResetTree(POST_ORDER);
	printingOrders(Tree, POST_ORDER);

	cout << endl << "Showing the tree (pre-order): " << endl;
	Tree.ResetTree(PRE_ORDER);
	printingOrders(Tree, PRE_ORDER);
	Tree.ResetTree(IN_ORDER);
	
	cout << endl << "Test Ancestors for C" << endl;
	Tree.Ancestors(Sixth);

	cout << endl<<"Test Swap: " << endl;
	Tree.Swap(swapTree);
	cout << "The swapped tree in-order:" << endl;
	swapTree.Print();

	cout << "Test LeafCount: " << endl;
	cout << "There are " << Tree.LeafCount() << " leaf nodes." << endl;

	cout << "Testing delete, please delete 'F'" << endl;
	Tree.DeleteItem(First);
	cout << "After deleting 'F' from the tree, the tree has " << Tree.GetLength() << " elements." << endl;
	Tree.Print();

	cout << endl << "Showing the tree (pre-order):" << endl;
	Tree.ResetTree(PRE_ORDER);
	printingOrders(Tree, PRE_ORDER);
	Tree.ResetTree(IN_ORDER);

	cout << endl << "After emptying the tree: " << endl;
	Tree.MakeEmpty();
	Tree.Print();

	return 0;
}