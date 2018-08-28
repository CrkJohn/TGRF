#include <bits/stdc++.h>
#define FOR(i,b) for(int i =0 ; i< b; i++)
#define FORI(i,a,b) for(int i = a; i< b; i++)

using namespace std;
struct gurinAndMalon{
    int gx, gy , mx , my , dis;
    gurinAndMalon(int dGx, int dGy, int dMx, int dMy, int Tdis): gx(dGx) , gy(dGy) , mx(dMx)  ,my(dMy) , dis(Tdis){
    }
};

int R,C,rl,cl,rg,cg,rm,cm;
vector<string> G;
int vis[42][42][42][42];
const int tmpGi[] = {1,-1, 0, 0};
const int tmpGj[] = {0, 0, 1,-1};
const int tmpMi[] = {1,-1, 0, 0};
const int tmpMj[] = {0, 0,-1, 1};

int bfs(){
    queue<gurinAndMalon> q;
    q.push(gurinAndMalon(rg-1,cg-1,rm-1,cm-1,0));
    memset(vis,0,sizeof vis);
    vis[rg-1][cg-1][rm-1][cm-1] = 1;
    if (cl == cg && rl == rg && cl == cm && rl == rm)return 0;
    while(!q.empty()){
        gurinAndMalon tmp = q.front(); q.pop();
        if(tmp.gx == rl-1 && tmp.gy == cl-1 && tmp.mx == rl-1 && tmp.my == cl-1 ){
                return tmp.dis;
				}
        FOR(i,4){
            // Move Gurin
            int tmpGX = tmp.gx,tmpGY= tmp.gy,tmpMX = tmp.mx,tmpMY = tmp.my;
            // k = tmpGurinI, h = tmpGurinJ
            int k = tmp.gx + tmpGi[i] , h = tmp.gy + tmpGj[i];
            if(k>=0 && k<R && h>=0 && h<C  && G[k][h]=='.'){
                tmpGX = k;
                tmpGY = h;
            }
            // Move Malon
            k = tmp.mx + tmpMi[i]; h = tmp.my + tmpMj[i];
            if(k>=0 && k<R && h>=0 && h<C && G[k][h]=='.'){
                tmpMX = k;
                tmpMY = h;
            }
            if(!vis[tmpGX][tmpGY][tmpMX][tmpMY]){
                vis[tmpGX][tmpGY][tmpMX][tmpMY]  = 1;
                vis[tmpMX][tmpMY][tmpGX][tmpGY]  = 1;
                q.push(gurinAndMalon(tmpGX,tmpGY,tmpMX,tmpMY,tmp.dis + 1));
            }
        }
    }
    return -1;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout << fixed;
    //cout.precision(10);
    string str;
    while(cin >> R >> C){
        G.clear();
        cin >> rl >> cl >> rg >> cg >> rm >> cm;
        FOR(i,R){
            cin >> str;
            G.push_back(str);
        }
        int rst = bfs();
        if(rst == -1 ){
            cout << "NO LOVE";
        }else{
            cout <<  rst ;
        }
        cout  <<  endl;
    }
    return 0;
}
