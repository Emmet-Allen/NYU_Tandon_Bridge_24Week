#include <iostream>
#include <string>

using namespace std; 

template <class T> 
class linkList{
  private:
  
  typedef struct node{
      T data;   // Stores data in list
      node* next; // Points to next node in list
  }* nodePtr;
  
  nodePtr head; 
  nodePtr curr;
  nodePtr temp; 
  
  public:
  // Constructor will all nodePtr set to NULL 
  List(){
      head = nullptr;
      curr = nullptr;
      temp = nullptr; 
  } 
  

  // Takes in data. 
  void AddNode(const T& addData){
    // Creates a node pointer 'n', and creates a new node 
      nodePtr n = new node; 
    // Find the node where 'n' is pointing to, access 'next'-element and set it to null 
      n->next = nullptr; 
    // Whatever we pass into the function will now be the data stored in 'n'
      n->data = addData; 

    // General Case: If we have a LL already created, then the head is not null
      if(head != nullptr){
          curr = head; 
    // Checks to see if we are at the end of the list, if we are at the end, then the next pointer will be null
          while(curr->next != nullptr){
    // This will advance the current pointer to the next pointer of the list 
          curr = curr->next; 
        }
        // Connects last node to the new node 'n' that was created
        curr->next = n; 
      }

    // Other Case: We dont have a LL created
      else{
          // Then the node 'n' will be the head of the list
          head = n; 
      }
    }

  void DeleteNode(const T& delData){
      // Create a node pointer 'delPtr' and set it to null
      nodePtr delPtr = nullptr; 
      
      // We set the temp and curr pointers to the head pointer, or the begining of the list 
      temp = head; 
      curr = head;

      // We are checking to see if the curr ptr is nullptr, which only happens if we are at the end of the list 
      // We also need to check if the curr pointers data is not the data we want to delete, cause we want to delete that data 
      while(curr != nullptr && curr->data != delData){
          // temp pointer will hold the current pointer, and is one step behind the next pointer
          temp =curr; 
          // the current pointer will transverse to the next pointer 
          curr = curr->next; 
      }
      // If we passed through the entire list, then that data is not in the list
      if(curr == nullptr){
          cout << delData << " Was not found" << endl; 
          // Free the memory of delPtr, unassign and release
          delete delPtr; 
      }
      else if(curr == head){
          // Set the delPtr to the head ptr, because we are at the start of the list
          delPtr = head;
          // Set the head ptr to the next ptr after the head
          head = head->next;
          // Set the current ptr to the next ptr after the head to patch the gap
          curr = head->next;
          // delete the delPtr
          delete delPtr;
          cout << delData << " Was found at the begining of the list" << endl;
      }
      // If the curr ptrs data is the same as the data we want to delete
      else{
          // We set the 'delPtr' to the current pointer
          delPtr = curr;
          // We then have the current pointer, assigned to the next pointer. Filling in the current pointer gap
          curr = curr->next;  
          // The temp of the next pointer would then be assigned the current pointer, because it is one-step behind in the list. 
          temp->next = curr; 
        
          //Delete the delPtr
          delete delPtr; 
          cout << "The value " << delData << " was deleted" << endl; 
      }
  }

  void PrintList(){
      // Point the current pointer to the head of the list
      curr = head; 

      // If curr ptr is not null, this is to transverse the list
      while(curr != nullptr){
          // Print out the current pointers data
          cout << curr->data << endl;
          // Continue to the next pointer
          curr = curr->next; 
      }
  }



};

int main()
{


    linkList<int> Emmet;
    Emmet.AddNode(12);
    Emmet.AddNode(14);
    Emmet.AddNode(16);
    Emmet.AddNode(20);

    Emmet.PrintList();

return 0;
}