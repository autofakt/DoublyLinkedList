#include "DoublyLinkedList.h"
#include <iostream>


using namespace std;

DoublyLinkedList::DoublyLinkedList ():num_items (0), list (nullptr),
tail (nullptr)
{
}

DoublyLinkedList::DoublyLinkedList (const DoublyLinkedList & other)
{
  num_items = other.num_items;
  list = nullptr;
  if (num_items == 0)
    return;
  Node *orig = other.list;
  Node *copy = new Node (orig->item);
  list = copy;
  copy->prev = nullptr;
  Node *copyPrev = list;

  orig = orig->next;
  while (orig != nullptr)
    {
      copy->next = new Node (orig->item);
      orig = orig->next;
      copy = copy->next;
      copy->prev = copyPrev;
      copyPrev = copy;
    }
  tail = copy;
  copy->next = nullptr;

}

DoublyLinkedList::~DoublyLinkedList ()
{
  int n = num_items;
  for (int pos = 1; pos <= n; pos++)
    {
      remove (0);
    }
}

void
DoublyLinkedList::add (E item)
{
  add (num_items, item);
}

void
DoublyLinkedList::add (int pos, E item)
{
  if (pos < 0 || pos > num_items)
    throw "invalid position specified";
  Node *p = new Node (item);
  if (pos == 0)
    {
      p->next = list;
      p->prev = nullptr;
      if (num_items != 0)
	{
	  list->prev = p;
	}
      list = p;
      if (num_items == 0)
	{
	  tail = p;
	}
      num_items++;
      return;
    }
// Find node that will be before new node
  Node *prev = getNodeAt (pos - 1);
  p->next = prev->next;
  prev->next = p;
  p->prev = prev;
  if (pos == num_items)
    {
      tail = p;
    }
  else
    {
      Node *next = getNodeAt (pos + 1);
      next->prev = p;
    }
  num_items++;
}

bool
DoublyLinkedList::contains (E item)
{
  Node *p = list;
  while (p != nullptr)
    {
      if (p->item == item)
	return true;
      p = p->next;
    }

  return false;
}

int
DoublyLinkedList::size ()
{
  return num_items;
}

bool
DoublyLinkedList::isEmpty ()
{
  return num_items == 0;
}

E
DoublyLinkedList::get (int pos)
{
  if (pos < 0 || pos >= num_items)
    throw "invalid position specified";
  Node *p = getNodeAt (pos);
  return p->item;
}

E
DoublyLinkedList::remove (int pos)
{
  if (pos < 0 || pos >= num_items)
    throw "invalid position specified";

  if (pos == 0 && num_items != 1)
    {
      Node *p = list;
      E item = p->item;
      list = list->next;
      p->next = nullptr;
      list->prev = nullptr;
      delete p;
      num_items--;
      return item;
    }

  if (pos == 0 && num_items == 1)
    {
      E item = list->item;
      delete list;
      num_items--;
      return item;
    }

  if (pos + 1 == num_items)
    {
      Node *prev = getNodeAt (pos - 1);
      Node *p = prev->next;
      E item = p->item;
      prev->next = p->next;
      p->prev = nullptr;
      prev = tail;
      num_items--;
      return item;
    }

  if (pos != num_items)
    {
      Node *prev = getNodeAt (pos - 1);
      Node *p = prev->next;
      Node *pNext = p->next;
      E item = p->item;
      prev->next = p->next;
      pNext->prev = p->prev;
      p->next = nullptr;
      p->prev = nullptr;
      delete p;
      num_items--;
      return item;
    }

}


// Private
Node *
DoublyLinkedList::getNodeAt (int pos)
{
  Node *p = list;
  for (int skip = 1; skip <= pos; skip++)
    p = p->next;
  return p;
}

void
DoublyLinkedList::reverse ()
{
  Node *current = list;
  Node *temp;
  Node *newTail;
  int counter = 0;

  while (current != nullptr)
    {

      temp = current->prev;
      current->prev = current->next;
      current->next = temp;
      current = current->prev;
    }
  newTail = list;
  list = temp->prev;
  tail = newTail;
}


vector < E > DoublyLinkedList::toVector (bool reverse)
{

  if (reverse == false)
    {
      Node *p = list;
      while (p != nullptr)
	{
	  myVector.push_back (p->item);
	  p = p->next;
	}
    }
  if (reverse == true)
    {
      Node *p = tail;
      while (p != nullptr)
	{
	  myVector.push_back (p->item);
	  p = p->prev;
	}
    }
  return myVector;
}

void
DoublyLinkedList::print (const char *msg, const vector < E > &vec)
{
  cout << msg << "   [ ";
  for (unsigned int i = 0; i < myVector.size (); i++)
    cout << vec[i] << " ";
  cout << "]" << endl;
  myVector.clear ();
}
