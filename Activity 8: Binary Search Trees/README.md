1. 
            1
             \
               5
             /   \
            2      9
             \   /  \
              4  6     10
            /      \
          3          8

2. The maximum number of steps it would take to search for a values in a well-balanced BST with 1,000 values is 10 steps. since 2^9 = 512 and 2^10= 1024. The 2 comes from the choice you have to compare to, whether the value you chose is smaller or larger than the one you are comparing to.

3. 
Check if there is a root node. if not, the tree is empty.
Check if there is a right node. if not, the root is the largest value in the tree.
If there is a right node, set that node as the current node. Repeat this step until you run into a nullptr.
If there is a nullptr, that means that this current node is the largest value in the BST.

4. 
```cpp
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Tree
{
private:
    Node* root;

public:
    Tree();

    void insert(int value);
    void printHelper(Node* element);
    void print();
};

Tree::Tree () 
{
    root = nullptr;
}

void Tree::insert(int value)
{
    Node* newNode = new Node{value, nullptr, nullptr};
    if (root == nullptr) // if there is no root, set this value as the root.
    {
        root = newNode;
        return;
    }

    Node* currentNode = root;

    while(true) { // create a loop
        if (value < currentNode->data) // check if the input is less than the value
        {
            if (currentNode->left == nullptr) // check if this node's left is open
            {
                currentNode->left = newNode; // assign
                break;
            }
            currentNode = currentNode->left; // move to the left
        }

        else  // other case, if the input is more than the value
        {
            if (currentNode->right == nullptr)
            {
                    currentNode->right = newNode; // assign
                    break;
            }
            currentNode = currentNode->right; // move to the right
        }
    }
}

void Tree::printHelper(Node* element) // recursion
{
    if (element == nullptr)
    {
        return;
    }
    printHelper(element->left); //put the next left node into this method
    cout << element->data << " " << endl; //print the data of this element
    printHelper(element->right); //put the next right node into this method
}

void Tree::print() // implemented print so i can make sure that this actually works!
{
    printHelper(root); //input the root!
    cout << endl;
}

int main(){
    Tree testTree;
    testTree.insert(1);
    testTree.insert(5);
    testTree.insert(9);
    testTree.insert(2);
    testTree.insert(4);
    testTree.insert(10);
    testTree.insert(6);
    testTree.insert(3);
    testTree.insert(8);

    testTree.print();

    return 0;
}
```
