//! Assignment-60: Hashing

//? 1. To store student records use hash table data structure. Define a class Student with member variables rollNumber, name, stream, year. Also define appropriate member function to handle Student class.
#include <iostream>
using namespace std;

class Student
{
private:
    int roll_no;
    string name;
    string stream;
    int year;

public:
    Student() {}
    void createStudent(int r, string n, string s, int y)
    {
        roll_no = r;
        name = n;
        stream = s;
        year = y;
    }
    void display()
    {
        cout << "Roll No: " << roll_no << endl;
        cout << "Name: " << name << endl;
        cout << "stream: " << stream << endl;
        cout << "year: " << year << endl;
    }
};
class HashTable
{
private:
    static const int size = 10;
    Student table[size];

public:
    HashTable() {};
    
};
//? 2. Define a structure node with member variables item of type Student and next pointer.

//? 3. Define a class HashTable with member variables capacity, a node pointer to point an array of node pointers (refer Question 2). Implement hashing with the help of open hashing method.

//? 4. Define a hashFunction which takes roll number as a key and return index number of the array of node pointers (refer Question 3).

//? 5. Define a function to insert Student data in the Hash Table

//? 6. Define a search function to find the Student data using rollNumber