#include "lib.h"

UniaoBusca* ub_cria (int n){

	int i;
	UniaoBusca* ub = ( UniaoBusca*) malloc(sizeof ( UniaoBusca));
	ub->n = n;
	ub->v = (int *) malloc(ub->n* sizeof (int ));	
	
	for (i=0; i<ub->n; ++i)
		ub->v[i] = -1; 

	return ub;

}

void ub_libera ( UniaoBusca* ub){
	free(ub->v);
	free(ub);
}

int ub_busca ( UniaoBusca* ub, int x){
	
	int r = x;
	
	while (ub->v[r] >= 0)
		r = ub->v[r];
	
	while (ub->v[x] >= 0) {
		int p = ub->v[x];
		ub->v[x] = r;
		x = p;
	}
	
	return r;
}

int ub_uniao ( UniaoBusca* ub, int x, int y){

	x = ub_busca(ub,x);
	y = ub_busca(ub,y);
	if (x == y) 
		return x;
	

	
	if (ub->v[x] <= ub->v[y]) {
		ub->v[x] += ub->v[y]; 
		ub->v[y] = x; 
		return x;
	}
	
	else {
		ub->v[y] += ub->v[x]; 
		ub->v[x] = y; 
		return y;
	}

}

void imprime (UniaoBusca* ub, int n){
	int i;
	for (i=0; i<n;i++){
		printf("%d ", ub->v[i]);
	}
}

void menu(){
	int op, elementoX, elementoY, tamanho;
	UniaoBusca* conjunto;
	//--------- iniciando a estrutura --------------------//
    printf("\n -- UNIAO E BUSCA -- \n");
    printf("Informe o numero de elementos do conjunto: ");
    scanf("%d", &tamanho);
    
    conjunto = ub_cria(tamanho);
    do{    
    //--------------- Exibir menu ---------------------//
        system("cls");
        puts("\n\t\t\t\tUNIAO E BUSCA\n");
        puts("\t  \n \t1- Uniao  \n \t2 - Busca \n\t0  - SAIR");
        printf("\nINFORME SUA OPCAO:\n");
        scanf("%d", &op);//Escolha da Opção
        
        switch(op)
        {
        //Opção de exibir lista
    		case 1:{
    			printf("\n -- UNIAO -- \n");
    			printf("Informe um elemento: ");
    			scanf("%d", &elementoX);
    			printf("Informe um elemento: ");
    			scanf("%d", &elementoY);
    			
    			ub_uniao(conjunto, elementoX, elementoY);
    			imprime(conjunto, tamanho);
				break;
			}
    		
    		case 2:{
    			printf("\n -- Representante de particao -- \n");
    			printf("Informe um elemento: ");
    			scanf("%d", &elementoX);
    			
    			printf("\n %d eh o representante da particao de %d\n", ub_busca(conjunto, elementoX), elementoX);
    			imprime(conjunto, tamanho);
    			
				break;
			}
    			
    			
	    	default:
	    			puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");break;
	      
	        }
		getch();
	    }while(op!=0);
}
