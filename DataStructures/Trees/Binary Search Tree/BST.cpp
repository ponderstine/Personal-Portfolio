#include "BST.hpp"

binarySearchTree::binarySearchTree(){

    // Create the tree with the root pointing to NULL
    root = NULL;
    return;
};

binarySearchTree::binarySearchTree(int key){

    // create a new node for the root to point to
    root = new Node;
    root->key = key;
    return;
};

void binarySearchTree::destructorHelper(Node* cur){

    // Base case: if on NULL node then return
    if (cur == NULL){

        return;
    }

    // General case: traverse to left subtree, right subtree, then delete current node
    destructorHelper(cur->leftChild);
    destructorHelper(cur->rightChild);
    delete cur;
    return;
};

binarySearchTree::~binarySearchTree(){

    // Call the destructor helper function
    destructorHelper(root);

    // Assign the root to NULL so the tree can be used for new nodes
    root = NULL;
    return;
};

bool binarySearchTree::isEmpty(){

    // if root is NULL then tree is empty, return true. If root is not NULL (else) tree is not empty and return false
    if (root == NULL){
        
        return true;
    } else {

        return false;
    }
};

void binarySearchTree::preOrderPrintHelper(Node* cur){

    // Base case: if pointing at NULL node, return up
    if (cur == NULL){
        return;
    }

    //General case
    // Print current node's key
    cout << cur->key << " ";

    // Call recursive function on left child
    preOrderPrintHelper(cur->leftChild);

    // Call recursive function on right child
    preOrderPrintHelper(cur->rightChild);
    return;
};

void binarySearchTree::preOrderPrint(){

    // if tree is empty then there is nothing to print.
    if(isEmpty()){

        // Print statement to std out
        cout << "Tree is empty so cannot preorder print." << endl;
        return;
    }

    // print beginning statement
    cout << "Preorder printing tree..." << endl;

    // Call recursive helper function on root node
    preOrderPrintHelper(root);

    // Finish print by ending the line
    cout << endl;
    return;
};

void binarySearchTree::inOrderPrintHelper(Node* cur){

    // Base case: if pointing at NULL node, return up
    if (cur == NULL){
        return;
    }

    // General case
    // Call recursive function on left child
    inOrderPrintHelper(cur->leftChild);

    // Print current node's key
    cout << cur->key << " ";

    // Call recursive function on right child
    inOrderPrintHelper(cur->rightChild);
    return;
};

void binarySearchTree::inOrderPrint(){

    // if tree is empty then there is nothing to print.
    if(isEmpty()){

        // Print statement to std out
        cout << "Tree is empty so cannot inorder print." << endl;
        return;
    }

    // print beginning statement
    cout << "In order printing tree..." << endl;

    // Call recursive helper function on root node
    inOrderPrintHelper(root);

    // Finish print by ending the line
    cout << endl;
    return;
};

void binarySearchTree::postOrderPrintHelper(Node* cur){

    // Base case: if pointing at NULL node, return up
    if (cur == NULL){
        return;
    }

    // General case
    // Call recursive function on left child
    postOrderPrintHelper(cur->leftChild);

    // Call recursive function on right child
    postOrderPrintHelper(cur->rightChild);

    // Print current node's key
    cout << cur->key << " ";
    return;
};

void binarySearchTree::postOrderPrint(){

    // if tree is empty then there is nothing to print.
    if(isEmpty()){

        // Print statement to std out
        cout << "Tree is empty so cannot postorder print." << endl;
        return;
    }

    // print beginning statement
    cout << "Postorder printing tree..." << endl;

    // Call recursive helper function on root node
    postOrderPrintHelper(root);

    // Finish print by ending the line
    cout << endl;
    return;
};

Node* binarySearchTree::searchFor(int key){

    // If tree is empty then there is nothing to search, no way the tree contains the node with the passed in key value.
    if(isEmpty()){

        // Print statement to std out
        cout << "Tree is empty so cannot search for node: " << key << "." << endl;
        return NULL;
    }

    // Initiate pointer to traverse tree
    Node* cur = root;

    // While we have not reached the NULL nodes past the leaves
    while(cur != NULL){

        // if the current node has the right key, WE FOUND IT
        if (cur->key == key){
            
            return cur;

        } else if (key < cur->key){
            
            // if key we want is less than the key we are on, traverse to left subtree
            cur = cur->leftChild;

        } else {

            // if key we want is greater than the key we are on, traverse to right subtree
            cur = cur->rightChild;
        }
    }

    // if exits while loop and cur is NULL, node with passed in key value is not in the tree
    if (cur == NULL){

        // Print statement to std out
        cout << "Tree does not contain node: " << key << endl;
        return NULL;
    }
};

