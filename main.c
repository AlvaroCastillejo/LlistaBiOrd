#include <stdio.h>
#include <conio.h>

void main() {
	LlistaBi l;
	Element element;
	int n;
	int i;

	l = LLISTABI_crea();

	printf("Quants numeros vols introduir: ");
	scanf("%d", &n);

	for(i=0;i<=n;i++){
		printf("\nIntrodueix un numero: ");
		scanf("%d", &element);
		fflushnou();
	    LLISTABI_insereixOrdenat(element, &l);  
	}

	printf("Aquesta es la llista ordenada: \n");

	LLISTABI_VesInici (&l); 
	for(i=0;i<=n;i++){
		element = LLISTABI_consulta(l);
		printf("%d\n", element);
		LLISTABI_avanca(&l);
	}

	printf("Aquesta es la llista ordenada a la inversa: \n");

	LLISTABI_VesFinal (&l); 
	for(i=0;i<=n;i++){
		element = LLISTABI_consulta(l);
		printf("%d\n", element);
		LLISTABI_retocedeix(&l); 
}