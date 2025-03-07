//! Assignment-58: Sorting

/* //? 1. Define a function to implement bubble sort
void bubbleSort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
 */

/* //? 2. Define a function to implement modified bubble sort to achieve O(n) time complexity in best case.
void modifiedBubbleSort(int arr[], int size)
{
    int temp;
    bool swapped;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j+1] = temp;

                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
} */

/* //? 3. Define a function to implement insertion sort.
void insertionSort(int arr[], int size)
{
    int temp;
    int i, j;
    for (i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
} */

/* //? 4. Define a function to implement selection sort.
void selectionSort(int arr[], int size)
{
    for (int j = 0; j < size - 1; j++)
    {
        int minIndex = j;
        int min = arr[j];
        for (int i = j + 1; i < size; i++)
        {
            if (min > arr[i])
            {
                min = arr[i];
                minIndex = i;
            }
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[j];
        arr[j] = temp;
    }
} */

/* //? 5. Define a function to implement quick sort
int partition(int arr[], int left, int right)
{
    int temp;
    int loc = left;
    while (left < right)
    {

        while (left < right && arr[loc] <= arr[right])
            right--;
        if (left == right)
            break;
        if (arr[loc] > arr[right])
        {
            temp = arr[loc];
            arr[loc] = arr[right];
            arr[right] = temp;
            loc = right;
        }

        while (left < right && arr[loc] > arr[left])
            left++;
        if (left == right)
            break;
        if (arr[loc] < arr[left])
        {
            temp = arr[loc];
            arr[loc] = arr[left];
            arr[left] = temp;
            loc = left;
        }
    }
    return loc;
}
void quickSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int p = partition(arr, left, right);
    quickSort(arr, left, p - 1);
    quickSort(arr, p + 1, right);
} */

/* //? 6. Define a function to implement merge sort
void merge(int arr[], int left, int m, int right)
{
    int LeftArray[m - left + 1], RightArray[right - m], i, j, k;
    for (i = 0; i < m - left + 1; i++)
        LeftArray[i] = arr[left + i];
    for (j = 0; j < right - m; j++)
        RightArray[j] = arr[m + 1 + j];

    for (i = 0, j = 0, k = left; i < m - left + 1 && j < right - m; k++)
    {
        if (LeftArray[i] < RightArray[j])
        {
            arr[k] = LeftArray[i];
            i++;
        }
        else
        {
            arr[k] = RightArray[j];
            j++;
        }
    }
    while (i < m - left + 1)
    {
        arr[k] = LeftArray[i];
        i++;
        k++;
    }
    while (j < right - m)
    {
        arr[k] = RightArray[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int left, int right)
{
    if (left >= right)
        return;
    int m = left + (right - left) / 2;
    mergesort(arr, left, m);
    mergesort(arr, m + 1, right);
    merge(arr, left, m, right);
}*/

/* //? 7. Define a class Employee with emp_id, name, salary as instance variables. Provide setters and getters in the class to access instance variables. Also define a function to sort Employee Array data by salary. Use Merge Sort.
#include <iostream>
using namespace std;

class Employee
{
private:
    int emp_id;
    string name;
    float salary;

public:
    Employee() {}
    Employee(int id, string n, float s) : emp_id(id), name(n), salary(s) {}
    void setEmployee_Id(int id) { emp_id = id; }
    void setName(string n) { name = n; }
    void setSalary(float s) { salary = s; }
    int getEmployee_ID() { return emp_id; }
    string getName() { return name; }
    float getSalary() { return salary; }
    void displayEmployee()
    {
        cout << "Employee id: " << emp_id << " " << "Name: " << name << " " << "Salary: " << salary << endl;
    }
};
void merge(Employee arr[], int left, int m, int right)
{
    Employee LeftArray[m - left + 1], RightArray[right - m];
    int i, j, k;
    for (i = 0; i < m - left + 1; i++)
        LeftArray[i] = arr[left + i];
    for (j = 0; j < right - m; j++)
        RightArray[j] = arr[m + 1 + j];

    for (i = 0, j = 0, k = left; i < m - left + 1 && j < right - m; k++)
    {
        if (LeftArray[i].getSalary() < RightArray[j].getSalary())
        {
            arr[k] = LeftArray[i];
            i++;
        }
        else
        {
            arr[k] = RightArray[j];
            j++;
        }
    }
    while (i < m - left + 1)
    {
        arr[k] = LeftArray[i];
        i++;
        k++;
    }
    while (j < right - m)
    {
        arr[k] = RightArray[j];
        j++;
        k++;
    }
}
void mergesort(Employee arr[], int left, int right)
{
    if (left >= right)
        return;
    int m = left + (right - left) / 2;
    mergesort(arr, left, m);
    mergesort(arr, m + 1, right);
    merge(arr, left, m, right);
}
void printEmployees(Employee arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i].displayEmployee();
}
int main()
{
    Employee e[5] = {Employee(101, "Shanti", 15000.00),
                     Employee(102, "Bhanu", 12000.00),
                     Employee(103, "Ajay", 18000.00),
                     Employee(104, "Deepti", 10000.00),
                     Employee(105, "Anurag", 16000.00)};

    int size = sizeof(e) / sizeof(e[0]);
    printEmployees(e, size);

    mergesort(e,0,size-1);

    printEmployees(e,size);
    return 0;
} */

