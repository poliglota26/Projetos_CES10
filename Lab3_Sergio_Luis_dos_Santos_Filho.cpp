/*  Sérgio Luís dos Santos Filho

    Turma 2

    Exercício 3: Conversor de Medidas

    Programa compilado com Code::Blocks 20.03 */
#include <stdio.h>
#include <stdlib.h>
int main ()
{
    // declaracao de variaveis
    int i,
        n,
        massa,
        maior_massa,
        qtd_massa,
        temperatura,
        qtd_temp,
        menor_temp,
        qtd_dist,
        milhas,
        jardas,
        pes,
        polegadas;
    float valor;
    char unidade;
    FILE * entrada;
    FILE * saida;
    // escrever mensagem inicial na tela
    printf("----------------------------\n");
    printf("INICIO DO PROGRAMA CONVERSOR\n");
    printf("----------------------------\n\n");
    // atribuicao inicial para algumas variaveis
    i = 1;
    qtd_massa = 0;
    qtd_temp = 0;
    qtd_dist = 0;
    // abrir arquivos de entrada e saida
    entrada = fopen ("entrada3.txt", "r");
    saida = fopen ("saida3.txt", "w");
    // escrever mensagem inicial no arquivo
    fprintf(saida, "--------------------------------------\n");
    fprintf(saida, "          PROGRAMA CONVERSOR\n");
    fprintf(saida, "--------------------------------------\n\n");
    // ler a quantidade n de casos
    fscanf(entrada, "%d", &n);
    // para cada um dos n casos, fazer:
    while (i <= n)
    {
        // ler um float e um char com a unidade
        fscanf(entrada, "%f %c", &valor,&unidade);
        // se unidade m (metros)
        if (unidade == 'm' || unidade == 'M')
        {
            // converter distancia
            milhas = valor / (2.54*0.01*12*3*1760);
            jardas = valor / (2.54*0.01*12*3) - 1760*milhas;
            pes = valor / (2.54*0.01*12) - 3*jardas - 1760*3*milhas;
            polegadas = valor / (2.54*0.01) - 12*pes - 12*3*jardas - 1760*3*12*milhas;
            fprintf (saida, " %.2f metros =\n", valor);
            fprintf (saida, " %8d milhas +\n", milhas);
            fprintf (saida, " %8d jardas +\n", jardas);
            fprintf (saida, " %8d pes    +\n", pes);
            fprintf (saida, " %8d polegadas\n\n", polegadas);
            // soma um a quantidade de casos do tipo distancia
            qtd_dist = qtd_dist + 1;
        }
        // se unidade k (kilogramas)
        else if (unidade == 'k' || unidade == 'K')
        {
            // converter massa
            massa = valor/0.453592;
            // verifica se eh a maior ate o momento
            if (massa > maior_massa || qtd_massa == 0)
                maior_massa = massa;
            fprintf (saida, " %.2f kilogramas =\n %8d libras\n\n", valor, massa);
            // soma um a quantidade de casos do tipo massa
            qtd_massa = qtd_massa + 1;
        }
        // se unidade c (celsius)
        else if (unidade == 'c' || unidade == 'C')
        {
            // converter temperatura
            temperatura = (9 * valor)/5 + 32;
            // verifica se eh a menor ate o momento
            if (temperatura < menor_temp || qtd_temp == 0)
                menor_temp = temperatura;
            fprintf (saida, " %.2f graus Celsius =\n %8d graus Fahrenheit\n\n", valor, temperatura);
            // soma um a quantidade de casos do tipo temperatura
            qtd_temp = qtd_temp + 1;
        }
        i = i + 1;
    }
    // Ao terminar arquivo de entrada, escrever as informaçoes acumuladas (a), (b) e (c)
    fprintf (saida, "--------------------------------------\n");
    fprintf (saida, "(a) Quantidade de casos de cada tipo:\n");
    fprintf (saida, "    Massa      :  %d vezes\n", qtd_massa);
    fprintf (saida, "    Temperatura:  %d vezes\n", qtd_temp);
    fprintf (saida, "    Distancia  :  %d vezes\n\n", qtd_dist);
    fprintf(saida, "(b) Qual a maior massa:\n");
    if (qtd_massa != 0)
        fprintf (saida, "%5d libras.\n\n", maior_massa);
    else
        fprintf (saida, "Nao ha valores de massa.\n\n");
    fprintf (saida, "(c) Qual a menor temperatura:\n");
    if (qtd_temp != 0)
        fprintf (saida, "%5d Fahrenheit.\n\n", menor_temp);
    else
        fprintf (saida, "Nao ha valores de temperatura.\n\n");
    fprintf (saida, "--------------------------------------\n");
    fprintf(saida, "Fim do arquivo.");
    // fechar arquivos de entrada e saida
    fclose (entrada);
    fclose (saida);
    // mensagem final na tela + pausa
    printf("----------------------------\n");
    printf(" FIM DO PROGRAMA CONVERSOR\n");
    printf("----------------------------\n\n");
    printf ("Tecle ENTER para fechar o programa");
    getchar ();
    //finalizar
    return 0;
}
