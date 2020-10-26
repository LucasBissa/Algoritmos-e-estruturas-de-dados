#include <iostream>
#include <stdlib.h>
#include <math.h>

main()
{
	int INICIAL, MEIO, M, FINAL, I, J, AUX, NUM;
	bool ENCONTRADO;
	int VET[6];
	// Preenchendo vetor
	printf("Fazendo o preenchimento do vetor\n\n");
	for(I=0; I<=5; I++)
	{
		printf("Informe o valor da %ia posicao do vetor:", I+1);
		scanf("%i", &VET[I]);
	}
	
	//Ordenando o vetor pelo método seleção.
	for (I=5; I>=1; I--)
	{
		M=0;
		for(J=1; J<=I; J++)
			if (VET[J]>VET[M])
				M=J;
		AUX=VET[I];
		VET[I]=VET[M];
		VET[M]=AUX;
	}
	
	//Exibindo o vetor ordenado.
	printf("\n\nVetor Ordenado\n");
	for (I=0; I<=5; I++)
		printf("VET[%i] = %i\n", I, VET[I]);
		
	
	
	while(1)
	{
		printf("\nInforme o valor a pesquisar:");
		scanf("%i", &NUM);
		INICIAL=0;
		FINAL=5;
		MEIO=(FINAL+INICIAL)/2;
		
		while(1)
		{
		if(VET[MEIO]==NUM)
		{
			printf("Valor %i localizado na posicao %i do vetor\n",NUM,MEIO);
			break;
		}
		if(INICIAL==FINAL)
		{
			printf("Valor %i nao encontrado no vetor\n",NUM);
			break;	
		}	
		else if(NUM>VET[MEIO])
			{
				INICIAL=MEIO+1;
				MEIO=(FINAL+INICIAL)/2;
			}
			else
				{
					FINAL=MEIO;
					MEIO=(FINAL+INICIAL)/2;
				}	
		}
	}
	

	
}
