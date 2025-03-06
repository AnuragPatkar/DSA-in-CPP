//! Assignment-59: Heap, Searching

/* //? 1. Define a function to implement linear search.
int linearSearch(int arr[],int size,int item)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==item)
          return i;
    }
    return -1;
} */

/* //? 2. Define a function to implement binary search.
int binarySearch(int arr[], int l, int r, int item)
{
    if (l > r)
    return -1;

    int m = (l + r) / 2;
    if (arr[m] == item)
        return m;
    if (item < arr[m])
        binarySearch(arr, l, m - 1, item);
    else
        binarySearch(arr, m + 1, r, item);
}
 */

/* //? 3. Define a class Heap with member variables capacity, lastIndex and pointer ptr.
#include <iostream>
using namespace std;
class Heap
{
private:
    int capacity;
    int lastindex;
    int *ptr;

public:
    Heap();
    Heap(int size);
    void insert(int data);
    int getTopElement();
    void del();
    void heapSort();
    void printHeap();
    ~Heap();
};
Heap::Heap()
{
    capacity = 0;
    lastindex = -1;
    ptr = NULL;
}
Heap::Heap(int size)
{
    capacity = size;
    lastindex = -1;
    ptr = new int[capacity];
}
void Heap::insert(int data)
{
    if (lastindex == capacity - 1)
    {
        cout << "Heap is full, cannot insert." << endl;
        return;
    }

    lastindex++;
    ptr[lastindex] = data;

    // Heapify-Up to maintain heap property
    int i = lastindex;
    while (i > 0)
    {
        int parent = (i - 1) / 2; // Find parent index
        if (ptr[parent] < ptr[i]) // Max heap condition: parent should be greater
        {
            swap(ptr[parent], ptr[i]); // Swap if child is greater
            i = parent;                // Move up
        }
        else
        {
            break; // Heap property satisfied
        }
    }
}
int Heap::getTopElement()
{
    if (lastindex == -1)
    {
        cout << "Heap is Empty." << endl;
        return -1;
    }
    return ptr[0];
}
void Heap::del()
{
    if (lastindex == -1)
    {
        cout << "Heap is Empty." << endl;
        return;
    }
    ptr[0] = ptr[lastindex];
    lastindex--;

    int i = 0;
    while (true)
    {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int largest = i;

        if (leftChild <= lastindex && ptr[leftChild] > ptr[largest])
            largest = leftChild;
        if (rightChild <= lastindex && ptr[rightChild] > ptr[largest])
            largest = rightChild;

        if (largest != i)
        {
            swap(ptr[i], ptr[largest]);
            i = largest;
        }
        else
            break;
    }
}
void Heap::heapSort()
{
    int originalSize = lastindex;
    for (int i = lastindex; i > 0; i--)
    {
        swap(ptr[0], ptr[i]);
        lastindex--;
        int j = 0;
        while (true)
        {
            int leftChild = 2 * j + 1;
            int rightChild = 2 * j + 2;
            int largest = j;

            if (leftChild <= lastindex && ptr[leftChild] > ptr[largest])
                largest = leftChild;
            if (rightChild <= lastindex && ptr[rightChild] > ptr[largest])
                largest = rightChild;

            if (largest != j)
            {
                swap(ptr[j], ptr[largest]);
                j = largest;
            }
            else
                break;
        }
    }
    lastindex = originalSize;
}
void Heap::printHeap()
{
    for (int i = 0; i <= lastindex; i++)
        cout << ptr[i] << " ";
    cout << endl;
}

Heap::~Heap()
{
    delete[] ptr;
}
int main()
{
    Heap h(10);
    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(5);
    h.insert(60);

    cout << "Heap elements: ";
    h.printHeap();

    cout << "Top element: " << h.getTopElement() << endl;

    h.del();
    cout << "After deleting top element: ";
    h.printHeap();

    h.heapSort();
    cout << "Sorted elements: ";
    h.printHeap();

    return 0;
} */

/* //? 4. In question 3, define a parameterised constructor to create a heap of given size.
Heap::Heap(int size)
{
    capacity = size;
    lastindex = -1;
    ptr = new int[capacity];
} */

/* //? 5. In question 3, define a function to insert data in the heap.
void Heap::insert(int data)
{
    if (lastindex == capacity - 1)
    {
        cout << "Heap is full, cannot insert." << endl;
        return;
    }

    lastindex++;
    ptr[lastindex] = data;

    // Heapify-Up to maintain heap property
    int i = lastindex;
    while (i > 0)
    {
        int parent = (i - 1) / 2; // Find parent index
        if (ptr[parent] < ptr[i]) // Max heap condition: parent should be greater
        {
            swap(ptr[parent], ptr[i]); // Swap if child is greater
            i = parent;                // Move up
        }
        else
        {
            break; // Heap property satisfied
        }
    }
} */

/* //? 6. In question 3, define a function to get the top element of the heap.
int Heap::getTopElement()
{
    if(lastindex==-1)
    {
        cout<<"Heap is Empty."<<endl;
        return -1;
    }
    return ptr[0];
} */

/* //? 7. In question 3, define a function to delete a data from the heap.
void Heap::del()
{
    if (lastindex == -1)
    {
        cout << "Heap is Empty." << endl;
        return;
    }
    ptr[0] = ptr[lastindex];
    lastindex--;

    int i = 0;
    while (true)
    {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int largest = i;

        if (leftChild <= lastindex && ptr[leftChild] > ptr[largest])
            largest = leftChild;
        if (rightChild <= lastindex && ptr[rightChild] > ptr[largest])
            largest = rightChild;

        if (largest != i)
        {
            swap(ptr[i], ptr[largest]);
            i = largest;
        }
        else
            break;
    }
} */

/* //? 8. Define a function to implement heap sort.
void Heap::heapSort()
{
    int originalSize = lastindex;
    for (int i = lastindex; i > 0; i--)
    {
        swap(ptr[0], ptr[i]);
        lastindex--;
        int j = 0;
        while (true)
        {
            int leftChild = 2 * j + 1;
            int rightChild = 2 * j + 2;
            int largest = j;

            if (leftChild <= lastindex && ptr[leftChild] > ptr[largest])
                largest = leftChild;
            if (rightChild <= lastindex && ptr[rightChild] > ptr[largest])
                largest = rightChild;

            if (largest != j)
            {
                swap(ptr[j], ptr[largest]);
                j = largest;
            }
            else
                break;
        }
    }
    lastindex = originalSize;
} */