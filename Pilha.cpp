#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Pilha {
	int topo; 
	int capa;
	int *pelem;
};

void criarpilha(struct Pilha *p, int c){
   p->topo = -1;
   p->capa = c;
   p->pelem = (int*) malloc (c * sizeof(int)); /*c * sizeof(int)) esta alocando c(Valor da capacidade) x a quantidade de bytes contiguos
   para criar o vetor*/ 
}

void desempilhar(struct Pilha *p)
{
	if(p->topo == -1)
	printf("pilha vazia");
	else
	{
	int remov_elem = p->pelem[p->topo]; 
	p->topo--; 
	printf("%d foi desempilhado", remov_elem);
	}
}

void empilhar (struct Pilha *p, int valor)
{
	p->topo++;
	p->pelem [p->topo] = valor; //O valor será alocado na posição [numero do topo] do vetor p->elem
}

int estacheia (struct Pilha *p)
{
	if (p->topo == p->capa - 1)
		return 1;
	else
		return 0;		
}

void listar(struct Pilha *p)
{
	if(p->topo == -1)
	printf("pilha vazia");
	else {
		for(int n=0;n<=p->topo;n++)
		printf("%d ",p->pelem[n]);
	}
}

int main()
{	
	struct Pilha minhapilha;
	int capacidade, op, valor;
		
	printf( "Informe a capacidade da pilha: " );
	scanf( "%d", &capacidade );

	criarpilha (&minhapilha, capacidade);
	
	while( 1 )
	{ /* loop infinito */
	
		printf("\n1- Empilhar (push)\n");
		printf("2- Desempilhar\n");
		printf("3- Listar Elementos\n");
		printf("4- sair\n");
		printf("\nopcao? ");
		scanf("%d", &op);
	
		switch (op)
		{
				
			case 1: //push
				if(estacheia(&minhapilha) == 1 )
					printf("\nPILHA CHEIA! \n");
				else{
						printf("\nDigite o valor? ");
						scanf("%d", &valor);
						
						empilhar (&minhapilha, valor);
					}
			break;
			
			case 2:
				desempilhar(&minhapilha);
				
			break;
			
			case 3:
				listar(&minhapilha);
			break;
					
			case 4: 
				exit(0);
					
			default: printf( "\nOPCAO INVALIDA! \n" );
		}
	}	
}
	
