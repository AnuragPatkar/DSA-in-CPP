//! Assignment-41: Problems on Arrays

/* //? 1. Define a function to sort elements of the array.
void Array::sort()
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
 */

/* //? 2. Define a function to find the greatest element in the array
int Array::greatest()
{
    int i, max = 0;
    for (i = 0; i <= lastindex; i++)
    {
        if (ptr[i] > max)
            max = ptr[i];
    }
    return max;
} */

/* //? 3. Define a function to find the smallest element in the array
int Array::smallest()
{
    int i, min = ptr[0];
    for (i = 0; i <= lastindex; i++)
    {
        if (ptr[i] < min)
            min = ptr[i];
    }
    return min;
} */

/* //? 4. Define a function to search an element in the array
bool Array::search(int data)
{
    int i;
    for(i=0;i<=lastindex;i++)
    {
        if(ptr[i]==data)
         return true;
    }
    return false;
} */

/* //? 5. Define a function to calculate sum of all the elements of an array.
int Array::sum_of_all_elements()
{
    int sum = 0;
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        sum += ptr[i];
    }
    return sum;
} */

/* //? 6. Define a function to calculate average of all the elements of an array.
float Array::average()
{
    float sum = 0;
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        sum += ptr[i];
    }
    return sum/lastindex;
} */

/* //? 7. Define a function to rotate an array towards right by one position
void Array::rotate_right()
{
    int i;
    int temp = ptr[lastindex];
    for (i = lastindex; i>0; i--)
    {
        ptr[i] = ptr[i-1];
    }
    ptr[0] = temp;
} */

/* //? 8. Define a function to remove duplicate elements in the array.
void Array::remove_duplicate()
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
    lastindex=j-1;
    for(i=0;i<=lastindex;i++)
    {
        ptr[i]=temp[i];
    }
} */

/* //? 9. Define a function to find the second largest element in the array.
int Array::second_greatest()
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
} */

/* //? 10. Define a function to swap elements with specified indices in the array.
void Array::swap(int i1, int i2)
{
    if (i1 < 0 || i1 > lastindex || i2 < 0 || i2 > lastindex)
    {
        cout << "Invalid index for swaping." << endl;
        return;
    }
    int temp;
    temp=ptr[i1];
    ptr[i1]=ptr[i2];
    ptr[i2]=temp;
} */