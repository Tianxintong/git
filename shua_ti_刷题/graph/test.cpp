#include<iostream>

using namespace std;
#include"./graph.h"

int main()
{
	Graph<char> gh;
	gh.InsertVertex('s');
	gh.InsertVertex('r');
	gh.InsertVertex('v');
	gh.InsertVertex('w');
	gh.InsertVertex('t');
	gh.InsertVertex('x');
	gh.InsertVertex('y');
	gh.InsertVertex('u');
	gh.InsertEdge('s','r');
	gh.InsertEdge('s','w');
	gh.InsertEdge('v','r');
	gh.InsertEdge('w','t');
	gh.InsertEdge('w','x');
	gh.InsertEdge('t','x');
	gh.InsertEdge('u','x');
	gh.InsertEdge('u','y');
	gh.InsertEdge('t','u');
	gh.InsertEdge('x','y');
	gh.ShowGraph();
	cout<<endl;
	gh.BFSTraverse();
	cout<<endl;
//	gh.ShowGraph();
//	cout<<endl;
	
	gh.DFSTraverse();

	cout<<endl;

	return 0;
}

