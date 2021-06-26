class Solution
{
public:
    bool isValid(string x)
    {
        stack<char> s;
        for (int i = 0; i < x.length(); i++)
        {
            if (x[i] == '(' || x[i] == '{' || x[i] == '[')
                s.push(x[i]);
            else
            {
                if (s.empty() == true)
                    return false;
                if (x[i] == ')' && s.top() != '(')
                    return false;
                else if (x[i] == ']' && s.top() != '[')
                    return false;
                else if (x[i] == '}' && s.top() != '{')
                    return false;
                else
                    s.pop();
            }
        }
        return (s.empty() == true);
        ;
    }
};