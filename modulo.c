#include "lib.h"

turma* cria_turma(int n){
	int i;
	turma* sala = (turma*) malloc (sizeof(turma));
	sala->tam_turma = n;
	sala->alunos = (aluno*) malloc (sala->tam_turma * sizeof(aluno));	
	sala->grupos_estudo = (int*) malloc ((sala->tam_turma + 5) * sizeof(int));
	
	for(i = 0; i < sala->tam_turma + 5; i++){
		sala->grupos_estudo[i] = -1;
	}
	for (i = 0; i < sala->tam_turma; i++){
		sala->alunos[i].nome = (char*) malloc (100 * sizeof(char));
		sala->alunos[i].nome = NULL;
		sala->alunos[i].num_chamada = 0;	
	}

	return sala;
}

int uniao(turma* sala, int gpest, int alu){
	
	gpest = busca(sala, gpest);
	alu = busca(sala, alu);
	if (gpest == alu) 
		return gpest;
	

	
	if (sala->grupos_estudo[gpest] <= sala->grupos_estudo[alu]) {
		sala->grupos_estudo[gpest] += sala->grupos_estudo[alu]; 
		sala->grupos_estudo[alu] = gpest; 
		return gpest;
	}
	
	else {
		sala->grupos_estudo[alu] += sala->grupos_estudo[gpest]; 
		sala->grupos_estudo[gpest] = alu; 
		return alu;
	}
}

int busca(turma* turma, int x){
	int r = x;
	
	while (turma->grupos_estudo[r] >= 0)
		r = turma->grupos_estudo[r];
	
	while (turma->grupos_estudo[x] >= 0) {
		int p = turma->grupos_estudo[x];
		turma->grupos_estudo[x] = r;
		x = p;
	}
	return r;
}

void listar_alunos(turma* sala){
	int i;
	for(i = 0; i < sala->tam_turma; i++){
		printf("Numero da chamada: %d\n", sala->alunos[i].num_chamada);
		switch(sala->grupos_estudo[i + 5]){
			case 0:{
				printf("Grupo de estudos: Estrutura de Dados\n\n");
				break;
			}
			case 1:{
				printf("Grupo de estudos: Fundamentos de Programacao\n\n");
				break;
			}
			case 2:{
				printf("Grupo de estudos: Banco de Dados\n\n");
				break;
			}
			case 3:{
				printf("Grupo de estudos: Calculo 1\n\n");
				break;
			}
			case 4:{
				printf("Grupo de estudos: Algebra Linear\n\n");
				break;
			}
		}
	}
}

void listar_porgrupo(turma* sala){
	int i, k;
	for(i = 0; i < 5; i++){
		printf("-----------------------------------------\n");
		if(i == 0){
			printf("Grupo de estudos: Estrutura de Dados\n\n");
			for(k = 0; k < sala->tam_turma; k++){
				if(sala->grupos_estudo[k + 5] == 0){
					printf("Numero da chamada: %d\n", sala->alunos[k].num_chamada);
				}
			}
			printf("\n");
		}
		if(i == 1){
			printf("Grupo de estudos: Fundamentos de Programacao\n\n");
			for(k = 0; k < sala->tam_turma; k++){
				if(sala->grupos_estudo[k + 5] == 1){
					printf("Numero da chamada: %d\n", sala->alunos[k].num_chamada);
				}
			}
			printf("\n");
		}
		if(i == 2){
			printf("Grupo de estudos: Banco de Dados\n\n");
			for(k = 0; k < sala->tam_turma; k++){
				if(sala->grupos_estudo[k + 5] == 2){
					printf("Numero da chamada: %d\n", sala->alunos[k].num_chamada);
				}
			}
			printf("\n");
		}
		if(i == 3){
			printf("Grupo de estudos: Calculo 1\n\n");
			for(k = 0; k < sala->tam_turma; k++){
				if(sala->grupos_estudo[k + 5] == 3){
					printf("Numero da chamada: %d\n", sala->alunos[k].num_chamada);
				}
			}
			printf("\n");
		}
		if(i == 4){
			printf("Grupo de estudos: Algebra Linear\n\n");
			for(k = 0; k < sala->tam_turma; k++){
				if(sala->grupos_estudo[k + 5] == 4){
					printf("Numero da chamada: %d\n", sala->alunos[k].num_chamada);
				}
			}
			printf("\n");
		}
		printf("-----------------------------------------\n");
	}
}

void menu(){
	int op, i, tamanho;
	turma* sala_aula;
	//--------- iniciando a estrutura --------------------//
    printf("\n -- SALA DE AULA -- \n");
    printf("Informe o numero de alunos da sala de aula: ");
    scanf(" %d", &tamanho);
    
    sala_aula = cria_turma(tamanho);
    
    for(i = 0; i < tamanho; i++){
    	system("cls");
    	int disc = 0;
    	sala_aula->alunos[i].num_chamada = i + 1;
    	printf("Digite o nome do aluno [%d]: ", sala_aula->alunos[i].num_chamada);
    	scanf(" %[^\n]", &sala_aula->alunos[i].nome);
    	char opc;
	    printf("\n -- ADICIONAR ALUNO A UM GRUPO DE ESTUDOS -- \n");
	    printf("\n\t1 - Estrutura de Dados\n\t2 - Fundamentos de Programacao\n\t3 - Banco de Dados\n\t4 - Calculo 1\n\t5 - Algebra Linear\n");
	
	    printf("Informe a disciplina: ");
	    scanf(" %d", &disc);
	    			
	    uniao(sala_aula, disc - 1, i + 5);
	}
	
    do{    
    //--------------- Exibir menu ---------------------//
        system("cls");
        puts("\n\t\t\t\tSALA DE AULA\n");
        puts("\t\n\t1 - Descobrir qual o grupo de estudos de um aluno\t\n\t2 - Listar todos os alunos\t\n\t3 - Lista dos grupos de estudos\t\n\t4 - Lista dos alunos por grupos de estudo\n\t0 - SAIR");
        printf("\nINFORME SUA OPCAO:\n");
        scanf("%d", &op);//Escolha da Opção
        
        switch(op)
        {
        //Opção de exibir lista
        	case 0:{
        		exit(0);
				break;
			}
    		
    		case 1:{
    			int alu;
    			printf("Informe o numero da chamada do aluno: ");
    			scanf("%d", &alu);
    			if(busca(sala_aula, alu + 4) == 0){
    				printf("Grupo de estudos: Estrutura de Dados");
				}
				if(busca(sala_aula, alu + 4) == 1){
    				printf("Grupo de estudos: Fundamentos de Programacao");
				}
				if(busca(sala_aula, alu + 4) == 2){
    				printf("Grupo de estudos: Banco de Dados");
				}
				if(busca(sala_aula, alu + 4) == 3){
    				printf("Grupo de estudos: Calculo 1");
				}
				if(busca(sala_aula, alu + 4) == 4){
    				printf("Grupo de estudos: Algebra Linear");
				}
    			
    			
				break;
			}
			
    		case 2:{
    			listar_alunos(sala_aula);
				break;
			}
			
    		case 3:{
    			printf("\n\t1 - Estrutura de Dados\n\t2 - Fundamentos de Programacao\n\t3 - Banco de Dados\n\t4 - Calculo 1\n\t5 - Algebra Linear\n");
				break;
			}
			
    		case 4:{
    			listar_porgrupo(sala_aula);
				break;
			}
    			
	    	default:
	    		puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");break;
	      
	    }
		getch();
	}while(op!=0);
}
