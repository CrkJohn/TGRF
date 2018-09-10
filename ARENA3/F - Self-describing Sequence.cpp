#include<bits/stdc++.h>
#define loop(i,a,b) for(int i =a;i<=b;i++)
#define pb push_back
#define fi first
#define se second

using namespace std;
typedef int i64;
typedef pair<int,int> ii;


const int maxN = 2000000010;
struct gen{
	int i,j,v;
	gen(int i_ , int j_ , int v_):i(i_) , j(j_)  , v(v_){}
};

vector<gen> res;
void generate(){
  res.clear();
  res.pb(gen(1,1,1));
  res.pb(gen(2,3,2));
  res.pb(gen(4,5,3));
  int sup=5,nxt=2;
	while(1){
      loop(newVal,res[nxt].i,res[nxt].j){
         res.pb(gen(sup+1,sup+res[nxt].v,newVal));
         sup = sup+res[nxt].v;
         if(sup>=maxN)break;
			}
			if(sup>=maxN)break;
			nxt++;
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	generate();
	int n;
	while(1){
			cin >> n;
			if(!n)break;
			//cout << bb(n) << endl;
			int bu;
			for(int i = 0;;i++){
					gen tmp = res[i];
					if(tmp.i<=n && n<=tmp.j){
							bu =  tmp.v;
							break;
					}
			}
			cout << bu << endl;
	}

	return 0;
}
