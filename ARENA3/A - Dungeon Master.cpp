#include<bits/stdc++.h>
#define FOR(i,b) for(int i = 0; i<b;i++)
#define SZ 210
#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<string> vs; // aaaaa aaaa aaaa
typedef vector<vs> G;

int vis[SZ][SZ][SZ];
//Movimientos FloodFill 2D
int x[] = {0,0,1,-1,1,-1};
int y[] = {1,-1,0,0,1,-1};
//Movimientos 3D
int dx[] ={-1, 0,  0, 1,  0, 0};
int dy[] ={0 , 0,  0, 0, -1, 1};
int dz[] ={0 , 1, -1, 0,  0, 0};


int n,fil,col;


G graph;
int isLet(int i, int j , int k){

	//cin >> 	n >> fil >> col;z y x
 	return 0<=i && 0<=j && 0<=k && i<n && j<fil && k<col	;
}

int bfs(iii src){
	memset(vis,-1,sizeof(vis));
	//Escaped in 11 minute(s).
	//Trapped!
	queue<iii> q;
	vis[src.X.X][src.X.Y][src.Y] = 0;
	q.push(src);
	while (!q.empty()){
        iii u = q.front(); q.pop();
		//printf("u : (%d,%d,%d)\n",u.X.X ,u.X.Y,u.Y);

        if(graph[u.X.X][u.X.Y][u.Y]=='E')return vis[u.X.X][u.X.Y][u.Y];
		FOR(adj,6){
            int h = u.X.X + dz[adj];
            int k = u.X.Y + dx[adj];
            int l = u.Y	+ dy[adj];
		    if(isLet(h,k,l)	 && vis[h][k][l]==-1   && graph[h][k][l]!='#'){
				//printf("pos : (%d,%d,%d,%s) \n",h,k,l,graph[h][k].c_str());
				q.push( mp(mp(h,k),l)   );
				vis[h][k][l] = vis[u.X.X][u.X.Y][u.Y] + 1;
            }
		}
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	int ntc = 1;
	iii src;
	while(1){
		cin >> 	n >> fil >> col;
		if(!(n+fil+col))break;
		graph.clear();
		string nivel;
		vs tmp;
		FOR(k,n){
			 tmp.clear();
			 FOR(j,fil){
				cin >> nivel;
				FOR(i,col){
					if(nivel[i]=='S')src = mp(mp(k,j),i);
				}
				tmp.pb(nivel);
			 }
            graph.pb(tmp);
		}
		//printf("(%d,%d,%d)\n",src.X.X,src.X.Y,src.Y);
		int distance =  bfs(src);
        if(distance!=-1){
			printf("Escaped in %d minute(s).\n",distance);
        }else{
			puts("Trapped!");
        }
	}
	return 0;
}
