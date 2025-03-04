//! Assignment-56: Graph List Representation

//? 1. Define a class Graph to implement linked list representation of graph. Define needful structure for node and class for AdjList.

//? 2. Define appropriate constructors in the classes AdjList and Graph

//? 3. Define appropriate methods to manage linked list in AdjList

//? 4. Define createGraph() method in Graph class to allocate memory for array of AdjList Objects.

//? 5. Define a method addEdge() in Graph class to add a new node in adjacency list.

//? 6. Define destructors in the classes AdjList and Graph

//? 7. Define a method to print graph (print values of adjacency list).

/*//! Answers: 
#include <iostream>
using namespace std;
struct node
{
    int vertex;
    node *next;
};
class Adjlist
{
private:
    node *start;

public:
    Adjlist()
    {
        start = NULL;
    }
    void addEdge(int v)
    {
        node *newnode = new node;
        newnode->vertex = v;
        newnode->next = start;
        start = newnode;
    }
    void display()
    {
        if (start == NULL)
        {
            cout << "Adjlist is Empty." << endl;
            return;
        }
        node *t = start;
        while (t)
        {
            cout << t->vertex << " -> ";
            t = t->next;
        }
        cout << "NULL" << endl;
    }
    void delEdge(int v)
    {
        if (start == NULL)
        {
            cout << "Adjlist is Empty." << endl;
            return;
        }
        if (start->vertex == v)
        {
            node *temp = start;
            start = start->next; // Move start pointer
            delete temp;
        }
        else
        {
            node *t = start;
            while (t->next != NULL && t->next->vertex != v)
            {
                t = t->next;
            }
            if (t->next != NULL)
            {
                node *p = t->next;
                t->next = t->next->next;
                delete p;
            }
        }
    }
    bool search(int v)
    {
        node *t = start;
        while (t)
        {
            if (t->vertex == v)
            {
                return true;
            }
            t = t->next;
        }
        return false;
    }
    void clear()
    {
        if (start == NULL)
        {
            cout << "Adjlist is Empty." << endl;
            return;
        }
        node *t;
        while (start)
        {
            t = start;
            start = start->next;
            delete t;
        }
        start = NULL;
    }
    ~Adjlist()
    {
        clear();
    }
};
class Graph
{
private:
    int v_count;
    Adjlist *arr;

public:
    Graph(int v)
    {
        v_count = v;
        arr = new Adjlist[v_count];
    }
    void createGraph()
    {
        int edges;
        cout << "Enter the number of edges: ";
        cin >> edges;

        cout << "Enter edges (format: u v for edge u->v):" << endl;
        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;

            if (u >= 0 && u < v_count && v >= 0 && v < v_count)
            {
                arr[u].addEdge(v); // Add edge u → v
                arr[v].addEdge(u); // Uncomment for undirected graph
            }
            else
            {
                cout << "Invalid edge! Try again." << endl;
                i--; // Retry invalid input
            }
        }

        // Step 4: Confirm Graph Creation
        cout << "Graph Created Successfully!" << endl;
        displayGraph(); // Display adjacency list
    }
    void displayGraph()
    {
        for (int i = 0; i < v_count; i++)
        {
            cout << i << " -> ";
            arr[i].display();
        }
    }
    void addEdge(int u, int v)
    {
        if (u >= 0 && u < v_count && v >= 0 && v < v_count)
        {
            arr[u].addEdge(v); // Add edge u → v
            arr[v].addEdge(u); // Uncomment for undirected graph
            cout << "Edge (" << u << " -> " << v << ") added successfully!" << endl;
        }
        else
        {
            cout << "Invalid edge! Try again." << endl;
        }
    }
    ~Graph()
    {
        delete[] arr;
    }
};
int main()
{
    
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.displayGraph();

    return 0;
} */