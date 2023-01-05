/*  Sérgio Luís dos Santos Filho

    Turma 2

    Exercício 4: Contagem de Dias

    Programa compilado com Code::Blocks 20.03 */
#include <stdio.h>
int main()
{
    // declaracao de variaveis
    int di, // dia inicial
        mi, // mes inicial
        ai, // ano inicial
        df, // dia final
        mf, // mes final
        af, // ano final
        n,  // quantidade de casos
        dias, // contagem de dias
        i,
        j;
    FILE * entrada;
    FILE * saida;
    // abrir arquivos de entrada e saida
    entrada = fopen ("entrada4.txt","r");
    saida = fopen ("Lab4_Sergio_Luis_dos_Santos_Filho.txt","w");
    // escrever mensagem inicial no arquivo de saida
    fprintf(saida,"       INICIO DO PROGRAMA DE CONTAGEM DE DIAS\n");
    fprintf(saida," Programado pelo aluno Sergio Luis dos Santos Filho\n");
    fprintf(saida,"                   Turma 2 - T26\n");
    fprintf(saida,"----------------------------------------------------\n");
    // ler a quantidade n de casos
    fscanf(entrada,"%d",&n);
    // para cada um dos n casos, fazer:
    for(i = 1; i<=n; i = i + 1)
    {
        // le as datas de inicio e de fim
        fscanf(entrada,"%d %d %d %d %d %d",&di,&mi,&ai,&df,&mf,&af);
        // caso as datas sao no mesmo mes do mesmo ano:
        if(mi == mf && ai == af)
            dias = df - di;
        // caso as datas sao do mesmo ano, mas nao no mesmo mes:
        else if (ai == af)
        {
            // contar quantos dias para encerrar o mes inicial
            if (mi == 2)
            {
                // se não for ano bissexto
                if(ai%4 != 0 || (ai%100 == 0 && (ai%400 != 0)))
                    dias = 28 - di;
                // se for ano bissexto
                else
                    dias = 29 - di;
            }
            else if (mi == 4 || mi == 6 || mi == 9 || mi == 11)
                dias = 30 - di;
            else
                dias = 31 - di;
            // somar os dias dos meses entre mi e mf
            for(j = 1; (mi + j) < mf; j = j + 1)
            {
                if ((mi+j) == 2)
                {
                    // se não for ano bissexto
                    if(ai%4 != 0 || (ai%100 == 0 && ai%400 != 0))
                        dias = dias + 28;
                    // se for ano bissexto
                    else
                        dias = dias + 29;
                }
                else if((mi+j)==4 || (mi+j)==6 || (mi+j)==9 || (mi+j)==11)
                    dias = dias + 30;
                else
                    dias = dias + 31;
            }
            // somar os dias do mes final
            dias = dias + df;
        }
        // caso as datas sejam de anos diferentes
        else
        {
            // contar quantos dias para encerrar o mes inicial
            if (mi == 2)
            {
                // se não for ano bissexto
                if(ai%4 != 0 || (ai%100 == 0 && (ai%400 != 0)))
                    dias = 28 - di;
                // se for ano bissexto
                else
                    dias = 29 - di;
            }
            else if (mi == 4 || mi == 6 || mi == 9 || mi == 11)
                dias = 30 - di;
            else
                dias = 31 - di;
            // contar quantos dias para encerrar o ano inicial
            for(j = 1; (mi+j)<13 ; j = j + 1)
            {
                if ((mi+j) == 2)
                {
                    // se não for ano bissexto
                    if(ai%4 != 0 || (ai%100 == 0 && (ai%400 != 0)))
                        dias = dias + 28;
                    // se for ano bissexto
                    else
                        dias = dias + 29;
                }
                else if ((mi+j) == 4 || (mi+j) == 6 || (mi+j) == 9 || (mi+j) == 11)
                    dias = dias + 30;
                else
                    dias = dias + 31;
            }
            // somar os dias dos anos entre ai e af
            for (j = 1; (ai+j)<af; j = j + 1)
            {
                // se não for ano bissexto
                if((ai+j)%4 != 0 || ((ai+j)%100 == 0 && ((ai+j)%400 != 0)))
                    dias = dias + 365;
                // se for ano bissexto
                else
                    dias = dias + 366;
            }
            // somar os dias dos meses entre janeiro e mf
            for(j = 1; j < mf; j = j + 1)
            {
                if (j == 2)
                {
                    // se não for ano bissexto
                    if(af%4 != 0 || (af%100 == 0 && af%400 != 0))
                        dias = dias + 28;
                    // se for ano bissexto
                    else
                        dias = dias + 29;
                }
                else if(j==4 || j==6 || j==9 || j==11)
                    dias = dias + 30;
                else
                    dias = dias + 31;
            }
            // somar os dias do mes final
            dias = dias + df;
        }
        // escrever no arquivo o numero de dias entre a data inicial e a final
        fprintf(saida,"%2d:%7d dias.\n",i,dias);
    }
    // fechar arquivos de entrada e saida
    fclose(entrada);
    fclose(saida);
    // finalizar
    return 0;
}
