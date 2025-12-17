#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void copy_to_clipboard(const char *password) {
    if (password == NULL) {
        fprintf(stderr, "Greska: Nevaljana lozinka za clipboard!\n");
        return;
    }

    printf("DEBUG: Pokusaj copy na clipboard...\n");
    printf("DEBUG: Lozinka duzina: %zu\n", strlen(password));

#ifdef _WIN32
    // Windows verzija - koristi PowerShell
    FILE *pipe = _popen("clip", "w");
    if (pipe != NULL) {
        fprintf(pipe, "%s", password);
        _pclose(pipe);
        printf("[OK] Lozinka je kopirana na clipboard (Windows)!\n");
        printf("DEBUG: Copy uspešan!\n");
    } else {
        fprintf(stderr, "Greska: Nije moguce pristupiti clipboard-u!\n");
    }
#elif __linux__
    FILE *pipe = popen("xclip -selection clipboard", "w");
    if (pipe != NULL) {
        fprintf(pipe, "%s", password);
        pclose(pipe);
        printf("[OK] Lozinka je kopirana na clipboard (Linux)!\n");
    } else {
        fprintf(stderr, "Greska: xclip nije dostupan! Instaliraj sa: sudo apt-get install xclip\n");
    }
#elif __APPLE__
    FILE *pipe = popen("pbcopy", "w");
    if (pipe != NULL) {
        fprintf(pipe, "%s", password);
        pclose(pipe);
        printf("[OK] Lozinka je kopirana na clipboard (macOS)!\n");
    } else {
        fprintf(stderr, "Greska: Nije moguce pristupiti clipboard-u!\n");
    }
#else
    fprintf(stderr, "Greska: Clipboard nije podrzan na ovom sistemu!\n");
#endif
}

int save_password_to_file(const char *password, const char *filename) {
    if (password == NULL) {
        fprintf(stderr, "Greska: Nevaljana lozinka!\n");
        return -1;
    }

    const char *file_to_use = (filename == NULL) ? PASSWORD_FILE : filename;

    FILE *file = fopen(file_to_use, "a");
    if (file == NULL) {
        fprintf(stderr, "Greska: Nije moguce otvoriti datoteku '%s'!\n", file_to_use);
        return -1;
    }

    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);
    char timestamp[30];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

    fprintf(file, "[%s] %s\n", timestamp, password);

    if (fclose(file) != 0) {
        fprintf(stderr, "Greska: Nije moguce zatvoriti datoteku!\n");
        return -1;
    }

    printf("[OK] Lozinka je sacuvana u datoteku '%s'!\n", file_to_use);
    return 0;
}

char get_yes_no_choice() {
    char choice;
    
    while (getchar() != '\n');
    
    if (scanf("%c", &choice) != 1) {
        fprintf(stderr, "Greska pri citanju unosa!\n");
        return '0';
    }

    while (getchar() != '\n');

    choice = tolower((unsigned char)choice);

    return choice;
}

void show_save_options(const char *password) {
    if (password == NULL) {
        fprintf(stderr, "Greska: Nevaljana lozinka!\n");
        return;
    }

    printf("\n");
    printf("========================================\n");
    printf("     OPCIJE ZA CUVANJE LOZINKE         \n");
    printf("========================================\n");
    printf("\nSta zelis da uradis sa lozinkom?\n");
    printf("  1 - Kopiraj na clipboard\n");
    printf("  2 - Sacuvaj u datoteku\n");
    printf("  3 - Oboje (clipboard + datoteka)\n");
    printf("  4 - Nista (samo prikazi)\n");
    printf("\nUnesi broj (1-4): ");

    char choice;
    if (scanf("%c", &choice) != 1) {
        fprintf(stderr, "Greska pri citanju unosa!\n");
        return;
    }

    while (getchar() != '\n');

    printf("\n");

    switch (choice) {
        case '1':
            copy_to_clipboard(password);
            break;

        case '2':
            save_password_to_file(password, NULL);
            break;

        case '3':
            copy_to_clipboard(password);
            printf("\n");
            save_password_to_file(password, NULL);
            break;

        case '4':
            printf("Lozinka nije sacuvana. Nastavi sa radom!\n");
            break;

        default:
            printf("Nevaljani izbor! Lozinka nije sacuvana.\n");
            break;
    }

    printf("\n");
}
