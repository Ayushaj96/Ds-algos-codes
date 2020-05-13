#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Templates + Comparator + iterator 
template<class ForwardIterator, class T, class Compare>
ForwardIterator search( ForwardIterator start, ForwardIterator end, T key, Compare cmp){
	
	while(start != end){
		if(cmp(*start,key))
			return start;
		
		start++;	
	}
	
	return end;
}

class Book{
	public:
		string name;
		int price;
		
		
		Book(string name, int price){
			this->name = name;
			this->price = price;
		}
};

class BookCompare{
	
	public:
		bool operator()(Book b1, Book b2){
			if(b1.name == b2.name)
				return true; 
				
			return false;	
		}
};

int main(){
	
	Book b1("C++", 100);
	Book b2("Golang", 120);
	Book b3("java", 130);
	
	list<Book> l;
	
	l.push_back(b1);
	l.push_back(b2);
	l.push_back(b3);
	
	Book bookTofind("C+", 120);
	BookCompare cmp;
	
	auto it = search(l.begin(), l.end(), bookTofind, cmp );
	if(it == l.end()){
		cout<<"Book not present";
	}
	else{
		cout<<"Book Found"<<endl;
	}
	
	return 0;
}
