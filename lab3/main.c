#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *tab) {
  int len = strlen(tab);
  for(int i = 0; i < len/2; i++) {
    char tmp = tab[i];
    tab[i] = tab[len - 1 - i];
    tab[len - 1 - i] = tmp;
  }
}

char* allocate(char znak) {
  int len, i;
  scanf("%d", &len);
  char *tab = malloc(len);
  for(i = 0; i < len; i++) {
    tab[i] = znak;
  }
  return tab;
}

// czytanie lini z pliku i zapisywanie ich do char[line][num_of_chars]
void czytanie() {
  FILE *file;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  file = fopen("ala.txt", "w");
  if (file == NULL)
    exit(EXIT_FAILURE);

  while ((read = getline(&line, &len, file)) != -1) {
    printf("Retrieved line of length %zu : %s\n", read, line);
  }

  printf("%zu\n", len);


  fclose(file);
}

int main () {

  /* char *string; */
  /* scanf("%s\n", string); */
  /* printf("%s\n", string); */
  /* reverse(string); */
  /* printf("%s\n", string); */

  /* char *test = allocate('6'); */
  /* printf("%s\n", test); */
  /* free(test); */

  czytanie();
  return 0;
}
