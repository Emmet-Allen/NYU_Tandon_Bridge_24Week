#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node{
private:
    T data;
    // We need to make a node of 'T' type
    Node<T>* link;

public:
    Node();
    Node(T data);
    Node(T data, Node<T>* next);

// We need to preface the functions in the class, then implement them outside while using templates 
    T getData();
    Node<T>* getNodePointer ();
    void setNodeData(T newData);
    void setNodePointer(Node<T>* nextPointer);

    ~Node(){
        link = nullptr;
    }
};

template <class T> // WIIL GO BEFORE EVERY FUNCTION DEFINITON! COMPILER NEEDS TO SPECIFY THE TYPE DURING RUNTIME
Node<T>::Node(){
    this->link = nullptr;
}

template <class T>
Node<T>::Node(T data){
    this->link = nullptr;
    this->data = data;
}

template <class T>
Node<T>::Node(T data, Node<T>* next){
    this->data = data;
    this->link = next;
}

template <class T>
T Node<T>::getData(){
    return data;
}

template <class T>
Node<T>* Node<T>::getNodePointer(){
    return link;
}

template <class T>
void Node<T>::setNodeData(T newData){
    this->data = newData;
}

template <class T>
void Node<T>::setNodePointer(Node<T>* nextPointer){
    this->link = nextPointer;
}


int main(){
    Node<int>* newNode = new Node<int>(1);
    cout << newNode->getNodePointer() << endl;

    Node<int>* newerNode = new Node<int>(2);
    newNode->setNodePointer(newerNode);
    cout << newNode->getNodePointer() << endl;
    cout << newerNode->getNodePointer() << endl;

    Node<string>* newestNode = new Node<string>("Bang");
    //newerNode->setNodePointer(newestNode); //WILL NOT WORK, LINKED LIST FOLLOW SAME DATA TYPES THROUGHOUT!

    delete newNode, newerNode, newestNode;

    return 0;
}