/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "DoublyLinkedList.h"


int
main ()
{
try
  {
  DoublyLinkedList mylist;
  mylist.add ("AA");
  mylist.add ("BB");
  mylist.add ("CC");
  mylist.add ("DD");
  mylist.add ("EE");

  mylist.toVector (false);
  mylist.print ("S2", mylist.myVector);
  mylist.toVector (true);
  mylist.print ("S3", mylist.myVector);

  mylist.add (0, "XX");
  mylist.add (3, "YY");
  mylist.add (7, "ZZ");

  mylist.toVector (false);
  mylist.print ("S5", mylist.myVector);
  mylist.toVector (true);
  mylist.print ("S6", mylist.myVector);

  DoublyLinkedList mylist2 = mylist;

  mylist2.toVector (false);
  mylist2.print ("S8", mylist2.myVector);

  mylist2.remove (0);
  mylist2.remove (2);
  mylist2.remove (5);

  mylist2.toVector (false);
  mylist2.print ("S10", mylist2.myVector);

  mylist2.reverse ();

  mylist2.toVector (false);
  mylist2.print ("S12", mylist2.myVector);

  mylist2.toVector (true);
  mylist2.print ("S13", mylist2.myVector);
}
  catch (const char *msg)
  {
    cout << msg << endl;
  }
  return 0;
}
