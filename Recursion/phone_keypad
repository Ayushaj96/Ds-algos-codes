//using string

#include <iostream>
#include <cstring>
using namespace std;

string keypad[10] = { {""},{""},{"ABC"},{"DEF"},{"GHI"},{"JKL"},{"MNO"},{"PQRS"},{"TUV"},{"WXYZ"}};

void printKeypadString(string in, string out)
{
	if(in.length() == 0)
	{
		cout<<out<<endl;
		return;
	}
	
	int digit = in[0] - '0';
    string key = keypad[digit];
	for( int k = 0; k < key.length(); k++)
	{
		char ch = key[k];
		printKeypadString(in.substr(1), out + ch);
	}
}

int main()
{
	string str;
	cin>>str;
	
	printKeypadString(str,"");
}

//*********************************
// using char array

#include <iostream>
using namespace std;

char keypad[][10] = { "","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void printKeypadString(char *in, int inlen, char *out, int outlen)
{
	if(in[inlen] == '\0')
	{
		out[outlen] = '\0';
		cout<<out<<endl;
		return;
	}
	
	int digit = in[inlen] - '0';
	if(digit == 0 || digit == 1)
	{
		printKeypadString(in, inlen+1,out,outlen);
	}
	for( int k = 0; keypad[digit][k] != '\0'; k++)
	{
		out[outlen] = keypad[digit][k];
		printKeypadString(in,inlen + 1, out, outlen + 1);
	}
}

int main()
{
	char str[100];
	cin>>str;
	
	char out[100];
	printKeypadString(str,0,out,0);
}