void binarySearchTree::addNode(int key){

    // If tree is empty then the new node will be the root
    if (isEmpty()){

        // Create a new node and point the root to it
        root = new Node;
        root->key = key;
        return;
    }
    
    // Initialize a pointer to traverse the tree
    Node* cur = root;
    while (1){

        // If new key is less than current key, traverse to left subtree
        if (key < cur->key){
 
            if (cur->leftChild != NULL){

                // if left child is not NULL then traverse to left child
                cur = cur->leftChild;

            } else {

                // If left child is NULL then that is the spot for the new node
                // Create a new node and assign pointers to insert it
                cur->leftChild = new Node;
                cur->leftChild->key = key;
                cur->leftChild->parent = cur;
                return;
            }
        } else {
        // If new key is greater than or equal to current key, traverse to right subtree

            if (cur->rightChild != NULL){

                // if right child is not NULL then traverse to right child
                cur = cur->rightChild;

            } else {

                // If right child is NULL then that is the spot for the new node
                // Create a new node and assign pointers to insert it
                cur->rightChild = new Node;
                cur->rightChild->key = key;
                cur->rightChild->parent = cur;
                return;
            }
        }
    }

    return;
};

void binarySearchTree::deleteNode(int key){

    if(isEmpty()){

        cout << "Tree is empty so cannot delete node: " << key << "." << endl;
        return;
    }

    Node* cur = root;

    if (root->key == key){

        //need to delete root

        if (root->leftChild == NULL && root->rightChild == NULL){

            //no kids
            delete root;
            root = NULL;
            return;

        } else if (root->leftChild != NULL && root->rightChild == NULL){

            // only left child
            Node* temp = root;
            root = temp->leftChild;
            delete temp;
            return;

        } else if (root->leftChild == NULL && root->rightChild != NULL){

            // only right child
            Node* temp = root;
            root = temp->rightChild;
            delete temp;
            return;

        } else {

            // two kids => find min value on right subtree and replace
            cur = root->rightChild;
            while (cur->leftChild != NULL){

                cur = cur->leftChild;
            }

            // cur pointing at min value of right subtree
            root->key = cur->key;

            if (cur->rightChild != NULL){
                
                cur->parent->leftChild = cur->rightChild;
            }
            delete cur;
            // Don't need to reassign root pointer since we aren't deleting the root, only transferring data too the root 

        }
    } else {

        // search rest of tree for node to delete
        while(cur != NULL){

            if(key == cur->key){
                
                // found node to be deleted
                if (cur->leftChild == NULL && cur->rightChild == NULL){

                    //no kids
                    if (cur == cur->parent->leftChild){

                        cur->parent->leftChild = NULL;

                    } else {

                        cur->parent->rightChild = NULL;

                    }
                    delete cur;
                    return;

                } else if (cur->leftChild != NULL && cur->rightChild == NULL){

                    // only left child
                    if (cur == cur->parent->leftChild){

                        cur->parent->leftChild = cur->leftChild;

                    } else {

                        cur->parent->rightChild = cur->leftChild;

                    }
                    cur->leftChild->parent = cur->parent;
                    delete cur;
                    return;

                } else if (cur->leftChild == NULL && cur->rightChild != NULL){

                    // only right child
                    if (cur == cur->parent->leftChild){

                        cur->parent->leftChild = cur->leftChild;

                    } else {

                        cur->parent->rightChild = cur->leftChild;

                    }
                    cur->leftChild->parent = cur->parent;
                    delete cur;
                    return;

                } else {

                    // two kids => find min value on right subtree and replace
                    Node* temp = cur->rightChild;
                    while (temp->leftChild != NULL){

                        temp = temp->leftChild;
                    }

                    // cur pointing at min value of right subtree
                    cur->key = temp->key;

                    if (temp->rightChild != NULL){
                        
                        temp->parent->leftChild = temp->rightChild;
                    }
                    delete temp;
                }
            }
        }
        //traversed whole list and didn't find node with key value passed in

        cout << "Could not delete, tree does not contain node: " << key << endl;
        return;
    }
};

void binarySearchTree::leftRotate(Node* cur){

    // If tree is empty then cannot rotate
    if(isEmpty()){

        // Print statement to std out
        cout << "Tree is empty so cannot left rotate." << endl;
        return;
    }

    //BLAH

};

void binarySearchTree::rightRotate(Node* cur){

    // If tree is empty then cannot rotate
    if(isEmpty()){

        // Print statement to std out
        cout << "Tree is empty so cannot right rotate." << endl;
        return;
    }

    //BLAH

};

int binarySearchTree::sizeHelper(Node* cur){

    // Base case: if reach NULL node then return 0
    if (cur == NULL){
        return 0;
    }

    // General case
    // Run recursive function on left subtree
    int left = sizeHelper(cur->leftChild);

    // Run recursive function on left subtree
    int right = sizeHelper(cur->rightChild);

    //return sum of left subtree count, right sub tree count, plus one for the current node
    return left + right + 1;
};

int binarySearchTree::size(){

    // Run the recursive size counter function on the root node
    return sizeHelper(root);
};