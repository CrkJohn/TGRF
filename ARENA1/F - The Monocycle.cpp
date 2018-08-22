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
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long i64;

const int MAXN = 100+5, INF = 1e9;
int N, M;
vector<vii> Gr;
vector<string> G;
short int vis[26][26][7][5];
const int dx[] = {-1,0,1,0} , dy[] = {0,1,0,-1};

struct node{
  int i,j,color,direccion, time;
		node(int i_ , int j_ , int color_, int direccion_ , int t): i(i_) , j(j_) , color(color_) ,
		direccion(direccion_) , time(t) {}
};
short int let(int i, int j){return 0<=i && i<N && 0<=j && j<M;}

int bfs(const ii src, const ii tgt){
	queue<node> q;
	q.push(node(src.fi,src.se,0,0,0));
	// 0 = N  ,  E  = 1 , S = 2 , W
	// 0 : verde 1 : NEGRO 2: ROJO 3 : AZUl 4  : BLANCO
	memset(vis,0,sizeof vis);
	while (!q.empty()){
				node e = q.front();q.pop();
				if(e.i == tgt.fi  && e.j == tgt.se && e.color == 0)return e.time;
				if(vis[e.i][e.j][e.color][e.direccion])continue;
				vis[e.i][e.j][e.color][e.direccion] = 1;
        node v = node(e.i+dx[e.direccion],e.j+dy[e.direccion],NEXT(e.color+1,5),e.direccion,e.time+1);
        //cerr << v.i << " " << v.j << endl;
        //cerr << let(v.i,v.j)  << "  : " <<  !vis[v.i][v.j][v.color][v.direccion] << endl;
        bool m = G[v.i][v.j] !=' #';
        //cerr <<  m << endl;
        if(let(v.i,v.j) && G[v.i][v.j]!='#' && !vis[v.i][v.j][v.color][v.direccion]){
						//cerr <<" Entre " << endl;
						q.push(v);
				}
				//cout << e.i << " " << e.j << " " << e.direccion << " " << e.color << " " << e.time << endl;
				q.push(node(e.i,e.j,e.color, NEXT(e.direccion+1,4),e.time+1));
				q.push(node(e.i,e.j,e.color,NEXT(e.direccion+3,4),e.time+1));
  }
	return INF;
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ntc = 1;
	int f = 0;
  while(1){
		G.clear();
		cin >> N >> M;
		if(N+M==0)break;
		ii src, tgt;
		if(f) cout << endl;
		f = 1;
		string str;
		FOR(i,N){
			cin >> str;
			G.push_back(str);
			FOR(j,M){
				if(G[i][j]=='S')src = ii(i,j);
				if(G[i][j]=='T')tgt = ii(i,j);
			}
		}
		int tmp  = bfs(src,tgt);
		//cout << tgt.fi << " " << tgt.se << endl;
		cout << "Case #"<<ntc++ <<endl;
		if(tmp==INF){
			cout <<"destination not reachable"<<endl;
		}else{
			cout << "minimum time = "<<tmp<<" sec"<<endl;
		}

  }
  return 0;
}
