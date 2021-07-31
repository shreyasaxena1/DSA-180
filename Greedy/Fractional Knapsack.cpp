class Solution {
public:
  static bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
  }
  // Function to get the maximum total value in the knapsack.
  double fractionalKnapsack(int W, Item arr[], int n) {

    sort(arr, arr + n, cmp);

    int currWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
      if (currWeight + arr[i].weight <= W) {
        currWeight += arr[i].weight;
        finalValue += arr[i].value;

      } else {
        int need = W - currWeight;
        currWeight += need;
        finalValue +=
            ((double)arr[i].value / (double)arr[i].weight) * (double)need;
        break;
      }
    }
    return finalValue;
  }
};