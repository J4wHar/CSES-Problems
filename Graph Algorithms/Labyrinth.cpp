#include "../main.h"

char maze[N][N];
bool visited[N][N];
pair<int, int> parent[N][N];
queue<pair<int, int>> q;
int n, m;

bool isSafe(int i, int j){
    return i>=0 && i<n && j>=0 && j<m;
}

void labyrinth(){
    cin >> n >> m;
    pair<int, int> entrance;
    pair<int, int> target;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cin >> maze[i][j];
            if (maze[i][j] == 'A'){
                entrance = mp(i, j);
            }
            if (maze[i][j] == 'B'){
                target = mp(i, j);
            }
        }
    }
    memset(visited, false, sizeof visited);
    q.push(entrance);
    parent[entrance.first][entrance.second] = entrance;
    visited[entrance.first][entrance.second] = true;
    bool possible = false;
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        for (int k=0;k<4;++k){
            int i = p.first + dx[k];
            int j = p.second + dy[k];
            if (isSafe(i, j) && !visited[i][j] && maze[i][j] != '#'){
                visited[i][j] = true;
                q.push(mp(i, j));
                parent[i][j] = p;
                if (i == target.first && j == target.second){
                    possible = true;
                    break;
                }
            }
        }
        if (possible){
            break;
        }
    }
    if (possible){
        yes;
        pair<int, int> cur = target;
        string ans = "";
        while (cur.first != entrance.first || cur.second != entrance.second){
            pair<int, int> child = cur;
            cur = parent[cur.first][cur.second];
            if (abs(cur.first - child.first) > 0){
                ans += cur.first > child.first ? 'U' : 'D';
            }else{
                ans += cur.second > child.second ? 'L' : 'R';
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        cout << ans;
    }else{
        no;
    }
}
