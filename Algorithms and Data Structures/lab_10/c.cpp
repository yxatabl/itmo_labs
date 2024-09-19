#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    long long a, b, w;
};

bool cmp(Edge &a, Edge &b){
    return a.w > b.w;
}

vector<long long> parent;
vector<long long> Rank;
vector<Edge> graph;
vector<bool> completed;

long long Find(long long v){
    if (v == parent[v]) return v;
    return parent[v] = Find(parent[v]);
}

void Union(long long a, long long b) {
    a = Find(a);
    b = Find(b);
    if (a != b){
        if (Rank[a] < Rank[b]) swap(a, b);
        parent[b] = a;
        if (Rank[a] == Rank[b]) Rank[a]++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;

    long long a, b, w;
    for (long long i = 0; i < m; i++){
        cin >> a >> b >> w;
        graph.push_back({a-1, b-1, w});
    }
    sort(graph.begin(), graph.end(), cmp);

    parent.resize(n);
    Rank.resize(n, 0);
    completed.resize(n, false);
    long long sum = 0;
    long long vertex_count = 0;
    for (long long i = 0; i < n; i++) parent[i] = i;

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