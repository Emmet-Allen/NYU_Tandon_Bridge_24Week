#include <iostream>
#include <list>
#include <string>

using namespace std;

template <class T>
class Queue{
private:
    list<T> data;
public:
    Queue(){}
    
    void enqueue(T newElement);
    void dequeue();
    T top();
    bool isEmpty();
    int size();
    void clear();
};

template <class T>
void Queue<T>::enqueue(T newElement){
    data.push_back(newElement);
}

template <class T>
void Queue<T>::dequeue(){ 
    data.pop_front();
}

template <class T>
T Queue<T>::top(){
    return *data.begin();
}

template <class T>
bool Queue<T>::isEmpty(){
    return data.empty();
}

template <class T>
int Queue<T>::size(){
    return data.size();
}

template <class T>
void Queue<T>::clear(){
    data.clear();
}


int main(){
    Queue<string> bankLine;
    bankLine.enqueue("Sally");
    bankLine.enqueue("Bob");
    bankLine.enqueue("Joe");

    cout << bankLine.top() << endl;
    bankLine.dequeue();
    cout << bankLine.top() << endl;

    return 0;
}