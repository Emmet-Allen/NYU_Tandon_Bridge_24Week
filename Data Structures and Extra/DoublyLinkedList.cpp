#include <iostream>
#include <string>

using namespace std;

// Doubly Linked-List structure.
struct Node{
    int data;
    Node* forward_link;
    Node* backward_link;
};
typedef Node* NodePtr; 

void printForward(NodePtr head){
    //Create a temp NodePtr and assign it to the front of the list (head)
    NodePtr temp = head; 
    while(temp != nullptr){
        cout << temp->data << ' ';
    // Have the temp transverse the forwards (forward_link)
        temp = temp->forward_link; 
    }
    cout << '\n';
}

void printBackward(NodePtr tail){
    // Create a temp NodePtr and assign it to the back of the list (tail)
    NodePtr temp = tail; 
    while(temp != nullptr){
        cout << temp->data << ' ';
    // Have the temp transverse the list backwards (backward_link)
        temp = temp->backward_link; 
    }
    cout << '\n';
}

// Have the function return the newHead node
NodePtr insetHead(NodePtr head, int data){
    // Setup a temp node
    NodePtr temp = new Node;
    temp->data = data;
    // Connect the foward link to the old 'head' node
    temp->forward_link = head;
    // Connect the backward link to a nullptr b/c the temp is now the new head
    temp->backward_link = nullptr;
    // Have the old 'head' node connect to the new head node
    head->backward_link = temp;
    // Have the new head node be assigned as the 'head' 
    head = temp;
    return head;  
}

// Have the function return the newTail node
NodePtr insertTail(NodePtr tail, int data){
    //Setup a temp node
    NodePtr temp = new Node;
    temp->data = data; 
    // connect the forward link to a nullptr b/c temp is now the new tail
    temp->forward_link = nullptr;
    // connect the backward link of the new tail to the old 'tail'
    temp->backward_link = tail;
    // connect the forward link of the old 'tail' to temp, b/c temp is now the new tail
    tail->forward_link = temp;
    // Have the new tail node be assigned as the 'tail'
    tail = temp; 
    return tail;
}

void searchForward(NodePtr head, int target){
    while(head != nullptr && head->data != target){
        head = head->forward_link;
    }
    if(head == nullptr){
        cout << "Target Not in List" << endl;
    }
    else if(head->data == target){
        cout << "Target Found" << endl;
    }
}

//Could also make this return a node, to make it easier to remove/insert. 
void searchBackward(NodePtr tail, int target){
    while(tail != nullptr && tail->data != target){
        tail = tail->backward_link; 
    }
    if(tail == nullptr){
        cout << "Target Not in List" << endl;
    }
    else if(tail->data == target){
        cout << "Target Found" << endl;
    }
}

// Time Complex = n/2. Going both forward and backward in list
NodePtr forwardBackwardSearch(NodePtr head, NodePtr tail, int target){
    NodePtr targetNodeForward = head;
    NodePtr targetNodeBackward = tail; 
    while( (targetNodeForward != nullptr && targetNodeForward->data != target ) && (targetNodeBackward != nullptr && targetNodeBackward->data != target)){
        targetNodeForward = targetNodeForward->forward_link;
        targetNodeBackward = targetNodeBackward->backward_link;
    }
            if(targetNodeForward == nullptr || targetNodeBackward == nullptr){
                cout << "Target is not in list" << endl;
                return NULL;
            }
            else if (targetNodeForward->data == target || targetNodeBackward->data == target){
                cout << "Target Found" << endl;
                }
            if(targetNodeForward->data == target){
                return targetNodeForward; // If the target is found closest to the tail, it will return that node.
                }
            if(targetNodeBackward->data == target){
                return targetNodeBackward; // If the target is found closest to the head, it will return that node. 
            }
    }


NodePtr insertNode(NodePtr targetNode, int data){
    NodePtr temp = new Node;
    temp->data = data;
    temp->backward_link = targetNode;
    temp->forward_link = targetNode->forward_link;
    targetNode->forward_link = temp;
    return temp;
}

void deleteNode(NodePtr before_me, NodePtr after_me, NodePtr delete_me){
    before_me->backward_link = after_me;
    after_me->forward_link = before_me;
    delete delete_me;
    delete_me = NULL;
    cout << "Node Deleted" << endl; 
}

//Work on this.
void deleteList(NodePtr head){
    NodePtr temp = head;
    while(temp!= nullptr){
    NodePtr delete_me = temp;
        temp = temp->forward_link;
        delete delete_me;
    }
    cout << "List Deleted";
}



int main(){
    NodePtr head = nullptr;
    NodePtr tail = nullptr;


    NodePtr newNode = new Node; 
    newNode->data = 1; 
    newNode->backward_link = nullptr;
    head = newNode;
    tail = newNode; 

    NodePtr newNode2 = new Node; 
    newNode2->data = 2;
    newNode2->backward_link = tail;
    tail->forward_link = newNode2; 
    tail = newNode2;

    NodePtr newNode3 = new Node; 
    newNode3->data = 3;
    newNode3->backward_link = tail;
    tail->forward_link = newNode3; 
    tail = newNode3;

    NodePtr newNode4 = new Node; 
    newNode4->data = 4;
    newNode4->backward_link = tail;
    tail->forward_link = newNode4; 
    tail = newNode4;
    tail->forward_link = nullptr; 

    printForward(head); 
    printBackward(tail);

NodePtr newHead = insetHead(head, -1);
    printForward(newHead);
NodePtr newTail = insertTail(tail, 5);
    printBackward(newTail);
NodePtr newerTail = insertTail(newTail,6);
    printBackward(newerTail);

    searchForward(newHead, 20);
    searchBackward(newerTail, 3);
    searchBackward(newerTail, 20);
    NodePtr target = forwardBackwardSearch(newHead, newerTail, 6);

    insertNode(target, 25);
    printForward(newHead);

    deleteList(newHead);

    return 0;
}