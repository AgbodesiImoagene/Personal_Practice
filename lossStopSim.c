#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct fraction {
  int numerator;
  int denominator;
} fraction;
fraction decToFraction(double x);
int main() {
  int y;
  double capital, betsize, x, z;
  double odds, risk;
  fraction a;
  printf("What are the odds: ");
  scanf("%lf", &odds);
  printf("What is the risk of losing: ");
  scanf("%lf", &risk);
  x = ((odds * (1.0 - risk)) - risk) / odds;
  if (x < 0) {
    printf("There is no safe bet. \n");
  } else {
    printf("Optimally you should bet %lf of your capital. \n", x);
  }
  printf("What is your capital: ");
  scanf("%lf", &capital);
  printf("How much of your capital will you bet: ");
  scanf("%lf", &betsize);
  x = capital;
  z = betsize / capital;
  a = decToFraction(risk);
  srand(time(0));
  while ((x > capital / 100) && (x < capital * 10)) {
      y = rand() % a.denominator;
      if (y < a.numerator) {
        x -= (z * x);
      } else {
        x += ((odds - 1) * z * x);
      }
      printf("%lf\n", x);
  }
  if (x < capital / 100) {
    printf("You lost all your money.");
  } else {
    printf("Jackpot.");
  }
}
fraction decToFraction(double x) {
  fraction y;
  int a = x, b = 1;
  while (x - a != 0) {
    x *= 10;
    b *= 10;
    a = x;
  }
  while ((a % 2 == 0) && (b % 2 == 0)) {
    a /= 2;
    b /= 2;
  }
  while ((a % 5 == 0) && (b % 5 == 0)) {
    a /= 5;
    b /= 5;
  }
  y.numerator = a;
  y.denominator = b;
  return y;
}
