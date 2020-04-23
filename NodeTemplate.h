
#include <iostream>
using namespace std;
template <class V>
class listNode{
  public:
    V data;
    listNode *next;
    listNode *prev;
    listNode();
    listNode(V c);
    ~listNode();

};

template<class V>
listNode<V> :: listNode(){
  data = NULL;
  next = NULL;
  prev = NULL;
}
template<class V>
listNode<V> :: listNode(V c){
  data = c;
  next = NULL;
  prev = NULL;
}
template<class V>
listNode<V> :: ~listNode(){

}
