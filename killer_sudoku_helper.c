#include <stdio.h>
void combinationUtil(int arr[], int data[], int start, int end, int index, int r, int x);
void printCombination(int arr[], int n, int r, int x);
int main(void) {
  int x, y;
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  printf("Enter number: ");
  scanf("%d", &x);
  printf("Enter number of boxes: ");
  scanf("%d", &y);
  printCombination(arr, 9, y, x);
  return 0;
}
void printCombination(int arr[], int n, int r, int x) {
  int data[r];
  combinationUtil(arr, data, 0, n - 1, 0, r, x);
  return;
}
void combinationUtil(int arr[], int data[], int start, int end, int index, int r, int x) {
  int i, j, k, y = 0;
  if (index == r) {
    for (k = 0; k < r; k++) {
      y += data[k];
    }
    if (y == x) {
      for (j = 0; j < r; j++) {
        printf("%d ", data[j]);
      }
      printf("\n");
    }
    return;
  }
  for (i = start; (i <= end) && (end - i + 1 >= r - index); i++) {
    data[index] = arr[i];
    combinationUtil(arr, data, i + 1, end, index + 1, r, x);
  }
  return;
}
