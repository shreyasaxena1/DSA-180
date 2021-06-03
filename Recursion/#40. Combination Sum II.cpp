//TC - O(2^n * k) k to insert in ds
//SC - O(kx) k-avg length of comb. x-possible comb

class Solution
{
public:
    void getCombinationSum(int ind, int target, vector<int> &candidates, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < candidates.size(); i++)
        {
            if (i > ind && candidates[i - 1] == candidates[i])
                continue;
            if (candidates[i] > target)
                break;
            ds.push_back(candidates[i]);
            getCombinationSum(i + 1, target - candidates[i], candidates, ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;

        getCombinationSum(0, target, candidates, ds, ans);

        return ans;
    }
};