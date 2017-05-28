#include <stdio.h>
#include <stdlib.h>

char* row(int length) {
  int A = 65;
  int i = 0;
  char *s = malloc(length * sizeof(char));
  while(i < length) {
    s[i] = A + i;
    i++;
  }
  return s;
}

void rb(int w, int h) {
  if(w > 24) {
    printf("Za duza szerokosc\n");
    return;
  }
  int i = 0;
  char* s = row(w);
  while(i < h) {
  printf("%*c", h - i, ' ');
  printf("%s\n", s);
    i++;
  }
  free(s);
}

int main() {
  rb(4, 3);
  rb(10, 20);
  return 0;
}
