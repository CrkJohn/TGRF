
#include<bits/stdc++.h>
#define FOR(i,b) for(int i = 0; i<b;i++)
#define loop(i,a,b) for(int i = a; i<b;i++)
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

vii G;
vi top;
bitset<27> vis;
int wn[27],d[27];

void topo(int u){
	vis[u] = 1;
	for(const int v : G[u]){
			if(!vis[v])topo(v);
	}
	top.pb(u);
}

const int INF = 1e9;
int maxVeU = -INF;

void longestPath(int u){
    //cerr << u << endl;
	for(const int v: G[u]){
		if(d[u]+wn[v]>d[v]){
			 d[v] = d[u] + wn[v];
			 maxVeU = max(maxVeU,d[v]);
			 longestPath(v);
		}

	}
	return;
}


int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ntc,wi;
	char src,tmp,c,f = 0;
	string line,noAdj;
	stringstream ss;
	cin >> ntc;
	cin.ignore();
	cin.ignore();
	G.assign(28,vi());
	while(ntc--){
            FOR(I,27)G[I].clear();
			ss.clear();
			memset(wn,-1,sizeof wn);
			if(f)cout << endl;
			f = 1;
			while(getline(cin,line) && line!=""){
					ss.clear();
					cerr << line << endl;
					ss << line;
					ss >> src;
					ss >> wi;
					wn[src-'A'] = wi;

					while(ss>>c){
                        G[src-'A'].pb(c-'A');
					}
			}
            vis.reset();
            top.clear();
			FOR(i,26){
			    if(G[i].size() && !vis[i]){
                    topo(i);
			    }
			}
			int lonPathTotal = -INF;
			reverse(top.begin(),top.end());
			//cerr << ntc << "Case " << endl;
            for(const int u : top){
                        cerr << u << endl;
						memset(d,0,sizeof d);
						d[u] = wn[u];
						maxVeU = -INF;
						longestPath(u);
						lonPathTotal = max(lonPathTotal,maxVeU);

					//cerr << u << endl;
            }
            cout << lonPathTotal << endl;
	}
	return 0;
}
