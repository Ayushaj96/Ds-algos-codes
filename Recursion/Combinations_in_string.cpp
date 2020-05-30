#include<iostream>
using namespace std;

void generateString(char *in, int m, char *out, int n)
{
    if(in[m] == '\0')
    {
        out[n] = '\0';
        cout<<out<<endl;
        return;
    }
    
    out[n] = in[m];
    out[n+1] = ' ';
    
    generateString(in,m+1,out,n+2); // tree recursion
    
    if(in[m + 1] != '\0')
    {
        generateString(in,m+1,out,n+1);
    }
}

int main()
{
    char in[100];
    cin>>in;
    
    char out[100];
    
    generateString(in,0,out,0);
    
    return 0;
}
