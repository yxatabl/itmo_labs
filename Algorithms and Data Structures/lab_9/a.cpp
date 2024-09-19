#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<set<int>> graph;
vector<bool> visited;

void dfs(int u){
    visited[u] = true;
    for (int el : graph[u]) if (!visited[el]) dfs(el);
}

int main(){
    int n, m, q;

    cin >> n >> m >> q;
    graph.resize(n + 1);
    visited.resize(n + 1);

    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a-1].insert(b-1);
        graph[b-1].insert(a-1);
    }

    char op;
    for (int i = 0; i < q; i++){
        cin >> op >> a >> b;
        if (op == '?'){
            fill(visited.begin(), visited.end(), false);
            dfs(a-1);
            visited[b-1] ? cout << "YES\n" : cout << "NO\n";
        }
        else if (op == '-'){
            graph[a-1].erase(b-1);
            graph[b-1].erase(a-1);
        }
    }

    return 0;
}