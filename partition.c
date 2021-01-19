/*Write a function that counts the number of ways you
can partition n objects using parts up to m (assuming m >= 0)*/
#include <stdio.h>
int partition(int n, int m);
int main() {
  int n, m, x;
  printf("Enter the number of objects n: ");
  scanf("%d", &n);
  printf("Enter the size of the partition m: ");
  scanf("%d", &m);
  x = partition(n, m);
  printf("There %d are ways n can be partitioned using parts up to m. \n", x);
  return 0;
}
int partition(int n, int m) {
  int x;
  if (n == 0) {
    return 1;
  } else if (m == 0) {
    return 0;
  } else {
    if (n - m > m) {
      x = partition(n - m, m) + partition(n, m -1);
    } else {
      x = partition(n - m, n - m) + partition(n, m - 1);
    }
    return x;
  }
}
