#include<bits/stdc++.h>
#define pb push_back
#define loop(i,a,b) for(int i = a; i<b;i++)
#define FOR(i,b) for(int i = 0; i<b;i++)
#define fi first
#define se second
#define len(a) ((int)a.size())
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> Graph;


const int N = 1000,INF = 1e9;
Graph G;
int p[N],r[N],dist[N];
int cost[N];


struct node{
	int u,v,dist;
	node(double u_, double v_, double dist_) : u(u_) , v(v_),dist(dist_) {};
	bool operator <( node e){
		return dist < e.dist;
	} 
};

vector<node> listEdges;

void makeSet(int n){
	FOR(i,n+1){
		p[i] = i;
		r[i] = 0;
		dist[i] = INF;
	}
	
}

int find(int i){
	if(i!=p[i]){
		p[i] = find(p[i]);
	}
	return p[i];
}



void Union(int x,int y){
		int xr = find(x) , yr = find(y);
		if (r[xr] < r[yr]){
			p[xr] = yr;
		}else{
			p[yr] = xr;
			if(r[yr]==r[xr])r[xr]++;
		}
}


/*double dist(pt a, pt b){
	return sqrt( (a.fi-b.fi)*(a.fi-b.fi) + (a.se-b.se)*(a.se-b.se));
}*/
int n;

int bfs(const int &src , const int &tgt){
	queue<int> q; 
	q.push(src);
	dist[src] = 0;
	int res[N];
	memset(res,0,sizeof res);
	res[src] = cost[src]; 
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(u==tgt){
			/*loop(i,1,n+1){
				cerr << res[i] << " " ;
			}
			cerr << endl;*/
			return res[u];
		}
		FOR(i,len(G[u])){
			ii v = G[u][i];
			if(dist[v.fi]==INF){
				dist[v.fi] = dist[u] + v.se;
				res[v.fi] = max(res[u],cost[v.fi]);
				q.push(v.fi);
			}
		}
	}
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(2);
	int cases = 1,f  = 0;
	int m , q ,u , v ,w,src,tgt;
	while(1){	
		cin >> n >> m >> q ;
		if(n+m+q==0)break;
		listEdges.clear();
		makeSet(n+1);
		G.assign(n+1,vii());
		FOR(i,n)cin >> cost[i+1];
		FOR(i,m){
			cin >> u >> v >> w;
			listEdges.pb(node(u,v,w));
		}
		if(f)cout<< endl;
		f=1;
		sort(listEdges.begin(),listEdges.end());
		double cst = 0;
		cout << "Case #"<<cases++ << endl;;
 		FOR(i,listEdges.size()){
 			node e = listEdges[i];
 			if(find(e.u)!=find(e.v)){
 				G[e.u].pb(ii(e.v,e.dist));
 				G[e.v].pb(ii(e.u,e.dist));
 				Union(e.u,e.v);
	 		}	
		}
		FOR(i,q){	
			FOR(i,n)dist[i] = INF;
			cin >> src >> tgt;
			
			if(p[src]!=p[tgt]){
				cout  << "-1" << endl;
			}else{
				int r = bfs(src,tgt);
				cout << r+dist[tgt] << endl;
			}
		}
		 
	}
	
}
