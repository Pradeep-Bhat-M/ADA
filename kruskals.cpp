#include<bits/stdc++.h>
using namespace std;

struct node {
	int parent;
	int rank;
};
struct Edge {
	int src;
	int dst;
	int wt;
};

vector<node> dsuf;
vector<Edge> mst;

int find(int v)
{
	if(dsuf[v].parent == -1)
		return v;
	return dsuf[v].parent = find(dsuf[v].parent);	//Path Compression
}

void union_op(int fromP,int toP)
{
	if(dsuf[fromP].rank > dsuf[toP].rank)
		dsuf[toP].parent = fromP;
	else if(dsuf[fromP].rank < dsuf[toP].rank)	
		dsuf[fromP].parent = toP;
	else
	{
		dsuf[fromP].parent = toP;
		dsuf[toP].rank += 1;		//Increase rank of parent
	}
}

bool comparator(Edge a,Edge b)
{
	return a.wt < b.wt;
}

void Kruskals(vector<Edge>& edge_List,int V,int E)
{
	//cout<<"edge_List before sort\n";
	//printEdgeList(edge_List);
	sort(edge_List.begin(), edge_List.end(), comparator);
	//cout<<"edge_List after sort\n";
	//printEdgeList(edge_List);

	int i = 0, j = 0;
	while(i < V-1 && j < E)
	{
		int fromP = find(edge_List[j].src);	// absolute parent of subset
		int toP = find(edge_List[j].dst);
		
		if(fromP == toP)
		{	
            j++;	
            continue;	
        }

		union_op(fromP, toP);	//UNION of 2 sets

		mst.push_back(edge_List[j]);
		i++;
	}
}

void display(vector<Edge>& mst)
{
    int sum = 0;
	cout<<"MST formed is\n";
	for(auto p: mst)
    {
        cout<<"src: "<<p.src<<"  dst: "<<p.dst<<"  wt: "<<p.wt<<"\n";
        sum = sum + p.wt;
    }
    cout << "\n Total weight of the MST = " << sum;
}

int main()
{
	int E;
	int V;	
	cout << "\n Enter V and E : ";
	cin >> V >> E;

	dsuf.resize(V);
	for(int i = 0; i < V; i++)
	{
		dsuf[i].parent = -1;
		dsuf[i].rank = 0;
	}
	cout << "\n Enter source destination weight respectively : \n";
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

	Kruskals(edge_List, V ,E);
	display(mst);
	
	return 0;
}