/* //? 8. In question-7, define a function to sort Employee Array data by name. Use Quick Sort
#include <iostream>
using namespace std;
class Employee
{
private:
    int emp_id;
    string name;
    float salary;

public:
    Employee() {}
    Employee(int id, string n, int s) : emp_id(id), name(n), salary(s) {}
    void setEmployee_id(int e) { emp_id = e; }
    void setName(string n) { name = n; }
    void setSalary(float s) { salary = s; }
    int getEmployee_id() { return emp_id; }
    string getName() { return name; }
    float getSalary() { return salary; }
    void displayEmployee()
    {
        cout << "Employee: " << endl;
        cout << "ID: " << emp_id << " Name: " << name << " Salary: " << salary << endl;
    }
    bool operator<=(const Employee &other) { return this->name <= other.name; }
    bool operator>(const Employee &other) { return this->name > other.name; }
};
int partition(Employee arr[], int low, int high)
{
    Employee pivot = arr[low]; // First element as pivot
    int i = low + 1;
    int j = high;

    while (true)
    {
        while (i <= j && arr[i] <= pivot) // Compare based on Name
            i++;
        while (arr[j] > pivot) // Compare based on Name
            j--;

        if (i >= j)
            break;

        swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(Employee arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}
void merge(Employee arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    Employee leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the two arrays
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i].getSalary() <= rightArr[j].getSalary())
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    // Copy remaining elements
    while (i < n1)
        arr[k++] = leftArr[i++];
    while (j < n2)
        arr[k++] = rightArr[j++];
}

// Merge Sort Function
void mergeSort(Employee arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // Find the middle point
        mergeSort(arr, left, mid);           // Sort first half
        mergeSort(arr, mid + 1, right);      // Sort second half
        merge(arr, left, mid, right);        // Merge the two halves
    }
}
void printEmployees(Employee arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i].displayEmployee();
}
int main()
{
    Employee e[5] = {Employee(101, "John", 50000),
                     Employee(102, "Alice", 70000),
                     Employee(103, "Bob", 45000),
                     Employee(104, "Emma", 60000),
                     Employee(105, "David", 55000)};
    int n=sizeof(e)/sizeof(e[0]);
    cout<<"Employee Details: "<<endl;
    printEmployees(e,n);

    quickSort(e,0,n-1);
    // mergeSort(e,0,n-1);

    cout<<"After Sorting(by Salary): "<<endl;
    printEmployees(e,n);
    return 0;
} */

/* #include <iostream>
using namespace std;

class Employee
{
private:
    int emp_id;
    string name;
    float salary;

public:
    Employee() {}
    Employee(int id, string n, float s) : emp_id(id), name(n), salary(s) {}
    void setEmployee_Id(int id) { emp_id = id; }
    void setName(string n) { name = n; }
    void setSalary(float s) { salary = s; }
    int getEmployee_ID() { return emp_id; }
    string getName() { return name; }
    float getSalary() { return salary; }
    void displayEmployee()
    {
        cout << "Employee id: " << emp_id << " " << "Name: " << name << " " << "Salary: " << salary << endl;
    }
};
void merge(Employee arr[], int left, int m, int right)
{
    Employee LeftArray[m - left + 1], RightArray[right - m];
    int i, j, k;
    for (i = 0; i < m - left + 1; i++)
        LeftArray[i] = arr[left + i];
    for (j = 0; j < right - m; j++)
        RightArray[j] = arr[m + 1 + j];

    for (i = 0, j = 0, k = left; i < m - left + 1 && j < right - m; k++)
    {
        if (LeftArray[i].getSalary() < RightArray[j].getSalary())
        {
            arr[k] = LeftArray[i];
            i++;
        }
        else
        {
            arr[k] = RightArray[j];
            j++;
        }
    }
    while (i < m - left + 1)
    {
        arr[k] = LeftArray[i];
        i++;
        k++;
    }
    while (j < right - m)
    {
        arr[k] = RightArray[j];
        j++;
        k++;
    }
}
void mergesort(Employee arr[], int left, int right)
{
    if (left >= right)
        return;
    int m = left + (right - left) / 2;
    mergesort(arr, left, m);
    mergesort(arr, m + 1, right);
    merge(arr, left, m, right);
}

int partition(Employee arr[], int left, int right)
{
    Employee temp;
    int loc = left;
    while (left < right)
    {

        while (left < right && arr[loc].getName() <= arr[right].getName())
            right--;
        if (left == right)
            break;
        if (arr[loc].getName() > arr[right].getName())
        {
            temp = arr[loc];
            arr[loc] = arr[right];
            arr[right] = temp;
            loc = right;
        }

        while (left < right && arr[loc].getName() > arr[left].getName())
            left++;
        if (left == right)
            break;
        if (arr[loc].getName() < arr[left].getName())
        {
            temp = arr[loc];
            arr[loc] = arr[left];
            arr[left] = temp;
            loc = left;
        }
    }
    return loc;
}
void quickSort(Employee arr[], int left, int right)
{
    if (left >= right)
        return;

    int p = partition(arr, left, right);
    quickSort(arr, left, p - 1);
    quickSort(arr, p + 1, right);
}
void printEmployees(Employee arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i].displayEmployee();
}
int main()
{
    Employee e[5] = {Employee(101, "Shanti", 15000.00),
                     Employee(102, "Bhanu", 12000.00),
                     Employee(103, "Ajay", 18000.00),
                     Employee(104, "Deepti", 10000.00),
                     Employee(105, "Anurag", 16000.00)};

    int size = sizeof(e) / sizeof(e[0]);
    printEmployees(e, size);

    // mergesort(e,0,size-1);
    quickSort(e,0,size-1);

    printEmployees(e,size);
    return 0;
} */