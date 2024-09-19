#include <vector>
#include <iostream>

using namespace std;

struct Edge {
    int a, b, cost;
};

int n, m, k;
vector<Edge> edges;
const int INF = 1e9;

bool bellmanFord(){
    vector<int> d(n);
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i){
        x = -1;
        for (Edge e : edges){
            if (d[e.a] < INF){
                if (d[e.a] + e.cost < d[e.b]){
                    d[e.b] = max(-INF, d[e.a] + e.cost);
                    p[e.b] = e.a;
                    x = e.b;
                }
            }
        }
    }

    if (x == -1){
        return true;
    } else{
        for (int i = 0; i < n; ++i) x = p[x];
        vector<int> cycle;
        for (int v = x;; v = p[v]){
            cycle.push_back(v);
            if (v == x && cycle.size() > 1) break;
        }
        return cycle.size() <= k;
    }
}

int main(){
    int N, u, v, h;

    cin >> N >> k;

    for (int block = 0; block < N; block++){
        cin >> n >> m;
        for (int i = 0; i < m; i++){
            cin >> u >> v >> h;
            edges.push_back(Edge({u-1, v-1, h}));
        }
        bellmanFord() ? cout << "YES\n" : cout << "NO\n";
        edges.clear();
    }
}