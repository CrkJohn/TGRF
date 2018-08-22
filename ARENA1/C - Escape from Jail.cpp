#include<bits/stdc++.h>
#define FOR(i,b) for(int i = 0 ; i <  b; i++)
#define loop(i,a,b) for(int i = a ; i <  b; i++)
#define cls(a,b) memset(a,b,sizeof a)
#define fi first
#define se second
#define pb push_back
#define len(a) ((int)a.size())

using namespace std;
typedef vector<int> vi;
typedef long long i64;
typedef vector<vi> Graph;

Graph G;

const int MAX_N   = 100010;

int keyFound[MAX_N],keyHave[MAX_N],vis[MAX_N],ex[MAX_N];

void bfs(int x){
   queue<int> q;
   q.push(x);
   vis[x] = 1;
   while (!q.empty()){
        int u = q.front();q.pop();
        FOR(j,len(G[u])){
						int v = G[u][j];
						//cerr << u << " " <<  v << endl;
						//cerr << keyFound[v] << " " << vis[v] <<  endl;
            if(keyFound[v] && !vis[v]){
								//cerr << "Entre" << endl;
								if(keyHave[v]){
										keyFound[keyHave[v]]=1;
										// Si ya lo explore pero tenia llave me puedo
										// devolver por el path del padre y volver al nodo
										// que tenia bloqueado por llave
										if(ex[keyHave[v]])q.push(keyHave[v]);
								}
								q.push(v);
								vis[v] = 1;
            }else if(!keyFound[v]){
								ex[v] = 1;
            }
        }
   }
}


int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
  int  n , m , k, u , v;
  while(1){
		cin >> n >> k >> m;
		if(n==-1)break;
		G.clear();
		G.assign(n+2,vi());
		cls(vis,0);
		FOR(e,MAX_N)keyFound[e]=1;
		cls(keyHave,0);
		cls(ex,0);
//		FOR(i,10){
//			cerr << ex[i] << " " ;
//		}
//		cerr << endl;
		FOR(i,k){
			cin >>  u >> v;
			keyHave[u] = v;
			keyFound[v] = 0;
		}
    FOR(i,m){
			cin>> u >> v;
			G[u].pb(v);
			G[v].pb(u);
    }
    bfs(1);
    char r = (vis[n]) ? 'Y' : 'N';
    cout << r << endl;
  }
	return 0;
}
