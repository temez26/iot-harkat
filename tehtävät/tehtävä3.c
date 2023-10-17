/*
* EI TOIMI VALITTAA KAATUU AINA KUN YRITTÄÄ LASKUTOIMITUKSIA SUORITTAA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HISTORY_SIZE 10

struct Command {
    char* input;
    int result;
};

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void free_history(struct Command* history, int count) {
    if (history) {
        for (int i = 0; i < count; i++) {
            if (history[i].input) {
                free(history[i].input);
            }
        }
        free(history);
    }
}

#ifdef _WIN32
#define strdup _strdup
#define _CRT_SECURE_NO_WARNINGS // Add this at the top of your file
#define sscanf sscanf_s
#endif

int main() {
    int num1, num2;
    char operator;
    int result;
    char buffer[100];
    struct Command* history = NULL;
    int history_count = 0;

    printf("# Ohjelman suoritus alkaa\n");

    while (1) {
        printf("Anna laskutoimitus (esim. 6 + 6, h nayttaa historian, c tyhjentaa historian): ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }

        if (strlen(buffer) == 2 && buffer[0] == 'q') {
            printf("Ohjelma lopetetaan.\n");
            break;
        }

        if (strlen(buffer) == 2 && buffer[0] == 'h') {
            if (history_count == 0) {
                printf("Komentohistoria on tyhja.\n");
            }
            else {
                printf("Komentohistoria:\n");
                for (int i = 0; i < history_count; i++) {
                    printf("%d: %s\n%d\n", i + 1, history[i].input, history[i].result);
                }
            }
            continue;
        }

        if (strlen(buffer) == 2 && buffer[0] == 'c') {
            printf("Komentohistoria tyhjennetty.\n");
            free_history(history, history_count);
            history = NULL;
            history_count = 0;
            continue;
        }

        if (sscanf(buffer, "%d %c %d", &num1, &operator, &num2) != 3) {
            if (strlen(buffer) == 1 && buffer[0] == '\n') {
                printf("Virheellinen syote (tyhja) kirjoita \"q\" lopettaaksesi ohjelman\n");
            }
            else {
                printf("Virheellinen syote (puuttuvia argumentteja)\n");
            }
            clear_input_buffer();
            continue;
        }

        switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Virhe: Jakolasku nollalla ei ole sallittu.\n");
                continue;
            }
            result = num1 / num2;
            break;
        case '%':
            if (num2 == 0) {
                printf("Virhe: Jakojäännos nollalla ei ole sallittu.\n");
                continue;
            }
            result = num1 % num2;
            break;
        default:
            printf("Virhe: Tuntematon operaatio '%c'. Kayta +, -, *, / tai %% (jakojaannos).\n", operator);
            continue;
        }

        printf("%d %c %d = %d\n", num1, operator, num2, result);

        // Save the command to the history
        if (history_count < MAX_HISTORY_SIZE) {
            struct Command* temp = (struct Command*)realloc(history, (history_count + 1) * sizeof(struct Command));
            if (temp == NULL) {
                printf("Muistin varaus epaonnistui.\n");
            }
            else {
                history = temp;
                history[history_count].input = strdup(buffer);
                history[history_count].result = result;
                history_count++;
            }
        }
        else {
            free(history[0].input);
            for (int i = 0; i < MAX_HISTORY_SIZE - 1; i++) {
                history[i] = history[i + 1];
            }
            history[MAX_HISTORY_SIZE - 1].input = strdup(buffer);
            history[MAX_HISTORY_SIZE - 1].result = result;
        }
    }

    // Free the memory allocated for the command history
    free_history(history, history_count);

    return 0;
}
*/