#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TRUE 1;
#define FALSE 0;

typedef int boolean;

/* escreve na tela uma mensagem inicial, sem precisar receber
 ou deolver valores*/
void mensagem_inicial_na_tela()
{
    printf("         Lab 9 - CES 10\n");
    printf(" Programado por Sergio Luis - T2\n");
    printf("      Prof. Armando Gouveia\n");
    printf("---------------------------------\n\n\n");
}
/*--------------------------------------------------------------*/

/* escreve na tela uma mensagem final e da uma pausa, sem precisar
 receber ou deolver valores */
void mensagem_final_na_tela_e_pausa()
{
    printf("Final do programa de Subprogramacao :-)\n\n");
    system("pause");
}
/*--------------------------------------------------------------*/

/* calcula o juros de um numero real (num), com determinada porcentagem real (porcent)
por um determinado periodo inteiro (meses), podendo ser simples ou composto
a ser determinado pela variavel tipo, que é char.
Devolve os juros compostos ou simples, dependendo do tipo*/
float juros(float num, float porcent, int meses, char tipo)
{
    if(tipo == 's' || tipo == 'S')
        return num + num*(porcent/100.0)*meses;
    return num*pow(1 + porcent/100.0, meses);
}

/*--------------------------------------------------------------*/

/* calcula a media entre dois numeros reais x e y, devolvendo essa media
que tambem eh real*/
float media(float x, float y)
{
    return (x+y)/2;
}

/*--------------------------------------------------------------*/

/* encontra o proximo numero multiplo de 26 a partir do numero que esta
apontado pelo ponteiro *n, dai encontrando o proximo multiplo de 26
coloca esse numero dentro da posicao apontada por *n, ou seja, a funcao
nao devolve nada*/
void pmvs(int *n)
{
    do
    {
        *n = *n + 1;
    }
    while(*n%26 != 0);
}
/*--------------------------------------------------------------*/

/* caso uma string tenha uma letra minuscula, trocamos essa letra por ela maiuscula,
assim, a funcao recebe um ponteiro que aponta a posicao da string, nao devolvendo
nada, visto que eh mudada a letra na propria string*/
void tudo_maiusculo(char *s)
{
    int i;
    for (i = 0; i < strlen(s); i++)
        if(s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 'a' + 'A';
}

/*--------------------------------------------------------------*/

/* confere se uma string eh hexadecimal ou nao, recebendo um ponteiro que
aponta a posicao da string, devolvendo TRUE se de fato a string for hexadecimal
e FALSE se nao for*/
boolean hexa(char *s)
{
    int i;
    for (i = 0; i<strlen(s); i++)
        if(!((s[i] >= 'A' && s[i] <= 'F') || (s[i] >= '0' && s[i] <= '9')))
            return FALSE;
    return TRUE;
}

/*--------------------------------------------------------------*/

int main()
{
    int i, cont, meses, num;
    float num_1, num_2, porcent;
    char residuo[80], // lixo
         tarefa[10], // qual funcao o programa deve fazer
         hexadec[20], // string para ver se eh hexadecimal
         tipo_juros; // se eh simples ou composto
    FILE * entrada,
         * saida;
    // abrir arquivos
    entrada = fopen("entrada9.txt","r");
    saida = fopen("Lab9_Sergio_Luis_dos_Santos_Filho.txt","w");
    mensagem_inicial_na_tela();
    // mensagem no arquivo de saida
    fprintf(saida, "         Lab 9 - CES 10\n");
    fprintf(saida, " Programado por Sergio Luis - T2\n");
    fprintf(saida, "      Prof. Armando Gouveia\n");
    fprintf(saida, "---------------------------------\n");
    // pular as 4 primeiras linhas do arquivo de entrada
    for(i = 0; i<4; i++)
        fgets(residuo, 80, entrada);
    // declarar valores
    cont = 0;
    // enquanto o arquivo de entrada nao termina
    while(!feof(entrada))
    {
        cont++;
        fprintf(saida, "%3d: ", cont);
        fscanf(entrada, "%s ", tarefa);
        // se a tarefa for "juros"
        if(strcmp(tarefa,"juros") == 0)
        {
            fscanf(entrada, "%s %f ",residuo, &num_1);
            fscanf(entrada, "%f %s ", &porcent, residuo);
            fscanf(entrada, "%d %c ",&meses,&tipo_juros);
            fprintf(saida, "R$ %.2f \n", juros(num_1, porcent, meses, tipo_juros));
        }
        // senao se a tarefa for "media"
        else if(strcmp(tarefa,"media") == 0)
        {
            fscanf(entrada, "%f %f ", &num_1, &num_2);
            fprintf(saida, "%.2f \n", media(num_1,num_2));
        }
        // senao se a tarefa for "pmvs"
        else if(strcmp(tarefa,"pmvs") == 0)
        {
            fscanf(entrada, "%d ",&num);
            pmvs(&num);
            fprintf(saida, "%d \n", num);
        }
        // senao se a tarefa for "hexa"
        else if(strcmp(tarefa,"hexa") == 0)
        {
            fscanf(entrada, "%s ", hexadec);
            tudo_maiusculo(hexadec);
            fprintf(saida, "%s em hexadecimal ", hexadec);
            if(hexa(hexadec))
                fprintf(saida, "eh valida\n");
            else
                fprintf(saida, "nao eh valida\n");
        }
    }
    mensagem_final_na_tela_e_pausa();
    // fechar arquivos
    fclose(entrada);
    fclose(saida);
    return 0;
}
