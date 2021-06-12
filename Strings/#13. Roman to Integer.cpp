// TC - O(N) SC - O(N)
//Approach : https://youtu.be/dlATMslQ6Uc
class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> table;
        table['I'] = 1;
        table['V'] = 5;
        table['X'] = 10;
        table['L'] = 50;
        table['C'] = 100;
        table['D'] = 500;
        table['M'] = 1000;
        int n = s.length();
        int result = table[s[n - 1]];
        for (int i = n - 2; i >= 0; i--)
        {
            if (table[s[i + 1]] > table[s[i]])
                result -= table[s[i]];
            else
                result += table[s[i]];
        }
        return result;
    }
};