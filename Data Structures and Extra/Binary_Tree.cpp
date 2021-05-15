#include <iostream>
#include <string>

using namespace std;

class TreeNode{
private:
    int data;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(): data(0), left(nullptr), right(nullptr) {}
    TreeNode(int newData, TreeNode* newLeft, TreeNode* newRight) : data{newData}, left(nullptr), right(nullptr) {}

    TreeNode* setRoot(int newData){
        TreeNode* root = new TreeNode();
        root->data = newData;
        root->left = nullptr;
        root->right = nullptr;  
        return root;   
    }

    void setBranch(int newData, TreeNode* parent){
        TreeNode* branch = new TreeNode();
        branch->data = newData; 
        branch->left = nullptr;
        branch->right = nullptr; 
        
        if(parent->data < branch->data && parent->left == nullptr)
            parent->left = branch;
        
        if(parent->data > branch->data && parent->right == nullptr)
            parent->right = branch; 
    }

// This was a PITA to create.
    void insertBranch(int newData, TreeNode*& root){
       if(root == nullptr){
            TreeNode* newNode = new TreeNode();    
            newNode->data = newData;
            root = newNode;
            return;
        }
        else if(newData > root->data)
            insertBranch(newData, root->right);
        else if(newData < root->data)
            insertBranch(newData, root->left);
        else
            return;
    }

    // Recursively some how. 
    int getSize(TreeNode* root){
        int size = 1;
        if (root->left == nullptr && root->right == nullptr)
            return size;
        else{
            if(root->left != nullptr){
                size++;
                getSize(root->left);
            }
            if(root->right != nullptr){
                size++;
                getSize(root->right);
            }
        }
        return size;
    }

    int getHeight2(TreeNode* root){
        int leftHeight = -1;
        int rightHeight = -1;
        if(root->left != nullptr)
            leftHeight = getHeight(root->left);
        if(root->right != nullptr)
            rightHeight = getHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
    }

    // Play around with this
    int getDepth(TreeNode* lowNode, TreeNode* highNode){
        int depthLeft = 0;
        int depthRight = 0;
        if(lowNode == nullptr || lowNode == highNode){
            return depthLeft;
        }
        //else{
            if(lowNode->left != nullptr){
                depthLeft++;
               return getDepth(lowNode->left, highNode);
            }
            if(lowNode->right != nullptr){
                depthRight++;
                return getDepth(lowNode->right, highNode);
            }
            if(depthRight > depthLeft){
                return depthRight;
            }
            else if(depthLeft >= depthRight){
                return depthLeft; 
            }
        //}
    }

    bool isFull(TreeNode* node){
        if(node->left != nullptr || node->right != nullptr)
            return true;
        else
            return false;
    }

    int getSibilingLeft(TreeNode* node){
        if(node->left != nullptr)
            return node->left->data;
            }

    int getSibilingRight(TreeNode* node){
        if(node->right != nullptr)
            return node->right->data;
            }

    TreeNode* searchNode(TreeNode* root, int data){
        if(root == nullptr){
            return nullptr;
        }
        // else if(root->data == data){
        //     return root;
        // }
        else if(data > root->data)
            return searchNode(root->right, data);
        else if(data < root->data)
            return searchNode(root->left, data);
        else
            return root;
    }

    TreeNode* findMin(TreeNode* node) const{
        if(node == nullptr){
            return nullptr;
        }
        if(node->left == nullptr){
            return node;
        }
        return findMin(node->left);
    }

// Node has no children just delete
// Node has 1 child, connect child to uncle
// Node has 2 children, idklol.
    void deleteNode(TreeNode*& delete_me, int oldData){
        if(delete_me == nullptr){
            return;
        }
        if(oldData < delete_me->data){
            deleteNode(delete_me->left, oldData);
        }
        else if(oldData > delete_me->data){
            deleteNode(delete_me->right, oldData);
        }
        else if(delete_me->left != nullptr && delete_me->right != nullptr){
        //Find the min. element in the right sub-tree
            delete_me->data = findMin(delete_me->right)->data;
            deleteNode(delete_me->right, delete_me->data);
        }
        else{
            TreeNode* temp = new TreeNode();
            temp = delete_me;
            if(delete_me->left != nullptr){
                temp = delete_me->left;
                delete delete_me;
                delete_me = nullptr; 
            }
            else{
                temp = delete_me->right;
                delete delete_me;
                delete_me = nullptr;
            }
        }
    }

    void printPreOrder(TreeNode* node){
        if(node != nullptr){
            cout << node->data << ", ";
            printInOrder(node->left);
            printInOrder(node->right);
        }
    }

    void printInOrder(TreeNode* node){
        if(node != nullptr){
            printInOrder(node->left);
            cout << node->data << ", ";
            printInOrder(node->right);
        }
    }

    void printPostOrder(TreeNode* node){
        if(node != nullptr){
            printInOrder(node->left);
            printInOrder(node->right);
            cout << node->data << ", ";
        }
    }

    int getData(TreeNode* node){
        return node->data;
    }

    int getHeight(TreeNode* root){
        if(root == nullptr)
            return 0;
    }

};


int main(){
    TreeNode bigTree;
    TreeNode* root = bigTree.setRoot(20);
    bigTree.insertBranch(5, root);
    bigTree.insertBranch(30, root);
    bigTree.insertBranch(3, root);
    bigTree.insertBranch(10, root);
    bigTree.insertBranch(25, root);
    bigTree.insertBranch(25, root);
    int height = bigTree.getHeight2(root);
    cout << height;
    TreeNode* findBranch = bigTree.searchNode(root, 30);
    cout << findBranch << endl;
    int depth = bigTree.getDepth(root, findBranch);
    cout << depth << endl; 
    int size = bigTree.getSize(root);
    cout << size << endl;
    int data = bigTree.getData(findBranch);
    cout << data;
    cout << '\n';
    cout << bigTree.isFull(root) << endl;
    bigTree.printPostOrder(root);
    bigTree.insertBranch(25,findBranch);
    cout << '\n';
    bigTree.printPostOrder(root);
    bigTree.deleteNode(root, 5);
    cout << '\n';
    bigTree.printInOrder(root);
    cout << '\n';
                       

    

    return 0;
}
