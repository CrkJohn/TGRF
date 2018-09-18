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
typedef pair<int,int> ii;

const int N = 1000;
int p[755], r[755];
struct node{
    int u, v, c;
    node(int x, int y,int d): u(x),v(y) ,c(d){};

};

bool cmp(const node &e,const node &e1){
		 return e.c < e1.c;
}

void createMST(int n){
	FOR(c,n){
		p[c] = c;
		r[c] = 0;
	}
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


int main(){
		//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
		ios::sync_with_stdio(0);
		cin.tie(0);
    int ntc, n, m;
    vector<ii> pts;
    int x, y,u,v;
		cin >> ntc;
		int f = 0;
    while(ntc--) {
        cin >> n;
        pts.clear();
        FOR(i,n){
						cin >> x >> y;
						pts.pb(ii(x,y));
        }

        if(f)cout<<endl;
        f = 1;
        createMST(n+5);
        cin >> m;
        int componentes = 0;
        while(m--) {
						cin >> u >> v;
            if(findR(u)!=findR(v)){
								unionFind(u,v);
								componentes++;
            }
        }
        if(componentes == n-1) {
            cout <<"No new highways need"<< endl;
        } else {
						vector<node> adjList;
            FOR(i,n) {
                loop(j,i+1,n){
										int dist =  (pts[i].fi-pts[j].fi)*(pts[i].fi-pts[j].fi)+(pts[i].se-pts[j].se)*(pts[i].se-pts[j].se);
										adjList.pb(node(i+1,j+1,dist));
                }
            }
            sort(adjList.begin(),adjList.end(),cmp);
            int lenAdj = adjList.size();
            FOR(i,lenAdj) {
								int h = adjList[i].u , k = adjList[i].v;
                if(findR(h)!=findR(k)) {
										unionFind(h,k);
										cout << h <<" "<< k<< endl;
                }
            }
        }
    }
    return 0;
}
