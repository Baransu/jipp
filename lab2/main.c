#include <stdio.h>

int silnia(int n) {
  if(n == 1) return 1;
  return n * silnia(n - 1);
}

int fibr(int e) {
  if(e < 2) return e;
  return fibr(e - 1) + fibr(e - 2);
}

int fib(int e) {
  int i, a = 0, b = 1;
  for(i = 2; i <= e; i++) {
    int tmp = a;
    a = b;
    b = b + tmp;
  }
  return b;
}

void do_pliku() {
  /* tablica */
  /*   zapisanie liczby 10 */
  /*   zapisanie liczb z tablicy */
}

void hanoi(char a, char b, char c, int n) {
  static int krok = 0;
  if(n==1) printf("%9d %c ==> %c\n", ++krok, a, b);
  else {
    hanoi(a, c, b, n - 1);
    hanoi(a, b, c, 1);
    hanoi(c, b, a, n - 1);
  }
}

void sort() {
  int i, tab[] = {0, 2,10, 1,123,2,3};
  for(i = 1; i < 7; i++) {
    int x = tab[i];
    int j = i - 1;
    while(j >= 0 && tab[j] > x) {
      tab[j + 1] = tab[j];
        j--;
    }
    tab[j + 1] = x;
  }
  for(i = 0; i < 7; i++) {
    printf("%d, ", tab[i]);
  }
}

int main () {

  /* int a = 14, b = 13; */
  /* printf("a ^ b = %d\n", a ^ b); */
  /* printf("a | b = %d\n", a | b); */
  /* printf("a & b = %d\n", a & b); */
  /* printf("a << 3 = %d\n", a << 3); */
  /* printf("a >> 2 = %d\n", a >> 2); */
  /* printf("~a = %d", ~a); */

  /* int a = 29, b = 4, c = 1996; */

  /* int d = a ^ b ^ c; */

  /* printf("d = %d\n", d); */
  /* printf("b = %d\n", c ^ a ^ d); */

  /* printf("silnia(5) = %d\n", silnia(5)); */
  /* printf("fib(42) = %d\n", fib(42)); */
  sort();
  return 0;
}
