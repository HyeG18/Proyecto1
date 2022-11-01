#include <stdio.h>
#include <stdlib.h>

// Estructura de nodos en columnas

typedef struct NodoColumnas
{
    int dato;
    int columna;
    struct NodoColumnas *next;

} NodoColumnas;

// Estructura de nodo en filas

typedef struct NodoFilas
{
    int fila;
    struct NodoFilas *next_abajo;
    struct NodoColumnas *next_derecha;

} NodoFilas;

// Nodo Principal

typedef struct nprincipal
{
    int Filas;
    int Columnas;
    struct NodoFilas *matriz;

} NodoPrincipal;

// Variables Globales
int PosColumna, PosFila, SizeColumna, SizeFila;

// Funcion para crear nodos de la lista de filas

NodoFilas *new_node_filas()
{
    PosFila++;
    NodoFilas *newp;
    if ((newp = (NodoFilas *)malloc(sizeof(NodoFilas))) == NULL)
    {
        fprintf(stderr, "error en el malloc\n");
        exit(1);
    }
    newp->fila = PosFila;
    newp->next_abajo = NULL;
    newp->next_derecha = NULL;

    return newp;
}

// Funcion para crear nodos de la lista de columnas

NodoColumnas *new_node_columnas(int v)
{
    NodoColumnas *newp;

    if ((newp = (NodoColumnas *)malloc(sizeof(NodoColumnas))) == NULL)
    {
        fprintf(stderr, "error en el malloc\n");
        exit(1);
    }

    newp->columna = PosColumna;
    newp->dato = v;
    newp->next = NULL;

    return newp;
}

NodoPrincipal *new_nodo_principal(int m, int n)
{
    NodoPrincipal *newp;
    if ((newp = (NodoPrincipal *)malloc(sizeof(NodoPrincipal))) == NULL)
    {
        fprintf(stderr, "error en malloc\n");
        exit(1);
    }

    newp->matriz = NULL;
    newp->Filas = m;
    newp->Columnas = n;

    return newp;
}

NodoColumnas *add_node_columna(NodoColumnas *list, NodoColumnas *newp)
{
    NodoColumnas *p;

    if (list == NULL)
        return newp;
    if (newp == NULL)
        return list;
    for (p = list; p->next != NULL; p = p->next)
        ;

    p->next = newp;
    return list;
}

NodoFilas *add_node_fila(NodoFilas *list, NodoFilas *newp)
{
    NodoFilas *p;

    if (list == NULL)
        return newp;
    for (p = list; p->next_abajo != NULL; p = p->next_abajo)
        ;

    p->next_abajo = newp;
    return list;
}

NodoPrincipal *crear_matriz()
{
    NodoPrincipal *Matriz = NULL;
    NodoFilas *newfila = NULL, *auxfila;
    NodoColumnas *newcolumna = NULL;
    int x, y, valor;

    printf("Ingrese el numero de filas:\n");
    scanf("%i", &SizeFila);
    printf("Ingrese el numero de columnas:\n");
    scanf("%i", &SizeColumna);

    Matriz = new_nodo_principal(SizeFila, SizeColumna);

    for (x = 1; x <= SizeFila; x++)
    {
        newfila = add_node_fila(newfila, new_node_filas());
    }

    auxfila = newfila;

    for (x = 1; x <= SizeFila; x++)
    {
        for (y = 1; y <= SizeColumna; y++)
        {
            printf("Ingrese el valor en la posicion(%i,%i):\n", x, y);
            scanf("%i", &valor);
            PosColumna++;
            if (valor != 0)
                newcolumna = add_node_columna(newcolumna, new_node_columnas(valor));
        }
        newfila->next_derecha = newcolumna;
        newfila = newfila->next_abajo;
        newcolumna = NULL;
        PosColumna = 0;
    }

    Matriz->matriz = auxfila;
    return Matriz;
}

//Buscar los elementos de la matriz

int Search(NodoColumnas *Column, int pos)
{
    while (Column)
    {
        if (Column->columna == pos)
        {
            return Column->dato;
        }
        Column = Column->next;
        
    }
    return 0;
}

//Mostrar los elementos de la matriz

void print_matrix(NodoPrincipal *MainNode)
{
    NodoFilas *Matrix;
    NodoColumnas *AuxColumn;
    int x = 0;
    
    if (MainNode == NULL)
    {
        printf("La matriz no existe");
        return;
    }
    Matrix = MainNode -> matriz;

    while (Matrix)
    {
        AuxColumn =  Matrix -> next_derecha;
        Matrix = Matrix -> next_abajo;
        for (int i = 1; i <= MainNode -> Columnas; i++)
        {
            x = Search(AuxColumn, i);
            printf("%i ", x);
        }
        printf("\n");
    }
    
}

//Obtener un elemento 

int get_item(int pos_column, int pos_row, NodoPrincipal *list)
{
    NodoFilas *aux_row;
    aux_row =list->matriz;
    for (int i = 1; i < pos_row; i++, aux_row = aux_row->next_abajo);
    return Search(aux_row->next_derecha, pos_column);
}

//Asignar elemento

void Assign(int PosColumn, int PosRow, int data, NodoPrincipal *list)
{
    NodoFilas *aux_row;
    NodoColumnas *column, *aux_col;
    PosColumna = PosColumn;
    aux_row = list->matriz;
    for (int i = 1; i < PosRow; i++, aux_row = aux_row ->next_abajo);
    column = aux_row->next_derecha;
    aux_col= column;
    while (column)
    {
        if (column->columna == PosColumn)
        {
            column->dato = data;
            return;
        }
        column = column->next;
    }
    aux_col = add_node_columna(aux_col,new_node_columnas(data));
    return;
} 
//Producto por escalar
//Suma de listas
//Producto de listas 
//Trasponer listas 

int main()
{
    int PosicionY, PosicionX, datico, item;
    NodoPrincipal *mtrx;
    

    mtrx = crear_matriz();
    print_matrix(mtrx);

    printf("Ingrese la posicion de la columna:\n");
    scanf("%i ", &PosicionY);
    printf("Ingrese la posicion de la fila:\n");
    scanf("%i ", &PosicionX);
    printf("Ingrese el dato a asignar:\n");
    scanf("%i \n", &datico);

    Assign(PosicionY,PosicionX,datico,mtrx);
    print_matrix(mtrx);


    printf("Ingrese la posicion de la columna:\n");
    scanf("%i ", &PosicionY);
    printf("Ingrese la posicion de la fila:\n");
    scanf("%i ", &PosicionX);

    item = get_item(PosicionY, PosicionX, mtrx);
    printf("%i \n", item);

}