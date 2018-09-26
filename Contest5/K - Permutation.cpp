#include<bits/stdc++.h>
#define FOR(i,b) for (int i=0; i<b; i++)
#define FORR(i,b) for (int i=b-1; i>=0; i--)
#define loop(i,a,b) for (int i=a; i<b; i++)
#define len(a) ((int)a.size())
#define fi first
#define se second
#define pb push_back
#define lectura() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)



using namespace std;


int main (){
		//lectura();
		ios::sync_with_stdio(0);
		cin.tie(0);
    int ntc,num;
    cin >> ntc;
    while(ntc-- ) {
        int n;
        cin >> n;
        vector <int> vi;
				loop(i,1,n+1)vi.pb(i);
				int f = 0;
        FOR(i,n){
						cin >> num;
						if(f) cout << " "; f = 1;
						cout << vi[num];
						vi.erase(vi.begin()+num);
				}
				cout << endl;
    }
    return 0;
}
