
#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i<b; i++)
#define FOR(i,b) for(int i = 0; i<b; i++)
#define fi first
#define se second
#define pb push_back


using namespace std;
typedef pair<int,int> ii;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef long long i64;

const int MAX_N = 1150 , INF = 1e9;

char  G[MAX_N][MAX_N];
int john[MAX_N][MAX_N], fire[MAX_N][MAX_N],n,m;
const int dx[] = {-1,1,0,0} , dy[] = {0,0,-1,1};

short int let(const int &i, const int &j){
	return 0<=i && i<n && 0<=j && j<m;
}

void bfsFire(queue<ii> q1){
	queue<ii> q = q1;
  while(!q.empty()){
			 ii u = q.front(); q.pop();
       FOR(i,4){
					int h = u.fi + dx[i] , k = u.se + dy[i];
					if(!let(h,k) || G[h][k]=='#')continue;
          if(fire[h][k]==0){
						fire[h][k] = fire[u.fi][u.se] + 1;
						q.push(ii(h,k));
          }
       }
  }
	return;
}

int bfsJohn(const ii src){
	queue<ii> q;
	q.push(src);
	john[src.fi][src.se] = 1;
	while(!q.empty()){
			ii u = q.front(); q.pop();
			if(u.fi == 0 || u.fi == n-1 ||  u.se == m-1  || u.se ==0)return john[u.fi][u.se];
			FOR(i,4){
          int h = u.fi + dx[i] , k = u.se + dy[i];
          if(!let(h,k) || G[h][k]=='#'|| john[h][k]!=0)continue;
          if(fire[h][k]>john[u.fi][u.se]+1 || fire[h][k]==0){
						john[h][k] = john[u.fi][u.se] + 1;
						q.push(ii(h,k));
          }
			}
	}
	return -1;
}

void pprintF(){
	FOR(i,n){
		FOR(j,m){
			if(fire[i][j]== INF)cerr <<  '.';
			else  cerr <<  fire[i][j];

		}
		cerr << endl;
	}
	cerr << endl;
}


void pprintJ(){
	FOR(i,n){
		FOR(j,m){
			if (john[i][j]== INF) cerr << '.' ;
			else cerr <<  john[i][j];
		}
		cerr << endl;
	}
	cerr << endl;
}


int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ntc;
	string str;
	cin >> ntc;
	while(ntc--){
			ii srcF,srcJ;
			cin >> n >> m;
			queue<ii> q;
			FOR(i,n)FOR(j,m)fire[i][j] = 0;
			FOR(i,n)FOR(j,m)john[i][j] = 0;
			FOR(i,n){
					cin >> G[i];
					FOR(j,m){
							if(G[i][j]=='J')srcJ = ii(i,j);
							if(G[i][j]=='F'){
								q.push(ii(i,j));
								fire[i][j] =1;
							}
					}
			}
      bfsFire(q);
      int minimun = bfsJohn(srcJ);
      if(minimun==-1)cout << "IMPOSSIBLE" << endl;
			else cout << minimun << endl;
	}
	return 0;
}
