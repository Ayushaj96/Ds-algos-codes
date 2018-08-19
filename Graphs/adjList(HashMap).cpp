#include<iostream>
#include<map>
#include<list>
using namespace std;

template<typename T>
class Graph{
		
	map<T,list<T> > adjList;
	
	public:
		Graph(){
		}
		
		void addEdge(T u,T v,bool bidir=true)
		{
			adjList[u].push_back(v);
			if(bidir)
					adjList[v].push_back(u);

		}
		
		
		void print()
		{
			for(auto a:adjList)
			{
				cout<<a.first<<"->";
				
				for(auto j:a.second)
				{
					cout<<j<<",";
				}
			cout<<endl;		
			}
		}
};

int main()
{
	Graph<string> g;
	g.addEdge("Putin","Trump",false);
	g.addEdge("Putin","Modi",false);
	g.addEdge("Trump","Modi",true);
	
	g.print();
	
	Graph<int> g2;
	g2.addEdge(1,2);
	g2.addEdge(2,3);
	g2.addEdge(3,4,true);
	g2.print();
}
