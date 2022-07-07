#include "lib.h"

/*UniaoBusca* ub_cria(int n){
	int i;
	UniaoBusca* ub = (UniaoBusca*) malloc(sizeof(UniaoBusca));
	ub->n = n;
	ub->v = (int *) malloc(ub->n* sizeof(int));	
	
	for (i = 0; i < ub->n; ++i)
		ub->v[i] = -1; 

	return ub;

}*/

turma* cria_turma(int n){
	int i;
	turma* sala = (turma*) malloc (sizeof(turma));
	sala->tam_turma = n;
	sala->alunos = (aluno*) malloc (sala->tam_turma * sizeof(aluno));	
	sala->grupos_estudo = (gp_estudo*) malloc (5 * sizeof(gp_estudo));
	
	sala->grupos_estudo[0]->area = "Estrutura de Dados";
	sala->grupos_estudo[1]->area = "Fundamentos de Programacao";
	sala->grupos_estudo[2]->area = "Banco de Dados";
	sala->grupos_estudo[3]->area = "Calculo 1";
	sala->grupos_estudo[4]->area = "Algebra Linear";
	for(i = 0; i < 5; i++){
		sala->grupos_estudo[i]->participantes = NULL;
		sala->grupos_estudo[i].tam = 0;
	}
	
	for (i = 0; i < alu->tam_turma; i++){
		sala->alunos[i]->area_interesse = (int*) malloc (sizeof(int));
		sala->alunos[i]->area_interesse[0] = -1;
		sala->alunos[i]->nome = NULL;
		sala->alunos[i]->num_chamada = 0;	
	}

	return sala;
}

/*
void ub_libera(UniaoBusca* ub){
	free(ub->v);
	free(ub);
}*/

/*
int ub_busca(UniaoBusca* ub, int x){
	int r = x;
	
	while (ub->v[r] >= 0)
		r = ub->v[r];
	
	while (ub->v[x] >= 0) {
		int p = ub->v[x];
		ub->v[x] = r;
		x = p;
	}
	
	return r;
}*/

int busca(aluno*, int){
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

/*
int ub_uniao(UniaoBusca* ub, int x, int y){

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

void imprime(UniaoBusca* ub, int n){
	int i;
	for (i = 0; i < n; i++){
		printf("%d ", ub->v[i]);
	}
}*/

void menu(){
	int op, elementoX, elementoY, tamanho;
	turma* sala_aula;
	//--------- iniciando a estrutura --------------------//
    printf("\n -- SALA DE AULA -- \n");
    printf("Informe o numero de alunos da sala de aula: ");
    scanf(" %d", &tamanho);
    
    sala_aula = cria_turma(tamanho);
    
    for(i = 0; i < tamanho; i++){
    	int disc = 0;
    	sala_aula->alunos[i]->num_chamada = i + 1;
    	printf("Digite o nome do aluno %d: ", sala_aula->alunos[i]->num_chamada);
    	scanf(" %[^\n]", sala_aula->alunos[i]->nome);
    	
    	printf("\n -- ADICIONAR ALUNO A UM GRUPO DE ESTUDOS -- \n");
    	printf("\n\t1 - Estrutura de Dados\n\t2 - Fundamentos de Programacao\n\t3 - Banco de Dados\n\t4 - Calculo 1\n\t5 - Algebra Linear\n");

    	printf("Informe a disciplina: ");
    	scanf(" %d", &disc);
    			
    	ub_uniao(conjunto, elementoX, elementoY);
    	imprime(conjunto, tamanho);
    	
    	
	}
	
    do{    
    //--------------- Exibir menu ---------------------//
        system("cls");
        puts("\n\t\t\t\tSALA DE AULA\n");
        puts("\t\n\t1 - Adicionar um aluno a um grupo de estudos\n\t2 - Descobrir qual o grupo de estudos de um aluno\t\n\t3 - Listar todos os alunos\t\n\t4 - Lista dos grupos de estudos\t\n\t5 - Lista dos alunos por grupos de estudo\n\t0 - SAIR");
        printf("\nINFORME SUA OPCAO:\n");
        scanf("%d", &op);//Escolha da Opção
        
        switch(op)
        {
        //Opção de exibir lista
        	case 0:{
        		exit(0);
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
			
    		case 3:{
    			
				break;
			}
			
    		case 4:{
    			printf("\n\t1 - Estrutura de Dados\n\t2 - Fundamentos de Programacao\n\t3 - Banco de Dados\n\t4 - Calculo 1\n\t5 - Algebra Linear\n");
				break;
			}
			
    		case 5:{
    			
				break;
			}
    			
	    	default:
	    			puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");break;
	      
	    }
		getch();
	}while(op!=0);
}
