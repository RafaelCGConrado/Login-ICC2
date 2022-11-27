#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct aluno ALUNO;
typedef struct hashtable HASHTABLE;
typedef struct lista LISTA;


struct aluno{

    char *nusp;
    unsigned long int senha;
    double notas[4];

};

struct hashtable{

    ALUNO** alunos;
    int tamanho;
    int qtd;
    

};

//Função utilizada para ler uma linha inteira da STDIN (Em particular, NUSP e senha)
char *readline();

//Cria o hash correspondente de acordo com o nusp ou senha
unsigned long int cria_hash(char *str);


//Cria a hashtable que será utilizada
HASHTABLE* cria_table(int tamanho);

//Lê as entradas, faz as conversões e cadastra os alunos na
//HashTable fornecida
void leitura_cadastro(HASHTABLE *hs, int n);




//Funções de Lista Encadeada

LISTA *cria_lista();

LISTA *insere_lista(LISTA *l, ALUNO *aluno);

ALUNO *pop_lista(LISTA *l);

void destroi_lista(LISTA *lista);
