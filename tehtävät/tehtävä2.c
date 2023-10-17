
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int num1, num2;
    char operator;
    int result;
    char buffer[100];

    printf("# Ohjelman suoritus alkaa\n");

    while (1) {
        printf("Anna laskutoimitus (esim. 6 + 6 tai q lopettaaksesi): ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }

        if (strlen(buffer) == 2 && buffer[0] == 'q') {
            printf("Ohjelma lopetetaan.\n");
            break;
        }

        if (sscanf_s(buffer, "%d %c %d", &num1, &operator, sizeof(operator), &num2) != 3) {
            if (strlen(buffer) == 1 && buffer[0] == '\n') {
                printf("Virheellinen syote (tyhjä) kirjoita \"q\" lopettaaksesi ohjelman\n");
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
                printf("Virhe: Jakojaannos nollalla ei ole sallittu.\n");
                continue;
            }
            result = num1 % num2;
            break;
        default:
            printf("Virhe: Tuntematon operaatio '%c'. Kayta +, -, *, / tai %% (jakojaannos).\n", operator);
            continue;
        }

        printf("%d %c %d\n", num1, operator, num2);
        printf("%d\n", result);
    }

    return 0;
}
*/