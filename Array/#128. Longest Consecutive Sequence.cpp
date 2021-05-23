//TC - O(N) SC-O(N)
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> u;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            u.insert(nums[i]);
        }
        int finalcount = 0;
        for (int i = 0; i < n; i++)
        {
            if (u.find(nums[i] - 1) == u.end())
            {
                int currmax = 1;
                int currNum = nums[i];
                while (u.find(currNum + 1) != u.end())
                {
                    currNum++;
                    currmax++;
                }
                finalcount = max(finalcount, currmax);
            }
        }
        return finalcount;
    }
};