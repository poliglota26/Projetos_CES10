#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1;
#define FALSE 0;
typedef int boolean;

int i, k,
    num_inscritos,
    folhas_resp,
    num_aux,
    ausente; // conta o numero de ausentes para facilitar a ordenacao dos presentes
char gab[55],
     residuo[80],
     curso[15],
     situacao[20];
FILE * saida;
boolean entrou; // booleana auxiliar
struct candidato
{
    char nome[30];
    int num_inscricao;
    char curso;
    char resposta[55];
    float nota = 0;
    boolean presente = FALSE;
    boolean aprovado = FALSE;
    boolean lista_espera = FALSE;
    boolean imprimiu_a = FALSE; //comparar se já imprimiu esse candidato no item a)
    boolean imprimiu_c = FALSE; //comparar se já imprimiu esse candidato no item c)
};
struct curso
{
    int aprovados = 0;
    int vagas;
    float nota_min;
};
struct candidato inscrito[70];
struct candidato stru_aux; // struct auxiliar
struct curso comp;
struct curso ast;
struct curso tur;
// funcao que ordena printa os nomes dos aprovados em ordem alfabetica por curso
void imprime_ordem_alfabetica(char letra_curso)
{
    entrou = TRUE;
    for(i = 0; i < num_inscritos && entrou; i++)
    {
        num_aux = 0;
        entrou = FALSE;
        for(k = 0; k < num_inscritos; k++)
        {
            if(inscrito[k].curso == letra_curso && inscrito[k].aprovado && !inscrito[k].imprimiu_a)
            {
                if(!entrou || strcmp(inscrito[k].nome, inscrito[num_aux].nome) < 0)
                    num_aux = k;
                entrou = TRUE;
            }
        }
        if(entrou)
        {
            fprintf(saida, "    %s\n", inscrito[num_aux].nome);
            inscrito[num_aux].imprimiu_a = TRUE;
        }
    }
}
// funcao que encontra o resultado do candidato (aprovado, fila de espera, etc.)
void resultado(int *num_aprovados, int num_vagas, int i, float nota_min)
{
    if(inscrito[i].nota >= nota_min)
    {
        if(*num_aprovados < num_vagas)
        {
            *num_aprovados = *num_aprovados + 1;
            inscrito[i].aprovado = TRUE;
        }
        else
            inscrito[i].lista_espera = TRUE;
    }
}

