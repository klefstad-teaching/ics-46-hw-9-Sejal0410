#include "dijkstras.h"

int main(){
    string file;
    cout << "Please enter the graph filename: ";
    cin >> file;

    Graph g;
    file_to_graph(file, g);
    int source = 0;
    vector<int> prev;
    vector<int> dist = dijkstra_shortest_path(g, source, prev);

    for(int i=0; i<g.numVertices; ++i){
        vector<int> path = extract_shortest_path(dist, prev, i);
        cout << "Shortest path from " << source << " to " << i << ": ";
        print_path(path, dist[i]);
    }
}