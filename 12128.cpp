/*
  Accepted.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;

const int inf = (1 << 29);

int di[] = {-1, +1, +0, +0};
int dj[] = {+0, +0, -1, +1};

int X, Y, D[1100][1100], v[1100][1100];

#define inside(i, j)(0 <= i && i < X && 0 <= j && j < Y)

struct state{
  int i, j, w;
  state(){}
  state(int I, int J, int W) : i(I), j(J), w(W) {}
  bool operator < (const state &that) const { return w < that.w; }
};

int main(){
  int C;
   freopen("in.txt","r",stdin);
  scanf("%d", &C);
  while (C--){
    int n;
    scanf("%d %d %d", &n, &X, &Y);
    int si, sj, fi, fj;
    scanf("%d %d %d %d", &si, &sj, &fi, &fj);


    /*
      Encontrar la distancia más corta entre cualquier bomba y cualquier casilla.
      El resultado queda en la matriz D.
      D[i][j] = mínima distancia entre la casilla (i,j) y alguna bomba.
     */
    for (int i=0; i<X; ++i){
      for (int j=0; j<Y; ++j){
        D[i][j] = inf;
      }
    }
    queue<state> pq;
    while (n--){
      int i, j;
      scanf("%d %d", &i, &j);
      D[i][j] = 0;
      pq.push(state(i, j, 0));
    }
    while (pq.size()){
      state u = pq.front();
      int i = u.i, j = u.j, w = u.w;
      pq.pop();
      if (w > D[i][j]) continue;
      for (int k=0; k<4; ++k){
        int ni = i + di[k], nj = j + dj[k];
        if (inside(ni, nj) && D[ni][nj] > w + 1){
          D[ni][nj] = w + 1;
          pq.push(state(ni, nj, w+1));
        }
      }
    }

    /*
      for (int i=0; i<X; ++i){
      for (int j=0; j<Y; ++j){
      cerr << D[i][j] << " ";
      }
      cerr << endl;
      }
    */

    int ans_d = -inf, ans_w = inf;
    for (int i=0; i<X; ++i){
      for (int j=0; j<Y; ++j){
        v[i][j] = -inf;
      }
    }
     /*
      Encontrar el camino que tenga máximo elemento mínimo entre start y end.
      Lo hago usando Dijkstra, igual a como resolví el problema 10099 - Tourist guide
      de la UVa.
      El resultado queda en ans_d = elemento máximo del camino con máximo elemento mínimo ;)
      En otras palabras, ans_d es el primer número de la salida.
     */
    priority_queue<state> q;
    q.push(state(si, sj, D[si][sj]));
    v[si][sj] = D[si][sj];
    while (q.size()){
      state u = q.top();
      int i = u.i, j = u.j, w = u.w;
      q.pop();

      if (i == fi && j == fj){
        ans_d = w;
        break;
      }
      if (w < v[i][j]) continue;
      //printf("popped (%d, %d, %d, %d)\n", i, j, w, d);

      for (int k=0; k<4; ++k){
        int ni = i + di[k], nj = j + dj[k];
        if (inside(ni, nj)){
          int new_d = (w < D[ni][nj])?w:D[ni][nj];
          if (new_d > v[ni][nj]){
            v[ni][nj] = new_d;
            q.push(state(ni, nj, new_d));
          }
        }
      }
    }

    while (pq.size()) pq.pop();
    for (int i=0; i<X; ++i){
      for (int j=0; j<Y; ++j){
        v[i][j] = 0;
      }
    }
    pq.push(state(si, sj, 0));
    while (pq.size()){
      state u = pq.front(); pq.pop();
      if (v[u.i][u.j]) continue;
      v[u.i][u.j] = true;
      if (u.i == fi && u.j == fj){
        ans_w = u.w;
        break;
      }
      for (int k=0; k<4; ++k){
        int ni = u.i + di[k], nj = u.j + dj[k];
        if (inside(ni, nj) && !v[ni][nj] && D[ni][nj] >= ans_d){
          pq.push(state(ni, nj, u.w + 1));
        }
      }

    }
    printf("%d %d\n", ans_d, ans_w);
  }
  return 0;
}
___________________
#include<bits/stdc++.h>
#define FOR(i,b) for(int i = 0; i<b;i++)
#define loop(i,a,b) for(int i = a; i<b;i++)
#define fi first
#define se second
#define pb push_back



using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvi g;
const int inf = 1e9;

const int di[] = {-1, +1, +0, +0};
const int dj[] = {+0, +0, -1, +1};

int X, Y, D[1100][1100], v[1100][1100];

struct node{
  int u, v, w;
  node(){}
  node(int U, int V, int W) : u(U), v(V), w(W) {}
  bool operator < (const node &that) const { return w < that.w; }
};

short int let(const int &i, const int &j){
    return (0 <= i && i < X && 0 <= j && j < Y);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ntc,n;
  int si, sj, fi, fj;

  freopen("in.txt","r",stdin);
  cin >> ntc;
  while (ntc--){
    cin >> n >> X >> Y;
    cin >> si >> sj >> fi >> fj;
    FOR(i,X){
      FOR(j,Y){
        D[i][j]=inf;

      }
    }
    queue<node> q;
    while (n--){
      int u, v;
      cin >> u >> v;
      D[u][v] = 0;
      q.push(node(u,v,0));
    }
    while (q.size()){
      node nd = q.front();q.pop();
      int i = nd.u, j = nd.v, w = nd.w;
      if (w > D[i][j]) continue;
      FOR(x,4){
        int h = i + di[x], k = j + dj[x];
        if (let(h,k)){
          D[h][k] = w+1;
          q.push(node(h,k,w+1));
        }
      }
    }
    int ans_d = -inf, ans_w = inf;
    priority_queue<node> pq;
    pq.push(node(si, sj, D[si][sj]));
    v[si][sj] = D[si][sj];
    while (pq.size()){
      node u = pq.top();
      int i = u.u, j = u.v, w = u.w;
      pq.pop();
      if (i == fi && j == fj){
        ans_d = w;
        break;
      }
      if (w < v[i][j]) continue;
      for (int k=0; k<4; ++k){
        int ni = i + di[k], nj = j + dj[k];
        if (let(ni, nj)){
          int new_d = (w < D[ni][nj])?w:D[ni][nj];
          if (new_d > v[ni][nj]){
            v[ni][nj] = new_d;
            pq.push(node(ni, nj, new_d));
          }
        }
      }
    }

    while (q.size())q.pop();
    FOR(i,X){
      FOR(j,Y){
        v[i][j] = -inf;
      }
    }
    q.push(node(si, sj, 0));
    while (q.size()){
      node u = q.front(); q.pop();
      if (v[u.u][u.v]) continue;
      v[u.u][u.v] = true;
      if (u.u== fi && u.v == fj){
        ans_w = u.w;
        break;
      }
     FOR(x,4){
        int h = u.u + di[x], k = u.v + dj[x];
        if (let(h,k) && !v[h][k] && D[h][k] >= ans_d){
          q.push(node(h,k,u.w+1));
        }
      }
    }
    cout << ans_d<<" " << ans_w << endl;
  }
  return 0;
}
