#include<bits/stdc++.h>
#define FOR(i,b) for (int i=0; i<b; i++)
#define loop(i,a,b) for (int i=a; i<b; i++)
#define len(a) ((int)a.size())
#define fi first
#define se second
#define pb push_back
#define lectura() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)


using namespace std;

const int N = 2000100;
typedef long long large;

large n,sgt[N],input[N],qs,qend;


void update(int lo, int hi, int pos){
        if(qs < lo || qs > hi)return;
        if(lo == hi){
			sgt[pos] = qend;
            return;
        }
        int mid = (lo+hi)/2;
        update(lo, mid, 2*pos+1);
        update(mid+1, hi, 2*pos+2);
        sgt[pos] = (sgt[2*pos+1]+sgt[2*pos+2]);
}

large query(int lo, int hi, int node) {
        if (lo >= qs && hi <= qend)return sgt[node];
        if (hi < qs || lo > qend ){
                //cerr << "Madre mia" << endl;
                return 0;
        }
        int mid = (lo+hi)>>1;
        large left = query(lo,mid,2*node+1);
        large right = query(mid+1,hi,2*node+2);
        return left + right;
}


void st(int lo, int hi,int pos){
   if(lo==hi){
		sgt[pos] = input[lo];
		return;
	}
	int mid = (lo+hi)/2;
	st(lo,mid,2*pos+1);
	st(mid+1,hi,2*pos+2);
	sgt[pos] =  sgt[2*pos+1]+sgt[2*pos+2];
}


int main(){
    //lectura();
	ios::sync_with_stdio(0);
	cin.tie(0);
	string q;
    int ntc = 1, f  = 0;
	while(1){
		cin >> n;
		if(!n)break;
		memset(input,0,sizeof input);
		memset(sgt,0,sizeof sgt);
		FOR(i,n){
			cin >> input[i];
		}
		if(f) cout << endl;
		f = 1;
		if(n&1!=0)n++;
		st(0,n-1,0);
		cout << "Case "<< ntc++<<":"<< endl;
        while(1){
            cin >> q;

            if(q=="END")break;
            cin >> qs >> qend;
             qs--;
            if(q!="M"){
                 update(0,n-1,0);
            }else{
                qend--;
                cout << query(0,n-1,0) << endl;
            }
        }

	}


	return 0;
}
