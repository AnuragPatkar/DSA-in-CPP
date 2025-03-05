//! Assignment-57: Graph Traversing

/* //? 1. Implement BFS in Graph Matrix.
#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};
class Queue
{
private:
    node *front;
    node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int data)
    {
        node *newnode = new node;
        newnode->item = data;
        newnode->next = NULL;
        if (front == NULL)
        {
            front = newnode;
            rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }
    void dequeue()
    {
        if (front == NULL)
        {
            return;
        }
        node *t = front;
        if (front == rear)
        {
            front = NULL;
            rear = NULL;
        }
        else
        {
            front = front->next;
        }
        delete t;
    }
    int getFront()
    {
        if (front == NULL)
        {
            return -1;
        }
        return front->item;
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    ~Queue()
    {
        while (front != NULL)
        {
            dequeue();
        }
    }
};
class Graph
{
private:
    int v_count;
    int e_count;
    int **adj;

public:
    Graph(int vertices)
    {
        v_count = vertices;
        e_count = 0;
        adj = new int *[v_count];
        for (int i = 0; i < v_count; i++)
        {
            adj[i] = new int[v_count];
            for (int j = 0; j < v_count; j++)
            {
                adj[i][j] = 0;
            }
        }
    }
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
    }

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
    }
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
    }
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
    }
    void BFS(int start)
    {
        if (start < 0 || start >= v_count)
        {
            cout << "Invalid start node." << endl;
            return;
        }
        bool *visited = new bool[v_count];
        for (int i = 0; i < v_count; i++)
        {
            visited[i] = false;
        }


        Queue q;
        q.enqueue(start);
        visited[start] = true;

        cout << "BFS Traversal: ";
        while (!q.isEmpty())
        {
            int n = q.getFront();
            q.dequeue();
            cout << n << " ";

            for (int i = 0; i < v_count; i++)
            {
                if (adj[n][i] == 1 && !visited[i])
                {
                    q.enqueue(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
        delete[] visited;
    }
    ~Graph()
    {
        for (int i = 0; i < v_count; i++)
        {
            delete[] adj[i];
        }
        delete[] adj;
        adj = NULL;
    }
};
int main()
{
    int vertices;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    g.createGraph();
    g.PrintGraphMatrix();

    int startNode;
    cout << "Enter start node for BFS: ";
    cin >> startNode;

    g.BFS(startNode);

    return 0;
} */

/* //? 2. Implement DFS in Graph Matrix.
#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};
class stack
{
private:
    node *top;

public:
    stack()
    {
        top = NULL;
    }
    void push(int data)
    {
        node *newnode = new node;
        newnode->item = data;
        newnode->next = top;
        top = newnode;
    }
    void pop()
    {
        if (top == NULL)
            return;
        node *t = top;
        top = top->next;
        delete t;
    }
    bool isEmpty()
    {
        return top == NULL;
    }
    int peek()
    {
        if (top == NULL)
            return -1;
        return top->item;
    }
    ~stack()
    {
        while (top != NULL)
            pop();
    }
};
class Graph
{
private:
    int v_count;
    int e_count;
    int **adj;

public:
    Graph(int vertices)
    {
        v_count = vertices;
        e_count = 0;
        adj = new int *[v_count];
        for (int i = 0; i < v_count; i++)
        {
            adj[i] = new int[v_count];
            for (int j = 0; j < v_count; j++)
            {
                adj[i][j] = 0;
            }
        }
    }
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
    }

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
    }
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
    }
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
    }
    void DFS(int start)
    {
        if (start < 0 || start >= v_count)
        {
            cout << "Invalid input." << endl;
            return;
        }
        bool *visited = new bool[v_count];
        for (int i = 0; i < v_count; i++)
        {
            visited[i] = false;
        }

        stack stk;
        stk.push(start);
        visited[start] = true;

        cout << "DFS Traversal: ";
        while (!stk.isEmpty())
        {
            int n = stk.peek();
            stk.pop();
            cout << n << " ";
            
            for (int i = 0; i < v_count; i++)
            {
                if (adj[n][i] == 1 && !visited[i])
                {
                    stk.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
        delete[] visited;
    }
    ~Graph()
    {
        for (int i = 0; i < v_count; i++)
        {
            delete[] adj[i];
        }
        delete[] adj;
        adj = NULL;
    }
};
 */

