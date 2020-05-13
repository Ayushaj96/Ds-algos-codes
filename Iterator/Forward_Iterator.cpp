#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<class ForwardIterator, class T>
ForwardIterator search( ForwardIterator start, ForwardIterator end, T key){
	
	while(start != end){
		if(*start == key)
			return start;
		
		start++;	
	}
	
	return end;
}

int main(){
	
	list<int> l;
	
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	
	auto it = search(l.begin(), l.end(), 40 );
	if(it == l.end()){
		cout<<"element not present";
	}
	else{
		cout<<*it<<endl;
	}
	
	return 0;
}
