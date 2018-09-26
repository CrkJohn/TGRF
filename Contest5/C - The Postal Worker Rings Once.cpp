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


graph G;
const int N = 210 ,INF = 1e9;
int indegre[27],wTotal,indegreTotal;

void clearSolve(){
	G.assign(27,vtup());
	memset(indegre,0,sizeof indegre);
	wTotal = 0;
	indegreTotal = 0;
}

void solve(){
  int src = -1,tgt = -1;
	FOR(i,27){
      if(indegre[i]&1 && src==-1)src = i;
			else if(indegre[i]&1 && tgt==-1) tgt = i;
			if(src!=-1 && tgt!=-1)break;
	}
	priority_queue< ii , vtup , greater<ii> > pq;
	int dis[27];FOR(i,27)dis[i] = INF;
	dis[src] = 0;
	pq.push(ii(0,src));
  ii par;
	int d,u;
  while(!pq.empty()){
		par=pq.top(); pq.pop();
		d=par.fi; u=par.se;
		if (d>dis[u])continue;
		loop(j,0,(int)G[u].size()){
				ii v=G[u][j];
				if(dis[u]+v.se < dis[v.fi]){
					dis[v.fi]= dis[u] + v.se;
					pq.push(ii(dis[v.fi], v.fi));
				}
			}
	}
	/*FOR(i,(int)G.size()){
		cerr << "Node " << i << ": ";
		FOR(j,(int)G[i].size()){
				ii v =  G[i][j];
				cerr << "(" << v.fi << ","<<v.se<<") ";
		}
		cerr << endl;
	}*/
	if(tgt!=-1)wTotal+=dis[tgt];
	cout << wTotal << endl;
	clearSolve();
}

int main(){
	lec();
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	clearSolve();
	while(1){
			cin >> s;
			if(cin.eof())break;
			if(s=="deadend")solve();
			else{
				int src = s[0]-'a' , tgt =  s[s.size()-1]-'a';
				G[src].pb(ii(tgt,s.size()));
				G[tgt].pb(ii(src,s.size()));
				indegre[src]++;indegre[tgt]++;
				wTotal += s.size();
      }
	}
	return 0;
}


