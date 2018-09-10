#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i<b; i++)
#define FOR(i,b) for(int i = 0; i<b; i++)
#define fi first
#define se second
#define pb push_back


using namespace std;
typedef pair<int,int> ii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vs> vvs;
typedef long long i64;

const int MAX_N = 1150 , INF = 1e9;

char  G[MAX_N][MAX_N];
int dis[MAX_N][MAX_N],n,m;
const int dx[] = {-1,1,0,0} , dy[] = {0,0,-1,1};

short int let(const int &i, const int &j){
	return 0<=i && i<n && 0<=j && j<m;
}


ii bfs1(ii src){
	queue<ii> q;
	q.push(src);
	dis[src.fi][src.se] = 0;
	int maxLon = 0;
	ii finalN = src;
	//cerr << src.fi << ": " << src.se << endl;
	while(!q.empty()){
		ii u = q.front(); q.pop();
		FOR(i,4){
				int h = u.fi +  dx[i], k = u.se + dy[i];
				if(!let(h,k) || G[h][k]=='#')continue;
				if(dis[h][k]==INF){
					dis[h][k] = dis[u.fi][u.se] + 1;
					q.push(ii(h,k));

					if(maxLon<dis[h][k]){
						//cerr << dis[h][k] << " "<< h << " " << k << endl;
						finalN = ii(h,k);
						maxLon= dis[h][k];
					}
				}
		}
	}
	//cerr << finalN.fi << " " << finalN.se << endl;
	return finalN;
}

int bfs2(ii src){
	queue<ii> q;
	q.push(src);
	dis[src.fi][src.se] = 0;
	int maxLon = 0;
	while(!q.empty()){
		ii u = q.front(); q.pop();
		FOR(i,4){
				int h = u.fi +  dx[i], k = u.se + dy[i];
				//cerr << h << ":" << k << endl;
				if(!let(h,k)|| G[h][k]=='#')continue;
				//cerr << h << "::" << k << endl;
				if(dis[h][k]==INF){
					dis[h][k] = dis[u.fi][u.se] + 1;
					q.push(ii(h,k));
					//cerr << maxLon  << " " << dis[h][k] <<" " << h << " " << k << endl;
					if(maxLon<dis[h][k]){
							maxLon = dis[h][k];

 					}
				}
		}
	}
	return maxLon;
}



int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ntc;
	ii src;
	cin >> ntc;
	while(ntc--){
			cin >> m>> n;
			int srcFlang = 1;
			FOR(i,n){
				cin >> G[i];
				if(srcFlang){
					FOR(j,m){
						if(G[i][j]=='.') {
							src = ii(i,j);
							srcFlang =0;
							break;
						}
					}
				}
			}
			FOR(i,n)FOR(j,m)dis[i][j] = INF;
			ii finalN = bfs1(src);
			//cerr << finalN.fi << "  " << finalN.se << endl;
			FOR(i,n)FOR(j,m)dis[i][j] = INF;
			int resultado = bfs2(finalN);
			cout << "Maximum rope length is " << resultado << "." << endl;
	}
	return 0;
}
