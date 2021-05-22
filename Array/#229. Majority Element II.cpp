//Solved at leetcode
// TC - O(2N) - O(N) SC - O(1)

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> result;
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0, ele1 = -1, ele2 = -1, i;

        for (i = 0; i < n; i++)
        {
            if (ele1 == nums[i])
                cnt1++;
            else if (ele2 == nums[i])
                cnt2++;
            else if (cnt1 == 0)
            {
                ele1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                ele2 = nums[i];
                cnt2 = 1;
            }

            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = cnt2 = 0;
        for (i = 0; i < n; i++)
        {
            if (nums[i] == ele1)
                cnt1++;
            else if (nums[i] == ele2)
                cnt2++;
        }
        if (cnt1 > n / 3)
            result.push_back(ele1);
        if (cnt2 > n / 3)
            result.push_back(ele2);
        return result;
    }
};