#include "TreeType.h"
#include <new>

TreeType::TreeType()
{
    root = NULL;
    preQue = NULL;
    postQue = NULL;
    inQue = NULL;
}

TreeType::TreeType(const TreeType& originalTree)
{
    CopyTree(root, originalTree.root);
}

void TreeType::operator=(const TreeType& originalTree)
{
    if (&originalTree == this)
        return;

    Destroy(root);
    CopyTree(root, originalTree.root);
}

void TreeType::CopyTree(TreeNode*& copy, const TreeNode* originalTree)
{

    if (originalTree == NULL)
        copy = NULL;
    else
    {
        copy = new TreeNode;
        copy->info = originalTree->info;
        CopyTree(copy->left, originalTree->left);
        CopyTree(copy->right, originalTree->right);
    }
}

TreeType::~TreeType()
{
    MakeEmpty();

    if (preQue != NULL)  delete preQue;
    if (postQue != NULL) delete postQue;
    if (inQue != NULL) delete inQue;
}

void TreeType::Destroy(TreeNode*& tree)
{
    if (tree != NULL)
    {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}

void TreeType::MakeEmpty()
{
    Destroy(root);
    root = NULL;
}

bool TreeType::IsFull() const
{

    TreeNode* location;
    try {
        location = new TreeNode;
        delete location;
        return false;
    }
    catch (std::bad_alloc e) {
        return true;
    }
}

bool TreeType::IsEmpty() const
{
    return root == NULL;

}

int TreeType::GetLength() const
{
    return Count(root);
}

int TreeType::Count(TreeNode* tree) const
{
    if (tree == NULL)
        return 0;
    else
        return Count(tree->left) + Count(tree->right) + 1;
}

void TreeType::RetrieveItem(ItemType& item, bool& found) const
{
    Retrieve(root, item, found);
}

void TreeType::Retrieve(TreeNode* tree, ItemType& item, bool& found) const
{
    if (tree == NULL)   found = false;

    else if (item.ComparedTo(tree->info) == LESS)
        Retrieve(tree->left, item, found);
    else if (item.ComparedTo(tree->info) == GREATER)
        Retrieve(tree->right, item, found);
    else
    {
        item = tree->info;
        found = true;
    }
}

void TreeType::InsertItem(ItemType item)
{
    Insert(root, item);
}

void TreeType::Insert(TreeNode*& tree, ItemType item)
{
    if (tree == NULL)
    { // Insertion place found.
        tree = new TreeNode;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else if (item.ComparedTo(tree->info) == LESS)
        Insert(tree->left, item);
    else
        Insert(tree->right, item);
}

void TreeType::DeleteItem(ItemType item)
{
    Delete(root, item);
}

void TreeType::Delete(TreeNode*& tree, ItemType item)
{
    if (item.ComparedTo(tree->info) == LESS)
        Delete(tree->left, item);
    else if (item.ComparedTo(tree->info) == GREATER)
        Delete(tree->right, item);
    else
        DeleteNode(tree);  // Node found
}

void TreeType::GetPredecessor(TreeNode* tree,
    ItemType& data)
{
    while (tree->right != NULL)
        tree = tree->right;
    data = tree->info;
}

void TreeType::Print() const
{
    std::cout << "Binary Search Tree: (in-order)" << endl;
    PrintTree(root);
    std::cout << endl;
}

void TreeType::PrintTree(TreeNode* tree) const
{

    if (tree != NULL)
    {
        PrintTree(tree->left);
        tree->info.Print();
        PrintTree(tree->right);
    }
}

void TreeType::PreOrder(TreeNode* tree, queue<ItemType>*& preQue)
{

    if (tree != NULL)
    {
        preQue->push(tree->info);
        PreOrder(tree->left, preQue);
        PreOrder(tree->right, preQue);
    }
}

void TreeType::InOrder(TreeNode* tree, queue<ItemType>*& inQue)
{

    if (tree != NULL)
    {
        InOrder(tree->left, inQue);
        inQue->push(tree->info);
        InOrder(tree->right, inQue);
    }
}

void TreeType::PostOrder(TreeNode* tree, queue<ItemType>*& postQue)
{

    if (tree != NULL)
    {
        PostOrder(tree->left, postQue);
        PostOrder(tree->right, postQue);
        postQue->push(tree->info);
    }
}

void TreeType::ResetTree(OrderType order)
{
    switch (order)
    {
    case PRE_ORDER: preQue = new queue<ItemType>;
        PreOrder(root, preQue);
        break;
    case IN_ORDER: inQue = new queue<ItemType>;
        InOrder(root, inQue);
        break;
    case POST_ORDER: postQue = new queue<ItemType>;
        PostOrder(root, postQue);
        break;
    }
}

void TreeType::GetNextItem(ItemType& item, OrderType order, bool& finished)
{
    finished = false;
    switch (order)
    {
    case PRE_ORDER: item = preQue->front();
        preQue->pop();
        if (preQue->empty())
        {
            finished = true;
            delete preQue;
            preQue = NULL;
        }
        break;
    case IN_ORDER: item = inQue->front();
        inQue->pop();
        if (inQue->empty())
        {
            finished = true;
            delete inQue;
            inQue = NULL;
        }
        break;
    case  POST_ORDER: item = postQue->front();
        postQue->pop();
        if (postQue->empty())
        {
            finished = true;
            delete postQue;
            postQue = NULL;
        }
        break;

    }
}

int TreeType::LeafCount() const {
    return CountLeaf(root);
}

int TreeType::CountLeaf(TreeNode* tree) const {
    if (tree == NULL)
    {
        return 0;
    }
    else if ((tree->left == NULL) && (tree->right == NULL))
    {
        return 1;
    }
    else
    {
        return CountLeaf(tree->left) + CountLeaf(tree->right);
    }
}

void TreeType::Ancestors(ItemType item)
{
    AncestorFind(item);
}

void TreeType::AncestorFind(ItemType item)
{
    bool found = false;
    TreeNode* tree = root;
    AncestorSearch(tree, item, found);
}

void TreeType::AncestorSearch(TreeNode*& tree, ItemType& item, bool& found) const
{
    if (tree == NULL)
    {
        found = false;
    }
    else if (item.ComparedTo(tree->info) == LESS)
    {
        tree->info.Print();
        AncestorSearch(tree->left, item, found);
    }
    else if (item.ComparedTo(tree->info) == GREATER)
    {
        tree->info.Print();
        AncestorSearch(tree->right, item, found);
    }
    else
    {
        item = tree->info;
        found = true;
    }
}

void TreeType::DeleteNode(TreeNode*& tree)
{
    ItemType data;
    TreeNode* tempPtr;

    tempPtr = tree;

    if (tree->left == NULL) {  
        tree = tree->right;       
        delete tempPtr;
    }
    else if (tree->right == NULL) {
        tree = tree->left;
        delete tempPtr;
    }
    else {                       
        GetSuccessor(tree->right, data);    
        tree->info = data;      
        Delete(tree->right, data);  
    } 
}

void TreeType::GetSuccessor(TreeNode* tree, ItemType& data)
{                                                         
    while (tree->left != NULL)                  
        tree = tree->left;
    data = tree->info;
}

void TreeType::Swap(TreeType& newTree)
{
    SwapFunc(newTree);
}

void TreeType::SwapFunc(TreeType& newTree)
{
    Mirror(newTree.root, root);
}

void TreeType::Mirror(TreeNode*& mirrored, const TreeNode* original)
{
    if (original == NULL)
    {
        mirrored = NULL;
    }
    else
    {
        mirrored = new TreeNode;
        mirrored->info = original->info;
        Mirror(mirrored->right, original->left); 
        Mirror(mirrored->left, original->right); 
    }
}