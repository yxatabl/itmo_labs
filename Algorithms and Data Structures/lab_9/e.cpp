#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> g;
vector<int> tin, fup;
vector<bool> used;
vector<pair<int, int>> bridges;

int timer;

void dfs(int v, int p = -1){
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (size_t i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if (to == p) continue;
        if (used[to]) fup[v] = min(fup[v], tin[to]);
        else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v]){
                if (v < to) bridges.push_back({v, to});
                else bridges.push_back({to, v});
            } 
        } 
    }
}

void find_bridges(){
    timer = 0;
    fill(used.begin(), used.end(), false);
    for (int i = 0; i < g.size(); i++) if (!used[i]) dfs(i);
}

int main(){
    int n, m;
    cin >> n >> m;
    
    g.resize(n);
    tin.resize(n);
    fup.resize(n);
    used.resize(n);

    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    find_bridges();
    sort(bridges.begin(), bridges.end());
    for (pair el : bridges) cout << el.first+1 << " " << el.second+1 << "\n";
}