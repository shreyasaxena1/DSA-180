//TC - O(N)  SC - O(1)

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxOnes = 0;
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                cnt++;
            else
                cnt = 0;

            maxOnes = max(cnt, maxOnes);
        }
        return maxOnes;
    }
};