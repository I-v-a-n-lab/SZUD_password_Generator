#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "password_gen.h"
#include "utils.h"

int main() {
    // Inicijalizacija seed-a za random broj generator
    srand((unsigned int)time(NULL));

    int password_length;
    char password[MAX_PASSWORD_LENGTH + 1];

    printf("\n");
    printf("========================================\n");
    printf("     PASSWORD GENERATOR v1.0            \n");
    printf("========================================\n");
    printf("\nDobrodosli u Password Generator!\n");
    printf("Ova aplikacija generise sigurne lozinke.\n\n");

    // Unos dužine lozinke od korisnika
    printf("Unesite zeljenu duzinu lozinke (10-128, ili Enter za default 10): ");

    char input[10];
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Validacija unosa
        password_length = validate_password_length(input);

        if (password_length == DEFAULT_PASSWORD_LENGTH && input[0] != '\n') {
            printf("Koriscenje default vrednosti (%d karaktera).\n\n",
                   DEFAULT_PASSWORD_LENGTH);
        } else if (password_length != DEFAULT_PASSWORD_LENGTH) {
            printf("\n");
        }
    } else {
        printf("Greska pri citanju! Koriscenje default vrednosti.\n\n");
        password_length = DEFAULT_PASSWORD_LENGTH;
    }

    // Generisanje lozinke
    printf("Generise se lozinka...\n");
    generate_password(password_length, password);
    printf("[OK] Lozinka je generisana!\n\n");

    // Prikaz lozinke
    display_password(password);

    // Prikaz opcija za čuvanje
    show_save_options(password);

    printf("=========================================\n");
    printf("Hvala sto si koristio Password Generator!\n");
    printf("=========================================\n\n");

    return EXIT_SUCCESS;
}
