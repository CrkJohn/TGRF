#include<bits/stdc++.h>
#define FOR(i,b) for(int i = 0 ; i<b;i++)
#define loop(i,a,b) for(int i =a ; i<b;i++)
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

using namespace std;
typedef vector<int> vi;

const int MAX_V=205, INF = 1e9;
int graph[MAX_V][MAX_V],vis[MAX_V],vis2[MAX_V],N,M,nodTop,AdjList[204][204];

int res[205][205], mf, f, s, t;                          // global variables
vi p;

void augment(int v, int minEdge) {     // traverse BFS spanning tree from s to t
  if (v == s) { f = minEdge; return; }  // record minEdge in a global variable f
  else if (p[v] != -1) {
			augment(p[v], min(minEdge, res[p[v]][v])); // recursive
			res[p[v]][v] -= f; res[v][p[v]] += f; }       // update
}


void EdmondKarps() {
	mf = 0;
  while (1) {
		f = 0;
    vi dist(MAX_V, INF);
		dist[s] = 0;
		queue<int> q;
		q.push(s);
    p.assign(MAX_V, -1);           // record the BFS spanning tree, from s to t!
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break;
      for (int v = 0; v < 2*N+2; v++)
        if (res[u][v] > 0 && dist[v] == INF)
          dist[v] = dist[u] + 1, q.push(v), p[v] = u;
    }
    augment(t, INF);     // find the min edge weight `f' along this path, if any
    if (f == 0) break;      // we cannot send any more flow (`f' = 0), terminate
    mf += f;                 // we can still send a flow, increase the max flow!
  }
}




void createBipartiteFlow(){
    int x0 = 0 , y0=2*N+1;
    loop(i,1,N+1){
        AdjList[x0][i] = 1; // {x0,xi}
        AdjList[N+i][y0] = 1; // {yi , y0}
        res[x0][i] = 1;
        res[N+i][y0] = 1;
    }

    FOR(i,N){
        FOR(j,N)if(graph[i][j]){
            AdjList[i+1][j+N+1] = 1;
            res[i+1][j+N+1] = 1;
        }
    }
		/*FOR(i,2*N+1){
        cerr << "Node " << i << " : ";
        FOR(j,2*N+2){
            //cerr << j <<"-";
            if(AdjList[i][j]){
                cerr << "("<<j<< ","<< res[i][j] <<") ";
            }
        }
        cerr << endl;

    }*/
    s = x0;
    t = y0;
    EdmondKarps();
    cerr << mf << endl;
    cout << N-mf << endl;
}


void dfs(const int u){
    vis[u] = 1;
    FOR(i,N){
        if(graph[u][i] && !vis[i]){
            graph[nodTop][i] = 1;
            dfs(i);
        }
    }
}



int main(){
    lec();
    int i1,j1;
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin >>N>>M;
        /*if(M<10){
						cout << N << " " << M << endl;
				}*/
        if(cin.eof())break;
        memset(graph,0,sizeof graph);
        memset(vis,0,sizeof vis);
        memset(AdjList,0,sizeof vis);
        memset(res,0,sizeof res);
        FOR(i,M){
            cin >> i1 >> j1;
						/*if(M<10){
							cout << i1 << " " << j1<< endl;
						}*/
            graph[i1][j1] = 1;
        }
        memset(vis2,0,sizeof vis2);
        FOR(i,N){
            nodTop = i;
            memset(vis,0,sizeof vis);
            if(!vis2[i]){
                dfs(i);
                vis2[i] = 1;
            }
        }
        createBipartiteFlow();
    }
    return 0;
}
