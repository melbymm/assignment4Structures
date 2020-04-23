#include <iostream>
#include <sstream>
#include <fstream>
#include "NodeTemplate.h"
using namespace std;

template<class V>
class naiveList{
  public:
    //variables & methods
    naiveList();
    ~naiveList();
    void insertFront(V d);
    V removeFront();
    int search(V val);
    V removeAtPos(int pos);
    V removeBack();
    void insertBack(V d);

    unsigned int getsize();
    bool isEmpty();
    void printList();
    //void removeFront();


    listNode<V> *front;
    listNode<V> *back;
    int size = 0;

};
//default constructor
template<class V>
naiveList <V>:: naiveList(){
  size = 0;
  front = NULL;
  back = NULL;
}
//destructor
template<class V>
naiveList<V> :: ~naiveList(){
  listNode<V> *curr = front;
  while(curr != NULL){
    listNode<V> *next = curr -> next;
    delete curr;
    curr = next;
  }
}
//get size
template<class V>
unsigned int naiveList<V> :: getsize(){
  return size;
}
//check empty
template<class V>
bool naiveList <V>:: isEmpty(){
  return (size == 0);
}
//print linked list
template<class V>
void naiveList<V> :: printList(){
  listNode<V> *curr = front;
  while (curr != NULL){
    cout << curr -> data << endl;
    curr = curr -> next;
  }
}

//insert at front of linked list
template<class V>
void naiveList<V> :: insertFront(V d){
  listNode<V> *node = new listNode<V>(d);
  node -> next = front;
  front = node;
  size ++;

  if(size ==1){
    back = node;
  }
}
//insert at back of linked list
template<class V>
void naiveList<V> :: insertBack(V d){
  listNode<V> *node = new listNode<V>(d);
  if(isEmpty()){
    front = node;
    back = node;
    size ++;
  }
  else{
    node->prev = back;
    back->next = node;
    back = node;
    size++;
  }
}
//remove front of linked list
template<class V>
V naiveList<V> :: removeFront(){
  if(!isEmpty()){
  	V temp = front -> data;
  	listNode<V> *ft = front;
  	front = front -> next;
  	ft -> next = NULL;
  	delete ft;

    --size;
    return temp;
  }
}
//search for a value, return index position
template<class V>
int naiveList<V> :: search(V val){
  int pos = -1;
  listNode<V> *curr = front;

  while(curr != NULL){
    ++pos;
    if(curr -> data == val){
      break;
    }
    else{
      curr = curr -> next;
    }
  }
  //not in list
  if(curr == NULL){
    cout << "Couldn't find it." << endl;
    pos = -1;
  }
  return pos;
}
//remove at given position
template<class V>
V naiveList<V> :: removeAtPos(int pos){
  int idx = 0;
  //cout << "o" << endl;
//make sure position is in list
  if(pos < naiveList::getsize()){

    listNode<V> *curr = front;
    listNode<V> *prev = front;
    //search
    while(idx != pos){
      prev = curr;
      curr = curr -> next;
      idx++;
    //  cout << idx << endl;

    }

    //remove
    if(idx == pos){
    //  cout << "Henlo" << endl;
      prev -> next = curr -> next;
      curr -> next = NULL;
      V temp = curr -> data;
      delete curr;
      size --;
      return temp;
    }


  }
}

//remove from back of linked list
template<class V>
V naiveList<V> :: removeBack(){
  listNode<V> *backnode = back;
  listNode<V> *almostback = back->prev;
  almostback->next = NULL;
  V temp = backnode -> data;
  delete backnode;
  size --;
  return temp;

}
