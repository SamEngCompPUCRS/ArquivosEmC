#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
	char nome[20];
	int p1;
	int p2;
	int ps;
	float g1;
	float media;
} Aluno;

typedef struct{
	int pos;
	Aluno aluno[10];
} Turma;

void media(Turma *t){
	int i ;
	for(i = 0; i < 10; i++) {
		t->aluno[i].media = (float)(t->aluno[i].p1 + t->aluno[i].p2);
		t->aluno[i].ps = 21 - t->aluno[i].media;
		t->aluno[i].g1 = (float)(t->aluno[i].p1 + t->aluno[i].p2 + t->aluno[i].ps)/3;
	}
}

void insere(Turma *t) {
	int i;
	for(i = 0; i < 10; i++) {
		srand(time(NULL));
		sprintf(t->aluno[i].nome,"aluno%d", i);
		t->aluno[i].p1 = rand() % 10+1;
		t->aluno[i].p2 = rand() % 10+1;
	}
	media(t);
}

void imprime(Turma *t) {
	int i ;
	for(i = 0; i < 10; i++) {
		printf("%s: ", t->aluno[i].nome);
		printf("P1 %d ", t->aluno[i].p1);
		printf("P2 %d ", t->aluno[i].p2);
		printf("PS %d ", t->aluno[i].ps);
		printf("G1 %f \n", t->aluno[i].g1);
	}
}

void save(Turma *t){
	FILE *arq = fopen("new.txt","w");	
	int i;
	for ( i = 0; i < 10; i++){		
		fprintf(arq,"%s ", t->aluno[i].nome);
		fprintf(arq,"%d ", t->aluno[i].p1);
		fprintf(arq,"%d ", t->aluno[i].p2);
		fprintf(arq,"%d ", t->aluno[i].ps);
		fprintf(arq,"%f ", t->aluno[i].g1);
		fprintf(arq,"\n");
	}
	fclose(arq);
}

void load(Turma *t){
	FILE *arq = fopen("new.txt","r");	
	int i;
	for ( i = 0; i < 10; i++){		
		fscanf(arq,"%s", (t->aluno[i].nome));
		fscanf(arq,"%d", &(t->aluno[i].p1));
		fscanf(arq,"%d", &(t->aluno[i].p2));
		fscanf(arq,"%d", &(t->aluno[i].ps));
		fscanf(arq,"%f ", &(t->aluno[i].g1));
		fscanf(arq,"\n");
	}
	fclose(arq);
}


void main() {
	Turma t = {0};
	char op;
	while(1) {
		printf("Selecione a operacao:\n");
		printf("i -> insere\n");
		printf("p -> imprime\n");
		printf("s -> save\n");
		printf("l -> load\n");
		if(op == 'i') insere(&t);
		if(op == 'p') imprime(&t);
		if(op == 's') save(&t);
		if(op == 'l') load(&t);
		scanf(" %c", &op);
		system("clear");		
	}
}