#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int ind){
    visited[ind] = true;
    for (int el : graph[ind]) if (!visited[el]) dfs(el);
}

int main(){
    int n, m;

    cin >> n >> m;
    graph.resize(n+1);
    visited.resize(n+1);

    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int count = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]) {
            count++;
            dfs(i);
        }
    }

    cout << count;
}