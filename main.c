#include "vigenere.h"
#include <stdio.h>

int main(void) {
  char p[] = "MYSTERY";
  char k[] = "KEYKEY";

  char *c = tocipher(p, k);
  int ci = 0;

  printf("Cipher Text: ");
  while (c[ci] != '\0') {
    printf("%c", c[ci]);
    ++ci;
  }
  printf("\n");

  return 0;
}
