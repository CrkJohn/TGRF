#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a ; i < b; i++)
#define pb push_back



using namespace std;
typedef vector<int> vi;
typedef vector<vi> Graph;

Graph AdjList;

vi dfs_num , dfs_low, dfs_parent , articulation_vertex;
int dfsNumberCounter  = 1, dfsRoot, rootChildren;

const int DFS_WHITE = -1;
 
void articulationPointAndBridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    int v = AdjList[u][j];
    if (dfs_num[v]==DFS_WHITE){ //tree edge
      dfs_parent[v] = u;
      if (u == dfsRoot) rootChildren++; // special case
      articulationPointAndBridge(v);
      if (dfs_low[v] >= dfs_num[u])articulation_vertex[u] = true;
      //if (dfs_low[v.first] > dfs_num[u]) // for bridgeprintf("Edge (%d, %d) is a bridge\n", u, v.first);
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
      // updated dfs_low[u]
    }else if (v != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}

int main(){
	int V,E; string u,v;
	map<string,int> ni;
	map<int,string> in;
	int cases = 1;
	int flang= 0;
	while(1){
		int ind = 1;
		cin >> V;
		if(!V)break;
		if(flang)puts("");		
		loop(i,0,V){
			cin >> u;
			in[ind] = u;
			ni[u] = ind++;
		}
		
		AdjList.clear();
		AdjList.assign(V+1,vi());
		cin >> E;
		loop(i,0,E){
			cin >> u >> v;
			AdjList[ni[u]].pb(ni[v]);
			AdjList[ni[v]].pb(ni[u]);
						
		}
		dfsNumberCounter = 0;
		dfs_num.assign(V+1, DFS_WHITE);
	  	dfs_low.assign(V+1, 0);
	  	dfs_parent.assign(V+1, 0);
	  	articulation_vertex.assign(V+1, 0);
	  	//articulation_vertex.assign(V+1, 0);
	  	//printf("Bridges:\n");
	  	for (int i = 0; i < V; i++)if (dfs_num[i] == DFS_WHITE) {
	      		dfsRoot = i; rootChildren = 0;
	      		articulationPointAndBridge(i);
	      		articulation_vertex[dfsRoot]=(rootChildren>1);
	    }
	    
		//sort(articulation_vertex.begin(),articulation_vertex.end());
	    int mycont = count (articulation_vertex.begin(), articulation_vertex.end(), 1);
		vector<string> vs;vs.clear();
	    
	    for (int i = 0; i <articulation_vertex.size(); i++)if(articulation_vertex[i])vs.pb(in[i]);
		sort(vs.begin(),vs.end());
		
	    printf("City map #%d: %d camera(s) found\n",cases++,mycont);
	  	for (int i = 0; i <vs.size(); i++){
	  		cout << vs[i] << endl;
		}
		flang = 1;
		
	}
	return 0;
}
