#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> st;

void dfs(int ind){
    visited[ind] = true;
    for (int el:graph[ind]) if (!visited[el]) dfs(el);
    st.push_back(ind);
}

void topSort(vector<int> &res){
    for (auto el:graph) visited.push_back(false);
    for (int i = 0; i < graph.size(); i++) if (!visited[i]) dfs(i);
    for (int i = st.size()-1; i >= 0; i--) res.push_back(st[i]);
}

int main(){
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a-1].push_back(b-1);
    }

    vector<int> order;
    topSort(order);
    vector<int> result(order.size());
    for (int i = 0; i < order.size(); i++){
        result[order[i]] = i+1;
    }
    for (int el : result) cout << el << " ";
}