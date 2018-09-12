#include<bits/stdc++.h>
#define pb push_back
#define loop(i,a,b) for(int i = a; i<b;i++)
#define FOR(i,b) for(int i = 0; i<b;i++)
#define fi first
#define se second

using namespace std;

typedef pair<double,double> pt;

const int N = 1000;
int p[N],r[N];


struct node{
	double u,v,dist;
	node(double u_, double v_, double dist_) : u(u_) , v(v_),dist(dist_) {};
	bool operator <( node e){
		return dist < e.dist;
	} 
};

vector<node> listEdges;

void makeSet(int n){
	FOR(i,n+1){
		p[i] = i;
		r[i] = 0;
	}
	
}

int find(int i){
	if(i!=p[i]){
		p[i] = find(p[i]);
	}
	return p[i];
}



void Union(int x,int y){
		int xr = find(x) , yr = find(y);
		if (r[xr] < r[yr]){
			p[xr] = yr;
		}else{
			p[yr] = xr;
			if(r[yr]==r[xr])r[xr]++;
		}
}


double dist(pt a, pt b){
	return sqrt( (a.fi-b.fi)*(a.fi-b.fi) + (a.se-b.se)*(a.se-b.se));
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,conect,u,v; double xi,yi;
	vector<pt> points;
	cout << fixed;
	cout.precision(2);
	int ntc = 0,f  = 0;
	while(1){	
		cin >> n;
		listEdges.clear();
		points.clear();
		if(cin.eof())break;
		makeSet(n+1);
		FOR(i,n){
			cin >> xi >> yi;
			points.pb(pt(xi,yi));
		}
		FOR(i,n){
			loop(j,i+1,n){
				listEdges.pb(node(i+1,j+1,dist(points[i],points[j])));
			}
		}
		sort(listEdges.begin(),listEdges.end());
		cin >> conect;
		FOR(i,conect){
			cin >> u >> v;
			Union(u,v);
			
		}
		double cst = 0;
 		FOR(i,listEdges.size()){
 			node e = listEdges[i];
 			if(find(e.u)!=find(e.v)){
 				Union(e.u,e.v);
 				cst+=e.dist;
			}	
		}
		cout << cst << endl;		 
	}
	
}
