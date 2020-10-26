#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;

main ()
{
	//prototipo de cardapio
	
	int option,option2;
	map <int, string > pratos;
	pratos[101] = "Parmegiana de Frango";
	pratos[102] = "Parmegiana de Carne";
	pratos[103] = "Almondegas";
	pratos[104] = "Bisteca Suina";
	pratos[105] = "Bife Acebolado";
	pratos[106] = "Frango Grelhado";

	map <int, string > bebidas;
	bebidas[201] = "Suco de Limao";
	bebidas[202] = "Suco de Morango";
	bebidas[206] = "Refrigerante de Uva";
	bebidas[204] = "Refrigerante de Laranja";
	bebidas[205] = "Refrigerante de Guarana";
	bebidas[203] = "Suco de Laranja";
	
	map <int, string > sobremesa;
	sobremesa[301] = "Bolo de Chocolate";
	sobremesa[302] = "Bolo de Coco";
	sobremesa[303] = "Sorvete de Flocos";
	sobremesa[304] = "Sorvete de baunilha";
	sobremesa[305] = "Sorvete de Chocolate";
	sobremesa[306] = "Pudim de Leite";

	while(1)
	{
	system("cls");
	printf("---------------------------- CARDAPIO --------------------------\n\n");
	printf("Escolha uma opcao\n");
	printf("1- Pratos\n");
	printf("2- Bebidas\n");
	printf("3- Sobremesas\n");
	scanf("%d",&option);
	system("cls");
	
	switch(option)
	{
		case 1:
			printf("---------------------------- CARDAPIO --------------------------\n\n");
			printf("Opcoes Disponiveis\n");
			for(int i=100*option +1;i<=100*option + pratos.size() ;i++)
			{
				cout <<i<<"  "<<pratos[i]<<endl;
			}
			break;
		case 2:
			printf("---------------------------- CARDAPIO --------------------------\n\n");
			printf("Opcoes Disponiveis\n");
			for(int i=100*option +1;i<=100*option + bebidas.size() ;i++)
			{
				cout <<i<<"  "<<bebidas[i]<<endl;
			}
			break;
		case 3:
			printf("---------------------------- CARDAPIO --------------------------\n\n");
			printf("Opcoes Disponiveis\n");
			for(int i=100*option +1;i<=100*option + sobremesa.size() ;i++)
			{
				cout <<i<<"  "<<sobremesa[i]<<endl;
			}
			break;	
		default:
			printf("Comando Invalido\n");
			option=0;
			system("pause");
			break;	
	}
	if(option!=0)
	{
		printf("\n\nSelecione um Item\n");
		scanf("%d",&option2);
		switch(option)
		{
			case 1:
				if(pratos.find(option2)==pratos.end())
				printf("Nao Encontrado\n");
				else
				cout <<"Voce escolheu "<<pratos[option2]<<endl;
				break;
			case 2:
				if(bebidas.find(option2)==bebidas.end())
				printf("Nao Encontrado\n");
				else
				cout <<"Voce escolheu "<<bebidas[option2]<<endl;
				break;		
			case 3:
				if(sobremesa.find(option2)==sobremesa.end())
				printf("Nao Encontrado\n");
				else
				cout <<"Voce escolheu "<<sobremesa[option2]<<endl;
				break;		
		}
		
		system("pause");
	}
	}
}
