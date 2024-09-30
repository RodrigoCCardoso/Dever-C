#include <stdio.h>

int main() {
    float n1, n2, ppd, eu, n3, nota_final;
    int fez_eu, fez_n3;

    printf("Digite as notas N1, N2 e PPD: ");
    scanf("%f %f %f", &n1, &n2, &ppd);

    if (n1 < 0 || n1 > 4.5 || n2 < 0 || n2 > 4.5 || ppd < 0 || ppd > 1) {
        printf("Erro: Notas invalidas. Codigo 3\n");
        return 3;
    }

    printf("Fez o Exame Unificado? (0 - nao, 1 - sim): ");
    scanf("%d", &fez_eu);
    if (fez_eu != 0 && fez_eu != 1) {
        printf("Erro: Flag do Exame Unificado invalida.\n");
        return 3;
    }

    if (fez_eu) {
        printf("Digite a nota do Exame Unificado: ");
        scanf("%f", &eu);
        if (eu < 0 || eu > 10) {
            printf("Erro: Nota do Exame Unificado invalida.\n");
            return 3;
        }
    }

    printf("Fez a N3? (0 - nao, 1 - sim): ");
    scanf("%d", &fez_n3);
    if (fez_n3 != 0 && fez_n3 != 1) {
        printf("Erro: Flag da N3 invalida.\n");
        return 3;
    }

    if (fez_n3) {
        printf("Digite a nota N3: ");
        scanf("%f", &n3);
        if (n3 < 0 || n3 > 4.5) {
            printf("Erro: Nota N3 invalida.\n");
            return 3;
        }

        if (n3 > (n1 < n2 ? n1 : n2)) {
            if (n1 < n2) {
                n1 = n3;
            } else {
                n2 = n3;
            }
        }
    }

    nota_final = (n1 + n2 + ppd) / 3;

    printf("Nota final: %.2f\n", nota_final);
    if (nota_final >= 6) {
        printf("Aprovado!\n");
    } else {
        printf("Reprovado.\n");
    }

    return 0;
}
