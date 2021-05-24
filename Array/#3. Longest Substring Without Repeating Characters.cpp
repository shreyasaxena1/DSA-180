class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> ind(256, -1);
        int left = 0, right = 0, len = 0;
        int n = s.length();

        while (right < n)
        {
            if (ind[s[right]] != -1)
                left = max(left, ind[s[right]] + 1);

            ind[s[right]] = right;

            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};