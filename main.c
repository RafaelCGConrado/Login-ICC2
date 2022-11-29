#include "hash.h"
#define tam 100

int main(){

    int n;
    scanf("%d", &n);

    //Leitura
    HT *ht = cria_ht(tam);
    leitura_cadastro(ht, n);

    //Pesquisa
    // int n_buscas;
    // scanf("%d", &n_buscas);

    
    
    int n_senhas;
    scanf("%d", &n_senhas);

    busca(ht, n_senhas);

   
    

    return 0;

}
