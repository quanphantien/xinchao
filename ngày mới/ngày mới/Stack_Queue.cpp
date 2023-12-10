#include "Stack_Queue.h"
#include <iostream>
using namespace std;

struct Node;
void Destroy(Ref&top)
{
	Ref p;
	while (top)
	{
		p = top;
		top = top->next;
		free(p);
	}
}
Ref getNode(char k,Ref& top)
{
	Ref p = (Ref)malloc(sizeof(Node));
	if (!p)
	{
		cout << "Mem error!\n";
		Destroy(top);
		exit(0);
	}
	p->key = k;
	p->next = nullptr;
}


