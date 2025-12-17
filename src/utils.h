#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

// Konstante za filove
#define PASSWORD_FILE "saved_passwords.txt"
#define MAX_FILENAME_LENGTH 256

// Funkcija za copy na clipboard (platform-dependent)
void copy_to_clipboard(const char *password);

// Funkcija za čuvanje lozinke u datoteku
int save_password_to_file(const char *password, const char *filename);

// Funkcija za prikaz opcija nakon generisanja lozinke
void show_save_options(const char *password);

// Funkcija za čitanje korisničkog izbora (y/n)
char get_yes_no_choice();

#endif // UTILS_H
