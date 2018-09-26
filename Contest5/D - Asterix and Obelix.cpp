#include<bits/stdc++.h>
#define pb push_back
#define loop(i,a,b) for(int i = a; i<b;i++)
#define FOR(i,b) for(int i = 0; i<b;i++)
#define fi first
#define se second
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

using namespace std;

typedef pair<double,double> pt;
typedef pair<int,int> ii;
typedef vector<ii> vtup;
typedef vector<vtup> graph;
typedef long long large;


const int N = 1010,INF = 1e9;
int feast[N],maxFeast[N][N],flody[N][N],c;

void flodyW(){
			FOR(h,2){
					FOR(k,c){
                FOR(i,c){
                    FOR(j,c){
												if(flody[i][k]==INF && flody[k][j]==INF)continue;
												int wTemp = flody[i][k] + flody[k][j] + max(maxFeast[i][k], maxFeast[k][j]);
												if(flody[i][j] + maxFeast[i][j]>wTemp) {
                            flody[i][j] = flody[i][k] + flody[k][j];
                            maxFeast[i][j] = max(maxFeast[i][k],maxFeast[k][j]);
                        }
                    }
                }
            }
        }
}

int main(){
		lec();
    ios::sync_with_stdio(0);
		cin.tie(0);
    int r,q,ntc=1,f = 0;
    int u,v,w;
    while(1){
				cin >> c >> r >> q;
				if(c+r+q==0)break;
				if(f)cout << endl;
				f = 1;
        FOR(i,c)cin >> feast[i];
        FOR(i,c){
					FOR(j,c){
							maxFeast[i][j] = max(feast[i],feast[j]);
							flody[i][j] = ((i==j) ? 0 : INF);
					}
				}

        FOR(row,r) {
            cin >> u >> v >> w;
            --u, --v;
            flody[u][v] = w;
            flody[v][u] = w;
        }
				flodyW();
        cout << "Case #" << ntc++<<endl;
        while(q--) {
            cin >> u >> v;
            --u, --v;
            if(flody[u][v] == INF) cout << "-1" <<endl;
            else cout << flody[u][v] + maxFeast[u][v] <<endl;
        }
    }

    return 0;
}
