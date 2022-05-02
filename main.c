#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PILHA 100

typedef struct Stack_t {
	int n;
 	char vet[MAX_PILHA];
} Stack;

Stack *criar_pilha(){
	Stack *sRet = (Stack *)malloc( sizeof( Stack ) );
	sRet->n = 0; // pilha zerada
	
	return sRet;
}

void inserir_na_pilha( Stack* p, char c )
{
	if (p->n == MAX_PILHA) { /* capacidade esgotada */
		printf("A linha nao pode possuir mais de 100 caracteres.\n");
		exit(1); /* aborta programa */
	}
	
	/* insere elemento na próxima posição livre */
	p->vet[ p->n ] = c;
	p->n++;
}

int pilha_vazia (Stack* p)
{
	return ( p->n == 0 );
}

char retirar_da_pilha( Stack* p )
{
	char c;
	
	if ( pilha_vazia( p ) ) {
		printf("Pilha vazia.\n");
		exit(1); /* aborta programa */
	}
	
	/* retira elemento do topo */
	c = p->vet[p->n-1];
	p->n--;
	
	return c;
}

void mostra_pilha(Stack* p) {
	int i;
	char c;
	
	for ( i = 0; i < p->n; i++ ) {
		c = p->vet[i];
		printf("%c", c);
	}
}

void libera_pilha( Stack* p)
{
	free( p );
}

void line_processing( Stack* p, char* line )
{
	int iTam = 0;
	int i;
	char c;
	
	if ( ( p == NULL ) || ( line == NULL ) ) {
		printf("Parametros invalidos ...\n\n");
		return;
	}
	
	iTam = strlen(line);
	
	for( i = 0; i < iTam; i++ ) {
		c = line[i];
		
		if (c != '#' ) {
			inserir_na_pilha(p,c);
		} else {
			retirar_da_pilha( p );
		}
	}
	
	mostra_pilha(p);
}

int main(int argc, char* argv[]) {

    Stack *PILHA = NULL;
    char vet[100];

    scanf("%[^\n]", vet);
	
    PILHA = criar_pilha();
	line_processing( PILHA, vet);

	
	//stt#afg##csnM###k
	libera_pilha(PILHA);

	return 0;
    
}
