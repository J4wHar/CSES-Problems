#include "../main.h"

vector<int> graph[N];
unordered_map<int, int> parent;
bool visited[N];
int n, m;

void messageRoute(){
    cin >> n >> m;
    int a, b;
    for (int i=0;i<m;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(visited, false, sizeof visited);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    bool possible = false;
    while (!q.empty()){
        int p = q.front();
        q.pop();
        for (auto& child: graph[p]){
            if (!visited[child]){
                visited[child] = true;
                q.push(child);
                parent[child] = p;
                if (child == n){
                    possible = true;
                    break;
                }
            }
        }
        if(possible){
            break;
        }
    }

    if (possible){
        vector<int> path;
        int child = n;
        path.push_back(child);
        while (child != 1){
            child = parent[child];
            path.push_back(child);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (auto& x: path){
            cout << x << " ";
        }
    }else {
        cout << "IMPOSSIBLE";
    }
}
