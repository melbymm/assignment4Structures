#include <iostream>
#include <sstream>
#include <fstream>
#include "linkedList.h"
using namespace std;

template<class V>
class listQueue{
public:
  //variables
  void insert(V d);
  V remove();
  V getfront();
  naiveList<V> *f = new naiveList<V>();
  listNode<V> *afront;
  listNode<V> *aback;
  int asize = 0;
  int search(V value);
  void printQueue();
};
//insert method
template<class V>
void listQueue<V>::insert(V d){

  f->insertBack(d);
  asize++;

}
//remove method
template<class V>
V listQueue<V>::remove(){

  asize--;
  int b = f->removeFront();
  return b;
}
//return front method
template<class V>
V listQueue<V>::getfront(){
  listNode<V> *newnode = f->front;
  return newnode->data;
}
template<class V>
int listQueue<V> :: search(V value){
  return f->search(value);
}
template<class V>
void listQueue<V> :: printQueue(){
  f->printList();
}
