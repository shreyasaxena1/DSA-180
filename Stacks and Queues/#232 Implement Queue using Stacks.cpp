//Normal
class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    stack<int> s1;
    stack<int> s2;

    /** Push element x to the back of queue. */
    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int result = s1.top();
        s1.pop();
        return result;
    }

    /** Get the front element. */
    int peek()
    {
        return s1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s1.empty();
    }
};

//Amortised
class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    stack<int> input;
    stack<int> output;
    void push(int x)
    {
        input.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int item = output.top();
        output.pop();
        return item;
    }

    /** Get the front element. */
    int peek()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return input.empty() && output.empty();
    }
};
