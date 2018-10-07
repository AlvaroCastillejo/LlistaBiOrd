#include "llista.h"

/****************************************
*@Finalitat: crea una llista del no res i afegeix un element fantasma
*@Parametres: -
*@Retorn: l
****************************************/
LlistaBi LLISTABI_crea () {										
	LlistaBi l; 

    l.pri = (NodeBi*) malloc (sizeof(NodeBi));  

    if (l.pri == NULL) { 
        //Error 
    } else { 
        l.ult=(NodeBi*)malloc(sizeof(NodeBi));     
        if (l.ult==NULL) {       
            free(l.pri);        
            //Error 
        } else { 
        	l.pri->seg = l.ult;
			l.ult->ant = l.pri;
		    l.ult->seg = NULL;
		    l.pri->ant = NULL;
		    l.pdi = l.ult;
        }
    }   
    return l;     
}

/****************************************
*@Finalitat: Consulta la casella del PDI.
*@Parametres: "LlistaBi l" La llista d'on consultar.
*@Retorn: Element
****************************************/
Element LLISTABI_consulta (LlistaBi l) {
    Element e=ELEMENT_indefinit;
    if (l.pri->seg==NULL && l.ult->ant==NULL) {
        //Error llista buida
    } else {
        e=l.pdi->e;
    }
    return e;
}

/****************************************
*@Finalitat: Porta el PDI al inici de la llista, es a dir, a l'element d'acontinuacio del fantasma
*@Parametres: "LlistaBi *l" llista sobre la que operar.
*@Retorn: void
****************************************/
void LLISTABI_VesInici (LlistaBi *l) {
    l->pdi=l->pri->seg;
}

/****************************************
*@Finalitat: Porta el PDI al final de la llista
*@Parametres: "LlistaBi *l" llista sobre la que operar.
*@Retorn: void
****************************************/
void LLISTABI_VesFinal (LlistaBi *l) {
    l->pdi=l->ult->ant;
}

/****************************************
*@Finalitat: Comprova si el PDI es al principi.
*@Parametres: "LlistaBi l" la llista on comprovar.
*@Retorn: int
****************************************/
int LLISTABI_inici(LlistaBi l) {
    return l.pdi==l.pri;
}

/****************************************
*@Finalitat: Comprova si el PDI es al final.
*@Parametres: "LlistaBi l" la llista on comprovar.
*@Retorn: int
****************************************/
int LLISTABI_final(LlistaBi l) {
    return l.pdi==l.ult;
}

/****************************************
*@Finalitat: elimina tots els elements de la llista alliberant la memoria dinamica que ocupen.
*@Parametres: "LlistaBi *l" llista a eliminar 
*@Retorn: void 
****************************************/
void LLISTABI_destrueixl(LlistaBi *l) {
    NodeBi *aux;
    aux=(NodeBi*)malloc(sizeof(NodeBi));
    if (aux==NULL) {
        //Error
    } else {
        while (l->pri!=NULL) {
            aux=l->pri;
            l->pri=aux->seg;
            free(aux);
        }
        l->ult=NULL;
        l->pdi=NULL;
    }
}

/****************************************
*@Finalitat: Esborra un element de la llista. Aquest element sera el PDI.
*@Parametres: "LlistaBi *l" llista d'on borrar. 	
*@Retorn: void
****************************************/
void LLISTABI_esborra(LlistaBi *l) {
    NodeBi *aux;
    if (l->pri->seg==NULL || l->ult->ant==NULL) {
        //Error
    } else {
        aux=l->pdi;
        l->pdi->ant->seg=l->pdi->seg;
        l->pdi->seg->ant=l->pdi->ant;
        l->pdi=l->pdi->seg;
        free(aux);
    }
}

/****************************************
*@Finalitat: avanca una posicio el PDI de la llista. 
*@Parametres: "LlistaBi *l" llista on avancar
*@Retorn: void 
****************************************/
void LLISTABI_avanca (LlistaBi *l) {
    if (l->pdi->seg==NULL) {
        //Error
    } else {
        l->pdi=l->pdi->seg;
    }
}

/****************************************
*@Finalitat: retrocedeix una posicio el PDI de la llista. 
*@Parametres: "LlistaBi *l" llista on avancar
*@Retorn: void 
****************************************/
void LLISTABI_retocedeix(LlistaBi*l) {
    if (l->pdi->ant==NULL) {
        //Error
    } else {
        l->pdi=l->pdi->ant;
    }
}

/****************************************
*@Finalitat: Comprova si la llista es buida, es a dir, que nomes conte l'element fantasma.
*@Parametres: "LlistaBi l" La llista a comprovar. 
*@Retorn: int que indica amb un 1 si esta buida
****************************************/
int LLISTABI_buida (LlistaBi l) {
    return l.pri->seg==l.ult;
}

/****************************************
*@Finalitat: insereix un nou element a la llista a l'esquerra d'el PDI.
*@Parametres: 	"LlistaBi *l" Llista on inserir. 
*				"Element e" Element a inserir a la llista. 
*@Retorn: void
****************************************/
void LLISTABI_insereixDavant (LlistaBi *l, Element e) {
	NodeBi *aux; 
	aux=(NodeBi*)malloc(sizeof(NodeBi)); 
	if (l->pdi->ant==NULL) { 
	 	//Error 
	} else { 
		if (aux==NULL) { 
			//Error 
		} else {	
		 	aux->e=e; 
		 	aux->seg=l->pdi; 
		 	aux->ant=l->pdi->ant; 
		 	aux->ant->seg=aux;
			l->pdi->ant=aux; 
		}
	}
}

/****************************************
*@Finalitat: insereix un nou element a la llista tot habent colocat el PDI on pertoca.
*@Parametres: 	"Element e" Element a inserir a la llista. 
*				"LlistaBi *l" Llista on inserir. 
*@Retorn: void
****************************************/
void LLISTABI_insereixOrdenat (Element e, LlistaBi *l) {
	NodeBi *aux; 
	aux=(NodeBi*)malloc(sizeof(NodeBi)); 
	int trobat = 0;

	if (aux==NULL) { 
		 //Error 
	} else { 
		LLISTABI_VesInici(&*l);
		while(!trobat && !LLISTABI_final(*l)){
			if(e < LLISTABI_consulta(*l)){
				LLISTABI_avanca(&*l);
				trobat = 0;
			} else {
				LLISTABI_avanca (&*l);
				LLISTABI_insereixDavant(&*l, e);
				trobat = 1;
			}
		} 
	}
}