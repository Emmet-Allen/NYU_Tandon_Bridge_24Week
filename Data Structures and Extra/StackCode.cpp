#include <iostream>
#include <list>

using namespace std;

template <class T>
class Stack{
private:
    List<T> data;
public:
    //O(1) TIME
    void push(T newdata){
        data.push_front(newData);
    }
    //O(1) TIME
    T pop(){
        return data.pop_front();
    }
    //O(1) TIME
    T top() const{
        return *data.begin();
    }
    //O(1) TIME
    bool isEmpty() const{
        return data.size() == 0; 
    }
    //O(1) TIME
    int size() const{
        return data.size();
    }
    //O(N) TIME
    void clear(){
        data.clear;
    }

};

int main(){
    

    return 0;
}