int main()
{
    FILE * inscritos,
         * gabarito,
         * respostas;
    inscritos = fopen("Lab10_inscritos.txt", "r");
    respostas = fopen("Lab10_respostas_preenchidas.txt", "r");
    gabarito = fopen("Lab10_gabarito.txt", "r");
    saida = fopen("Lab10_Sergio_Luis_dos_Santos_Filho.txt", "w");
    // Leitura dos dados dos candidatos
    for (i = 0; i < 4; i++)
        fgets(residuo, 80, inscritos);
    for (i = 0; i < 4; i++)
        fscanf(inscritos, " %s ", residuo);
    fscanf(inscritos," %d ", &num_inscritos);
    for(i = 0; i < 3; i++)
        fgets(residuo, 80, inscritos);
    for(i = 0; i < num_inscritos; i++)
    {
        fscanf(inscritos, " %d ", &inscrito[i].num_inscricao);
        fgets(inscrito[i].nome, 27, inscritos);
        fscanf(inscritos, " %c ", &inscrito[i].curso);
    }
    // Leitura do gabarito
    for(i = 0; i < 6; i++)
        fgets(residuo, 80, gabarito);
    fscanf(gabarito, " %s ", gab);
    for(i = 0; i < 3; i++)
        fgets(residuo, 80, gabarito);
    fscanf(gabarito, " %s ", residuo);
    fscanf(gabarito, " %d ", &comp.vagas);
    fscanf(gabarito, " %f ", &comp.nota_min);
    fscanf(gabarito, " %s ", residuo);
    fscanf(gabarito, " %d ", &ast.vagas);
    fscanf(gabarito, " %f ", &ast.nota_min);
    fscanf(gabarito, " %s ", residuo);
    fscanf(gabarito, " %d ", &tur.vagas);
    fscanf(gabarito, " %f ", &tur.nota_min);
    // Leitura dos cartoes respostas
    for(i = 0; i < 4; i++)
        fgets(residuo, 80, respostas);
    for (i = 0; i < 4; i++)
        fscanf(respostas, " %s ", residuo);
    fscanf(respostas, " %d ", &folhas_resp);
    for(i = 0; i < 3; i++)
        fgets(residuo, 80, respostas);
    for(i = 0; i < folhas_resp; i++)
    {
        fscanf(respostas, " %d ", &num_aux);
        entrou = FALSE;
        for(k = 0; k < num_inscritos && !entrou; k++)
            if(num_aux == inscrito[k].num_inscricao)
            {
                fscanf(respostas, " %s ", inscrito[k].resposta);
                inscrito[k].presente = TRUE;
                entrou = TRUE;
            }
    }
    // fechar arquivos
    fclose(inscritos);
    fclose(gabarito);
    fclose(respostas);
    // calcular a nota de cada candidato
    for(i = 0; i < num_inscritos; i++)
        if(inscrito[i].presente)
            for(k = 0; k < 50; k++)
                if(gab[k] == inscrito[i].resposta[k])
                    inscrito[i].nota += (10.0 / 50.0);
    // ordenar (decrescente) por nota, sendo ordem alfabetica o criterio de desempate
    entrou = TRUE;
    for(i = 0; i < num_inscritos && entrou; i++)
    {
        entrou = FALSE;
        for( k = 0; k < (num_inscritos - i - 1); k++)
        {
            if(inscrito[k].nota < inscrito[k+1].nota)
            {
                stru_aux = inscrito[k+1];
                inscrito[k+1] = inscrito[k];
                inscrito[k] = stru_aux;
                entrou = TRUE;
            }
            else if(inscrito[k].nota == inscrito[k+1].nota)
                if(strcmp(inscrito[k].nome, inscrito[k+1].nome) > 0)
                {
                    stru_aux = inscrito[k+1];
                    inscrito[k+1] = inscrito[k];
                    inscrito[k] = stru_aux;
                    entrou = TRUE;
                }
        }
    }
    // Conferir quais candidatos foram aprovados ou estao na lista de espera
    for(i = 0; i < num_inscritos; i++)
        if(inscrito[i].presente)
        {
            if(inscrito[i].curso == 'C')
                resultado(&comp.aprovados, comp.vagas, i, comp.nota_min);
            else if(inscrito[i].curso == 'A')
                resultado(&ast.aprovados, ast.vagas, i, ast.nota_min);
            else if(inscrito[i].curso == 'T')
                resultado(&tur.aprovados, tur.vagas, i, tur.nota_min);
        }
    /// item a)
    fprintf(saida, "----------------------------------\n");
    fprintf(saida, "a) Classificados no vestibular\n");
    fprintf(saida, "----------------------------------\n\n");
    // sublista de computacao
    fprintf(saida, "Sub-lista Computacao:\n\n");
    imprime_ordem_alfabetica('C');
    if(comp.aprovados > 0)
        fprintf(saida,"\n");
    fprintf(saida, "        Numero de classificados: %d\n", comp.aprovados);
    fprintf(saida, "        Vagas remanescentes:     %d\n\n", comp.vagas - comp.aprovados);
    // sublista de astronomia
    fprintf(saida, "Sub-lista Astronomia:\n\n");
    imprime_ordem_alfabetica('A');
    if(ast.aprovados > 0)
        fprintf(saida,"\n");
    fprintf(saida, "        Numero de classificados: %d\n", ast.aprovados);
    fprintf(saida, "        Vagas remanescentes:     %d\n\n", ast.vagas - ast.aprovados);
    // sublista de turismo
    fprintf(saida, "Sub-lista Turismo:\n\n");
    imprime_ordem_alfabetica('T');
    if(tur.aprovados > 0)
        fprintf(saida,"\n");
    fprintf(saida, "        Numero de classificados: %d\n", tur.aprovados);
    fprintf(saida, "        Vagas remanescentes:     %d\n\n", tur.vagas - tur.aprovados);
    /// item b)
    fprintf(saida, "----------------------------------\n");
    fprintf(saida, "b) Pontuacao geral\n");
    fprintf(saida, "----------------------------------\n\n");
    fprintf(saida, "Posicao       Nome                   Nota\n\n");
    ausente=0;
    // printa em ordem de nota, apenas os candidatos presentes
    for(i = 0; i < num_inscritos; i++)
    {
        if(inscrito[i].presente)
            fprintf(saida, "%5d    %s  %4.1f\n", i+1-ausente, inscrito[i].nome, inscrito[i].nota);
        else ausente++;
    }
    /// item c)
    fprintf(saida, "\n----------------------------------\n");
    fprintf(saida, "c) Relatorio completo\n");
    fprintf(saida, "----------------------------------\n\n");
    fprintf(saida, " Num.          Nome                   Curso    Nota   Situacao\n\n");
    for(i = 0; i < num_inscritos; i++)
    {
        num_aux = 0;
        entrou = FALSE;
        for(k = 0; k < num_inscritos; k++)
        {
            if(!inscrito[k].imprimiu_c)
            {
                if(!entrou || strcmp(inscrito[k].nome, inscrito[num_aux].nome) < 0)
                    num_aux = k;
                entrou = TRUE;
            }
        }
        if(inscrito[num_aux].curso == 'C')
            strcpy(curso, "Computacao");
        else if(inscrito[num_aux].curso == 'A')
            strcpy(curso, "Astronomia");
        else if(inscrito[num_aux].curso == 'T')
            strcpy(curso, "Turismo   ");
        if (!inscrito[num_aux].presente)
            strcpy(situacao, "ausente");
        else if(inscrito[num_aux].aprovado)
            strcpy(situacao, "classificado");
        else if(inscrito[num_aux].lista_espera)
            strcpy(situacao, "lista de espera");
        else strcpy(situacao, "reprovado");
        // printa a situacao de cada aluno em ordem alfabetica
        fprintf(saida, "%5d  %s  %s  %4.1f  %s\n", inscrito[num_aux].num_inscricao, inscrito[num_aux].nome, curso, inscrito[num_aux].nota, situacao);
        inscrito[num_aux].imprimiu_c = TRUE;
    }
    fclose(saida);
    return 0;
}
