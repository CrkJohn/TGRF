#include<bits/stdc++.h>
#define FOR(i,b) for(int i =0 ; i< b;i++)
#define loop(i,a,b) for(int i =a ; i< b;i++)
#define fi first
#define se second
#define len(a) ((int)a.size())
#define pb push_back
#define NEXT(a,b) ((a)%b)

using namespace std;


typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<vector<int> > vii;
typedef vector<int> vi;
typedef long long i64;

const int MAX_N = 100+5, INF = 1e9;
int n, m;
ii p[MAX_N][MAX_N];
//const int IINF = ii(-1,-1);
const int dx[] = {-1,-1,0,0,1,1},  dy[] = {0,1,-1,1,-1,0};

short int let(const int &i, const int &j){
		return 0<=i && i<n && 0<=j && j<m;
}


int color[MAX_N][MAX_N],blo[MAX_N][MAX_N];
char G[MAX_N][MAX_N];

void bloqueo(ii src){
		blo[src.fi][src.se]=2;
		FOR(i,6){
			int h = src.fi + dx[i] , k =  src.se + dy[i];
      if(let(h,k) && blo[h][k]!=2 && (G[h][k]=='I' || G[h][k]=='*')){
					bloqueo(ii(h,k));
      }
		}
		return;
}


int bfs(const ii &s){
		queue<ii> q;
		q.push(s);
		color[s.fi][s.se] = 0;
		bool isBipartite = true;
		while (!q.empty() & isBipartite){
				ii u = q.front(); q.pop();
				FOR(i,6){
					int h = u.fi + dx[i] , k =  u.se + dy[i];
					if(!let(h,k) || G[h][k]=='.')continue;
					if(G[h][k]=='I')color[h][k] = 0;
					if(blo[u.fi][u.se]==2)bloqueo(ii(u.fi,u.se));
					if (color[h][k] == INF) {
							color[h][k] = 1 - color[u.fi][u.se];
							q.push(ii(h,k));
					}else if (color[h][k] == color[u.fi][u.se] || blo[h][k]==2){
							bloqueo(ii(u.fi,u.se));
					}
			}
	}
}

void pprint(){
	FOR(i,n){
		FOR(j,m){
			cerr << G[i][j];
		}
		cerr <<endl;
	}
	cerr << endl;
}

int main(){
			//freopen("in.txt","r",stdin);
			//freopen("out.txt","w",stdout);
			ios::sync_with_stdio(0);
			cin.tie(0);
			while(1){
        cin >> n >> m;
        if(n+m==0)break;
				FOR(i,n)cin >> G[i];
				//pprint();

				FOR(i,n)FOR(j,m){
					color[i][j] = INF;
					blo[i][j] = 0;
					p[i][j] = ii(-1,-1);
				}

				FOR(i,n)FOR(j,m)if(G[i][j]=='I')bfs(ii(i,j));
				cout << endl;
				FOR(i,n){FOR(j,m){
            if(blo[i][j]==2)cout << 'B';
            else if(color[i][j]==0) cout << '(';
            else if(color[i][j]==1)cout << ')';
            else if(G[i][j]=='*')cout << 'F' ;
						else {
							cout << '.';
						}
						//cout << color[i][j] << ' ' ;
					}
					cout << endl;
				}
			}
	return 0;
}
