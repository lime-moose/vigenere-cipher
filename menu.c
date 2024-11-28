#include "include/menu.h"
#include "include/decryption.h"
#include "include/encryption.h"
#include "include/textutils.h"

#include <stdio.h>

void menu_options_text() {
  printf("\n---- VIGNERE CIPHER ----\n");
  printf("1. Encrypt\n");
  printf("2. Decrypt\n");
  printf("3. Quit\n");
}

void user_choice_switch(int choice) {
  switch (choice) {
  case 1:
    printf("\n---- Encryption ----\n");
    get_encryption_input();
    break;
  case 2:
    printf("\n---- Decryption ----\n");
    get_decryption_input();
    break;
  case 3:
    printf("\nQuitting...\n");
    break;
  default:
    printf("\nInvalid Choice!\n");
    break;
  }
}

void get_user_choice() {
  int user_choice = -1;

  while (user_choice < 1 || user_choice > 3) {
    printf("\nEnter Your Choice: ");
    // if non-number is entered
    if (scanf("%d", &user_choice) != 1) {
      getstr(0);
      printf("\nNot Number!\n");
    } else {
      getchar();
      user_choice_switch(user_choice);
    }
  }
}

void init_menu() {
  menu_options_text();
  get_user_choice();
}
