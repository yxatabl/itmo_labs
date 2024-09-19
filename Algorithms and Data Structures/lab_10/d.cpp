#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector<int>> g;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int next : g[v]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}


bool is_euler() {
    for (int i = 0; i < g.size(); i++) {
        if (g[i].size() % 2 != 0) {
            return false;
        }
    }

    visited.resize(g.size(), false);

    int oddV = 0;
    for (int i = 0; i < g.size(); i++) {
        if (g[i].size() > 0) {
            oddV++;
            break;
        }
    }

    if(oddV == 0) return true;
    
    dfs(0);
    
    for(int i = 0; i < g.size(); i++){
        if(!visited[i] && g[i].size() > 0){
            return false;
        }
    }

    return true;
}

vector<int> get_cycle(vector<int>& res){
    stack<int> st;
    st.push(0);
    while (!st.empty()) {
        int u = st.top();
        if (!g[u].empty()) {
            int v = g[u].back();
            g[u].pop_back();
            for (int i = 0; i < g[v].size(); i++) {
                if (g[v][i] == u){
                    g[v].erase(g[v].begin() + i);
                    break;
                }
            }
            st.push(v);
        } else {
            res.push_back(u);
            st.pop();
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        reverse(g[i].begin(), g[i].end());
    }
    if (!is_euler()) {
        cout << ":(";
        return 0;
    }
    vector<int> ans;
    get_cycle(ans);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << " ";
}