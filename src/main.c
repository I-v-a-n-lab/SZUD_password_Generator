#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "password_gen.h"

int main() {
    // Inicijalizacija seed-a za random broj generator
    srand((unsigned int)time(NULL));
    
    int password_length;
    char password[MAX_PASSWORD_LENGTH + 1]; // +1 za '\0'
    
    printf("=== PASSWORD GENERATOR ===\n");
    printf("Dobrodošli u Password Generator!\n\n");
    
    // Unos dužine lozinke od korisnika
    printf("Unesite željenu dužinu lozinke (10-128, ili Enter za default 10): ");
    
    char input[10];
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Pokušaj da konvertuj unos u broj
        char *endptr;
        long value = strtol(input, &endptr, 10);
        
        // Validacija unosa
        if (endptr == input || *endptr != '\n') {
            // Unos nije broj - koristi default
            printf("Nevaljani unos! Korišćenje default vrednosti (10 karaktera).\n\n");
            password_length = DEFAULT_PASSWORD_LENGTH;
        } else if (value < MIN_PASSWORD_LENGTH || value > MAX_PASSWORD_LENGTH) {
            // Broj je van dozvoljenog opsega
            printf("Dužina mora biti između %d i %d! Korišćenje default vrednosti.\n\n", 
                   MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
            password_length = DEFAULT_PASSWORD_LENGTH;
        } else {
            // Validna vrednost
            password_length = (int)value;
        }
    } else {
        // Greška pri čitanju - koristi default
        printf("Greška pri unošenju! Korišćenje default vrednosti.\n\n");
        password_length = DEFAULT_PASSWORD_LENGTH;
    }
    
    // Generisanje lozinke
    generate_password(password_length, password);
    
    // Prikaz lozinke
    display_password(password);
    
    printf("\n=== NAPOMENA ===\n");
    printf("Lozinka sadrži:\n");
    printf("- Brojeve (0-9)\n");
    printf("- Mala slova (a-z)\n");
    printf("- Velika slova (A-Z)\n");
    
    return EXIT_SUCCESS;
}
