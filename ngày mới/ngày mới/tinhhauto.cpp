#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "Struct.h"

void Operator(char dau, StackAll& st)
{
	int a, b;
	if (st.Empty() == 0)         
	{                            
		a = st.Pop();
	}
	else
	{
		cout << "Du lieu khong hop le\n";
		Destroy(st.top);
		exit(0);
	}
	if (st.Empty() == 0)
	{
		b = st.Pop();
	}
	else
	{
		cout << "Du lieu khong hop le\n";
		Destroy(st.top);
		exit(0);
	}
	switch (dau)
	{
	case '+':
		st.Push(b+a);
		break;                       //Dùng để đổi toán tử thành phép tính
	case '-':
		st.Push(b - a);
		break;
	case '*':
		st.Push(b * a);
		break;
	case '/':
		st.Push(b / a); 
		break;
	default:
		cout << "Du lieu khong hop le";
		Destroy(st.top);
		exit(0);
		break;
	}
}
int calculate(string s)
{
	char* temp=new char[s.size()+1];
	if (!temp)
	{
		cout << "memory error\n";
		exit(0);
	}
	strcpy(temp,s.c_str());
	char* word=nullptr;
	int a,start=0;
	char dau;
	StackAll st;
	st.Init();
	while(word||start==0)
	{
		if (start == 0)
		{
			word = strtok(temp, " ");
			start = 1;
		}
		else
			word = strtok(nullptr, " ");
		if (!word)
			break;
		if (isdigit(word[0]))
		{
			sscanf(word, "%d", &a);
			st.Push(a);
		}
		else
		{
			sscanf(word, "%c", &dau);
			Operator(dau, st);
		}
	}
	delete[]temp;
	int result = st.Pop();
	Destroy(st.top);
	return result;
}