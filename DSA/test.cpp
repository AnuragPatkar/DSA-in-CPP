/* #include <iostream>
#include <stdio.h>
using namespace std;
struct node
{
    int item;
    node *next;
    node(int data)
    {
        item = data;
        next = NULL;
    }
};
class SLL
{
private:
    node *head;

public:
    SLL()
    {
        head = NULL;
    }
    SLL(const SLL &list)
    {
        head = NULL;
        node *temp = list.head;
        while (temp != NULL) // Fix: Changed 'head' to 'temp'
        {
            AtLast(temp->item);
            temp = temp->next;
        }
    }

    SLL &operator=(const SLL &list)
    {
        if (this != &list)
        {
            while (head != NULL)
                delFirst(); // Clear existing list

            node *temp = list.head;
            while (temp != NULL)
            {
                AtLast(temp->item);
                temp = temp->next;
            }
        }
        return *this;
    }

    void AtStart(int data)
    {
        node *newnode = new node(data);
        newnode->next = head;
        head = newnode;
    }
    void AtLast(int data)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    void After(int key, int data)
    {
        node *newnode = new node(data);
        node *temp = head;
        while (temp->item != key)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    void delFirst()
    {
        node *temp = head;
        head = temp->next;
        delete temp;
    }
    void delLast()
    {
        if (head == NULL)
            return;
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        
    }
    void delNode(int data)
    {

        if (head == NULL)
        {
            cout << "List is empty. Deletion not possible!" << endl;
            return;
        }

        if (head->item == data) // If head node is to be deleted
        {
            delFirst();
            return;
        }

        node *temp = head;

        while (temp->next != NULL && temp->next->item != data)
        {
            temp = temp->next;
        }

        if (temp->next == NULL) // If data is not found
        {
            cout << "Node with value " << data << " not found!" << endl;
            return;
        }

        node *delNode = temp->next;    // Node to be deleted
        temp->next = temp->next->next; // Unlink node
        delete delNode;                // Free memory
    }
    void edit(int old_data, int new_data)
    {
        node *temp = head;
        while (temp != NULL && temp->item != old_data)
        {
            temp = temp->next;
        }
        if (temp->next == NULL) // If data is not found
        {
            cout << "Node with value " << old_data << " not found!" << endl;
            return;
        }
        temp->item = new_data;
    }
    int search(int key)
    {
        int index = 0;
        node *temp = head;

        while (temp != NULL)
        {
            if (temp->item == key)
            {
                return index;
            }
            temp = temp->next;
            index++;
        }

        return -1;
    }
    int count()
    {
        int c = 0;
        node *temp = head;

        while (temp != NULL)
        {
            temp = temp->next;
            c++;
        }

        return c;
    }
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->item << "-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    ~SLL()
    {
        while (head != NULL)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main()
{
    SLL list;
    list.AtStart(10);
    list.AtStart(20);
    list.AtStart(25);
    list.AtLast(5);
    list.After(20, 15);

    list.display();

    SLL list2 = list;
    list2.display();
} */

#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int **arr;
    int lastindex;
    int capacity;

public:
    // ✅ Constructor
    PriorityQueue(int cap) {
        capacity = cap;
        lastindex = -1;
        arr = new int*[capacity];
        for (int i = 0; i < capacity; i++) {
            arr[i] = new int[2];  // [priority, value]
        }
    }

    // ✅ Destructor
    ~PriorityQueue() {
        for (int i = 0; i < capacity; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    // ✅ Insert Function
    void insert(int priority, int value) {
        if (lastindex == capacity - 1) {
            cout << "Queue is full!" << endl;
            return;
        }

        lastindex++;
        int i = lastindex;
        while (i > 0 && arr[i - 1][0] < priority) {
            arr[i][0] = arr[i - 1][0];
            arr[i][1] = arr[i - 1][1];
            i--;
        }
        arr[i][0] = priority;
        arr[i][1] = value;
    }

    // ✅ Display Queue
    void display() {
        if (lastindex == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Priority Queue: ";
        for (int i = 0; i <= lastindex; i++) {
            cout << "(" << arr[i][0] << ", " << arr[i][1] << ") ";
        }
        cout << endl;
    }
};

// ✅ Test Code
int main() {
    PriorityQueue pq(5);
    pq.insert(3, 10);
    pq.insert(5, 20);
    pq.insert(2, 15);
    pq.insert(4, 25);

    pq.display();  // Output: (5, 20) (4, 25) (3, 10) (2, 15)

    return 0;
}


