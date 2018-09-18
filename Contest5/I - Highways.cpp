#include<bits/stdc++.h>
#define FOR(i,b) for (int i=0; i<b; i++)
#define loop(i,a,b) for (int i=a; i<b; i++)
#define len(a) ((int)a.size())
#define fi first
#define se second
#define pb push_back


using namespace std;

typedef vector<int> vi;
typedef vector<vi> graph;
typedef pair<double,double> dd;

const  int N  = 500000 ,INF = 1e9;
int componentes;
int dis[N] , p[N], r[N];

graph G;


double dist(dd p1, dd p2) {
    return sqrt(((p1.fi-p2.fi)*(p1.fi-p2.fi) ) + ((p1.se-p2.se)*(p1.se-p2.se)));
}

struct node{
	int u,v;
	double c;
	node(int x, int y,double d): u(x),v(y) ,c(d){};
	bool operator <(const node &e){
		return c<e.c;
	}
};

void createMST(int n){
	//cerr << n << endl;
	FOR(c,n){
		p[c] = c;
		r[c] = 0;
		//cerr<< c << endl;
	}
	componentes = 0;
}

int findR(int x){
	if(x!=p[x])p[x]=findR(p[x]);
	return p[x];
}

void unionFind(int x, int y){
		int xRaiz = findR(x);
		int yRaiz = findR(y);
		if(xRaiz == yRaiz)return;
		if (r[xRaiz] < r[yRaiz]){
				p[xRaiz] = yRaiz;
		}else{
				p[yRaiz] = xRaiz;
        if(r[xRaiz]==r[yRaiz])r[xRaiz]++;
		}
}


int main() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string lec;
	stringstream ss;
	double v,t,d;
	double x,y;
	vector<dd> pts;
	int ntc,n,m;
	cin >> ntc;
	cout << fixed;
	cout.precision(2);
	int f = 0;
    while (ntc--){
			cin >> n;
			pts.clear();
			FOR(i,n){
				cin >> x >> y;
    			pts.push_back(dd(x,y));
			}
			if(f)cout << endl;
			f = 1;
			vector<node> adjList;
			FOR(i,n){
				loop(j,i+1,n){
					adjList.pb(node(i+1,j+1,dist(pts[i],pts[j])));
				}
			}

			cerr << "Good" << endl;
			createMST(adjList.size());
			cin >> m;
			int u ,v ;

			FOR(i,m){
				cin >> u >> v;
				unionFind(u,v);
				componentes++;
			}
			int lon = adjList.size();
			if(componentes==n-1)cout << "No new highways need" << endl;
			else{
				sort(adjList.begin(),adjList.end());
				vector<pair<int,int> > result;
				int tmpLON =0;
				FOR(i,lon){
					node e = adjList[i];
					if(findR(e.u)!=findR(e.v)){
						unionFind(e.u,e.v);
						result.pb( make_pair(min(e.u,e.v), max(e.u,e.v) ));
						cout  << e.u << " " << e.v << endl;
						tmpLON++;
						componentes++;
					}
					if(componentes==n-1)break;
				}
				
			}
    }
}
/*

*/
