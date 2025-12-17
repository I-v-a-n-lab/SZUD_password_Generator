#ifndef PASSWORD_GEN_H
#define PASSWORD_GEN_H

#include <stddef.h>

// Konstante za dužinu lozinke
#define MIN_PASSWORD_LENGTH 10
#define MAX_PASSWORD_LENGTH 128
#define DEFAULT_PASSWORD_LENGTH 10

// Funkcija za generisanje lozinke
void generate_password(int length, char *password);

// Funkcija za ispis lozinke
void display_password(const char *password);

#endif // PASSWORD_GEN_H
