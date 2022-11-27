#include "hash.h"
#define n_notas 4

char *readline(){

    char *str = NULL;
    int n_char = 0;
     
     
     while(1){
        char c = getchar();
        
        if(c == '\r') continue;

        str = realloc(str, (n_char+1) * sizeof(char));
        if(c == ' '|| c == EOF){
            str[n_char] = '\0';
            break;
        }

        str[n_char] = c;
        n_char ++;
     }

    return str;

}

unsigned long int cria_hash(char *str){

    unsigned int low = 1, high = 0;
    for(int i = 0; str[i]; i++){
        low = (low + str[i]) % 65521;
        high = (high + low) % 65521;
    }

    unsigned long int hash = (high << 16) + low;
    return hash;

}

ALUNO *cria_aluno(){

    ALUNO *aluno = (ALUNO *)malloc(sizeof(ALUNO));
    return aluno;

}

HASHTABLE* cria_table(int tamanho){


    HASHTABLE* ht = (HASHTABLE*) malloc(sizeof(HASHTABLE));
    ht -> tamanho = tamanho;
    ht -> qtd = 0;
    ht -> alunos = (ALUNO **)calloc(tamanho, sizeof(ALUNO*));

    //Setar todos os ponteiros de ALUNO para nulo será extremamente útil para futuras
    //comparações
    for(int i = 0; i < ht -> tamanho; i++) ht -> alunos[i] = NULL;
    
    return ht;

}

void table_insere(HASHTABLE *ht, ALUNO *aluno, char *nusp){

    unsigned long int index = cria_hash(nusp) % (ht -> tamanho);
    
    ALUNO *aluno_atual = ht -> alunos[index];


    //Caso 1: Não há aluno registrado nesse index
    if(aluno_atual == NULL){

        if(ht -> qtd == ht -> tamanho){
            //adicionar um free aluno depois
            return;
        }

        ht -> alunos[index] = aluno;
        ht -> qtd ++;
        printf("Cadastro efetuado com sucesso\n");
        return;

    }

    //Caso 2: Já existe um aluno registrado nesse index, mas o nusp é o mesmo
    //(Portanto, sem colisão)
    if(strcmp(aluno_atual -> nusp, nusp) == 0){
        printf("NUSP ja cadastrado\n");
        return;
    }


    //Caso 3: Já existe um aluno diferente registrado nesse index (colisão)

    //colisao (adicionar aqui)







}



void leitura_cadastro(HASHTABLE *ht, int n){

    for(int i = 0; i < n; i++){

        ALUNO *aluno = cria_aluno();
        char *nusp = readline();
        char *senha = readline();
        for(int j = 0; j < 4; j++){
            scanf("%lf", &aluno -> notas[j]);
        }

        unsigned long int senha_ht = cria_hash(senha);
        aluno -> nusp = nusp;
        aluno -> senha = senha_ht;
        
        

        table_insere(ht, aluno, nusp);
        



    }



}

LISTA** cria_lista_colisoes(HASHTABLE *ht){

    LISTA** colisoes = (LISTA**) calloc(ht -> tamanho, sizeof(LISTA*));

    for(int i = 0; i < ht -> tamanho; i++) colisoes[i] = NULL;

    return colisoes;

}





void printa(ALUNO **alunos, int n){

   
}





// LISTA *cria_lista(){

//     LISTA* l = (LISTA *)malloc(sizeof(LISTA));
//     return l;

// }

// LISTA* insere_lista(LISTA *l, ALUNO *aluno){

//     //Caso 1: Lista vazia
//     if(!l){
        
//         LISTA* head = cria_lista();
//         head -> aluno = aluno;
//         head -> prox = NULL;
//         l = head;
//         return l;


//     }

//     //Caso 2: Inserção no começo
//     if(l -> prox = NULL){
        
//         LISTA *bloco = cria_lista();
//         bloco -> aluno = aluno;
//         bloco -> prox = NULL;
//         l -> prox = bloco;
//         return l;

//     }

//     //Caso 3: Inserção no fim
//     LISTA* aux = l;
//     while(aux -> prox != NULL) aux = aux -> prox;

//     LISTA *bloco = cria_aluno();
//     bloco -> aluno = aluno;
//     bloco -> prox = NULL;
//     aux -> prox = bloco;
//     return l;
    

// }

// ALUNO *pop_lista(LISTA *l){

//     if(l -> prox == NULL) return NULL;

//     LISTA *bloco = l -> prox;
//     LISTA *aux = l;

//     aux -> prox = NULL;
//     l = bloco;

//     ALUNO *aluno = NULL;
//     memcpy(aux -> aluno, aluno, sizeof(ALUNO));
    
//     free(aux -> aluno -> nusp);
//     free(aux -> aluno -> senha);
//     free(aux -> aluno);
//     free(aux);

//     return aluno;


// }

// void destroi_lista(LISTA *l){
    
//     LISTA *aux; 
//     while(l != NULL){
        
//         aux = l;
//         l = l -> prox;
//         free(aux -> aluno -> nusp);
//         free(aux -> aluno -> senha);
//         free(aux -> aluno);
//         free(aux);

//     }

// }
