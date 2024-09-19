#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> adj;
vector<int> parent;

void dfs(int v){
    for (int u : adj[v]){
        if (u != parent[v]){
            parent[u] = v;
            dfs(u);
        }
    }
}

vector<int> pruefer_code(){
    int n = adj.size();
    parent.resize(n);
    parent[n-1] = -1;
    dfs(n-1);

    int ptr = -1;
    vector<int> degree(n);
    for (int i = 0; i < n; i++){
        degree[i] = adj[i].size();
        if (degree[i] == 1 && ptr == -1)
            ptr = i;
    }

    vector<int> code(n - 2);
    int leaf = ptr;
    for (int i = 0; i < n - 2; i++){
        int next = parent[leaf];
        code[i] = next;
        if (--degree[next] == 1 && next < ptr){
            leaf = next;
        } else {
            ptr++;
            while(degree[ptr] != 1) ptr++;
            leaf = ptr;
        }
    }

    return code;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj.resize(n);

    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    for (int el : pruefer_code()) cout << el+1 << " ";
}