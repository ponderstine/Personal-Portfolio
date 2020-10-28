#include <iostream>

using namespace std;


struct Node{                                        // A struct for the nodes of the tree

    int key;                                        // The key value for the node (doesn't have to be an int)
    Node* leftChild = NULL;                         // A pointer to the left child. In a binary search tree, everything on the left child and children of the left child will have a key less than this node.
    Node* rightChild = NULL;                        // A pointer to the right child. In a binary search tree, everything on the right child and children of the right child will have a key greater than or equal to this node.
    Node* parent = NULL;                            // A pointer to the parent of the current node (pointing back toward the root of the tree).
};

class binarySearchTree{                             // A class for the methods and variable of the binary search tree

    private:

        Node* root = NULL;                          // A pointer to the root of the tree.
        void destructorHelper(Node* cur);           // A recursive helper function for the destructor function.
        void preOrderPrintHelper(Node* cur);        // A recursive helper function for the pre order print function.
        void inOrderPrintHelper(Node* cur);         // A recursive helper function for the in order print function.
        void postOrderPrintHelper(Node* cur);       // A recursive helper function for the post order print function
        void levelOrderPrintHelper(Node* cur, int level, int counter);      // A recursive helper function for the level order print function.
        int sizeHelper(Node* cur);                  // A recursive helper function for the size getter.
        int heightHelper(Node* cur);

    public:

        binarySearchTree();                         // An initiator function.
        binarySearchTree(int key);                  // An initiator function that creates the root pointing to a node with the key value passed in.
        ~binarySearchTree();                        // A destructor function.
        bool isEmpty();                             // A function to check if the binary search tree is empty or not.
        void preOrderPrint();                       // A function that will print the contents of the tree with the parent node printed before its children.
        void inOrderPrint();                        // A function that will print the contents of the tree in ascending order.
        void postOrderPrint();                      // A function that will print the contents of the tree with the parent node printed after its children.
        void levelOrderPrint();                     // A Function that will print the contents of the tree level by level from the root down.
        Node* searchFor(int key);                   // A function that will search for the node with the passed in key value.
        void addNode(int key);                      // A function to add a new node to the binary search tree.
        void deleteNode(int key);                   // A function to delete the node with the passed in value from the search value.
        void leftRotate(Node* cur);                 // A function to perform a left rotation on the passed in node.
        void rightRotate(Node* cur);                // A function to perform a right rotation on the passed in node.
        int size();                                 // A function to count the size (number of nodes) currently in the binary search tree.
        int height();                               // A function to count the height of the binary search tree
};