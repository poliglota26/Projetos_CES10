/* Sérgio Luís dos Santos Filho
   Turma 02
   Exercício 2: Juros Simples e Compostos

   Programa compilado com CodeBlocks 20.03
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i =1;
    float emprestimo,
          divida,
          juros;

    printf("--------------------------------------------------\n");
    printf("PROGRAMA PARA CALCULO DE JUROS SIMPLES E COMPOSTOS\n");
    printf("--------------------------------------------------\n\n");
    printf("Qual o valor do emprestimo?\n");
    scanf("%f", &emprestimo);
    printf("Qual o valor dos juros (em %%)?\n");
    scanf("%f", &juros);
    printf("\n---------------\n");
    printf("JUROS SIMPLES\n");
    printf("---------------\n\n");
    divida = emprestimo;
    printf("Mes   Divida\n");
    while(i <= 12){
        divida = divida + emprestimo*(juros/100);
        printf("%2d    %.2f\n", i, divida);
        i = i + 1;
    }
    printf("\n---------------\n");
    printf("JUROS COMPOSTOS\n");
    printf("---------------\n\n");
    i = 1;
    divida = emprestimo;
    printf("Mes   Divida\n");
    while(i <= 12){
        divida = divida*(1 + juros/100);
        printf("%2d    %.2f\n", i, divida);
        i = i + 1;
    }
    printf("\n--------------------------------------------------\n");
    printf("Fim do programa!\n");
    printf("Pressione ENTER para terminar...");
    getchar();
    getchar();
	return 0;
}
