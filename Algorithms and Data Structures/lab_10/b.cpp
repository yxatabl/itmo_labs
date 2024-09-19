#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int a, b, w;
};

bool cmp(Edge &a, Edge &b){
    return a.w > b.w;
}

vector<int> parent;
vector<int> Rank;
vector<Edge> graph;
vector<bool> completed;

int Find(int v){
    if (v == parent[v]) return v;
    return parent[v] = Find(parent[v]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b){
        if (Rank[a] < Rank[b]) swap(a, b);
        parent[b] = a;
        if (Rank[a] == Rank[b]) Rank[a]++;
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    int a, b, w;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> w;
        graph.push_back({a-1, b-1, w});
    }
    sort(graph.begin(), graph.end(), cmp);

    parent.resize(n);
    Rank.resize(n, 0);
    completed.resize(n, false);
    int sum = 0;
    int vertex_count = 0;
    for (int i = 0; i < n; i++) parent[i] = i;

    while (vertex_count < n){
        Edge e = *graph.end();
        graph.pop_back();

        if (Find(e.a) != Find(e.b)){
            sum += e.w;
            if (!completed[e.a]){
                completed[e.a] = true;
                vertex_count++;
            }
            if (!completed[e.b]){
                completed[e.b] = true;
                vertex_count++;
            }
            Union(e.a, e.b);
        }
    }

    cout << sum;
}