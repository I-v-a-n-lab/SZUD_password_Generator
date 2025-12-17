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
        fprintf(stderr, "Greska: Nevaljani pokazivac na lozinku!\n");
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
        fprintf(stderr, "Greska: Nevaljana lozinka!\n");
        return;
    }
    printf("Generisana lozinka: %s\n", password);
    printf("Duzina lozinke: %zu karaktera\n", strlen(password));
}

/**
 * Funkcija za validaciju unosa dužine lozinke
 * Vraća validnu dužinu ili DEFAULT_PASSWORD_LENGTH ako je nevaljano
 */
int validate_password_length(const char *input) {
    if (input == NULL) {
        return DEFAULT_PASSWORD_LENGTH;
    }

    char *endptr;
    long value = strtol(input, &endptr, 10);

    // Provera da li je unos validan broj
    if (endptr == input || (*endptr != '\0' && *endptr != '\n')) {
        return DEFAULT_PASSWORD_LENGTH;
    }

    // Provera da li je u dozvoljenom opsegu
    if (value < MIN_PASSWORD_LENGTH || value > MAX_PASSWORD_LENGTH) {
        printf("Upozorenje: Duzina mora biti izmedju %d i %d!\n",
               MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return DEFAULT_PASSWORD_LENGTH;
    }

    return (int)value;
}
