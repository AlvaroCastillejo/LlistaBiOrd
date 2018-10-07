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
}