// #include<iostream>
// #include<queue>
// #include<functional>
// #include<vector>

#include<bits/stdc++.h>
using namespace std;

class Fruit
{
	public:
		int price;
		string name;
		
		Fruit(int a,string b)
		{
			price=a;
			name=b;
		}
};

class myCompare{
    public :
     bool operator ()(int a,int b){
         //cout<<"\nThe number is "<<a<<","<<b;
         return a<b; //for maxheap
         //a>b for minheap
     }
};

class mycompare{
	
	public:
		
		bool operator()(Fruit a,Fruit b)
		{
			//if price is equal then sort lexiographically
         //minheap based upon price and then name
         if(a.price==b.price){
             return a.name>b.name;
         }
         return a.price>b.price;
		}
	
};

int main()
{
	
	 Fruit f1(180,"Mango");
    Fruit f2(180,"Apple");
    Fruit f3(150,"Guave");
    
    priority_queue<Fruit,vector<Fruit>,mycompare> pq;
    pq.push(f1);
    pq.push(f2);
    pq.push(f3);

    while(!pq.empty()){
        Fruit f=pq.top();
        pq.pop();
        cout<<f.name<<endl;
        cout<<f.price<<endl<<endl;
    
}


int a[]={1,4,3,2,6,0,10,12};
    int n=sizeof(a)/sizeof(a[0]);
 
 priority_queue<int> pqmax;
 
    for(int i=0;i<n;i++){
        pqmax.push(a[i]);
    }
    cout<<"Maxheap \n";
    while(!pqmax.empty()){
        cout<<pqmax.top()<<" ";
        pqmax.pop();
    }
    
  priority_queue<int,vector<int>,greater<int> >  pqmax2; 
  
  for(int i=0;i<n;i++){
        pqmax2.push(a[i]);
    }
    
    cout<<"\nMinheap \n";
    while(!pqmax2.empty()){
        cout<<pqmax2.top()<<" ";
        pqmax2.pop();
    }
  
  priority_queue<int,vector<int>,myCompare >  pqmax3; 
  
  for(int i=0;i<n;i++){
        pqmax3.push(a[i]);
    }
    
    cout<<"\nMinheap \n";
    while(!pqmax3.empty()){
        cout<<pqmax3.top()<<" ";
        pqmax3.pop();
    }
  
   
return 0;	
}
