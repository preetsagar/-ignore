#include <bits/stdc++.h>
using namespace std;

int n,l,s;
map<int, int> m;

int bfs(int u){
    queue<int> q;
    int dis[110];
    for(int i=0; i<110; i++) dis[i] = 1e9;

    q.push(u);
    dis[u]=0;
    while(!q.empty()){
        int t = q.front(); q.pop();

        if(m.find(t)!=m.end()){
            if(dis[m[t]]!=1e9) continue;
            q.push(m[t]);
            dis[m[t]] = dis[t];
        }else{
            for(int i=1; i<=6; i++){
                int v = t+i;
                if(v<=100 && dis[v]==1e9){
                    q.push(v);
                    dis[v] = dis[t]+1;
                }
            }
        }
    }

    return dis[100]==1e9 ? -1 : dis[100];
}

int main() {
    int t; cin>>t; while(t--){
        m.clear();
        cin>>l;
        while(l--){
            int x,y; cin>>x>>y;
            m[x]=y;
        }
        cin>>l;
        while(l--){
            int x,y; cin>>x>>y;
            m[x]=y;
        }
        cout<<bfs(1)<<"\n";
    }
    return 0;
}
