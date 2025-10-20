#include "../main.h"

vector<int> graph[N];
bool visited[N];
int n, m;

void dfs(int parent){
    visited[parent] = true;
    for (auto& child : graph[parent]){
        if (!visited[child]){
            dfs(child);
        }
    }
}

void buildingRoads(){
    cin >> n >> m;
    int a, b;
    for (int i=0;i<m;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(visited, false, sizeof visited);
    vector<int> nodesToLink;
    for (int i=1;i<=n;++i){
        if (!visited[i]){
            nodesToLink.push_back(i);
            dfs(i);
        }
    }
    if (nodesToLink.size() == 1){
        cout << 0;
    }else{
        cout << nodesToLink.size() - 1 << endl;
        for (int i=1;i<nodesToLink.size();++i){
            cout << nodesToLink[i-1] << " " << nodesToLink[i] << endl;
        }
    }
}
