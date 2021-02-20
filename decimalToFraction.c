#include <stdio.h>
int main() {
  double x, a;
  int b, c, i = 2;
  printf("Enter the decimal number: ");
  scanf("%lf", &x);
  a = x;
  b = 1;
  c = x;
  while (a - c != 0) {
    a *= 10;
    b *= 10;
    c = a;
    printf(" double %lf int %d\n", a, c);
  }
  while (i < 6) {
    if ((c % i == 0) && (b % i  == 0)) {
      c /= i;
      b /= i;
    } else {
      i++;
    }
  }
  printf("Fraction is %d / %d\n", c, b);

  return 0;
}
