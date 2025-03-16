#include "dijkstras.h"
#include <queue>
#include <algorithm>

vector<int> dijkstra_shortest_path(const Graph &G, int source, vector<int> &previous){
    vector<int> d(G.numVertices, INF);
    d[source] = 0;
    previous.assign(G.numVertices, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});

    while(!pq.empty()){
        int dist = pq.top().first;
        int i = pq.top().second;
        pq.pop();
        if(dist > d[i]){
            continue;
        }

        for(const Edge &e : G[i]){
            int v = e.dst;
            int weight = e.weight;
            if(d[i] + weight < d[v]){
                d[v] = d[i]+weight;
                previous[v] = i;
                pq.push({d[v], v});
            }
        }
    }

    return d;
}

vector<int> extract_shortest_path(const vector<int> &distances, const vector<int> &previous, int destination){
    vector<int> path;
    if(destination == INF){
        return path;
    }
    for(int a = destination; a!=-1; a=previous[a]){
        path.push_back(a);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int> &path, int total){
        for(size_t i=0; i<path.size(); ++i){
            cout << path[i] << " ";
        }
        cout << "\nTotal cost is " << total << endl;
}