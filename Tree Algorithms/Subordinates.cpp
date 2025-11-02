#include "../main.h"

int n;
int dist[N];
vector<int> graph[N];

int dfs(int parent){
    if (graph[parent].empty()){
        return dist[parent] = 0;
    }
    dist[parent] = 0;
    for (auto& x: graph[parent]){
        dist[parent] += (1+dfs(x));
    }

    return dist[parent];
}

void subordinates(){
    cin >> n;
    for (int i=2;i<=n;++i){
        int x;
        cin >> x;
        graph[x].pb(i);
    }
    dfs(1);
    for (int i=1;i<=n;++i){
        cout << dist[i] << " ";
    }
}
