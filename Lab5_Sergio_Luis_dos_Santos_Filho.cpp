#include <stdio.h>
int main ()
{
    // declaracao de variaveis
    int bolo, gelatina, fruta, sorvete; // contem o numero de pedidos de cada sobremesa
    FILE * entrada;
    FILE * saida;
    // abrir arquivos
    entrada = fopen("entrada5.txt","r");
    saida = fopen ("Lab5_Sergio_Luis_dos_Santos_Filho.txt","w");
    // escrever mensagem inicial na tela
    fprintf(saida, "Programa Sobremesas\n");
    fprintf(saida, "Escrito pelo aluno Sérgio Luís\n");
    fprintf(saida, "Lab-5 de CES 10\n");
    fprintf(saida, "-----\n");
    // enquanto tiver algum pedido:
    while ((fscanf(entrada, "%d %d %d %d", &bolo, &gelatina, &fruta, &sorvete)) != -1)
    {
        // caso tenha pedido bolo
        if (bolo != 0)
        {
            fprintf(saida, "%d ", bolo);
            // se tiver pedido um bolo
            if (bolo == 1)
                fprintf(saida, "bolo");
            // se tiver pedido mais de um bolo
            else
                fprintf(saida, "bolos");
        }
        // caso tenha pedido gelatina
        if (gelatina != 0)
        {
            // se tiver pedido bolo
            if (bolo != 0)
            {
                // se tiver pedido fruta ou sorvete
                if (fruta != 0 || sorvete != 0)
                    fprintf(saida, ", ");
                else
                    fprintf(saida, " e ");
            }
            fprintf(saida, "%d ", gelatina);
            if (gelatina == 1)
                fprintf(saida, "gelatina");
            else
                fprintf(saida, "gelatinas");
        }
        // se tiver pedido fruta
        if (fruta != 0)
        {
            // se tiver pedido bolo ou gelatina
            if(bolo != 0 || gelatina != 0)
            {
                // se não tiver pedido sorvete
                if (sorvete == 0)
                    fprintf (saida, " e ");
                // se tiver pedido sorvete
                else
                    fprintf (saida, ", ");
            }
            fprintf(saida, "%d ", fruta);
            // se tiver pedido uma fruta
            if (fruta == 1)
                fprintf(saida, "fruta");
            // se tiver pedido mais de uma fruta
            else
                fprintf(saida, "frutas");
        }
        // se tiver pedido sorvete
        if (sorvete != 0)
        {
            // se tiver pedido bolo ou gelatina ou fruta
            if (bolo != 0 || gelatina != 0 || fruta != 0)
                fprintf (saida, " e ");
            fprintf(saida, "%d ", sorvete);
            // se tiver pedido um sorvete
            if (sorvete == 1)
                fprintf(saida, "sorvete");
            // se tiver pedido mais de um sorvete
            else
                fprintf(saida, "sorvetes");
        }
        // ponto final
        fprintf(saida,".\n");
    }
    // fechar arquivos
    fclose(entrada);
    fclose(saida);
    // encerrar
    return 0;
}
