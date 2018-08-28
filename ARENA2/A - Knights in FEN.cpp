#include<bits/stdc++.h>
#define FOR(i,b) for(int i =0 ; i< b;i++)
#include <vector>
#define REV(i,b) for(int i = b; i>=0;i--)
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
typedef vector<string> si;
typedef long long i64;

const int MAXN = 100+5, INF = 1e9;
int ky[] = {2, 2,-2,-2, 1,-1, 1,-1};
int kx[] = {1,-1, 1,-1, 2, 2,-2,-2};


short int let(const int i , const int j){return 0<= i && i<5 && 0<=j && j<5;}
char g[6][6];

const int src  = 403203039;

map<int,int> result;
void casesAll(){
	vi curr;
	curr.pb(src);
	result[src] = 0;
	FOR(ntc,10){
		vi next;
		int lon = curr.size();
		for(int t = 0;t<lon;t++){
				int e = curr[t];
				int i = (e >> 25) / 5 ,  j = (e  >> 25) % 5;
				FOR(x,8){
  						int h  = i + kx[x] , k  = j + ky[x];
  						if(!let(h,k))continue;
  						int v  = (e&~(1<<(h*5+k))) | ((( e >>(h*5+k))&1)<<(i*5+j));
							v = ((v>>25)<<25)^v;
							v = v | (h*5 + k) << 25;
							if(!result[v] && 403203039!=v){
									result[v] = ntc+1;
							}
							next.pb(v);
				}
		}
		curr = next;
	}
	return;
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ntc;
	casesAll();
	char g[6][6];
	scanf("%d",&ntc);
	getchar();
	while(ntc--){
		FOR(i,5)gets(g[i]);
		int boardInt = 0,pos;
		REV(i,4){
			REV(j,4){
				if(g[i][j]== '1' ||  g[i][j]== '0'){
					boardInt = (boardInt<<1)|((g[i][j]=='1') ? 1 : 0);
				}else{
					boardInt<<=1;
					pos = (i*5 + j);
				}
			}
		}
		boardInt  = boardInt | pos << 25;
		int res = result[boardInt];
    if(!res && boardInt!=src ) cout << "Unsolvable in less than 11 move(s)." << endl;
		else cout << "Solvable in "<< result[boardInt]<<" move(s)."<< endl;
	}

	return 0;
}
