#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    int numVertices;

public:
    Graph(int n) : numVertices(n), adjList(n) {}

    void insertEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            // Check if edge already exists
            auto& uList = adjList[u];
            if (find(uList.begin(), uList.end(), v) == uList.end()) {
                adjList[u].push_back(v);
                adjList[v].push_back(u); // Undirected graph
            }
        }
    }

    void deleteEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            // Remove v from u's list
            auto& uList = adjList[u];
            auto it = find(uList.begin(), uList.end(), v);
            if (it != uList.end()) uList.erase(it);
            
            // Remove u from v's list
            auto& vList = adjList[v];
            auto it2 = find(vList.begin(), vList.end(), u);
            if (it2 != vList.end()) vList.erase(it2);
        }
    }

    bool searchEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            auto& uList = adjList[u];
            return find(uList.begin(), uList.end(), v) != uList.end();
        }
        return false;
    }

    void display() {
        for (int i = 0; i < numVertices; ++i) {
            cout << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, choice, u, v;
    cout << "Enter number of vertices: ";
    cin >> n;
    Graph g(n);

    do {
        cout << "\nMenu:\n1. Insert Edge\n2. Delete Edge\n3. Search Edge\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter vertices (u v): ";
                cin >> u >> v;
                if (u < 0 || u >= n || v < 0 || v >= n)
                    cout << "Invalid vertices!\n";
                else 
                    g.insertEdge(u, v);
                break;

            case 2:
                cout << "Enter vertices (u v): ";
                cin >> u >> v;
                if (u < 0 || u >= n || v < 0 || v >= n)
                    cout << "Invalid vertices!\n";
                else 
                    g.deleteEdge(u, v);
                break;

            case 3:
                cout << "Enter vertices (u v): ";
                cin >> u >> v;
                if (u < 0 || u >= n || v < 0 || v >= n)
                    cout << "Invalid vertices!\n";
                else
                    cout << (g.searchEdge(u, v) ? "Edge exists\n" : "Edge absent\n");
                break;

            case 4:
                g.display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
/*Insert Edge: O(d) average case, O(V) worst case
(d = degree of vertex, V = number of vertices)

Delete Edge: O(d₁ + d₂) average case, O(V) worst case
(d₁ and d₂ = degrees of the two vertices)

Search Edge: O(d) average case, O(V) worst case

Display: O(V + E)
(E = total number of edges)

Exit: O(1)*/
