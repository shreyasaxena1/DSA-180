//TC - O(n) SC-O(1)

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int ver1 = 0, ver2 = 0, i, j;
        for (i = 0, j = 0; (i < version1.length() || j < version2.length());)
        {

            while (i < version1.length() && version1[i] != '.')
            {
                ver1 = ver1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < version2.length() && version2[j] != '.')
            {
                ver2 = ver2 * 10 + (version2[j] - '0');
                j++;
            }

            if (ver1 > ver2)
                return 1;
            if (ver1 < ver2)
                return -1;
            //If they are equal , we need to check for digits after dot
            ver1 = 0, ver2 = 0;
            i++, j++;
        }
        return 0;
    }
};