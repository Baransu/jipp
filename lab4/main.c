#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct towar {
  char nazwa[25];
  double cena;
  int stan;
} Towar;

void pokaz_towar(Towar t) {
  printf("Nazwa: %s\n", t.nazwa);
  printf("Cena: %.2lf\n", t.cena);
  printf("Stan: %d\n", t.stan);
}

void licz(float r, float *objetosc, float *pole) {
  *pole = 4 * 3.14 * r * r;
  *objetosc = 3.14 * r * r * r * 4/3;
}

double fun(int n) {
  double result = 0;

  for(int i = 1; i <= n; i++)
    result += i/(i + 1.0);

  return result;
}

int main () {
  float promien = 1.23, objetosc, pole;
  licz(promien, &objetosc, &pole);
  printf("r: %.3f\nV: %.3f\nP: %.3f \n\n", promien, objetosc, pole);
  printf("fun(10) = %f\n\n", fun(10));

  Towar towar = { "mleko", 2.99, 1 };
  pokaz_towar(towar);

  printf("sizeof(short) = %ld\n", sizeof(short));
  return 0;
}
