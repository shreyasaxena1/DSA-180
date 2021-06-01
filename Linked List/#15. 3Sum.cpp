//TC - O(N2)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        int n = nums.size();

        for (int i = 0; i < n - 2; i++)
        { //consider till third last as we need triplet
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                int reqsum = 0 - nums[i], low = i + 1, high = n - 1;
                while (low < high)
                {
                    if (nums[low] + nums[high] == reqsum)
                    {
                        vector<int> q(3);
                        q[0] = nums[i];
                        q[1] = nums[low];
                        q[2] = nums[high];
                        result.push_back(q);
                        while (low < high && nums[low] == nums[low + 1])
                            low++;
                        while (low < high && nums[high] == nums[high - 1])
                            high--;
                        low++, high--;
                    }
                    else if (nums[low] + nums[high] < reqsum)
                        low++;
                    else
                        high--;
                }
            }
        }
        return result;
    }
};