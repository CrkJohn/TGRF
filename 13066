#include<bits/stdc++.h>
#define FOR(i,b) for(int i = 0 ; i<b;i++)
#define loop(i,a,b) for(int i =a ; i<b;i++)
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

using namespace std;
typedef vector<int> vi;

const int maxN=102 , INF = 1e9;
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
		bitset<2*maxN+1> visited;
		visited.set(s);
		queue<int> q;
		q.push(s);
		p.assign(2*maxN+1, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u==t)break;
			//for (int i = 0; i < (int) AdjList[u].size(); i++) {
            FOR(i,2*N+1){
				if (res[u][i] > 0 && !visited.test(i) && AdjList[u][i]) {
                    cerr << "ENTRE\n";
					visited.set(i);
					q.push(i);
					p[i] = u;
				}
			}
		}
		augment(t, INF);
		if (f == 0)
			break;
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
        FOR(j,N){
            AdjList[i+1][j+N+1] = 1;
            res[i+1][j+N+1] = 1;
        }
    }

    FOR(i,2*N+1){
        cerr << "Node " << i << " : ";
        FOR(j,2*N+2){
            //cerr << j <<"-";
            if(AdjList[i][j]){
                cerr << j<< " ";
            }
        }
        cerr << endl;

    }
    s = x0;
    t = y0;
    EdmondKarps();
    cerr << mf << endl;
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
    int i,j;
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin >>N>>M;
        if(cin.eof())break;
        memset(graph,0,sizeof graph);
        memset(vis,0,sizeof vis);
        FOR(i,M){
            cin >> i >> j;
            graph[i][j] = 1;
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
        /*FOR(i,N){
            cerr << "Node " << i << " : ";
            FOR(j,N){
                if(graph[i][j]){
                    cerr << j<< " ";
                }
            }
            cerr << endl;
        }*/
        createBipartiteFlow();


    }
    return 0;
}
