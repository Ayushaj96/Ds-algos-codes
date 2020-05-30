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
