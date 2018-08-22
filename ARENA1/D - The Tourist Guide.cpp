#include<bits/stdc++.h>
#define FOR(i,b) for(int i =0 ; i< b;i++)
#define loop(i,a,b) for(int i =a ; i< b;i++)
#define fi first
#define se second
#define len(a) ((int)a.size())
#define pb push_back


using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int MAXN = 100+5, INF = 1e9;
vector<vii> Gr;
int p[MAXN],r[MAXN];


struct node{
  int u,v,w;
  node(int u1, int v1, int w1): u(u1) , v(v1), w(w1) {}
	bool operator <(const node &nodeTmp){
			return w > nodeTmp.w;
	}
};
vector<node> G;
int maxW[MAXN],vis[MAXN],n;
void makeSet(){
	FOR(fa,n+2){
			p[fa] = fa;
			r[fa] = 0;
	}
}
int find(int x){
	if(x!=p[x])p[x] = find(p[x]);
	return p[x];
}

void mst(int x, int y){
	int xR = find(x) , yR = find(y);
	if(r[xR]<r[yR]){
		p[xR] = yR;
	}else{
    p[yR] = xR;
    if(r[xR]==r[yR])r[xR]++;
	}
}


void bfs(int src){
	memset(vis,0,sizeof vis);
	FOR(i,n+3)maxW[i] = INF;
	vis[src] = 1;
	queue<int> q;
	q.push(src);
	vis[src] = 1;
	while(!q.empty()){
		int u = q.front();q.pop();
		FOR(i,len(Gr[u])){

				ii  v = Gr[u][i];
				if(!vis[v.fi]){
						maxW[v.fi] = min(maxW[u],v.se);
						vis[v.fi] = 1;
						q.push(v.fi);
				}
		}
	}
}


int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int  m , q , u , v, w , flang = 0, ntc = 1;
	while(1){
			cin >> n >> m;
			if(n+m==0)break;
			Gr.clear();
			G.clear();
			flang = 1;
			FOR(i,m){
					cin >> u >> v >>w;
					w--;
					G.pb(node(u,v,w));
			}
			sort(G.begin(),G.end());
      Gr.assign(n+1,vii());
      makeSet();
			FOR(i,m){
          node e = G[i];
          if(find(e.u)!=find(e.v)){
						 mst(e.u, e.v);

						 Gr[e.u].pb(ii(e.v,e.w));
						 Gr[e.v].pb(ii(e.u,e.w));
          }
			}
			int src, tgt ;
			double pass;
			cin >> src >> tgt >> pass;
			//cerr << src << "  " << tgt << "  " << pass << endl;
			bfs(src);
			//cerr << maxW[tgt] << endl;
			cout <<  "Scenario #" << ntc++ << endl;
			cout << "Minimum Number of Trips = " << ceil(pass/maxW[tgt]) << endl;
			cout << endl;

	}
}
