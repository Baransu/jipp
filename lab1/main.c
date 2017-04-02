#include <stdio.h>
#include <math.h>

double func(double x) {
  return exp(-x) * cos(3*x) - 0.125;
}

void table(double (*fn)(double), double xleft, double xright, double step, FILE *out) {
  double x;
  fprintf(out, "    x         f(x)     \n");
  fprintf(out, "=======================\n");
  for(x = xleft; x <= xright; x += step) {
    fprintf(out, "%6.2lf %12.5lf \n", x, fn(x));
  }
}

void do_pliku(char* name) {
  FILE *file = fopen(name, "w");
  table(func, 0.0, 3.0, 0.25, file);
  fclose(file);
}

void do_terminala() {
  table(func, 0.0, 3.0, 0.25, stdout);
}

double miejsce_zerowe(
                      double (*f)(double),
                      double left,
                      double right,
                      double epsilon) {

  double srodek = (left + right) / 2.0;
  if(right - left < epsilon)
    return srodek;

  if(f(left) * f(srodek) < 0.0)
    return miejsce_zerowe(f, left, srodek, epsilon);

  return miejsce_zerowe(f, srodek, right, epsilon);
}

int main () {
  /* do_pliku("wynik.txt"); */
  /* do_terminala(); */
  printf("Miejsce zerowe: %6.6lf\n", miejsce_zerowe(func, -3.0, 3.0, 0.000001));
  return 0;
}
