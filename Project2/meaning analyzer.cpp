#define _CRT_SECURE_NO_DEPRECATE
#include"header.h"                                      //check header file to see what's in header =ω=
ifstream file ("C:\\fileinput.txt");


void trans()				                            //rev.polandtype creation
{
	char str[max];                                      //save intrinsic expression
	memset(str, '\0', max * sizeof(char));
	char stack[max];                                    //it's just a stack……yep, just a stack
	char ch;
	int sum, i=0, j, t, k, top = 0;
	printf("*****************************************\n");
	printf("*choose input type*\n 1->typewritting\n 2->flie reading\n");
	printf("******************************************\n");
	printf("input：");
	cin >> k;

//	k = 2;
	if (k == 1)
	{
		printf("input your expression(end with '#' please XD):");
		i = 0;											//well, type ugh?
		do
		{
			i++;
			cin >> str[i];								//god damn VS13, scanf can't be used here……
														//scanf("%c",&str[i]);
		} while (str[i] != '#'&&i != max);
	}
	else
	{
		char c=' ';
		FILE *fp = nullptr;
		errno_t err = fopen_s(&fp, "D:\\fileinput.txt", "r");
		
//		fp = fopen("D:\\fileinput.txt", "r");
		if (err)
		{
			printf("oops, fileopen error!\n");
			system("pause");
			exit(0);
		}
		else
		{
			i++;
			while (1)
			{
				c = fgetc(fp);
				if ( c == EOF) break;
				str[i] = c;
				i++;
			}
		}
	}
	sum = i;
	t = 1; i = 1;
	ch = str[i]; i++;
	//
	while (ch != '#')
	{
		switch (ch)
		{
		case'(':/*判定为左括号*/
			top++; stack[top] = ch;
			break;
		case')':/*判定为右括号*/
			while (stack[top] != '(')
			{
				ex[t] = stack[top]; top--; t++;
			}
			top--;
			break;
		case'+':/*判定为加减号*/
		case'-':
			while (top != 0 && stack[top] != '(')
			{
				ex[t] = stack[top];
				top--;
				t++;
			}
			top++;
			stack[top] = ch;
			break;
		case'*':/*判定为乘除号*/
		case'/':
			while (stack[top] == '*' || stack[top] == '/')
			{
				ex[t] = stack[top];
				top--;
				t++;
			}
			top++;
			stack[top] = ch;
			break;
		case' ':break;
		default:
			while ((ch >= '0'&&ch <= '9') || ch == '.' || ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')))
			{/*判定为数字*/
				ex[t] = ch; t++;
				ch = str[i]; i++;
			}
			i--;
			ex[t] = ' '; t++;
		}
		ch = str[i]; i++;
	}
	while (top != 0)
	{
		ex[t] = stack[top];
		t++; top--;
	}
	ex[t] = ' ';
	string s = "";
	printf("\n\t原来表达式：");
	for (j = 1; j < sum; j++)
	{
		printf("%c", str[j]);
	}
	printf("\n\t逆波兰式：", ex);
	for (j = 1; j < t;)
	{
		s += ex[j];
		printf("%c", ex[j]);
		if (ex[j] == '+' || ex[j] == '-' || ex[j] == '*' || ex[j] == '/')
		{
			vect.push_back(s);
			s = "";
			j++;
			continue;
		}
		j++;
		if (ex[j] == ' ')
		{
			vect.push_back(s);
			j++;
			s = "";
			continue;
		}
	}

}
void quadraelement()
{
	stack<string> quad;
	int i = 0, j = 0;
	for (;;)
	{
		if (vect[i] != "+" && vect[i] != "-" && vect[i] != "*" && vect[i] != "/")
		{
			quad.push(vect[i]);
			i++;
		}
		else
		{
			cout << vect[i] << "\t" << quad.top() << "\t";
			quad.pop();
			cout << quad.top()<<"\t"<< t[j]<<endl;
			quad.pop();
			quad.push(t[j]);
			j++;
			i++;
		}
		if (i==vect.size()) break;
	}

}

int main()
{
	trans();
	system("pause");
	quadraelement();
	system("pause");
	return 0;
}
