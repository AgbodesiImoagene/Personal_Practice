#include <stdio.h>
int main(int argc, char const *argv[]) {
  static int m[2];
  printf("%d\n", m[0] += 1);
  return 0;
}
