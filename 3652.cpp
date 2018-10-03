#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i<b;i++)
#define loopI(i,a,b) for(int i = a; i<=b;i++)
#define FOR(i,b) for(int i = 0; i<b;i++)
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
#define fi first
#define se second

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> edge;
typedef long long large;

int cal[5][5] = {
		{7,6,5,6,7},
		{6,3,2,3,6},
		{5,2,0,2,5},
		{6,3,2,3,6},
		{7,6,5,6,7}};


const int dx[] = {-2,-1,0,1,2};
const int dy[] = {-2,-1,0,1,2};


const int N = 1010, INF = 1e9 ;
short int g[N][N];
large dis[N][N];
int r,c;


/*
 if (dis[u]+v.Y < dis[v.X]){
	      dis[v.X]= dis[u] + v.Y;
	      pq.push(ii(dis[v.X], v.X));
	}
*/
short int let(int i, int j){
	return 1<=i && i<=r && 1<=j && j<=c;
}

int dijkstra(ii src, ii tgt){
	priority_queue<edge, vector<edge>, greater<edge> > pq;
	loopI(i,1,r)loopI(j,1,c)dis[i][j]=INF; 
	dis[src.fi][src.se]=0;
	pq.push(edge(0,src));
	edge par;
	int d;ii u;
	while (!pq.empty()){
	  par=pq.top(); pq.pop();
	  d=par.fi; u=par.se;
	  //if (d>dis[u.fi][u.se]) continue;
	  if(tgt.fi==u.fi && tgt.se==u.se)break;
	  FOR(i,5){
	  	FOR(j,5){
	  		int h = u.fi + dx[i], k  = u.se + dy[j];
			if(let(h,k) && g[h][k]==0){
				int w = cal[i][j];
				if (dis[u.fi][u.se]+cal[i][j] < dis[h][k]){
				      dis[h][k]= dis[u.fi][u.se] + cal[i][j];
				      pq.push(edge(dis[h][k],ii(h,k)));
				}
			} 
		}
	  }
	}
	return dis[tgt.fi][tgt.se];
}


int main(){
	//lec();
	ios::sync_with_stdio(0);
	cin.tie(0);
	int est;
	int x,y,x1,y1;
	while(1){
		memset(g,0,sizeof g);
		cin >> r >> c;
		if(r+c==0)break;
		ii src,tgt;
		cin >> src.fi >> src.se; 
		cin >> tgt.fi >> tgt.se; 
		cin >> est;
	
		FOR(estan,est){
			cin >>  x >> y >> x1 >> y1;
			loopI(i,x,x1){
				loopI(j,y,y1){
					 g[i][j] = 1;
				}
			}	
		}
		if(src.fi == tgt.fi && src.se ==tgt.se)
			cout<< 0 << endl;
		else{
			large wMax = dijkstra(src,tgt);
			if(wMax == INF)cout << "impossible" << endl;
			else cout << wMax<< endl;
		}
	}
	return 0;
}
