#include <iostream>
#include <stdlib.h>

typedef struct no
{
	int num;
	struct no *prox;
	struct no *ant;
}No;

void Clear(){
	system("cls");
}

void printlista(No *Lista)
{
	No *aux=Lista;
	if(aux==NULL)
	{
		printf("Lista vazia\n");
	}
	else while(aux!=NULL)
	{
		printf("%d \n",aux->num);
		aux=aux->prox;
	}
}

int ContarNo(No *aux,int cont)
{
	cont=0;
	while(aux!=NULL)
	{
		aux=aux->prox;
		cont++;
	}
	return cont;	
}

void printno(No *Lista)
{
	No *aux=Lista;
	
	if(aux==NULL)
	{
		printf("A Lista nao contem Nos\n");		
	}
	else 
	{
		int cont=ContarNo(aux,cont);
		printf("A Lista possui %d Nos\n",cont);		
	} 
	
}

void printlistainversa(No *Lista)
{	
	No *aux=Lista;
	if(aux==NULL)
	{
		printf("Lista vazia\n");
	}
	else
	{
		while(aux->prox!=NULL)
		aux=aux->prox;
		while(aux!=NULL)
		{	
			printf("%d \n",aux->num);
			aux=aux->ant;
		}
	}
	
}

No* inserirfinal(No *lista,int inf)
{
	No *novo = (No*) malloc(sizeof(No));
	novo->num=inf;
	novo->prox=NULL;
	No *aux=lista;
	if (lista==NULL)
	{
		novo->ant=NULL;
		lista=novo;		
	}
	else
	{
	while(aux->prox!=NULL)
	aux=aux->prox;
		
	aux->prox=novo;
	novo->ant=aux;		
	}
		
	return lista;
}

No* inseririnicio(No *Lista,int inf)
{
	No *novo = (No*) malloc(sizeof(No));
	novo->num=inf;
	novo->prox=Lista;
	novo->ant=NULL;
	if (Lista!=NULL)
		Lista->ant=novo;

	return novo;	
}

No* inserirmeio(No *Lista,int inf,int position)
{	No *aux=Lista;
	int cont=ContarNo(aux,cont);
	if (position==1)
	Lista=inseririnicio(Lista,inf);
	else if (position==cont+1)
		Lista=inserirfinal(Lista,inf);
		else if (position<1 || position>cont+1)
			printf("Nao e possivel inserir um elemento na posicao %d\n",position);
			else
			{	
				No *novo= (No*) malloc(sizeof(No));
				novo->num=inf;
				int contaux=1;
				while (contaux!=position-1)
				{
				aux=aux->prox;
				contaux++;
				}
				No *aux2=aux->prox;
				aux->prox=novo;
				novo->prox=aux2;
				novo->ant=aux;
				aux2->ant=novo;
			}
	return Lista;		
}

No* RemoverNo(No *Lista,int position)
{
	No *aux=Lista;
	int cont=ContarNo(aux,cont);
	
	if(Lista==NULL)
		printf("A Lista Ja Esta Vazia\n");	
	else if (position==1)
	{
		Lista=Lista->prox;
		if (cont>1)
		Lista->ant=NULL;
		free(aux);	
	}
	else if (cont==position)
		{
			int contaux=1;
			while (contaux!=position-1)
			{
				aux=aux->prox;
				contaux++;
			}
			No *aux2=aux->prox;
			aux->prox=NULL;
			free(aux2);
		}	
	
		else if (position>cont || position<=0)
			{
				printf("O No de posicao %d nao existe\n",position);
			}
			else if (position<cont)
			{
				int contaux=1;
				while (contaux!=position-1)
				{
					aux=aux->prox;
					contaux++;
				}
				No *aux2=aux->prox;
				No *aux3=aux2->prox;
				aux->prox=aux3;
				aux3->ant=aux;
				free(aux2);
			}
	return Lista;
}
	
No* RemoverValor(No *Lista,int Valor)
{
	No *aux=Lista;
	int pv=1;
	int cont=ContarNo(aux,cont);

	while(aux!=NULL)
	{
		if(aux->num==Valor)
		break;
		else
		{
			aux=aux->prox;
			pv++;
		}		
	}
	if(pv>cont)
	printf("O elemento de valor: %d nao foi encontrado\n",Valor);
	else
	Lista=RemoverNo(Lista,pv);
	
	return Lista;
}

void Menu()
{
	printf("                   Menu\n");
	printf("------------------------------------------------\n");
	
	printf("1-Imprimir lista                   | ");
	printf("4-Inserir valor no inicio          | ");
	printf("7-Remover No por posicao\n");
	
	printf("2-Imprimir lista na ordem inversa  | ");
	printf("5-Inserir valor no fim             | ");
	printf("8-Remover No por valor\n");
	
	printf("3-Imprimir quantidade de Nos       | ");
	printf("6-Inserir valor por posicao        | ");
	printf("0-Encerrar\n");
}
int main()
{
	No *Lista=NULL;
	int option,con=1,num,pos;
	
	while (con==1)
	{
		Menu();
		printf("\nEscolha uma opcao\n");
		scanf("%i",&option);
		
		switch(option)
		{
			case 0:{
				con=0;
				break;
			}
			case 1:{
				Clear();
				printf("Lista:\n");
				printlista(Lista);
				break;
			}
			case 2:{
				Clear();
				printf("Lista:\n");
				printlistainversa(Lista);
				break;
			}
			case 3:{
				Clear();
				printno(Lista);
				break;
			}
			case 4:{
				printf("Digite o valor a ser inserido");
				scanf("%i",&num);
				Lista=inseririnicio(Lista,num);
				Clear();
				break;
			}
			case 5:{
				printf("Digite o valor a ser inserido");
				scanf("%i",&num);
				Lista=inserirfinal(Lista,num);
				Clear();
				break;
			}
			case 6:{
				printf("Digite o valor a ser inserido\n");
				scanf("%i",&num);
				printf("Digite a posicao do valor a ser inserido");
				scanf("%i",&pos);
				Clear();
				Lista=inserirmeio(Lista,num,pos);
				break;
			}
			case 7:{
				printf("Digite a posicao do No a ser removido");
				scanf("%i",&pos);
				Clear();
				Lista=RemoverNo(Lista,pos);
				break;
			}
			case 8:{
				printf("Digite o valor a ser removido");
				scanf("%i",&num);
				Clear();
				Lista=RemoverValor(Lista,num);
				break;
			}
		}
	}	
}
