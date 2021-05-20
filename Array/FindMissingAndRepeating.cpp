class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {

        int x = 0, y = 0, xor1 = arr[0];

        //xor of all elements
        for (int i = 1; i < n; i++)
            xor1 = xor1 ^ arr[i];

        //xor of result with numbers 1-n
        for (int i = 1; i <= n; i++)
            xor1 = xor1 ^ i;

        //get right most bit
        int getBit = xor1 & ~(xor1 - 1);

        //Make bucket
        for (int i = 0; i < n; i++)
        {
            if (arr[i] & getBit)
                x = x ^ arr[i]; // arr[i] belongs to bucket 1
            else
                y = y ^ arr[i]; // arr[i] belongs to bucket 2
        }

        //add 1-n elements in bucket
        for (int i = 1; i <= n; i++)
        {
            if (i & getBit)
                x = x ^ i; // arr[i] belongs to bucket 1
            else
                y = y ^ i;
        }

        int missing = x, repeating = y;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
            {
                missing = y;
                repeating = x;
                break;
            }
        }

        //0 index- repeating 1 index- missing
        arr[0] = repeating;
        arr[1] = missing;
        return arr;
    }
};