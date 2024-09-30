#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

double f(int x, double b) {
    double a0 = 186.752;
    double a1 = -148.235;
    double a2 = 34.5049;
    double a3 = -3.5091;
    double a4 = 0.183166;
    double a5 = -0.00513554;
    double a6 = 0.0000735464;
    double a7 = -4.22038e-7;

    return a0 + (a1 + b) * x + a2 * x * x + a3 * x * x * x +
           a4 * x * x * x * x + a5 * x * x * x * x * x +
           a6 * x * x * x * x * x * x + a7 * x * x * x * x * x * x * x;
}

void decode_message(const char *hex_string, double b) {
    char decoded_chars[51];
    int index = 0;

    for (int i = 0; i < strlen(hex_string); i += 2) {
        if (hex_string[i] == '0' && hex_string[i + 1] == '0') {
            break;
        }

        char hex_pair[3] = { hex_string[i], hex_string[i + 1], '\0' };
        int decimal_value = (int)strtol(hex_pair, NULL, 16);

        if (f((i / 2) + 1, b) >= 0) {
            decoded_chars[index++] = (char)decimal_value;
        }
    }

    decoded_chars[index] = '\0';
    printf("%s", decoded_chars);
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    for (int i = 0; i < num_cases; i++) {
        double b;
        char hex_input[101];

        scanf("%lf", &b);
        scanf("%s", hex_input);

        decode_message(hex_input, b);
    }

    return 0;
}
