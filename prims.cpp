#include<bits/stdc++.h>
using namespace std;

struct node {
	bool known;
	int cost, path;
};
struct Edge {
	int src;
	int dst;
	int wt;
};

vector<node> mst;
vector<Edge> adjList;

bool comparator(Edge a,Edge b)
{
	return a.wt < b.wt;
}

void prims(vector<Edge>& edge_List,int V,int E)
{
	//cout<<"edge_List before sort\n";
	//printEdgeList(edge_List);
	sort(edge_List.begin(), edge_List.end(), comparator);
	//cout<<"edge_List after sort\n";
	//printEdgeList(edge_List);



}

void display(vector<node>& mst)
{
    // int sum = 0;
	// cout<<"MST formed is\n";
	// for(auto p: mst)
    // {
    //     cout<<"src: "<<p.src<<"  dst: "<<p.dst<<"  wt: "<<p.wt<<"\n";
    //     sum = sum + p.wt;
    // }
    // cout << "\n Total weight of the MST = " << sum;
}

int main()
{
	int E;	//No of edges
	int V;	//No of vertices (0 to V-1)
	cin >> E >> V;

	mst.resize(V);	//Mark all vertices as separate subsets with only 1 element
	for(int i = 0; i < V; i++)	//Mark all nodes as independent set
	{
		mst[i].known = false;
		mst[i].cost = INT_MAX;
	}

	vector<Edge> edge_List;	//Adjacency list
	Edge temp;
	for(int i=0; i < E; i++)
	{
		int from,to,wt;
		cin>>from>>to>>wt;
		temp.src = from;
		temp.dst = to;
		temp.wt = wt;
		edge_List.push_back(temp);
	}

	prims(edge_List, V ,E);
	display(mst);
	
	return 0;
}

//TIME COMPLEXITY: O(ElogE + ElogV)
//ElogE for sorting E edges in edge_list
//ElogV for applying FIND & UNION operations on E edges having V vertices