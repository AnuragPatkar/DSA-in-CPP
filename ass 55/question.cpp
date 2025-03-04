//! Assignment-55: Graph Matrix

/* //? 1. Define a class Graph using matrix representation with v_count, e_count and adj pointer as instance members.
#include <iostream>
using namespace std;
class Graph
{
    private:
    int v_count;
    int e_count;
    int **adj;
    public:
}; */

/* //? 2. In Question 1, define a method createGraph() to create and store adjacent node information.
void createGraph()
{
    int u, v;
    cout << "Enter number of Edges: ";
    cin >> e_count;

    if (e_count < 0 || e_count > (v_count * (v_count - 1)) / 2)
    {
        cout << "Invalid number of edges." << endl;
        return;
    }
    for (int i = 0; i < e_count; i++)
    {
        cout << "Enter u and v(connected nodes): ";
        cin >> u >> v;
        if (u < 0 || v < 0 || u >= v_count || v >= v_count)
        {
            cout << "Invalid nodes." << endl;
            i--;
            continue;
        }
        if (u == v) // Optional: Self-loops allow nahi karne
        {
            cout << "Self-loops are not allowed. Try again." << endl;
            i--;
            continue;
        }
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    cout << "Graph created successfully!" << endl;
} */

/* //? 3. In question 1, define a method to print graph matrix.
void PrintGraphMatrix()
{
    cout << "Adjacency Matrix: " << endl;
    for (int i = 0; i < v_count; i++)
    {
        for (int j = 0; j < v_count; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
} */

/* //? 4. In question 1, define a method to print all the adjacent nodes of a given node.
void PrintAdjacentNodes(int node)
{
    if (node < 0 || node >= v_count)
    {
        cout << "Invalid input." << endl;
        return;
    }

    cout << "Adjacent nodes of " << node << ": ";

    if (isolated(node))
        cout << "None" << endl;
    else
    {
        for (int i = 0; i < v_count; i++)
        {
            if (adj[node][i] == 1)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
} */

/* //? 5. In question 1, define a method to check if a given node is isolated node.
bool isolated(int node)
{
    if (node < 0 || node >= v_count)
    {
        cout << "Invalid input." << endl;
        return false;
    }

    for (int i = 0; i < v_count; i++)
    {
        if (adj[node][i] == 1)
            return false;
    }
    return true;
} */

/* //? 6. In question 1, define a destructor to deallocates memory
~Graph()
{
    for (int i = 0; i < v_count; i++)
    {
        delete[] adj[i];
    }
    delete[] adj;
    adj = NULL;
} */