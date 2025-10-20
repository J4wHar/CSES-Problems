#include "../main.h"

char maze[N][N];
bool visited[N][N];
int n, m;

bool isSafe(int i, int j){
    return i>=0 && i<n && j>=0 && j<m;
}

void dfs(int i, int j){
    visited[i][j] = true;
    for (int k=0;k<4;++k){
        int x = i+dx[k];
        int y = j+dy[k];
        if (isSafe(x, y) && !visited[x][y] && maze[x][y] == '.'){
            dfs(x, y);
        }
    }
}

int countingRooms(){
    cin >> n >> m;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cin >> maze[i][j];
        }
    }
    int ans = 0;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (maze[i][j] == '.' && !visited[i][j]){
                ++ans;
                dfs(i, j);
            }
        }
    }

    return ans;
}
