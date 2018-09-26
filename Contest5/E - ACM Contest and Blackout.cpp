#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i< b;i++)
#define FOR(i,b) for(int i = 0; i< b;i++)
#define pb push_back

using namespace std;

struct node{
	int u , v ,w, mst1 = 0;
  node(int u_ , int v_ , int w_) : u(u_) , v(v_) ,w(w_){}
  bool operator ==(const node &e1){
  	return u==e1.u && v==e1.v  && w==e1.w;
  }
};

bool cmp(node a, node b){ return a.w < b.w;}

typedef vector<node> vn;
typedef vector<vn> graph;

vn G;
const int MAXN = 105;

int p[MAXN],r[MAXN],componentes;


void createMST(int n){
	FOR(c,n){
		p[c] = c;
		r[c] = 0;
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
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ntc,N,M,u,v,w;
	cin >> ntc;
	FOR(ca,ntc){
		G.clear();
    cin >> N >> M;
    //G.assign(N+1,vn());
    FOR(edge,M){
				cin >> u >> v >> w;
				u--; v--;
				G.pb(node(u,v,w));
		}
		int MST1 = 0 ,MST2  = 1e9;
		sort(G.begin(),G.end(),cmp);
    //MST KRUKAL;
    createMST(N);
    vn vMST1;
    FOR(k,M){
				node e = G[k];
        if(findR(e.u)==findR(e.v))continue;
        unionFind(e.u,e.v);
        MST1+=e.w;
        componentes++;
				e.mst1 = 1;
				vMST1.pb(e);
    }
    cerr << componentes << endl;
    FOR(i,N-1){
    	createMST(N);
    	node eMST1 = vMST1[i];
    	//cerr << eMST1.u << " " << eMST1.v << " " << eMST1.w << endl;
    	int tmp = 0;
			FOR(j,M){
					node e = G[j];
					if(e==eMST1)continue;
					if(findR(e.u)==findR(e.v))continue;
					unionFind(e.u,e.v);
					tmp+=e.w;
			}
			if(tmp>=MST1)MST2 = min(MST2,tmp);
    }
    cout << MST1 << " " << MST2 << endl;
	}
	return 0;
}
