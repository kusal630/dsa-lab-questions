#include <iostream>
#include <cstring>
using namespace std;

class Graph {
private:
    int** adjMatrix;
    int numVertices;

public:
    // Constructor to initialize graph with n vertices
    Graph(int n) : numVertices(n) {
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
            memset(adjMatrix[i], 0, sizeof(int) * numVertices);
        }
    }

    // Destructor to free memory
    ~Graph() {
        for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }

    // Insert edge between two vertices (undirected graph)
    void insertEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
    }

    // Delete edge between two vertices
    void deleteEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjMatrix[u][v] = 0;
            adjMatrix[v][u] = 0;
        }
    }

    // Check if edge exists between vertices
    bool searchEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices)
            return adjMatrix[u][v] == 1;
        return false;
    }

    // Display adjacency matrix
    void display() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";
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
/* Time Complexity Analysis:

Insert Edge: O(1) - Direct array access

Delete Edge: O(1) - Direct array access

Search Edge: O(1) - Direct array access

Display: O(n²) - Nested loop through matrix

Exit: O(1) - Program termination */