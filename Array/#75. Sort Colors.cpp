// O(n) Medium at leetcode

class Solution
{
public:
    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        while(mid<=high)
        {
            switch (nums[mid])
            {
            case 0:
                swap(&nums[mid++], &nums[low++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(&nums[mid], &nums[high--]);
                break;
            }
        }
    }
};
