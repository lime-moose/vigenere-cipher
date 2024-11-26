#ifndef VIGNERE_H

char *encrypt(char *p, char *k);
char *decrypt(char *p, char *k);
char *getstr(int size);

int isalphabet(char ch);
int islowerchar(char ch);

#endif // !VIGNERE_H
