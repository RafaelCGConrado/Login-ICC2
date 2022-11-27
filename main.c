#include "hash.h"
#define tam_ht 100


int main(){

   

    int n, n_login;
    scanf("%d", &n);


    HASHTABLE *hs = cria_table(tam_ht);

    //Leitura da entrada, conversões e inserções na Hash Table
    leitura_cadastro(hs, n);

    for(int i = 0; i < tam_ht; i++){
        if(hs -> alunos[i] != NULL){
            printf("%s\n", hs -> alunos[i] -> nusp);
            for(int j = 0; j < 4; j++) printf("%lf ", hs -> alunos[i] -> notas[j]);
            printf("\n");
            
        }
    }




    //pesquisa e retorno


   

    return 0;
}
