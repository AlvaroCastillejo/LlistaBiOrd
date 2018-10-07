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

}

void LLISTABI_avanca (LlistaBi *l) {

}

void LLISTABI_retocedeix(LlistaBi*l) {

}

int LLISTABI_buida (LlistaBi l) {

}

void LLISTABI_insereixDavant (LlistaBi *l, Element e) {

}

void LLISTABI_insereixOrdenat (Element e, LlistaBi *l) {

}