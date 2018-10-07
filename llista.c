#include "llista.h"

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

Element LLISTABI_consulta (LlistaBi l) {
    Element e=ELEMENT_indefinit;
    if (l.pri->seg==NULL && l.ult->ant==NULL) {
        //Error llista buida
    } else {
        e=l.pdi->e;
    }
    return e;
}

void LLISTABI_VesInici (LlistaBi *l) {
    l->pdi=l->pri->seg;
}

void LLISTABI_VesFinal (LlistaBi *l) {
    l->pdi=l->ult->ant;
}

int LLISTABI_inici(LlistaBi l) {
    return l.pdi==l.pri;
}

int LLISTABI_final(LlistaBi l) {
    return l.pdi==l.ult;
}

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

void LLISTABI_avanca (LlistaBi *l) {
    if (l->pdi->seg==NULL) {
        //Error
    } else {
        l->pdi=l->pdi->seg;
    }
}

void LLISTABI_retocedeix(LlistaBi*l) {
    if (l->pdi->ant==NULL) {
        //Error
    } else {
        l->pdi=l->pdi->ant;
    }
}

int LLISTABI_buida (LlistaBi l) {
    return l.pri->seg==l.ult;
}

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
				LLISTABI_avanca (&l)
				LLISTABI_insereixDavant(&*l, e);
				trobat = 1;
			}
		} 
	}
}