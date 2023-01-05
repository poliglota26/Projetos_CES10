/*
Programado por Sergio Luis dos Santos Filho
CES 10
Programado em Code::Blocks 20.03
Prof. Armando Gouveia
*/

#include <stdio.h>
#include <math.h>

int main ()
{
    float matriz[10][10],
          valor, // elemento que se encaixa em cada item
          norma_um; // armazena a norma um
    int m, n; // numero de linhas (m) e de colunas (n) da matriz
    int i, j, k, p; // variaveis auxiliares
    int qtd; // quantidade de numeros negativos
    int pos_lin, pos_col, pos_lin_2,pos_col_2; // armazena a posicao de um elemento
    FILE * entrada,
         * saida;
    entrada = fopen("entrada8.txt","r");
    saida = fopen("Lab8_Sergio_Luis_dos_Santos_Filho.txt","w");
    // mensagem inicial
    fprintf(saida,"           Lab 8 de CES 10 - 2022\n");
    fprintf(saida," Programado por Sérgio Luís dos Santos Filho\n");
    fprintf(saida,"---------------------------------------------\n\n");
    // armazenar numero de linhas e de colunas da matriz
    fscanf(entrada,"%d %d ", &m, &n);
    // armazenar os valores da matriz
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            fscanf(entrada,"%f ", &matriz[i][j]);
    }
    // menor elemento da matriz
    valor = matriz[0][0];
    pos_lin = 0;
    pos_col = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (matriz[i][j] < valor)
            {
                valor = matriz[i][j];
                pos_lin = i;
                pos_col = j;
            }
        }
    }
    fprintf(saida, "(a) \nO menor elemento eh %g \n", valor);
    fprintf(saida, "Estah na posicao (%d, %d)\n\n", pos_lin, pos_col);
    // elemento que contem mais "vizinhos" negativos
    qtd = 0;
    pos_col = 0;
    pos_lin = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            valor = 0;
            for(k = i-1; k <= i+1; k++)
            {
                // para contabilizar os vizinhos negativos
                for(p = j-1; p <= j+1; p++)
                {
                    // se existe o elemento na matriz
                    if(0 <= k && k < m && 0 <= p && p < n)
                    {
                        // se o numero eh negativo e eh vizinho do elemento selecionado inicialmente
                        if(matriz[k][p] < 0 && !(k == i && p == j))
                        {
                            valor++;
                        }
                    }
                }
            }
            if (valor > qtd)
            {
                qtd = valor;
                pos_col = j;
                pos_lin = i;
            }
        }
    }
    if (qtd == 0)
    {
        fprintf(saida, "(b) \nA matriz nao possui valores negativos \n\n");
    }
    else
    {
        fprintf(saida, "(b) \nO elemento que contem mais vizinhos negativos eh %g \n", matriz[pos_lin][pos_col]);
        fprintf(saida, "Estah na posicao (%d, %d) \n", pos_lin, pos_col);
        fprintf(saida, "Possui %d vizinhos negativos\n\n", qtd);
    }

    // o par de elementos com menor diferenca de valor
    valor = fabs(matriz[0][0] - matriz[0][1]);
    pos_lin = 0;
    pos_col = 0;
    pos_lin_2 = 0;
    pos_col_2 = 1;
    for (i = 0; i< m; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < m; k++)
            {
                for (p = 0; p < n; p++)
                {
                    // se o modulo diferenca eh o menor ate entao e as posicoes nao sao as mesmas
                    if((fabs(matriz[i][j] - matriz[k][p]) < valor) && (i != k || j != p))
                    {
                        valor = fabs(matriz[i][j] - matriz[k][p]);
                        pos_lin = i;
                        pos_col = j;
                        pos_lin_2 = k;
                        pos_col_2 = p;
                    }
                }
            }
        }
    }
    fprintf(saida, "(c) \nO par de elementos com menor diferenca de valor eh:\n");
    fprintf(saida, "%g na posicao (%d, %d)\n", matriz[pos_lin][pos_col], pos_lin, pos_col);
    fprintf(saida, "%g na posicao (%d, %d)\n\n", matriz[pos_lin_2][pos_col_2], pos_lin_2, pos_col_2);
    // a "norma um"
    norma_um = 0;
    k = 0;
    for (j = 0; j < n; j++)
    {
        valor = 0;
        for (i = 0; i < m; i++)
        {
            valor += fabs(matriz[i][j]);
        }
        if (valor > norma_um)
        {
            norma_um = valor;
            k = j;
        }
    }
    fprintf(saida, "(d) \nA \"norma um\" vale %g\n", norma_um);
    fprintf(saida, "Ocorre na coluna %d \n\n", k);
    // finalizando arquivos
    fclose(entrada);
    fclose(saida);
    return 0;
}
