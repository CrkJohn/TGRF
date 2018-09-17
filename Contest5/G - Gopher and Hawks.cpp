#include<bits/stdc++.h>
#define FOR(i,b) for (int i=0; i<b; i++)
#define loop(i,a,b) for (int i=a; i<b; i++)
#define len(a) ((int)a.size())
#define fi first
#define se second


using namespace std;

typedef vector<int> vi;
typedef vector<vi> graph;
typedef pair<double,double> dd;

const  int N  = 1005 ,INF = 1e9;
int dis[N];

graph G;


double dist(dd p1, dd p2) {
    return sqrt(((p1.fi-p2.fi)*(p1.fi-p2.fi) ) + ((p1.se-p2.se)*(p1.se-p2.se)));
}

int bfs() {
    queue<int> q;
    dis[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        FOR(i,len(G[u])){
        	int v = G[u][i];
            if (dis[v]==INF) {
                if (v==1) return dis[u];
                dis[v] = dis[u]+1;
                q.push(v);
            }
    	}
	}
    return -1;
}

main() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	string lec;
	stringstream ss;
	double v,t,d;
	double x,y;
	vector<dd> pts;
    while (1) {
    	cin >> v >> t;
		getline(cin,lec);
        d = v*t*60.0;
        if(v+t==0)break;
        pts.clear();
        while (1){
        	getline(cin,lec);
            if (lec == "") break;
            ss.clear();
            ss << lec;
			ss >> x >> y;            
            pts.push_back(dd(x,y));
        }
        //cerr << "Vamos good" << endl;
        int lon = pts.size();
        G.assign(lon+1,vi());
        FOR(i,lon){
            loop(j,i+1,lon)
            	if(dist(pts[i],pts[j])<=d){
            		G[i].push_back(j);
            		G[j].push_back(i);
				}
        }
        FOR(i,lon)dis[i] = INF;
        int res = bfs();
        if (res==-1) cout << "No.";
        else cout << "Yes, visiting "<<res<<" other holes.";
        cout << endl;
    }
}

