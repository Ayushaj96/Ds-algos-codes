
#include<iostream>
#include<cstdlib>
using namespace std;
 
int main(int argc, char *argv[]) 
{
    int a, b, c;
 
    
    a = atoi(argv[1]); 
    b = atoi(argv[2]);
    c = atoi(argv[3]);
 
    
 
    
        if (a > b && a > c)             
            cout<<"largest"<<a;
     
        else if (b > c && b > a) 
            cout<<"largest"<<b;
 		else
		            cout<<"largest"<<c;
 	
    
    return 0;
}
