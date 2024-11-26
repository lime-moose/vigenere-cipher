#include "vigenere.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getstr(int size) {
  char *str = (char *)malloc(size);
  char ch;
  int i = 0;

  while ((ch = getchar()) != '\n') {
    str[i] = ch;
    ++i;
  }

  str[i] = '\0';
  return str;
}

int isalphabet(char ch) {
  return (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z');
}

int islowerchar(char ch) { return ch >= 'a' && ch <= 'z'; }

char *encrypt(char *p, char *k) {
  char *cipher = (char *)malloc(strlen(p) + 1);
  int ki = 0;

  for (int pi = 0; pi < strlen(p); ++pi) {
    // convert key to uppercase
    if (islowerchar(k[ki]))
      k[ki] -= 32;

    // encrypt each charecter
    if (!isalphabet(p[pi])) {
      // Non-alphabetic characters remain unchanged
      cipher[pi] = p[pi];
    } else if (islowerchar(p[pi])) {
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

char *decrypt(char *c, char *k) {
  char *plain = (char *)malloc(strlen(c) + 1);
  int ki = 0;

  // decrypt each charecter
  for (int ci = 0; ci < strlen(c); ++ci) {
    // convert key to uppercase
    if (islowerchar(k[ki]))
      k[ki] -= 32;

    // decrypt each charecter
    if (!isalphabet(c[ci])) {
      // Non-alphabetic characters remain unchanged
      plain[ci] = c[ci];
    } else if (islowerchar(c[ci])) {
      // decrypt lowercase
      c[ci] -= 32;
      plain[ci] = ((c[ci] - k[ki]) % 26) + 'a';
      plain[ci] += 32;
      ++ki;
    } else {
      // decrypt lowercase
      plain[ci] = ((c[ci] - k[ki]) % 26) + 'A';
      ++ki;
    }

    // reset the key's index
    if (ki > strlen(k) - 1)
      ki = 0;
  }

  plain[strlen(c)] = '\0';
  return plain;
}
