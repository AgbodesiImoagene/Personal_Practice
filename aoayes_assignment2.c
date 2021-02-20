#include <stdio.h>
int main() {
  FILE *file;
  int a = 0, e = 0, i = 0, o = 0, u = 0, j;
  char car[1000];
  file = fopen("newprogram.txt", "r");
  for (j = 0; j < 200; j++) {
    car[j] = fgetc(file);
  }
  fclose(file);
  car[j] = '\0';
  printf("%s\n", car);
  for (j = 0; j < 200; j++) {
    if ((car[j] == 'a') || (car[j] == 'A')) {
      a++;
    } else if ((car[j] == 'e') || (car[j] == 'E')) {
      e++;
    } else if ((car[j] == 'i') || (car[j] == 'I')) {
      i++;
    } else if ((car[j] == 'o') || (car[j] == 'O')) {
      o++;
    } else if ((car[j] == 'u') || (car[j] == 'U')) {
      u++;
    }
  }
  printf("There are %d a's in the first 200 characters of the file\n", a);
  printf("There are %d e's in the first 200 characters of the file\n", e);
  printf("There are %d i's in the first 200 characters of the file\n", i);
  printf("There are %d o's in the first 200 characters of the file\n", o);
  printf("There are %d u's in the first 200 characters of the file\n", u);
  return 0;
}
