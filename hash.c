#include "hash.h"

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


ALUNO *cria_aluno(){

    ALUNO *aluno = (ALUNO*)malloc(sizeof(ALUNO));
    aluno -> prox = NULL;
    return aluno;

}

HT *cria_ht(int tamanho){

    HT* ht = (HT*)malloc(sizeof(HT));
    ht -> tamanho = tamanho;
    ht -> alunos = (ALUNO **)malloc(tamanho * sizeof(ALUNO*));

    for(int i = 0; i < tamanho; i++) ht -> alunos[i] = NULL;

    return ht;

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

void insere_ht(HT *ht, ALUNO *aluno){

    //o erro está nessa funcao, certeza
    unsigned long int index = (cria_hash(aluno -> nusp) % (ht -> tamanho));

    ALUNO *aluno_atual = ht -> alunos[index];

    //Caso 1: Sem registros prévios nesse index
    if(aluno_atual == NULL){

        ht -> alunos[index] = aluno;
        if(ht -> alunos[index] != NULL) printf("Cadastro efetuado com sucesso\n");
        printf("%s", ht -> alunos[index] -> nusp);
        if(ht -> alunos[index] != NULL) printf("ue porra\n");
        return;

    }

    //Caso 2: nusp são iguais
    if(strcmp(ht -> alunos[index] -> nusp, aluno_atual -> nusp) == 0) printf("NUSP ja cadastrado\n");

    //Caso 3: Colisão (É preciso lidar usando listas)
    else{
        ALUNO *p = aluno_atual;
        ALUNO *aux = aluno -> prox;

        while(p != NULL){
            
            p = p -> prox;
        }

        p = aux;
    }



}

void leitura_cadastro(HT *ht, int n){

    
    for(int i = 0; i < n; i++){
        
        ALUNO *aluno_atual = cria_aluno();
        char *nusp, *senha;
        nusp = readline();
        senha = readline();
        unsigned long int senha_hash = cria_hash(senha);

        aluno_atual -> nusp = nusp;
        aluno_atual -> senha = senha_hash;

        printf("%s\n", aluno_atual -> nusp);


        for(int j = 0; j < 4; j++){

            scanf("%lf", &aluno_atual -> notas[j]);

        }

        insere_ht(ht, aluno_atual);
        
    }



}

void busca_ht(HT *ht, char *nusp, char *senha){

    unsigned long int index = (cria_hash(nusp) % (ht -> tamanho));
    unsigned long int senha_hs = cria_hash(senha);

    ALUNO *aluno_atual = ht -> alunos[index];
    //o problema esta aqui, certeza!!!!!!
    if(aluno_atual != NULL) printf("Achei\n");


    

    //NUSP existe e ocupa o "topo" da lista
    if(strcmp(aluno_atual -> nusp, nusp) == 0){
        
        if(senha_hs == aluno_atual -> senha){
            
            printf("P1:%.1lf, ", aluno_atual -> notas[0]);
            printf("P2:%.1lf, ", aluno_atual -> notas[1]);
            printf("T1:%.1lf, ", aluno_atual -> notas[2]);
            printf("T2:%.1lf\n", aluno_atual -> notas[3]);

        }

        else printf("Senha incorreta\n");

        
    

    //     else printf("Senha incorreta para o NUSP digitado\n");

   }

    // //NUSP existe mas não é o do "topo" da lista (colisão)

    
    // aluno_buscado = aluno_buscado -> prox;
    // while(aluno_buscado != NULL){
        
        
    //     if(strcmp(aluno_buscado -> nusp, nusp) == 0){

    //         if(senha_hs == aluno_buscado -> senha){
                
    //             printf("P1:%1.lf, ", aluno_buscado -> notas[0]);
    //             printf("P2:%1.lf, ", aluno_buscado -> notas[1]);
    //             printf("T1:%1.lf, ", aluno_buscado -> notas[2]);
    //             printf("T2:%1.lf\n", aluno_buscado -> notas[3]);

    //         }

    //         else printf("Senha incorreta para o NUSP digitado\n");

    //     }
    //     aluno_buscado = aluno_buscado -> prox;
        
    // }

    // //NUSP não existe
    // if(aluno_buscado == NULL){

    //     printf("NUSP invalido\n");


    // }

}

void busca(HT *ht, int n_senhas){

    char *nusp;
    char *senha;

    for(int i = 0; i < n_senhas; i++){
        nusp = readline();
        senha = readline();

        busca_ht(ht, nusp, senha);
    }
}
