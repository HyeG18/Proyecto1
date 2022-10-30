#include <stdio.h>
#include <stdlib.h>

//Estructura de nodos en columnas

typedef struct NodeJ
{
    int dato;
    int columna;
    struct NodeJ *next;
    
} NodoJ;

//Estructura de nodo en filas

typedef struct NodeI
{
    int fila;         
    struct NodeI *nexti;
    struct NodeJ *nextj; 
} NodoI;

//Nodo Principal

typedef struct nprincipal
{
    int sizerow;
    int sizecolumn;
    struct NodoI *matriz; 
    
}NodoP;

//Declaraciones Globales
int fila,columna,posi,posj;

//Funcion para crear nodos de la lista de filas

NodoI *add_nodei(NodoI *l,int f){
    NodoI *newp=l;

    newp =(NodoI*)malloc(sizeof(NodoI));
    newp->nexti = NULL;
    newp->nextj = NULL;

    return newp;
}

//Funcion para crear nodos de la lista en columnas

NodoJ *add_nodej(NodoJ *l, int colum, int v){
    NodoJ *newpj = l;

    newpj = (NodoJ*)malloc(sizeof(NodoJ));
    newpj->columna = colum;
    newpj->dato = v;
    newpj->next = NULL;

    return newpj;
}

//Funcion de enlace de nodos de columnas con estructura iterativa

NodoJ *enlace_nodej(NodoI *l, NodoJ *tj){
    
    while (l->nextj != NULL)
    {
        l->nextj = l->nextj; //Revicion de nextj
    }
    l->nextj = tj;
    
    return l->nextj;
}

/* add_end añade newp al final de la listp */ 
NodoJ *add_endj(NodoJ *listp, NodoJ *newp){
	NodoJ *p;

	if(listp==NULL)
 		return newp;
    if (listp == NULL)
        return listp;
	for(p=listp;p->next!=NULL;p=p->next);
	p->next = newp;
	
    return listp;
}

//Creacion de Matriz
NodoP create_m(){
    int vcol;

    printf("Ingrese la cantidad de filas:\n");
    scanf("%i", &fila);
    printf("Ingrese la cantidad de columnas:\n");
    scanf("%i", &columna);

    if (fila<=0 || columna<=0)
    {
        printf("El valor de las filas o columnas no puede ser menor a cero 0\n");
    }
    else
    {
        //Creacion de la lista Matriz principal

        NodoI *M = NULL;
        M = add_nodei(M,0);
        NodoI *mp = M; //Auxiliar para recorrer las filas de la matriz

        NodoJ *auxj=NULL;

        for (int x = 0; x < fila; x++)
        {
            for(int y = 0; y < columna; y++)
            {
                printf("Ingrese dato de la columna:\n");
                scanf("%d",vcol);
                if (vcol != 0)
                {
                    auxj= add_nodej(auxj,y,vcol); 
                    mp->nextj=add_endj(mp->nextj,auxj);
                }
                mp->nexti=add_nodei(mp,x+1);
                mp=mp->nexti;
            }
    }
    }
}
int main(){
    create_m();
}