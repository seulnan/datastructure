#include "CircularList.h"
void main()
{
	CircularList	list;

	list.insert( 0, new Node(10) );	
	list.display("List(i1)");
	list.insert( 0, new Node(20) );
	list.display("List(i2)");
	list.insert( 1, new Node(30) );
	list.display("List(i3)");
	list.insert( 0, new Node(40) );
	list.display("List(i4)");
	list.insert( 2, new Node(50) );
	list.display("List(Àü)");

	list.remove(2);
	list.display("List(d2)");
	list.remove(1);
	list.display("List(d1)");
	list.clear();
	list.display("List(³¡)");
}

