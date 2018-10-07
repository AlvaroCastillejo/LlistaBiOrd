/******************************************
*
*No he conseguir fer funcionar la funcio  
*"Insereix ordenat", per aixo el programa 
*et mostra que tots els elements son "0"
*
******************************************/


#include <stdio.h>
#include <conio.h>
#include "llista.h"

void main() {
	LlistaBi l;					//La llista es diu "l".
	Element element;			//Els elements a inserir es diuen "element".
	int n;						//Nombre d'elements a introduir.
	int i;						//Variable auxiliar pels bucles.

	l = LLISTABI_crea();

	printf("Quants numeros vols introduir: ");
	scanf("%d", &n);
	printf("\n");
	//Bucle que demana els nombres.
	for(i=0;i<n;i++){
		printf("Introdueix un numero: ");
		scanf("%d", &element);
		fflushnou();
	    LLISTABI_insereixOrdenat(element, &l);  
	}

	printf("\nAquesta es la llista ordenada: \n");

	//Bucle que mostra la llista.
	LLISTABI_VesInici (&l); 
	for(i=0;i<n;i++){
		element = LLISTABI_consulta(l);
		printf("%d\n", element);
		LLISTABI_avanca(&l);
	}

	printf("\nAquesta es la llista ordenada a la inversa: \n");

	//Bucle que mostra la llista del reves.
	LLISTABI_VesFinal (&l); 
	for(i=0;i<n;i++){
		element = LLISTABI_consulta(l);
		printf("%d\n", element);
		LLISTABI_retocedeix(&l);
	} 

	printf("Adeu y gracies!");
}