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

NodoFilas *new_node_filas();

// Funcion para crear nodos de la lista de columnas

NodoColumnas *new_node_columnas(int v);

NodoPrincipal *new_nodo_principal(int m, int n);

NodoColumnas *add_node_columna(NodoColumnas *list, NodoColumnas *newp);

NodoFilas *add_node_fila(NodoFilas *list, NodoFilas *newp);

NodoPrincipal *crear_matriz();

// Buscar los elementos de la matriz

int Search(NodoColumnas *Column, int pos);

// Mostrar los elementos de la matriz

void print_matrix(NodoPrincipal *MainNode);

// Obtener un elemento

int get_item(int pos_column, int pos_row, NodoPrincipal *list);

// Asignar elemento

void Assign(int PosColumn, int PosRow, int data, NodoPrincipal *list);

// Producto por escalar

NodoPrincipal *mporescalar(NodoPrincipal *listp, int escalar);
// Suma de listas
NodoPrincipal *sumar(NodoPrincipal *m1, NodoPrincipal *m2);