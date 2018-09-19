#include<bits/stdc++.h>
#define FOR(i,b) for (int i=0; i<b; i++)
#define FORI(i,b) for (int i=0; i<=b; i++)
#define loop(i,a,b) for (int i=a; i<b; i++)
#define len(a) ((int)a.size())
#define fi first
#define se second
#define pb push_back
#define lectura() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)


using namespace std;

typedef pair<int,int> ii;
typedef pair<double,int> di;
typedef vector<di> vdi;
typedef vector<vdi> graph;

graph G;
const double wa = 10.0/ 60.0 * 1000.0, tr  = 40.0/ 60.0 * 1000.0;
const int N = 210;

double dist(ii p,ii p2){
    return sqrt((p.fi-p2.fi)*(p.fi-p2.fi) + (p.se-p2.se)*(p.se-p2.se));
}

double dijsktra(int s, int t){
    double cost[N];
    FOR(i,N)cost[i] = 1e9;
    priority_queue<di, vector<di>, greater<di> > pq;
    cost[s]=0;
    pq.push(ii(0, s));
    di par;
    double d;int u;
    while(!pq.empty()){
      par=pq.top(); pq.pop();
      d=par.fi;
      u=par.se;
      if (d>cost[u])continue;
      FOR(j,len(G[u])){
        di v=G[u][j];
        if (cost[u]+v.fi < cost[v.se]){
          cost[v.se]= cost[u] + v.fi;
          pq.push(di(cost[v.se], v.se));
        }
      }
    }
    return cost[t];
}



int main(){
    //lectura();
	ios::sync_with_stdio(0);
	cin.tie(0);
	stringstream ss;
	string str;
	int ntc,srcx,srcy,tgtx,tgty,nodes;
	double distance;
	cin >>  ntc;
	getline(cin,str);
	getline(cin,str);
	vector<ii> pts;
	cout<< fixed;
    short int ft = 0;
	cout.precision(0);
	while(ntc--){
        if(ft)cout << endl;
        ft =1;
        getline(cin,str);
        pts.clear();
        G.assign(N,vdi());
        ss.clear();
        ss << str;
        ss >> srcx >> srcy >> tgtx >> tgty;
        pts.pb(ii(srcx,srcy));
        pts.pb(ii(tgtx,tgty));
        distance = dist(pts[0],pts[1])/wa;
        G[0].pb(di(distance,1));
        G[1].pb(di(distance,0));
        nodes = 2;
        while(1){
            getline(cin,str);
            if(str=="")break;
            ss.clear();
            ss << str;
            int flang = 0,sup,r=0;
            while(ss >> srcx >> srcy){
                    if(srcx<0)break;
                    pts.pb(ii(srcx,srcy));
                    sup = nodes - 2;
                    if(!flang)sup = nodes-1;
                    else{
                        ii  u = pts[nodes] , v = pts[nodes-1];
                        distance = dist(u,v)/tr;
                        G[nodes].pb(di(distance,nodes-1));
                        G[nodes-1].pb(di(distance,nodes));
                    }
                    flang = 1;
                    FORI(i,sup){
                        ii u = pts[nodes], v = pts[i];
                        distance = dist(u,v)/wa;
                        G[i].pb(di(distance,nodes));
                        G[nodes].pb(di(distance,i));
                    }
                    nodes++;
            }
       	 }

    
       	 cout << dijsktra(0,1) << endl;

	}
	return 0;

}
