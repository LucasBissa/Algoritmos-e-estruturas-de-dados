#include<iostream>
#include<stdlib.h>

# define N 5

struct fila
{
	int ini;
	int n;
	int vet[N];
	
}typedef Fila;

Fila* inicia_fila()/*Função para iniciar fila*/
{
	Fila *f = (Fila*) malloc(sizeof(Fila));
	f -> ini = 0; 
	f -> n = 0;
	return f;
}


void entrar_fila(Fila* f, int numero)/*Função para inserir elemento na fila*/
{
	if (f -> n == N)
	{
		printf("\nSenha nao inserida,a fila esta cheia!\n");	
	}
	else
	{
		f -> vet[(f -> ini + f -> n) % N] = numero;
		f -> n++; 	
	}	

}


int fila_vazia(Fila* f)/*Função verifica se fila esta vazia*/
{
	return (f -> n == 0);
}


void atende_fila(Fila* f)/*Função para remover elemento da fila*/
{
	int atendido;
	int fim;
	
	if (fila_vazia(f))
	{
		printf("\nFila vazia!\n");	
	}
	
	else
	{
		atendido = f->vet[f->ini];
		f -> ini =(f -> ini + 1) % N;	
		f -> n --;
		printf("\nA senha %i foi atendida.\n", atendido);
	}		
	
}


main()
{
	Fila *minha_fila;
	minha_fila = inicia_fila();
	int op, valor, atendido, fim;
	
	printf("+----------------+\n");
	printf("| LOJA DO LUCAS | \n");
	printf("+----------------+\n");
	
	while(1)/*lopp infinito*/
	{
		
		printf("\n1 - Entrar na fila.\n");
		printf("2 - Realizar atendimento.\n");
		printf("3 - Mostrar ultimo da fila.\n");
		printf("4 - Sair.\n\n");
		
		scanf("%i", &op);
		
		switch (op)
		{
			case 1:
				{
					printf("Informe sua senha: ");
					scanf("%i", &valor);
					
					entrar_fila(minha_fila,valor);	
				}
				break;
		
			case 2:
				{
					atende_fila(minha_fila);	 	
				} 
				break;
			
			case 3:
				{
					if (fila_vazia(minha_fila))
						printf("\nFila vazia!\n");
						
						else{
								printf("Primeiro da fila = %i\n",minha_fila -> vet[minha_fila->ini]);
								printf("Ultimo da fila = %i\n",minha_fila -> vet[(minha_fila -> ini + minha_fila -> n-1) % N]);
							}
				}
				break;
			
			case 4: 
				{
					exit(1);
				}
				break;
				
			default: printf("\nOpcao invalida!\n");
		}		
	}
}



