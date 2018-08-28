#include<bits/stdc++.h>
#include<string>
#define FOR(i,b) for(int i = 0 ; i<b;i++)

using namespace std;

map<int,string> path;



void bfs(){
  int src = 123456789,u;
  path[src] = string();
  queue<int> qs;
  qs.push(src);
  while(!qs.empty())/*FOR(x,3)*/{
			u = qs.front();qs.pop();

			//cerr << u <<  "  padre  "  << endl;
			FOR(i,3){
				string moveHorizontal = to_string(u);
				swap(moveHorizontal[6+i],moveHorizontal[3+i]);
				swap(moveHorizontal[3+i],moveHorizontal[0+i]);
				int intOVE = stoi(moveHorizontal);
        if(path.find(intOVE)==path.end()){
            string son = "V" + to_string(i+1);
            //cerr << son <<  " " <<  intOVE << endl;
            path[intOVE] = son+path[u];
            qs.push(intOVE);
        }
			}
      for(int i = 0 , cnt = 1; i<9 ; i+=3){
				string moveHorizontal = to_string(u);
				swap(moveHorizontal[2+i],moveHorizontal[1+i]);
				swap(moveHorizontal[1+i],moveHorizontal[0+i]);
				int intOVE = stoi(moveHorizontal);
        if(path.find(intOVE)==path.end()){
            string son = "H" + to_string(cnt);
            path[intOVE] = son+path[u];
            qs.push(intOVE);
            //cerr << son <<  " " << intOVE << endl;
        }
        cnt++;
      }
  }
	return;
}



int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	bfs();
	int tmp,f = 1;
  while (f){
			string q = string();
			FOR(i,3){
				FOR(j,3){
					cin >> tmp;
          q+=to_string(tmp);
					if(tmp==0){
							return 0;
					}
				}
			}
			int numero = stoi(q);

			cout << path[numero] << endl;
  }
	return 0;
}
