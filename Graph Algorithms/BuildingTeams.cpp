#include "../main.h"

int color[N];
vector<int> graph[N];
queue<int> q;
int n, m;

bool bfs(){
    while (!q.empty()){
        int parent = q.front();
        q.pop();
        for (auto& child: graph[parent]){
            if (color[child] == -1){
                color[child] = 1-color[parent];
                q.push(child);
            }
            if (color[child] == color[parent]){
                return false;
            }
        }
    }

    return true;
}

void buildingTeams(){
    cin >> n >> m;
    int x,y;
    for (int i=0;i<m;++i){
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    memset(color, -1, sizeof color);
    for (int i=1;i<=n;++i){
        if (color[i] != -1){
            continue;
        }

        q.push(i);
        color[i] = 1;
        if (!bfs()){
            cout << "IMPOSSIBLE";
            return;
        }
    }
    for(int i=1;i<=n;++i){
        cout << color[i]+1 << " ";
    }
}
