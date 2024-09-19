#include "blazingio.hpp"
#include <vector>

using namespace std;

const int INF = (int)1e9;
const int S = 1;
int T;

vector<int> firstEdge, visited;
vector<int> onEnd, nextEdge, capacity;
int N, M, edgeCount;

void addEdge(int u, int v, int cap){
    onEnd[edgeCount] = v;
    nextEdge[edgeCount] = firstEdge[u];
    firstEdge[u] = edgeCount;
    capacity[edgeCount++] = cap;

    onEnd[edgeCount] = u;
    nextEdge[edgeCount] = firstEdge[v];
    firstEdge[v] = edgeCount;
    capacity[edgeCount++] = 0;
}

int findFlow(int u, int flow){
    if (u == T) return flow;
    visited[u] = true;
    for (int edge = firstEdge[u]; edge != -1; edge = nextEdge[edge]){
        int to = onEnd[edge];
        if (!visited[to] && capacity[edge] > 0){
            int minResult = findFlow(to, min(flow, capacity[edge]));
            if (minResult > 0){
                capacity[edge] -= minResult;
                capacity[edge^1] += minResult;
                return minResult;
            }
        }
    }
    return 0;
}

int main(){
    cin >> N >> M;

    firstEdge.resize(4*N, -1);
    visited.resize(4*N);
    
    onEnd.resize(4*M);
    nextEdge.resize(4*M);
    capacity.resize(4*M);
    
    T = N;
    
    for (int i = 0, u, v, cap; i < M; i++){
        cin >> u >> v >> cap;
        addEdge(u, v, cap);
    }

    int res = 0;
    int f = 0;

    while ((f = findFlow(S, INF)) > 0){
        fill(visited.begin(), visited.end(), false);
        res += f;
    }

    cout << res;
}