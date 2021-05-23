//TC - O(N3)

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;

        if (nums.empty())
            return result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {

            for (int j = i + 1; j < n; j++)
            {
                int left = j + 1;
                int right = n - 1;

                int target_2 = target - nums[i] - nums[j];

                while (left < right)
                {
                    int two_sum = nums[left] + nums[right];
                    if (two_sum < target_2)
                        left++;
                    else if (two_sum > target_2)
                        right--;
                    else
                    {
                        vector<int> quad(4, 0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[left];
                        quad[3] = nums[right];
                        result.push_back(quad);
                        while (left < right && nums[left] == quad[2])
                            ++left;
                        while (left < right && nums[right] == quad[3])
                            --right;
                    }
                }
                while (j + 1 < n && nums[j] == nums[j + 1])
                    ++j;
            }
            while (i + 1 < n && nums[i] == nums[i + 1])
                ++i;
        }
        return result;
    }
};