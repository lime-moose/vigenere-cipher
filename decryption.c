#include "include/decryption.h"
#include "include/menu.h"
#include "include/textutils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decryption(char *c, char *k) {
  char *plain = (char *)malloc(strlen(c) + 1);
  int ki = 0;

  // decrypt each charecter
  for (int ci = 0; ci < strlen(c); ++ci) {
    // convert key to uppercase
    if (islowercase(k[ki]))
      k[ki] -= 32;

    // decrypt each charecter
    if (!isalphabet(c[ci])) {
      // Non-alphabetic characters remain unchanged
      plain[ci] = c[ci];
    } else if (islowercase(c[ci])) {
      // decrypt lowercase
      c[ci] -= 32;
      plain[ci] = ((c[ci] - k[ki] + 26) % 26) + 'a';
      plain[ci] += 32;
      ++ki;
    } else {
      // decrypt lowercase
      plain[ci] = ((c[ci] - k[ki] + 26) % 26) + 'A';
      ++ki;
    }

    // reset the key's index
    if (ki > strlen(k) - 1)
      ki = 0;
  }

  plain[strlen(c)] = '\0';
  return plain;
}

void get_decryption_input() {
  char *cipher, *key, choice = '\0';

  while (choice != 'n' && choice != 'N') {
    printf("\nEnter Plain Text: ");
    cipher = getstr(255);

    printf("Enter Key: ");
    key = getstr(255);

    printf("Cipher Text: ");
    char *plain_text = decryption(cipher, key);
    printf("%s\n", plain_text);

    printf("\nDo you want to do this again? [Y/n] ");
    scanf("%c", &choice);
    getchar();
  }

  free(cipher);
  free(key);

  init_menu();
}