/* //? 3. Implement BFS in Graph list representation
#include <iostream>
using namespace std;
struct Qnode
{
    int item;
    Qnode *next;
};
class Queue
{
private:
    Qnode *front;
    Qnode *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int data)
    {
        Qnode *newnode = new Qnode;
        newnode->item = data;
        newnode->next = NULL;
        if (front == NULL)
        {
            front = newnode;
            rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }
    void dequeue()
    {
        if (front == NULL)
        {
            return;
        }
        Qnode *t = front;
        if (front == rear)
        {
            front = NULL;
            rear = NULL;
        }
        else
        {
            front = front->next;
        }
        delete t;
    }
    int getFront()
    {
        if (front == NULL)
        {
            return -1;
        }
        return front->item;
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    ~Queue()
    {
        while (front != NULL)
        {
            dequeue();
        }
    }
};
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
    node *getStart()
    {
        return start;
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
    void BFS(int start)
    {
        if (start < 0 || start >= v_count)
        {
            cout << "Invalid start node." << endl;
            return;
        }
        bool *visited = new bool[v_count];
        for (int i = 0; i < v_count; i++)
        {
            visited[i] = false;
        }

        Queue q;
        q.enqueue(start);
        visited[start] = true;

        cout << "BFS Traversal: ";
        while (!q.isEmpty())
        {
            int n = q.getFront();
            q.dequeue();
            cout << n << " ";

            // 🔹 Now traverse adjacency list of node `n` 
            node *adjNode = arr[n].getStart(); // Yeh adjacency list ka start node hai
            while (adjNode)
            {
                int neighbor = adjNode->vertex;
                if (!visited[neighbor])
                {
                    q.enqueue(neighbor);
                    visited[neighbor] = true;
                }
                adjNode = adjNode->next;
            }
        }
        cout << endl;
        delete[] visited;
    }
    ~Graph()
    {
        delete[] arr;
    }
}; */

/* //? 4. Implement DFS in Graph list representation
#include <iostream>
using namespace std;
struct Snode
{
    int item;
    Snode *next;
};
class stack
{
private:
    Snode *top;

public:
    stack()
    {
        top = NULL;
    }
    void push(int data)
    {
        Snode *newnode = new Snode;
        newnode->item = data;
        newnode->next = top;
        top = newnode;
    }
    void pop()
    {
        if (top == NULL)
            return;
        Snode *t = top;
        top = top->next;
        delete t;
    }
    bool isEmpty()
    {
        return top == NULL;
    }
    int peek()
    {
        if (top == NULL)
            return -1;
        return top->item;
    }
    ~stack()
    {
        while (top != NULL)
            pop();
    }
};
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
    node *getStart()
    {
        return start;
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
    void DFS(int start)
    {
        if (start < 0 || start >= v_count)
        {
            cout << "Invalid start node." << endl;
            return;
        }
        bool *visited = new bool[v_count];
        for (int i = 0; i < v_count; i++)
        {
            visited[i] = false;
        }

        stack s;
        s.push(start);
        visited[start] = true;

        cout << "DFS Traversal: ";
        while (!s.isEmpty())
        {
            int n = s.peek();
            s.pop();
            cout << n << " ";

            // 🔹 Now traverse adjacency list of node `n`
            node *adjNode = arr[n].getStart(); // Yeh adjacency list ka start node hai
            while (adjNode)
            {
                int neighbor = adjNode->vertex;
                if (!visited[neighbor])
                {
                    s.push(neighbor);
                    visited[neighbor] = true;
                }
                adjNode = adjNode->next;
            }
        }
        cout << endl;
        delete[] visited;
    }
    ~Graph()
    {
        delete[] arr;
    }
}; */