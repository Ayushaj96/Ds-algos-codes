#include<bits/stdc++.h>
using namespace std;


int gcd(int a,int b)
{
	if(b==0)
		return a;
		
	else
	gcd(b,a%b);	
}
int gcd1(int a, int b)
{

	while (b) {
		int t = b;

		b = a % b;
		a = t;
		cout<<a<<" ";
	}
  	return a;
}

int lcm(int a,int b)
{
	return a*b/gcd(a,b);
	
}

int main()
{
	int a,b;
	cin>>a>>b;
	
	cout<<gcd1(a,b)<<endl;
	//cout<<lcm(a,b);
	return 0;
}
