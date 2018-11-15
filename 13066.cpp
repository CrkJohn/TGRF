#include<bits/stdc++.h>
#define FOR(i,b) for(int i = 0 ; i<b;i++)
#define loop(i,a,b) for(int i =a ; i<b;i++)
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

using namespace std;
typedef vector<int> vi;

const int maxN=108, INF = 1e9;
int graph[maxN][maxN],vis[maxN],vis2[maxN],N,M,nodTop,AdjList[204][204],res[204][204],s,t;


int mf, f;
vi p;


void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	} else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

void EdmondKarps() {
	mf = 0;
	while (1) {
		f = 0;
		bitset<2*maxN+3> visited;
		visited.set(s);
		queue<int> q;
		q.push(s);
		p.assign(2*maxN+2, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u==t)break;
			//for (int i = 0; i < (int) AdjList[u].size(); i++) {
			FOR(i,2*N+2){
				if (res[u][i] > 0 && !visited.test(i) && AdjList[u][i]) {

						cerr << u << "->" << i<< endl;
						visited.set(i);
						q.push(i);
						p[i] = u;
				}
			}
		}
		augment(t, INF);

		//cerr << "Flow : "<< f << endl;
		if (f == 0)break;
		mf += f;
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
		FOR(i,2*N+1){
        cerr << "Node " << i << " : ";
        FOR(j,2*N+2){
            //cerr << j <<"-";
            if(AdjList[i][j]){
                cerr << "("<<j<< ","<< res[i][j] <<") ";
            }
        }
        cerr << endl;

    }
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


/*
4 5
0 1
0 2
0 3
1 2
2 3
4 5
1 0
1 2
2 0
2 3
3 0
5 6
1 0
2 1
2 3
3 0
3 4
4 0
5 7
0 3
0 4
1 4
2 0
2 1
2 4
3 4
2 1
0 1
3 3
0 1
0 2
1 2
5 7
0 1
0 2
0 3
0 4
1 4
2 4
3 4
6 8
1 0
2 0
3 2
4 1
4 2
5 0
5 3
5 4
5 7
0 4
1 4
2 0
2 1
2 3
2 4
3 4
2 1
1 0
4 4
0 3
1 0
1 2
2 0
4 4
0 1
0 2
1 3
2 1
6 8
0 1
2 5
3 0
3 2
3 4
3 5
4 1
5 1
4 4
0 1
0 2
1 2
3 0
3 3
1 0
2 0
2 1
4 5
0 1
0 2
0 3
1 3
2 3
2 1
0 1
6 9
1 0
1 4
2 0
3 0
4 0
5 0
5 1
5 2
5 3
2 1
1 0
5 6
0 1
1 2
3 0
3 1
3 4
4 2
5 7
0 3
1 3
1 4
2 3
4 0
4 2
4 3
4 5
0 3
1 0
1 2
1 3
2 3
3 3
1 0
1 2
2 0
2 1
1 0
4 5
0 2
1 0
1 2
1 3
3 2
5 6
0 1
1 2
3 0
3 4
4 1
4 2
4 4
0 2
1 0
1 3
3 2
4 4
0 3
1 0
1 2
2 3
6 8
0 3
1 0
1 2
1 4
1 5
2 3
4 3
5 3
4 5
0 3
1 0
2 0
2 1
2 3
6 9
0 5
1 0
1 3
1 4
2 5
3 0
3 2
3 5
4 5
3 3
0 2
1 0
1 2
2 1
0 1
5 7
0 1
2 0
2 1
2 3
3 1
4 1
4 2
3 3
0 1
0 2
2 1
2 1
1 0
2 1
0 1
6 8
0 1
2 1
3 1
3 2
4 0
4 3
4 5
5 1
2 1
0 1
6 8
0 3
1 2
1 4
1 5
2 4
4 0
4 5
5 3
5 6
0 3
1 0
1 2
1 4
2 3
4 2
2 1
1 0
4 4
0 2
1 2
3 0
3 1
3 3
0 2
1 0
1 2
6 8
0 1
1 5
3 2
4 0
4 1
4 2
4 3
5 2
3 3
0 1
0 2
1 2
2 1
0 1
3 3
0 1
2 0
2 1
3 3
0 2
1 0
1 2
3 3
______________________ Prueba _____________________________


5 7
0 3
1 2
2 0
4 0
4 1
4 2
4 3


*/
