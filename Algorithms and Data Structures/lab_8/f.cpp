#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector<vector<int>> graph;
const int INF = numeric_limits<int>::max();

vector<int> bfs(int ind){
    vector<int> dist(graph.size(), INF);
    queue<int> q;

    dist[ind] = 0;
    q.push(ind);

    while (!q.empty()){
        int cur = q.front();
        q.pop();

        for (int el: graph[cur]){
            if (dist[el] > dist[cur] + 1){
                dist[el] = dist[cur] + 1;
                q.push(el);
            }
        }
    }

    return dist;
}

int main(){
    int n;
    cin >> n;
    graph.resize(n+1);

    int e, k;
    cin >> e >> k;

    int a, b;
    for (int i = 0; i < e; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> distances = bfs(1);
    int count = 0;
    for (int i=1; i < distances.size(); i++){
        if (distances[i] == k){
            cout << i << "\n";
            count++;
        } else continue;
    }

    if (count == 0) cout << "NO";
}