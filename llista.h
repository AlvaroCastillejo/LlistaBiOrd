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

#endif