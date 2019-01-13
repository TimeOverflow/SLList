#include"SLList.h"
#include "SLList.cpp"

// test for github.
int main()
{
   SLList<int> l1(3, 2);
   l1.addToTail(1);
   l1.printAll();        //2 2 2 1

   l1.deleteIth(3);
   l1.printAll();        //2 2 2

   l1.addToTail(3);      //2 2 2 3
   l1.addToTail(4);      //2 2 2 3 4
   l1.addToHead(5);      //5 2 2 2 3 4
   l1.printAll();
   l1.deleteNode(2);     //5 3 4
   l1.printAll();
   l1.deleteNode(5);     //3 4
   l1.printAll();

   l1.addToHead(3);
   l1.addToHead(3);
   l1.addToHead(3);
   l1.printAll();       //3 3 3 3 4

   l1.deleteNode(3);
   l1.printAll();       //4

   l1.deleteNode(4);
   l1.printAll();      //empty list

   for (int i = 0; i < 10; i++)
      l1.addToTail(i);
   l1.printAll();         //0 1 2 3 4 5 6 7 8 9

   l1.deleteFromHead();
   l1.deleteFromTail();
   l1.printAll();         //1 2 3 4 5 6 7 8

   l1.reverse();
   l1.printAll();

   for (int i = 1; i < l1.getLength(); i++)
      l1.deleteIth(i);
   l1.printAll();         //8 6 4 2

   l1.reverse();
   l1.printAll();         //2 4 6 8
   l1.deleteIth(1);
   l1.printAll();         //2 6 8
   cout << endl << endl;

   SLList<int> l2(1,2);
   l2.printAll();
   l2.reverse();
   l2.printAll();

   l2.deleteIth(0);
   l2.printAll();

   l2.reverse();
   l2.printAll();

   l1.printAll();
   l2.printAll();

   l1.addToTail(10);


   l2.addToTail(1);
   l2.addToTail(3);
   l2.addToTail(9);
   l2.addToTail(9);
   //l2.addToTail(11);
   l2.addToTail(12);

   cout << "-----------------merge--------------------" << endl;
   cout << "List 1:" << endl;
   l1.printAll();
   cout << "List 2:" << endl;
   l2.printAll();
   //mergeTwoSortedList(l1, l2);
   cout << "Merged list:" << endl;              //failed
   //SLList<int> L = mergeTwoSortedList(l1, l2);
   SLList<int> L2;
   L2 = mergeTwoSortedList(l1, l2);
   //L.printAll();
   //cout << L.getLength() << endl;
   //L.reverse();
   L2.printAll();

   return 0;
}

