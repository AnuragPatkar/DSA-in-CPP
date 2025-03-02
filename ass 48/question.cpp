//! Assignment-48: Stack using linked list

/* //? 1. Define a class Stack with node type pointer top as member variable. Implement stack using linked list.
#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};
class STACK
{
private:
    node *start;

public:

}; */

/* //? 2. In question 1, define a constructor to initialise member variable.
STACK()
{
    top = NULL;
} */

/* //? 3. In question 1, define a method to push a new element on to the Stack.
void push(int data)
{
    node *newnode = new node();
    newnode->item = data;
    newnode->next = top;
    top = newnode;
} */

/* //? 4. In question 1, define a method to peek top element of the stack.
int peek()
{
    if (top == NULL)
    {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    return top->item;
} */

/* //? 5. In question 1, define a method to pop the top element of the stack.
void pop()
{
    if (top == NULL)
    {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    node *temp = top;
    top = top->next;
    delete temp;

} */

/* //? 6. In question 1, define a destructor to deallocates the memory.
~STACK()
{
    while (top)
    {
        node *temp = top;
        top = top->next;
        delete temp;
    }
} */

/* //? 7. In question 1, define a copy constructor to implement deep copy.
STACK(STACK &s)
{
    if (s.top == NULL)
    {
        top = NULL;
        return;
    }
    node *t= s.top;
    s.reverse();
    while (t)
    {
        push(t->item);
        t = t->next;
    }
    s.reverse();
} */

/* //? 8. In question 1, define a copy assignment operator to implement deep copy.
STACK &operator=(STACK &s)
{
    if (this != &s)
    {
        if (top != NULL)
        {
            while (top)
                pop();
        }
        if (s.top == NULL)
        {
            top = NULL;
            return *this;
        }

        node *t = s.top;
        s.reverse();
        while (t)
        {
            push(t->item);
            t = t->next;
        }
        s.reverse();
    }
    return *this;
} */

/* //? 9. Define a method to reverse a stack.
void reverse()
{
    STACK S1;
    while (top)
    {
        S1.push(peek());
        pop();
    }
    top = S1.top;
    S1.top = NULL;
} */