#include "include/textutils.h"

#include <stdio.h>
#include <stdlib.h>

char *getstr(int size) {
  char *str = (char *)malloc(size + 1);
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

int islowercase(char ch) { return ch >= 'a' && ch <= 'z'; }
