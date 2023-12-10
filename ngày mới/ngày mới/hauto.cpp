#include "Struct.h"
#include "hauto.h"

string Hauto(string Str)
{
	string result;
	int a[128] = { 0 };
	a['+'] = 1; a['-'] = 1; a['*'] = 3; a['/'] = 3;//Dùng để sếp độ ưu tiên toán tử
	if (Str.empty())
	{
		return Str;
	}
	StackAll st;
	st.Init();
	Str += ')';						//Thêm vào chuỗi input '(' ở đầu và ')' ở cuối
	Str.insert(Str.begin(), '(');
	int i = 0;
	char c;
	for (i; i < Str.length(); i++)  //Duyệt chuỗi từ đầu đến cuối
	{
		c = Str[i];
		if (c == '(')  //Nếu là '(' push vào Stack
			st.Push(c);
		else if (isdigit(c))
		{						//là số thì nhập vào chuỗi output
			result += c;
			if (!isdigit(Str[i + 1])) //neu ky tu tiep theo khong phai so thi them 
			{                         //ky tu khoang trang vao
				result += ' ';
			}
		}
		else if (c == ')')
		{
			while (1)
			{
				c = st.Pop();		//Nếu gặp ')'
				result += c;		//Nhập hết stack vào chuỗi cho đến dấu ')'
				result += ' ';  //them ' ' moi khi them dau vao trong chuoi ket qua
				if (st.Front() == '(')
				{
					st.Pop();
					break;
				}
			}
		}
		else                        //trường hợp c là toán tử 
		{

			if (a[st.Front()] >= a[c]) //Độ ưu tiên của toán tử top Stack lớn hơn của 
			{							//c thì Pop, thêm top vào chuỗi, push(c)
				char sttop = st.Pop();
				result += sttop;
				result += ' ';  //them ' ' moi khi them dau vao trong chuoi ket qua
				st.Push(c);
			}
			else
				st.Push(c);		
		}
	}
	return result;
}

