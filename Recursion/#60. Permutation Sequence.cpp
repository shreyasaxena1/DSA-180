//TC - O(N^2) SC - O(N)
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> numbers;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;      //calculating n-1 factorial : as we first fix 1 and permute for n-1 places
            numbers.push_back(i); //pushing all nos in vector
        }
        numbers.push_back(n);
        string ans = "";
        k = k - 1; //as number consider to be start by index 0
        while (true)
        {
            ans = ans + to_string(numbers[k / fact]); //adding fixed digit
            numbers.erase(numbers.begin() + k / fact);
            if (numbers.size() == 0)
                break;

            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};