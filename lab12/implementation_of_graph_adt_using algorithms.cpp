#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Graph {
private:
    struct Edge {
        int src, dest, weight;
        Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
    };

    vector<vector<pair<int, int>>> adjList;
    vector<Edge> edges;
    int vertices;

    // Union-Find for Kruskal's
    class UnionFind {
    private:
        vector<int> parent, rank;
    public:
        UnionFind(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i < n; i++)
                parent[i] = i;
        }
        
        int find(int u) {
            if(parent[u] != u)
                parent[u] = find(parent[u]);
            return parent[u];
        }
        
        void unite(int u, int v) {
            int rootU = find(u);
            int rootV = find(v);
            
            if(rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else {
                parent[rootU] = rootV;
                if(rank[rootU] == rank[rootV])
                    rank[rootV]++;
            }
        }
    };

public:
    Graph(int V) : vertices(V), adjList(V) {}
    
    void addEdge(int u, int v, int w) {
        if(u < 0 || u >= vertices || v < 0 || v >= vertices || w < 0) {
            cout << "Invalid edge parameters!\n";
            return;
        }
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
        edges.emplace_back(u, v, w);
    }
    
    void deleteEdge(int u, int v) {
        if(u < 0 || u >= vertices || v < 0 || v >= vertices) {
            cout << "Invalid vertices!\n";
            return;
        }
        
        // Remove from adjacency list
        auto remove = [&](int a, int b) {
            for(auto it = adjList[a].begin(); it != adjList[a].end(); ++it) {
                if(it->first == b) {
                    adjList[a].erase(it);
                    break;
                }
            }
        };
        
        remove(u, v);
        remove(v, u);
        
        // Remove from edge list
        edges.erase(remove_if(edges.begin(), edges.end(), 
            [&](Edge& e) { return (e.src == u && e.dest == v) || (e.src == v && e.dest == u); }),
            edges.end());
    }
    
    bool hasEdge(int u, int v) {
        for(auto& neighbor : adjList[u])
            if(neighbor.first == v)
                return true;
        return false;
    }
    
    void display() {
        for(int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for(auto& neighbor : adjList[i])
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            cout << endl;
        }
    }
    
    void primMST() {
        if(vertices == 0) {
            cout << "Graph is empty!\n";
            return;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> key(vertices, INT_MAX);
        vector<bool> inMST(vertices, false);
        vector<int> parent(vertices, -1);
        
        pq.push({0, 0});
        key[0] = 0;
        
        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            inMST[u] = true;
            
            for(auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                if(!inMST[v] && key[v] > weight) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }
        
        cout << "Prim's MST:\n";
        for(int i = 1; i < vertices; i++) {
            if(parent[i] == -1) {
                cout << "No MST exists (disconnected graph)\n";
                return;
            }
            cout << parent[i] << " - " << i << " : " << key[i] << endl;
        }
    }
    
    void kruskalMST() {
        sort(edges.begin(), edges.end(), 
            [](Edge& a, Edge& b) { return a.weight < b.weight; });
        
        UnionFind uf(vertices);
        vector<Edge> result;
        int totalWeight = 0;
        
        for(Edge& edge : edges) {
            int rootU = uf.find(edge.src);
            int rootV = uf.find(edge.dest);
            
            if(rootU != rootV) {
                result.push_back(edge);
                totalWeight += edge.weight;
                uf.unite(rootU, rootV);
            }
        }
        
        if(result.size() != vertices - 1) {
            cout << "No MST exists (disconnected graph)\n";
            return;
        }
        
        cout << "Kruskal's MST:\n";
        for(Edge& e : result)
            cout << e.src << " - " << e.dest << " : " << e.weight << endl;
        cout << "Total weight: " << totalWeight << endl;
    }
    
    void dijkstra(int src) {
        if(src < 0 || src >= vertices) {
            cout << "Invalid source vertex!\n";
            return;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(vertices, INT_MAX);
        
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty()) {
            int u = pq.top().second;
            int distance = pq.top().first;
            pq.pop();
            
            if(distance > dist[u]) continue;
            
            for(auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                if(dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        cout << "Dijkstra's Shortest Paths from " << src << ":\n";
        for(int i = 0; i < vertices; i++) {
            if(dist[i] == INT_MAX)
                cout << i << ": Unreachable\n";
            else
                cout << i << ": " << dist[i] << endl;
        }
    }
};

int main() {
    int V, choice, u, v, w, src;
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);
    
    do {
        cout << "\nMenu:\n1. Add Edge\n2. Delete Edge\n3. Check Edge\n4. Display\n"
             << "5. Prim's MST\n6. Kruskal's MST\n7. Dijkstra's Algorithm\n8. Exit\n"
             << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter u, v, weight: ";
                cin >> u >> v >> w;
                g.addEdge(u, v, w);
                break;
                
            case 2:
                cout << "Enter u, v: ";
                cin >> u >> v;
                g.deleteEdge(u, v);
                break;
                
            case 3:
                cout << "Enter u, v: ";
                cin >> u >> v;
                cout << (g.hasEdge(u, v) ? "Edge exists\n" : "Edge absent\n");
                break;
                
            case 4:
                g.display();
                break;
                
            case 5:
                g.primMST();
                break;
                
            case 6:
                g.kruskalMST();
                break;
                
            case 7:
                cout << "Enter source vertex: ";
                cin >> src;
                g.dijkstra(src);
                break;
                
            case 8:
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 8);
    
    return 0;
}
/*Prim's Algorithm: O((V+E) log V) using priority queue

Kruskal's Algorithm: O(E log E) for sorting + O(E α(V)) for union-find

Dijkstra's Algorithm: O((V+E) log V) with priority queue*/