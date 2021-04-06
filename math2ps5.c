#include <stdio.h>

void q1(void);
void q2(void);
int main(void) {
  q1();
  q2();
  return 0;
}

void q1(void) {
  int a[32], check[32];
  int temp1[16], temp2[16];
  int same = 0, count = 0;

  for (size_t i = 0; i < 32; i++) {
    a[i] = i + 1;
    check[i] = i + 1;
  }

  for (size_t i = 0; i < 32; i++) {
    printf("%02d ", a[i]);
  }
  puts("");
  while (same == 0) {
    for (size_t i = 0; i < 16; i++) {
      temp1[i] = a[i];
      temp2[i] = a[16 + i];
    }
    for (size_t i = 0; i < 16; i++) {
      a[2 * i] = temp1[i];
      a[(2 * i) + 1] = temp2[i];
    }
    for (size_t i = 0; i < 32; i++) {
      printf("%02d ", a[i]);
    }
    puts("");
    count++;
    printf("Iteration: %d\n\n", count);
    same = 1;
    for (size_t i = 0; i < 32; i++) {
      if (a[i] != check[i]) {
        same = 0;
        break;
      }
    }
  }
}

void q2(void) {
  int a[32], check[32];
  int temp1[16], temp2[16];
  int same = 0, count = 0;

  for (size_t i = 0; i < 32; i++) {
    a[i] = i + 1;
    check[i] = i + 1;
  }

  for (size_t i = 0; i < 32; i++) {
    printf("%02d ", a[i]);
  }
  puts("");
  while (same == 0) {
    for (size_t i = 0; i < 16; i++) {
      temp1[i] = a[2 * i];
      temp2[i] = a[(2 * i) + 1];
    }
    for (size_t i = 0; i < 16; i++) {
      a[i] = temp1[i];
      a[16 + i] = temp2[i];
    }
    for (size_t i = 0; i < 32; i++) {
      printf("%02d ", a[i]);
    }
    puts("");
    count++;
    printf("Iteration: %d\n\n", count);
    same = 1;
    for (size_t i = 0; i < 32; i++) {
      if (a[i] != check[i]) {
        same = 0;
        break;
      }
    }
  }
}
