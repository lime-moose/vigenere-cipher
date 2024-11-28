#include "include/encryption.h"
#include "include/menu.h"
#include "include/textutils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encryption(char *p, char *k) {
  char *cipher = (char *)malloc(strlen(p) + 1);
  int ki = 0;

  for (int pi = 0; pi < strlen(p); ++pi) {
    // convert key to uppercase
    if (islowercase(k[ki]))
      k[ki] -= 32;

    // encrypt each charecter
    if (!isalphabet(p[pi])) {
      // Non-alphabetic characters remain unchanged
      cipher[pi] = p[pi];
    } else if (islowercase(p[pi])) {
      // encrypt lowercase
      p[pi] -= 32;
      cipher[pi] = ((p[pi] + k[ki]) % 26) + 'A';
      cipher[pi] += 32;
      ++ki;
    } else {
      // encrypt lowercase
      cipher[pi] = ((p[pi] + k[ki]) % 26) + 'A';
      ++ki;
    }

    // reset the key's index
    if (ki > strlen(k) - 1)
      ki = 0;
  }

  cipher[strlen(p)] = '\0';
  return cipher;
}

void get_encryption_input() {
  char *plain_text, *key, choice = '\0';

  while (choice != 'n' && choice != 'N') {
    printf("\nEnter Plain Text: ");
    plain_text = getstr(255);

    printf("Enter Key: ");
    key = getstr(255);

    printf("Cipher Text: ");
    char *cipher = encryption(plain_text, key);
    printf("%s\n", cipher);

    printf("\nDo you want to do this again? [Y/n] ");
    scanf("%c", &choice);
    getchar();
  }

  free(plain_text);
  free(key);

  init_menu();
}
