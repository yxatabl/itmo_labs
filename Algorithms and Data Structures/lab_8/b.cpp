#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> graph, rgraph;
vector<bool> visited;
stack<int> st;
vector<int> component;

void dfs(int ind){
    visited[ind] = true;
    for (int el : graph[ind]) if (!visited[el]) dfs(el);
    st.push(ind);
}

void dfsReversed(int ind, int comp){
    visited[ind] = true;
    component[ind] = comp;
    for (int el : rgraph[ind]) if (!visited[el]) dfsReversed(el, comp);
}

int main(){
    int n, m, q;

    cin >> n >> m >> q;
    graph.resize(n+1);
    rgraph.resize(n+1);
    visited.resize(n+1, false);
    component.resize(n+1, -1);

    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }

    for (int i = 1; i < n; i++) if (!visited[i]) dfs(i);
    fill(visited.begin(), visited.end(), false);
    
    int countComponents = 0;
    int el;
    while(!st.empty()){
        el = st.top();
        st.pop();
        if (!visited[el]){
            dfsReversed(el, countComponents);
            countComponents++;
        }
    }

    for (int i = 0; i < q; i++){
        cin >> a >> b;
        component[a] == component[b] ? cout << "YES\n" : cout << "NO\n";
    }
}