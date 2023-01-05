#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    // declarar varáveis
    int    i,
           k = 0,
           tamanho, // tamanho da string
           base_ent, // base do valor de entrada
           base_sai, // base do valor de saida
           fator,
           num_dec, // numero na base 10
           numero[31]; // numero inteiro para servir de suporte
    char residuo[71],
         valor_ent[35], // valor de entrada
         valor_sai[35]; // valor de saida
    FILE * entrada,
         * saida;
    // abrir arquivos
    entrada = fopen("entrada7.txt","r");
    saida = fopen("Lab7_Sergio_Luis_dos_Santos_Filho.txt","w");
    // escrever na tela
    fprintf(saida,"    Programa Bases Numericas\n");
    fprintf(saida," Escrito pelo aluno Sérgio Luís\n");
    fprintf(saida,"        Lab-7 de CES 10\n");
    fprintf(saida,"--------------------------------\n");
    // pular as 4 primeiras linhas
    for (i = 1; i < 5; i++)
        fgets(residuo,70,entrada);
    // enquanto o arquivo não terminar
    while (!feof(entrada))
    {
        k += 1;
        fator = 1;
        num_dec = 0;
        // limpar strings de entrada e de saída
        for(i = 0; i < 31; i++)
        {
            valor_ent[i] = '\0';
            valor_sai[i] = '\0';
        }
        fscanf(entrada,"%d ",&base_ent);
        fscanf(entrada,"%d ",&base_sai);
        fscanf(entrada,"%s ",valor_ent);
        fprintf(saida,"%2d: ",k);
        // converte o valor de entrada para a base 10
        for (i = 0; i < 31; i++)
        {
            // se for uma letra
            if (valor_ent[i] >= 'A' && valor_ent[i] <= 'Z' )
                numero[i] = valor_ent[i] - 'A' + 10;
            // se for um número
            else
                numero[i] = valor_ent[i] - '0';
        }
        // transformar para base 10
        tamanho = strlen(valor_ent);
        for (i = tamanho - 1; i >= 0; i--)
        {
            num_dec = num_dec + numero[i] * fator;
            fator = fator * base_ent;
        }
        // converte o valor da base 10 para a base de saida
        i=0;
        do
        {
            numero[i] = num_dec % base_sai;
            // se o numero for maior que ou igual a 10 transforma em letra
            if (numero[i] >= 10)
                valor_sai[i] = 'A' + (numero[i] - 10);
            else
                valor_sai[i] = '0' + numero[i];
            num_dec = num_dec/base_sai;
            i++;
        }
        while (num_dec > 0);   // enquanto a parte inteira do numero na base decimal for maior que 0
        // escrever no arquivo de saida o valor final
        tamanho = strlen(valor_sai);
        for (i = tamanho - 1; i>=0; i--)
            fprintf(saida,"%c",valor_sai[i]);
        fprintf(saida,"\n");
    }
    // fechar arquivos
    fclose(entrada);
    fclose(saida);
    return 0;
}
