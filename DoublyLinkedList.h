#ifndef Doubly_Linked_List
#define Doubly_Linked_List
#include <string>
#include <vector>
using namespace std;

typedef string E;

struct Node
{
  E item;
  Node *next;
  Node *prev;
    Node (E e)
  {
    item = e;
    next = nullptr;
    prev = nullptr;
  }

};

class DoublyLinkedList
{
private:
  Node *list;
  Node *tail;
  int num_items;
  Node *getNodeAt (int pos);

public:
    DoublyLinkedList ();
    DoublyLinkedList (const DoublyLinkedList & other);
   ~DoublyLinkedList ();
  void add (E item);
  void add (int pos, E item);
  bool contains (E item);
  int size ();
  bool isEmpty ();
  vector < E > myVector;
  E get (int pos);
  E remove (int pos);
  void reverse ();
  vector < E > toVector (bool reverse);
  void print (const char *msg, const vector < E > &vec);
};

#endif
