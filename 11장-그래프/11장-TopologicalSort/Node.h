#pragma once
#include <stdio.h>

class Node
{
protected:
	int		id;		
	Node*	link;	
public:
	Node( int i, Node *l=NULL ) : id(i), link(l) { }
	~Node(void) { 
		if( link != NULL )
			delete link;
	}
	int	  getId()			{ return id; }
	Node* getLink()			{ return link; }
	void setLink(Node* l)	{ link = l; }
};

