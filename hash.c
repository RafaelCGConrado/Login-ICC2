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
        n_char++;
        
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

    
    unsigned long int index = (cria_hash(aluno -> nusp) % (ht -> tamanho));

    ALUNO *aluno_atual = ht -> alunos[index];

    //Caso 1: Sem registros prévios nesse index
    if(aluno_atual == NULL){

        ht -> alunos[index] = aluno;
        printf("Cadastro efetuado com sucesso\n");
        return;

    }
    
    //Caso 2: nusp são iguais
    if(strcmp(aluno_atual -> nusp, aluno -> nusp) == 0){
        printf("NUSP ja cadastrado\n");
        return;

    }
    

   // Caso 3: Colisão (Resolvendp com listas encadeadas)
       
        ALUNO *p = aluno_atual;
        ALUNO *anterior;


        while(p != NULL){
            
            anterior = p;
            p = p -> prox;

        }
        
        anterior -> prox = aluno;
        printf("Cadastro efetuado com sucesso\n");
        return;

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
    
    if(aluno_atual != NULL){

        //Primeiro caso: Existe e é o aluno buscado
        if(strcmp(aluno_atual -> nusp, nusp) == 0){

            if(senha_hs == aluno_atual -> senha){

                printf("Notas: ");
                printf("P1=%.1lf, P2=%.1lf, ", aluno_atual -> notas[0], aluno_atual -> notas[1]);
                printf("T1=%.1lf, T2=%.1lf\n", aluno_atual -> notas[2], aluno_atual -> notas[3]);
                return;

            }

            printf("Senha incorreta para o NUSP digitado\n");
            return;
        }

        //Segundo caso: Existe, mas ainda não é o buscado (colisao)
        ALUNO *p = aluno_atual -> prox;
        

        while(p != NULL){
            if(strcmp(p -> nusp, nusp) == 0){
                
                if(senha_hs == p -> senha){

                    printf("Notas: ");
                    printf("P1=%.1lf, P2=%.1lf, ", p -> notas[0], p -> notas[1]);
                    printf("T1=%.1lf, T2=%.1lf\n", p -> notas[2], p -> notas[3]);
                    return;

                }
                printf("Senha incorreta para o NUSP digitado\n");
                return;

            }

            //Ainda não é o aluno procurado. Avançamos para
            //o próximo aluno da lista
            p = p -> prox;

        }


    }

    //Ultimo caso: Não foi registrado
    printf("NUSP invalido\n");
    return;

}

void busca(HT *ht, int n_senhas){

    char *nusp;
    char senha[50];

    for(int i = 0; i < n_senhas; i++){
        nusp = readline();
        scanf("%s", senha);

        busca_ht(ht, nusp, senha);
    }
}
