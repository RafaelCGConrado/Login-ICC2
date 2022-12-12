#include "hash.h"
#define tam 100

int main(){

    int n;
    scanf("%d", &n);

    //Leitura
    HT *ht = cria_ht(tam);
    leitura_cadastro(ht, n);

    int n_senhas;
    scanf("%d", &n_senhas);

    //Buscas
    busca(ht, n_senhas);

    return 0;

}
