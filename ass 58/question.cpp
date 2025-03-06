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

//? 5. Define a function to implement quick sort

//? 6. Define a function to implement merge sort

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
    void setEmployee_id(int e) { emp_id = e; }
    void setName(string n) { name = n; }
    void setSalary(float s) { salary = s; }
    int getEmployee_id() { return emp_id; }
    string getName() { return name; }
    float getSalary() { return salary; }
}; */

//? 8. In question-7, define a function to sort Employee Array data by name. Use Quick Sort
