#include<bits/stdc++.h>
#define FOR(i,b) for (int i=0; i<b; i++)
#define loop(i,a,b) for (int i=a; i<b; i++)
#define len(a) ((int)a.size())
#define fi first
#define se second
#define pb push_back
#define lectura() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)


using namespace std;

typedef pair<int,int> ii;


int main(){
    lectura();
	ios::sync_with_stdio(0);
	cin.tie(0);
	stringstream ss;
	string str;
	int ntc,srcx,srcy,tgtx,tgty;
	cin >>  ntc;
	getline(cin,str);
	getline(cin,str);
	while(ntc--){
        getline(cin,str);
        ss.clear();
        ss << str;
        ss >> srcx >> srcy >> tgtx >> tgty;
        while(1){
            getline(cin,str);
            if(str=="")break;
            ss.clear();
            ss << str;
	    ss.clear();

       	 }
	}
	return 0;

}
