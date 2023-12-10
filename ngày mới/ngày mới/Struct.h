#pragma once
#include "Stack_Queue.h"
#include <iostream>
using namespace std;

struct QueueAll
{
	Ref Q;
	Ref T;
	void Init()
	{
		Q = T = nullptr;
	}
	int Empty()
	{
		return !Q;
	}
	char Front()
	{
		if (Empty())
			return -1;
		return Q->key;
	}
	void enQueue(char k)
	{
		Ref p = getNode(k, Q);
		if (Empty())
			Q = T = p;
		else
		{
			T->next = p;
			T = p;
		}
	}
	void print()
	{
		Ref p = Q;
		while (p)
		{
			cout << p->key;
			p = p->next;
		}
	}
	char deQueue()
	{
		if (Empty())
			return -1;
		Ref p = Q;
		char k = p->key;
		if (Q == T)
		{
			Q = T = nullptr;
		}
		else
		{
			Q = Q->next;
			p->next = nullptr;
		}
		free(p);
		return k;
	}
};
struct StackAll
{
	Ref top;
	int Empty()
	{
		return !top;
	}
	void Init()
	{
		top = nullptr;
	}
	char Pop()
	{
		if (Empty())
			return -1;
		Ref p = top;
		char k = p->key;
		top = top->next;

		p->next = nullptr;

		free(p);
		return k;
	}
	void Push(char k)
	{
		Ref p = getNode(k, top);
		if (Empty())
			top = p;
		else
		{
			p->next = top;
			top = p;
		}
	}
	char Front()
	{
		if (Empty())
			return -1;
		return top->key;
	}
	void print()
	{
		Ref p = top;
		while (p)
		{
			cout << p->key;
			p = p->next;
		}
	}
};
