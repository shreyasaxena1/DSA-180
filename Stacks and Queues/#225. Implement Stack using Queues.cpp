//Two Queues

void QueueStack ::push(int x)
{
    if (q1.empty())
        q1.push(x);
    else
    {
        while (q1.empty() == false)
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while (q2.empty() == false)
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
}

int QueueStack ::pop()
{
    if (q1.empty())
        return -1;

    int result = q1.front();
    q1.pop();
    return result;
}

//One queue

class MyStack
{
public:
    /** Initialize your data structure here. */

    queue<int> q;

    /** Push element x onto stack. */
    void push(int x)
    {
        int s = q.size();

        q.push(x);

        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        if (q.empty())
            return -1;

        else
        {
            int temp = q.front();
            q.pop();
            return temp;
        }
    }

    /** Get the top element. */
    int top()
    {
        return (q.empty()) ? -1 : q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return (q.empty());
    }
};
