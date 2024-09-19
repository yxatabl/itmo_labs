#include "blazingio.hpp"
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> graph;

void move(vector<int> &v){
    int a = *v.begin();
    for (int i = 0; i < v.size()-1; i++){
        v[i] = v[i+1];
    }
    v[v.size()-1] = a;
}

int main(){
    int n, m;
    cin >> n >> m;
    graph.resize(n, vector<bool>(n, false));

    vector<bool> exists(n, false);
    vector<int> q;

    for (int i = 0, u, v; i < m; i++){
        cin >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
        if (!exists[u]){
            q.push_back(u);
            exists[u] = true;
        }
        if (!exists[v]){
            q.push_back(v);
            exists[v] = true;
        }
    }

    for (int k = 0; k < n*(n-1); k++){
        if (!graph[q[0]][q[1]]){
            int i = 2;
            while (!graph[q[0]][q[i]] || !graph[q[1]][q[i+1]]) i++;
            reverse(q.begin()+1, q.begin()+i+1);
        }
        move(q);
    }

    for (int el : q) cout << el << " ";
}