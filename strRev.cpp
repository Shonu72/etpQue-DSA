
#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
class Stack{
private:
    char arr[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX_SIZE - 1;
    }

    void push(char c)
    {
        if (isFull())
        {
            cout << "Stack Overflow Error" << endl;
        }
        else
        {
            top++;
            arr[top] = c;
        }
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow Error" << endl;
            return -1; // or any other value that indicates error
        }
        else
        {
            char c = arr[top];
            top--;
            return c;
        }
    }
};

int main()
{
    Stack s;
    string str = "Ramesh Kumar";
    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }
    while (!s.isEmpty())
    {
        cout << s.pop();
    }
    return 0;
}
