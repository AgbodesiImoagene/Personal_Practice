/*Write a function that counts the number of ways you
can partition n objects using parts up to m (assuming m >= 0)*/
#include <stdio.h>
int partition(int n, int m, int a[], int ind, int end);
int printPartition(int n, int m);
int main() {
  int n, m, x;
  printf("Enter the number of objects n: ");
  scanf("%d", &n);
  printf("Enter the size of the partition m: ");
  scanf("%d", &m);
  if (m > n) {
    printf("The size of the partition cannot be greater than the number of objects. \n");
  } else if ((n <= 0) || (m <= 0)) {
    printf("The size of the partition and the number of objects cannot be 0 or negative. \n");
  } else {
    x = printPartition(n, m);
    printf("There %d are ways n can be partitioned using parts up to m. \n", x);
    return 0;
  }
}
int printPartition(int n, int m) {
  int a[n], i;
  for (i = 0; i < n; i++) {
    a[i] = 0;
  }
  return partition(n, m, a, 0, n);
}
int partition(int n, int m, int a[], int ind, int end) {
  int i, j, x;
  if (n == 0) {
    for (i = 0; i < end; i++) {
      for (j = 0; j < a[i]; j++) {
        printf("|");
      }
      printf(" ");
    }
    printf("\n");
    return 1;
  } else if (m == 0) {
    a[ind] = 0;
    return 0;
  } else {
    if (n - m > m) {
      a[ind] = m;
      x = partition(n - m, m, a, ind + 1, end) + partition(n, m -1, a, ind, end);
    } else {
      a[ind] = m;
      x = partition(n - m, n - m, a, ind + 1, end) + partition(n, m - 1, a, ind, end);
    }
    return x;
  }
}
