#include "Struct.h"
#include "hautologic.h"

char changeOperator(string s)
{
	char o;
	if(s == "and")
		o = '&';
	if (s == "or")
		o = '|';
	if (s == "not")
		o = '!';
	return o;
}
void insertOperator(char o,string& s)
{
	switch (o)
	{
	case '&':
		s+= "and ";
		break;
	case '|':
		s+="or ";
		break;
	case '!':
		s+= "not ";
	default:
		break;
	}
}
string Hautologic(string Str)
{
	string result;
	int a[128] = { 0 };
	a['&'] = 1; a['|'] = 1; a['!'] = 2;
	if (Str.empty())
	{
		return Str;
	}
	StackAll st;
	st.Init();
	Str += ')';
	Str.insert(Str.begin(), '(');
	int i = 0;
	char c;
	for (i; i < Str.length(); i++)
	{
		c = Str[i];
		if (c == '(')
			st.Push(c);
		else if (isalpha(c) && !isalpha(Str[i+1]))
		{
			result += c;
			result+=' ';
		}
		else if (c == ')')
		{
			while (1)
			{
				c = st.Pop();
				insertOperator(c,result);
				if (st.Front() == '(')
				{
					st.Pop();
					break;
				}
			}
		}
		else if(isalpha(c) && isalpha(Str[i + 1]))
		{
			string temp;
			while (isalpha(Str[i]))
				temp += Str[i++];
			c = changeOperator(temp);
			if (a[st.Front()] >= a[c])
			{
				insertOperator(st.Pop(), result);
				st.Push(c);
			}
			else
				st.Push(c);
		}
	}
	return result;
}

