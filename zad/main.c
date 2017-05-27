#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void header(short number) {
  printf("\n========== %d =========\n\n", number);
}

void zadanie1() {
  header(1);
  int a=14, b=7, c;
  c=a^b;
  printf("%d %d\n", c, a>b?a:b);
  printf("%d %d\n", a/b, b/a);
  printf("%d %d\n", a%b, b%a);
  printf("%d %d\n", a&b, b|a);
  printf("%d %d\n", a<<3, b>>1);
  printf("%d %d\n", ~a, !b);
}

double fn(float x) {
  double p = pow(x, 4);
  double x3 = 4 * (p - x);
  double x2 = 3.5 * x * x;
  double x1 = 1.5 * x;
  return p - x3 + x2 - x1 + 2;
}

void zadanie2(int n) {
  header(2);
  int j, i = 0, number = 0, max = n + 2 * (n - 1);
  while(i <= n) {
    j = 0;
    int line = 1 + 2 * (i - 1);
    int offset = (max - line)/2;
    printf("%*c", offset, ' ');
    while(j < line) {
      printf("%x", number);
      number++;
      if(number > 15) number = 0;
      j++;
    }
    printf("\n");
    i++;
  }
}

void zadanie3(float start, float end, float delta) {
  header(3);
  printf("    x         f(x)     \n");
  printf("=======================\n");
  while(start <= end) {
    printf("%6.2lf %12.5lf \n", start, fn(start));
    start += delta;
  }
}

void row(int length, int offset, char c) {
  char* s = malloc(length*sizeof(char));
  int i = 0;
  while(i < length) {
    s[i] = c;
    i++;
  }
  if(offset > 0) {
    printf("%*c", offset, ' ');
  }
  printf("%s\n", s);
  free(s);
}

void zadanie4(const int w, const int h) {
  header(4);
  int i = 1;
  row(w, 0, '#');
  while(i <= h - 2) {
    printf("%*c", i + 1, '#');
    printf("%*c\n", w - 1, '#');
    i++;
  }
  row(w, i, '#');
}

void zadanie5() {
  header(5);
  char s[100];
  int i = 0;
  scanf("%s", s);
  unsigned long len = strlen(s);
  while(i < len) {
    if(s[i] >= 97) s[i] -= 32;
    i++;
  }
  printf("%s | %lu\n", s, len);
}

void count(long number, int* acc, int* it) {
  *it += 1;
  if(number != 0 && number != 1) {
    int mod = number % 2;
    if(mod == 0) {
      *acc += 1;
    }
    return count(number / 2, acc, it);
  } else if(number == 0) {
    *acc += 1;
  }
}

void zadanie6(long n) {
  header(6);
  int zeros = 0, iterations = 0;
  count(14, &zeros, &iterations);
  int ones = iterations - zeros;
  printf("%d\n", ones);
}

void from_dec(unsigned int number, short base) {
  if(number >= base) {
    from_dec(number / base, base);
    int rest = number % base;
    if(rest >= 10)
      printf("%c", rest + 55);
    else
      printf("%d", rest);
  } else {
    if(number > 10 && base > 10)
      printf("%c", number + 55);
    else
      printf("%d", number);
  }
}

void zadanie7(unsigned int number, short base) {
  header(7);
  from_dec(number, base);
  printf("\n");
}

int main () {

  zadanie1();
  zadanie2(5);
  zadanie3(-3, 3, 0.25);
  zadanie4(8, 4);
  zadanie5();
  zadanie6(14);
  zadanie7(255, 16);

  return 0;
}
