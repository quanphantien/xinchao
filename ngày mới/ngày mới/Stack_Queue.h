#pragma once

struct Node
{
	char key;
	Node* next;
};
typedef struct Node* Ref;
void Destroy(Ref& top);
Ref getNode(char k, Ref& top);

