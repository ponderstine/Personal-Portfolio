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

    // If tree is empty then there is nothing to delete
    if(isEmpty()){

        // Print statement to std out
        cout << "Tree is empty so cannot delete node: " << key << "." << endl;
        return;
    }

    // check if root node is the node that has to be deleted
    if (root->key == key){

        //need to delete root

        // check how many kids the root has (4 cases)
        if (root->leftChild == NULL && root->rightChild == NULL){

            //no kids => can just delete and set root to null
            delete root;
            root = NULL;
            return;

        } else if (root->leftChild != NULL && root->rightChild == NULL){

            // only left child, left child will replace root
            // initialize temporary pointer to old root
            Node* temp = root;

            // reassign new root
            root = temp->leftChild;

            // fix new root parent pointer
            root->parent = NULL;

            // delete old root
            delete temp;
            return;

        } else if (root->leftChild == NULL && root->rightChild != NULL){

            // only right child, right child will replace root
            // initialize temporary pointer to old root
            Node* temp = root;

            // reassign new root
            root = temp->rightChild;

            //fix new root parent pointer
            root->parent = NULL;

            // delete old root
            delete temp;
            return;

        } else {

            // two kids => find min value on right subtree and replace (can also replace with max value on left subtree)
            // initialize pointer to find min value of right subtree
            Node* cur = root->rightChild;

            // while there is a lesser value to traverse to (left child is not NULL), traverse left
            while (cur->leftChild != NULL){

                // traverse left
                cur = cur->leftChild;
            }

            // cur pointing at min value of right subtree
            root->key = cur->key;

            // if replacement node has a right child, need to assign that child in the replacements place (replacement-ception)
            if (cur->rightChild != NULL){
                
                // fix pointers to replace the replacement
                cur->parent->leftChild = cur->rightChild;
                cur->rightChild->parent = cur->parent;
            }

            // delete node that replaced the root
            delete cur;
            
            // NOTE: Don't need to reassign root pointer since we aren't deleting the root, only transferring data too the root 

        }
    } else {

        // root is not node to be deleted

        // make pointer to traverse tree
        Node* cur = root;

        // search rest of tree for node to delete
        while(cur != NULL){

            // if current node has the key we are looking for, this is the node we need to delete
            if(key == cur->key){
                
               // Check how many kids the node has (4 cases)
                if (cur->leftChild == NULL && cur->rightChild == NULL){

                    //no kids
                    if (cur == cur->parent->leftChild){

                        // fix parent pointer
                        cur->parent->leftChild = NULL;

                    } else {

                        // fix parent pointer
                        cur->parent->rightChild = NULL;

                    }
                    
                    // delete node
                    delete cur;
                    return;

                } else if (cur->leftChild != NULL && cur->rightChild == NULL){

                    // only left child
                    if (cur == cur->parent->leftChild){

                        //fix child pointer
                        cur->parent->leftChild = cur->leftChild;

                    } else {

                        // fix child pointer
                        cur->parent->rightChild = cur->leftChild;

                    }

                    // fix parent pointer
                    cur->leftChild->parent = cur->parent;

                    // delete node
                    delete cur;
                    return;

                } else if (cur->leftChild == NULL && cur->rightChild != NULL){

                    // only right child
                    if (cur == cur->parent->leftChild){

                        //fix child pointer
                        cur->parent->leftChild = cur->leftChild;

                    } else {

                        //fix child pointer
                        cur->parent->rightChild = cur->leftChild;

                    }

                    // fix parent pointer
                    cur->leftChild->parent = cur->parent;

                    // delete node
                    delete cur;
                    return;

                } else {

                    // two kids => find min value on right subtree and replace
                    // initiate temporary pointer to traverse right subtree for min value
                    Node* temp = cur->rightChild;

                    // while there is a lower value, traverse to it
                    while (temp->leftChild != NULL){

                        // traverse to left child
                        temp = temp->leftChild;
                    }

                    // cur pointing at min value of right subtree
                    cur->key = temp->key;

                    // if replacement node has a right child, need to reassign so right child replaces replacement node
                    if (temp->rightChild != NULL){
                        
                        // fix pointers
                        temp->parent->leftChild = temp->rightChild;
                        temp->rightChild->parent = temp->parent;
                    }

                    // delete node
                    delete temp;
                }
            }
        }
        
        //traversed whole list and didn't find node with key value passed in
        // Print statement to std out
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