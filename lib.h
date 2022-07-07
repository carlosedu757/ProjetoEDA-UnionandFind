#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
/*struct UniaoBusca{
	int n;
	int *v; 
};*/
//FAZER STRUCT DE ALUNOS E OUTRO DE SALA DE AULA???

struct aluno{
	int num_chamada;
	char *nome;
	int *area_interesse;
};

struct gp_estudo{
	int tam;
	char *area;
	aluno *participantes;
};

struct turma{
	int tam_turma;
	gp_estudo *grupos_estudo;
	aluno *alunos;
};

/*UniaoBusca* ub_cria(int n);*/
turma* cria_turma(int);
/*void insere_alunos(*turma, int, char*, int*);*/
/*void ub_libera(UniaoBusca* ub);*/
int busca(aluno*, int);/*
int ub_uniao(UniaoBusca* ub, int x, int y);
void imprime(UniaoBusca* ub, int n);*/
void menu();

