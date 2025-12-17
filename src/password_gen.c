#include "password_gen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Karakteri koji se koriste za generisanje lozinke
// Brojevi: 0-9
// Mala slova: a-z
// Velika slova: A-Z
#define CHARSET "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define CHARSET_LENGTH (sizeof(CHARSET) - 1)

/**
 * Funkcija za generisanje lozinke sa random karakterima
 * @param length - Dužina željene lozinke
 * @param password - Pokazivač na buffer gde će se sačuvati lozinka
 */
void generate_password(int length, char *password) {
    if (password == NULL) {
        fprintf(stderr, "Greška: Nevaljani pokazivač na lozinku!\n");
        return;
    }

    // Generisanje random karaktera
    for (int i = 0; i < length; i++) {
        // Randomni indeks iz charset-a
        int random_index = rand() % CHARSET_LENGTH;
        password[i] = CHARSET[random_index];
    }
    
    // Terminiranje stringa
    password[length] = '\0';
}

/**
 * Funkcija za ispis lozinke
 * @param password - Lozinka za ispis
 */
void display_password(const char *password) {
    if (password == NULL) {
        fprintf(stderr, "Greška: Nevaljana lozinka!\n");
        return;
    }
    printf("Generisana lozinka: %s\n", password);
    printf("Dužina lozinke: %zu karaktera\n", strlen(password));
}
