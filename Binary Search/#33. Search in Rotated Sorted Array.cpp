
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (nums[mid] == target)
                return mid;
            //if left sorted
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid]) //lie within the left sorted array
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                //if left not sorted - right sorted
                //check within its limit
                if (nums[mid] <= target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};