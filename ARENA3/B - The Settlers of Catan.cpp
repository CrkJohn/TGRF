#include<bits/stdc++.h>
#define len(a) ((int)a.size())
#define loop(i,a,b) for(int i = a; i<b; i++)
#define FOR(i,b) for(int i = 0; i<b; i++)
#define pb push_back


using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e9, N = 27;
int depthMax  = -INF;
vvi G;

short int backTrac[N][N];

void dfs(const int u, int depth){
	 depthMax  = max(depth,depthMax);
	 for(const int v : G[u]){
			if(backTrac[u][v]==0){
				backTrac[u][v] = 1;
				backTrac[v][u] = 1;
				dfs(v,depth +1);
				backTrac[u][v] = 0;
				backTrac[v][u] = 0;
			}
	 }
	 return;
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,u,v;
  while(1){
		cin >> n >> m;
		if(n+m==0)break;
		memset(backTrac,0,sizeof backTrac);
		G.assign(n+1,vi());
		FOR(i,m){
			cin >> u >> v;
			G[u].pb(v);
			G[v].pb(u);
		}
		depthMax = -INF;
		FOR(i,n){
			dfs(i,0);

		}
    cout << depthMax << endl;
  }
	return 0;

}
