#ifndef  _LLISTA_H_ 
#define _LLISTA_H_ 

#include <stdio.h>
#include <stdlib.h>

#define ELEMENT_indefinit -1

typedef int Element;

typedef struct N { 
	Element e; 
	struct N *seg; 
	struct N *ant; 
} NodeBi; 

typedef struct { 
	NodeBi *pri; 
	NodeBi *ult; 
	NodeBi *pdi; 
} LlistaBi; 

LlistaBi LLISTABI_crea(); 
Element LLISTABI_consulta (LlistaBi l); 
void LLISTABI_esborra (LlistaBi *l); 
void LLISTABI_avanca (LlistaBi *l); 
void LLISTABI_retocedeix (LlistaBi *l); 
int LLISTABI_buida (LlistaBi l); 
void LLISTABI_VesInici (LlistaBi *l); 
void LLISTABI_VesFinal (LlistaBi *l); 
int LLISTABI_inici (LlistaBi l); 
int LLISTABI_final (LlistaBi l); 
void LLISTABI_destrueix (LlistaBi *l); 
void LLISTABI_insereixDavant (LlistaBi *l, Element e); 
void LLISTABI_insereixOrdenat(Element e, LlistaBi *l);


#endif