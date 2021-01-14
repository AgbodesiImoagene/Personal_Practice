#include <stdio.h>
void combinationUtil(int arr[], int data[], int start, int end, int index, int r);
void printCombination(int arr[], int n, int r);
int main(void) {
  int i, x, y;
  printf("Enter number: ");
  scanf("%d", &x);
  printf("Enter number of boxes: ");
  scanf("%d", &y);
  int arr[x];
  for (i = 0; i < x; i++) {
    arr[i] = i + 1;
  }
  printCombination(arr, x, y);
  return 0;
}
void printCombination(int arr[], int n, int r) {
  int data[r];
  combinationUtil(arr, data, 0, n - 1, 0, r);
  return;
}
/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be printed */
void combinationUtil(int arr[], int data[], int start, int end, int index, int r) {
  int i, j;
  // Current combination is ready to be printed, print it
  if (index == r) {
    for (j = 0; j < r; j++) {
      printf("%d ", data[j]);
    }
    printf("\n");
    return;
  }
  // replace index with all possible elements. The condition
  // "end-i+1 >= r-index" makes sure that including one element
  // at index will make a combination with remaining elements
  // at remaining positions
  for (i = start; (i <= end); i++) {
    data[index] = arr[i];
    combinationUtil(arr, data, i + 1, end, index + 1, r);
  }
  return;
}
