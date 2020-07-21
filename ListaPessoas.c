#include<stdio.h>
#include<string.h>

struct Pessoa {
    char nome[20];
    int idade;
};

typedef struct Pessoa Pes;

struct Lista {
    int ate;
    Pes qtd[20];
};

typedef struct Lista Lis;

void save(Lis *l) {
    FILE *novo = fopen("nome.txt", "w");
    int i = 0;
    while(i < l->ate) {
        fprintf(novo, "Nome: %s\nIdade: %d\n", l->qtd[i].nome, l->qtd[i].idade);
        i++;
    }
    fclose(novo);
}

int load(Lis *l) {
    FILE *novo = fopen("nome.txt", "r");
    if(novo == NULL) {
        printf("Arquivo não encontrado\n");
        return 0;
    }
    int i = 0;
    while (1) {
	    if(!feof(novo)) break;
        fscanf(novo, "Nome: %s\nIdade: %d\n", &l->qtd[i].nome, &l->qtd[i].idade);
        i++;
    }
    fclose(novo);
}

void empilha( Lis *l, Pes a ) {
    l->qtd[l->ate++] = a;
}


void desempilha( Lis *l ) {
    l->qtd[l->ate] = l->qtd[--(l->ate)];
}

void imprimePes(Pes a) {
    printf("Nome: %s\nIdade: %d\n", a.nome, a.idade);
}

void imprime( Lis *l ) {
    printf( "\n" );
    int i;
    for( i = l->ate - 1; i >= 0; i-- ) {
        printf( " %2d ) ", i );
        imprimePes( l->qtd[i] );
        printf( "\n" );
    }
    printf( "\n" );
}

void insere(Pes *a) {
    printf("Insira o nome\n");
    scanf("%20s", a->nome);
    printf("Insira a idade\n");
    scanf("%d", &a->idade);
}

void main() {
    Pes a;
    Lis l = { 0 };
    while(1) {
        insere(&a);
        empilha( &l, a);
        save(&l);
        load(&l);
        imprime(&l);
    }

}
