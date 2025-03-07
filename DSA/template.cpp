/* #include <iostream>
#include <stdio.h>
using namespace std;
template <class X>
class Array
{
private:
    int capicity;
    int lastindex;
    X *ptr; // jha jha data type bdlna h waha data type likh do

public:
    Array();
    Array(Array &); // deep copy
    Array &operator=(const Array &);
    void createArray(X);
    void insert(int, X);
    void append(X);
    X getItem(int);
    bool isEmpty();
    bool isFull();
    void delValue(X);
    void delIndex(int);
    void edit(int, X);
    int count();
    int getCapicity();
    void sort();
    void display();
    X greatest();
    X smallest();
    bool search(X);
    X sum_of_all_elements();
    X average();
    void rotate_right();
    void remove_duplicate();
    X second_greatest();
    void swap(X, X);
    ~Array();
};

template <class X>      // class ke bahar define h isliye her function ke phle ye likhna pdega
Array<class X>::Array() // Array <class X> , ab direct class name ki jagah esa likhna h
{
    ptr = NULL;
}
template <class X>
Array<class X>::Array(Array &arr)
{
    capicity = arr.capicity;
    lastindex = arr.lastindex;
    ptr = new X[capicity]; // new se X type ka array create hoga
    for (int i = 0; i <= lastindex; i++)
    {
        ptr[i] = arr.ptr[i];
    }
}
template <class X>
Array<class X> &Array<class X>::operator=(const Array &arr)
{
    capicity = arr.capicity;
    lastindex = arr.lastindex;
    if (ptr != NULL)
    {
        delete[] ptr;
    }
    ptr = new X[capicity];
    for (int i = 0; i <= lastindex; i++)
    {
        ptr[i] = arr.ptr[i];
    }
    return *this;
}

template <class X>
void Array<class X>::createArray(X c)
{
    this->capicity = c;
    lastindex = -1;
    if (ptr != NULL)
    {
        delete[] ptr;
    }
    ptr = new int[capicity];
}

template <class X>
void Array<class X>::insert(int index, X value)
{
    if (index < 0 || index > lastindex + 1)
    {
        cout << "Invalid index or array is full\n";
        return;
    }

    for (int i = lastindex; i >= index; i--)
    {
        ptr[i + 1] = ptr[i];
    }

    ptr[index] = value;
    lastindex++;
}

template <class X>
void Array<class X>::append(X value)
{
    if (isFull())
    {
        cout << "Error: Array is full.\n";
        return;
    }

    lastindex++;
    ptr[lastindex] = value;
}

template <class X>
X Array<class X>::getItem(int index)
{
    if (index < 0 || index > lastindex)
    {
        cout << "Invalid index\n";
        return -1;
    }
    return ptr[index];
}

template <class X>
bool Array<class X>::isEmpty()
{
    return lastindex == -1;
}

template <class X>
bool Array<class X>::isFull()
{
    return lastindex == capicity - 1;
}

template <class X>
void Array<class X>::delValue(X value)
{
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        if (value == ptr[i])
        {
            break;
        }
    }
    if (i > lastindex)
    {
        cout << "Value not found\n";
        return;
    }

    for (int j = i; j < lastindex; j++)
    {
        ptr[j] = ptr[j + 1];
    }
    lastindex--;
}

template <class X>
void Array<class X>::delIndex(int index)
{
    if (index < 0 || index > lastindex)
    {
        cout << "Invalid index\n";
        return;
    }
    for (int i = index; i < lastindex; i++)
    {
        ptr[i] = ptr[i + 1];
    }
    lastindex--;
}

template <class X>
void Array<class X>::edit(int index, X value)
{
    if (index < 0 || index > lastindex)
    {
        cout << "Invalid index\n";
        return;
    }
    ptr[index] = value;
}

template <class X>
int Array<class X>::count()
{
    return lastindex + 1;
}

template <class X>
int Array<class X>::getCapicity()
{
    return capicity;
}

template <class X>
void Array<class X>::sort()
{
    int i, j, temp;
    for (i = 0; i <= lastindex; i++)
    {
        for (j = 0; j <= lastindex - i - 1; j++)
        {
            if (ptr[j] > ptr[j + 1])
            {
                // Manually swapping values without using swap()
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
}

template <class X>
X Array<class X>::greatest()
{
    int i, max = 0;
    for (i = 0; i <= lastindex; i++)
    {
        if (ptr[i] > max)
            max = ptr[i];
    }
    return max;
}

template <class X>
X Array<class X>::smallest()
{
    int i, min = ptr[0];
    for (i = 0; i <= lastindex; i++)
    {
        if (ptr[i] < min)
            min = ptr[i];
    }
    return min;
}

template <class X>
bool Array<class X>::search(X data)
{
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        if (ptr[i] == data)
            return true;
    }
    return false;
}

template <class X>
X Array<class X>::sum_of_all_elements()
{
    int sum = 0;
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        sum += ptr[i];
    }
    return sum;
}

template <class X>
X Array<class X>::average()
{
    float sum = 0;
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        sum += ptr[i];
    }
    return sum / lastindex;
}

template <class X>
void Array<class X>::rotate_right()
{
    int i;
    int temp = ptr[lastindex];
    for (i = lastindex; i > 0; i--)
    {
        ptr[i] = ptr[i - 1];
    }
    ptr[0] = temp;
}

template <class X>
void Array<class X>::remove_duplicate()
{
    int i, j;
    for (i = 0; i <= lastindex; i++)
    {
        if (ptr[i] != -1)
        {
            for (j = i + 1; j <= lastindex; j++)
            {
                if (ptr[i] == ptr[j])
                    ptr[j] = -1;
            }
        }
    }
    int temp[lastindex];

    for (i = 0, j = 0; i <= lastindex; i++)
    {
        if (ptr[i] != -1)
        {
            temp[j] = ptr[i];
            j++;
        }
    }
    lastindex = j - 1;
    for (i = 0; i <= lastindex; i++)
    {
        ptr[i] = temp[i];
    }
}

template <class X>
X Array<class X>::second_greatest()
{
    if (lastindex < 1)
    {
        cout << "Error:Not enough element." << endl;
        return -1;
    }
    int max = this->greatest();
    int i, second_max = this->smallest();
    for (i = 0; i <= lastindex; i++)
    {
        if (ptr[i] < max && ptr[i] > second_max)
        {
            second_max = ptr[i];
        }
    }
    return second_max;
}

template <class X>
void Array<class X>::swap(X i1, X i2)
{
    if (i1 < 0 || i1 > lastindex || i2 < 0 || i2 > lastindex)
    {
        cout << "Invalid index for swaping." << endl;
        return;
    }
    int temp;
    temp = ptr[i1];
    ptr[i1] = ptr[i2];
    ptr[i2] = temp;
}

template <class X>
void Array<class X>::display()
{
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        cout << ptr[i] << " ";
    }
}

template <class X>
Array<class X>::~Array()
{
    delete[] ptr;
    ptr = NULL;
}
int main()
{
    Array<int> a1;  // Array < typename > krke object bnana h , yaha int as a data type pass ho rha h
    a1.createArray(5);

    a1.insert(0, 6);
    a1.insert(1, 3);
    a1.insert(2, 9);
    a1.insert(3, 5);
    a1.insert(4, 11);
    a1.insert(5, 10);

    cout << "Before Sorting: ";
    a1.display();

    // a1.sort();

    // cout << "After Sorting: ";
    // a1.display();

    // cout << a1.smallest();
    cout << endl;
    // a1.rotate_right();

    // a1.remove_duplicate();
    // a1.display();

    // cout << a1.second_greatest();
    a1.swap(3, 4);
    a1.display();
    return 0;
} */