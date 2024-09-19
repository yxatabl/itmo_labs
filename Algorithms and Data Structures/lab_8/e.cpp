#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
bool hasCycle = false;

void dfs(int ind, int last){
    visited[ind] = 1;
    for (int el : graph[ind]){
        if (el == last) continue;
        else if (visited[el] == 0) dfs(el, ind);
        else if (visited[el] == 1) hasCycle = true;
    }
    visited[ind] = 2;
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

    for (int i = 1; i <= n; i++){
        if (!visited[i]) dfs(i, -1);
    }

    hasCycle ? cout << "YES" : cout << "NO";
}