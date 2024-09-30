#include <stdio.h>
#include <stdlib.h>

double f(int x, double b) {
    double a0 = 186.752;
    double a1 = -148.235;
    double a2 = 34.5049;
    double a3 = -3.5091;
    double a4 = 0.183166;
    double a5 = -0.00513554;
    double a6 = 0.0000735464;
    double a7 = -4.22038e-7;
    
    return a0 + (a1 + b) * x + a2 * x * x + a3 * x * x * x + a4 * x * x * x * x +
           a5 * x * x * x * x * x + a6 * x * x * x * x * x * x + a7 * x * x * x * x * x * x * x;
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
    printf("Mensagem decodificada: %s\n", decoded_chars);
}

int main() {
    const char *hex_input = "48656c6c6f20576f726c642100";
    double b_value = 10;

    decode_message(hex_input, b_value);
    return 0;
}
