class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        stack<int>s;
        s.push(arr[0]);
        int temp=INT_MIN;
        for(int i=1;i<N;i++){
            if(temp>arr[i]) return 0;
            
            while(!s.empty() && s.top()<arr[i])
            {
                temp=s.top();
                s.pop();
            }
            s.push(arr[i]);
        }
        return true;
    }
};
