/* IMPLEMENTING STACK USING ARRAY */

#include <iostream>
using namespace std;
class stackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    stackUsingArray(int size)
    {
        capacity = size;
        data = new int[size];
        nextIndex = 0;
    }

    // Return number of element in stack
    int size()
    {
        return nextIndex;
    }

    // is empty function
    bool isEmpty()
    {
        return nextIndex == 0;
    }

    // insert function
    void push(int element)
    {
        if (nextIndex < capacity)
        {
            data[nextIndex] = element;
            nextIndex++;
        }
        else
        {
            cout << "Stack is already full " << element << endl;
        }
    }

    // Delete function
    int pop()
    {
        if (isEmpty())
        {
            return -1;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // Top element
    int top()
    {
        if (isEmpty())
        {
            return -1;
        }
        return data[nextIndex - 1];
    }
};

int main()
{
    stackUsingArray st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout << st.pop();
    cout << st.pop();
}