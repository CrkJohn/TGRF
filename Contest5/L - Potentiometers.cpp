#include<bits/stdc++.h>
#define FOR(i,b) for (int i=0; i<b; i++)
#define loop(i,a,b) for (int i=a; i<b; i++)
#define len(a) ((int)a.size())
#define fi first
#define se second
#define pb push_back
#define lectura() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)


using namespace std;

const int N = 200100;

int n,sgt[N],input[N],qs,qend;

int query(int lo, int hi, int node) {
        if (lo >= qs && hi <= qend)return tree[node];
        if (hi < qs || lo > qend)return 0;
        int mid = (lo+hi)>>2;
        int left = query(lo, mid,2*node+1);
        int right = query(mid+1, hi,2*node+2);
        return left + right;
    }


void st(int lo, int hi,int pos){
    cerr << lo << " " << hi << " " << pos << endl;
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
    lectura();
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1){
		cin >> n;
		if(!n)break;
		memset(input,0,sizeof input);
		memset(sgt,0,sizeof sgt);
		FOR(i,n){
			cin >> input[i];
		}
		if(n&1!=0)n++;
		st(0,n-1,0);
		FOR(i,2*n){
			cerr << sgt[i] << " ";
		}
		cerr << endl;


	}


	return 0;
}
