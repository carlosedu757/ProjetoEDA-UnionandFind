#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

struct aluno{
	int num_chamada;
	char *nome;
};

struct turma{
	int tam_turma;
	int *grupos_estudo;
	aluno *alunos;
};

turma* cria_turma(int);
int busca(turma*, int);
int uniao(turma*, int, int);
void listar_porgrupo(turma*);
void listar_alunos(turma*);
void menu();

