#include <stdio.h>
#include <string.h>

int main ()
{
    // declarar variaveis
    // Obs: Em algumas variáveis foi colocado mais espaço que o necessário para não dar erro na concatenação
    int qtd, // quantidade de palavras
        i;
    char pasta[35], // serve para guardar nome da pasta
         pre_pasta[35], // serve para verificar se tem "=" ou nao na pasta
         comp_pasta[35], // serve para comparar pasta
         arquivo[20], // serve para guardar nome do arquivo
         pre_arquivo[20], // serve para verificar se tem "=" ou nao no arquivo
         comp_arquivo[20], // serve para comparar arquivo
         palavra[20], // palavra desejada
         procura[20], // ajuda a procurar a palvra desejada
         residuo[85], // captura caracteres que nao importam
         completo[55], // arquivo completo
         salvo[55]; // salvar o arquivo completo anterior para futura comparaçao
    FILE * entrada,
         * saida,
         * arq_cmplt; // arquivo completo
    // abrir arquivos
    entrada = fopen("C:\\Lab6\\entrada6.txt","r");
    saida = fopen("C:\\Lab6\\Lab6_Sergio_Luis_dos_Santos_Filho.txt","w");
    fprintf(saida,"        Programa Strings\n");
    fprintf(saida," Escrito pelo aluno Sérgio Luís\n");
    fprintf(saida,"        Lab-6 de CES 10\n");
    fprintf(saida,"--------------------------------");
    // declarar variáveis
    strcpy(salvo,"");
    // pular as 7 primeiras linhas
    for (i = 1; i < 8; i++)
        fgets(residuo,80,entrada);
    // pula um caracter
    fscanf(entrada, "%s ",residuo);
    // enquanto o residuo não for o caractere |
    while (strcmp(residuo,"|") == 0)
    {
        qtd = 0;
        fscanf(entrada,"%s ", pre_pasta);
        fscanf(entrada,"%s ", residuo);
        fscanf(entrada,"%s ", pre_arquivo);
        fscanf(entrada,"%s ", residuo);
        fscanf(entrada,"%s ", palavra);
        fscanf(entrada,"%s ", residuo);
        fscanf(entrada,"%s ", residuo);
        // se a pasta for a mesma que a anterior
        if (strcmp(pre_pasta,"=") == 0)
        {
            // copia o nome da pasta para a string pasta
            strcpy(pasta,comp_pasta);
            // se o arquivo for igual ao anterior
            if (strcmp(pre_arquivo, "=") == 0)
                // copia o nome do arquivo para a string arquivo
                strcpy(arquivo,comp_arquivo);
            else
            {
                // copia o nome do arquivo para a string arquivo
                strcpy(arquivo,pre_arquivo);
                strcpy(comp_arquivo,pre_arquivo);
            }
        }
        else
        {
            // copia o nome da pasta para a string pasta
            strcpy(comp_pasta,pre_pasta);
            strcpy(pasta,pre_pasta);
            // copia o nome do arquivo para a string arquivo
            strcpy(comp_arquivo,pre_arquivo);
            strcpy(arquivo,pre_arquivo);
        }
        // montando o local do arquivo:
        strcpy(completo, strcat(pasta,"\\"));
        strcat(completo, strcat(arquivo, ".txt"));
        // abrir arquivo completo
        arq_cmplt = fopen (completo,"r");
        if (strcmp(pre_pasta,"=") != 0 || strcmp(pre_arquivo,"=") != 0)
        {
            fprintf(saida,"\n%s\n",completo);
        }
        // se nao ha arquivo e nao eh o mesmo que o arquivo anterior
        if (arq_cmplt == NULL && (strcmp(salvo,completo) != 0))
            fprintf(saida,"       ARQUIVO NAO ENCONTRADO.\n");
        // senao se nao ha arquivo
        else if(arq_cmplt != NULL)
        {
            // enquanto nao acabar de ler o arq_cmplt
            while (!feof(arq_cmplt))
            {
                // procura palavra e contabiliza quantas vezes foi encontrada
                fscanf(arq_cmplt,"%s ", procura);
                // se a palavra for igual a que procuramos, adicionamos 1 a sua quantidade
                if (strcmp(palavra,procura) == 0)
                    qtd += 1;
            }
            fprintf(saida, "       %s: %d ocorrencias\n",palavra,qtd);
            // fecha o arquivo completo
            fclose(arq_cmplt);
        }
        // copia o nome do arquivo completo para a string salvo
        strcpy(salvo,completo);
    }
    // fecha arquivos de entrada e saida
    fclose(entrada);
    fclose(saida);
    return 0;
}
