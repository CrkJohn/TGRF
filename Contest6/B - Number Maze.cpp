#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a ; i <b;i++)
#define FOR(i,b) for(int i = 0; i <b;i++)
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
#define fi first
#define se second

using namespace std;
typedef pair<int,int> ii;
const int maxN = 1000, INF = 1e9;

int ntc,N,M;
int maze[maxN][maxN],dis[maxN][maxN];
const short int dx[] = {-1,1,0,0} , dy[] = {0,0,-1,1};

short int let(int i, int j){
		return 0<=i && i<N && 0<=j && j<M;
}

int dijkstra(){
	//11111111111100000000001111111111
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	FOR(i,N)FOR(j,M)dis[i][j]=INF;
	dis[0][0]=maze[0][0];
	pq.push(ii(maze[0][0], 0));
	ii par;
	while (!pq.empty()){
		par=pq.top(); pq.pop();
		int x = par.se >> 10, y = (par.se & 1023);
		if(x ==N-1 && y == M-1)return dis[N-1][M-1];
		if(par.fi>dis[x][y])continue;
		FOR(i,4){
			int h  = x + dx[i], k =  y + dy[i];
			if(!let(h,k))continue;
			if(dis[x][y] + maze[h][k] < dis[h][k]){
				dis[h][k] = dis[x][y] + maze[h][k];
				pq.push(ii(dis[h][k],((h|0)<<10)|k));
			}
		}
	}
}

int main(){
	lec();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> ntc;
	while(ntc--){
		cin >> N >> M;
		FOR(i,N){
				FOR(j,M){
						cin >> maze[i][j];
				}
		}
		cout <<  dijkstra() << endl;
	}
	return 0;
}
