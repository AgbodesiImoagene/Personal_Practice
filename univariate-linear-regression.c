#include <stdio.h>
#include <stdlib.h>
#define STR_LEN 100
double summation0(double variables[], double results[], int size, double theta0, double theta1);
double summation1(double variables[], double results[], int size, double theta0, double theta1);
int main(int argc, char const *argv[]) {
  if (argc < 2) {
    puts("No file specified. ");
    exit(EXIT_FAILURE);
  }
  FILE *fp;
  if ((fp = fopen(argv[1], "r")) == NULL) {
    puts("File not found. ");
    exit(EXIT_FAILURE);
  }

  int size = 0;
  char temp[STR_LEN];
  while (!feof(fp)) {
    fgets(temp, STR_LEN, fp);
    size++;
  }
  size -= 1;
  rewind(fp);
  double variables[size], results[size];
  for (size_t i = 0; i < size; i++) {
    fscanf(fp, "%lf %lf", &variables[i], &results[i]);
  }
  double theta0 = 0, theta1 = 0;
  const double learningRate = 0.01;
  int convergence = 0, convergence0 = 0, convergence1 = 0;
  while (convergence == 0) {
    double temp0, temp1;
    temp0 = theta0 - ((learningRate * summation0(variables, results, size, theta0, theta1)) / size);
    temp1 = theta1 - ((learningRate * summation1(variables, results, size, theta0, theta1)) / size);
    if (temp0 == theta0) {
      convergence0 = 1;
    }
    if (temp1 == theta1) {
      convergence1 = 1;
    }
    if ((convergence0 == 1) && (convergence1 == 1)) {
      convergence = 1;
    }
    theta0 = temp0;
    theta1 = temp1;
  }
  printf("theta0 is %lf and theta1 is %lf\n", theta0, theta1);

  double x;
  printf("Enter the value you want to predict the result of: ");
  scanf("%lf", &x);
  printf("The result is %lf. \n", theta0 + theta1 * x);
  return 0;
}

double summation0(double variables[], double results[], int size, double theta0, double theta1) {
  double sum = 0;
  for (size_t i = 0; i < size; i++) {
    sum += (theta0 + (theta1 * variables[i])) - results[i];
  }
  return sum;
}

double summation1(double variables[], double results[], int size, double theta0, double theta1) {
  double sum = 0;
  for (size_t i = 0; i < size; i++) {
    sum += ((theta0 + (theta1 * variables[i])) - results[i]) * variables[i];
  }
  return sum;
}
