#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno ALUNO;
typedef struct hashtable HT;

//OBS: A struct aluno possui um *prox para que funcione
//como uma lista encadeada, com a intenção de resolver
//problemas de colisão
struct aluno{

    char *nusp;
    unsigned long int senha;
    double notas[4];
    ALUNO *prox;

};

struct hashtable{

    ALUNO **alunos;
    int tamanho;

};

//Lê a linha até encontrar um espaço (Fundamental para a leitura de NUSP e senha)
char *readline();

//Cria o item ALUNO
ALUNO *cria_aluno();

//Cria a HashTable
HT *cria_ht(int tamanho);

//Cria a hash que será utilizada no index e nas senhas
unsigned long int cria_hash(char *str);

//Insere o respectivo aluno na hashtable
void insere_ht(HT *ht, ALUNO *aluno);

//Recebe as entradas e cadastra na hashtable
void leitura_cadastro(HT *ht, int n);

//realiza as buscas de fato e printa de acordo com a saída
void busca_ht(HT *ht, char *nusp, char *senha);

//Recebe as entradas 
void busca(HT *ht, int n_senhas);
