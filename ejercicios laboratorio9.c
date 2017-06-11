#include <stdio.h>
#include <stdlib.h>

/**************************************************
* PROGRAMA : laboratorio 09
* OBJETIVO : Insertar un arbol
* Fecha creacion : 24 / 05 / 2017
* ALUMNO: Wa
* ASIGNATURA : Estructura de Datos 
* SECCION : 651
* FECHA DE ULTIMA ACTUALIZACION : 24 / 05 / 2017
***************************************************/



/* Definiciones */

#define M 9   
#define N 9   

unsigned char A[N], B[N], *C;
unsigned char x, y;

/* Prototipos de funciones */
void Iniciar (unsigned char C[]);
unsigned char byte (unsigned char x);
unsigned char bit (unsigned char x);
unsigned char Pertenece (unsigned char x, unsigned char C[]);
void Incluir (unsigned char x, unsigned char C[]);
unsigned char *Or(unsigned char A[], unsigned char B[]);
unsigned char *And (unsigned char A[], unsigned char B[]);
unsigned char *Diferencia(unsigned char A[], unsigned char B[]);
void Escribir (unsigned char C[]);

void main() {
    // Iniciamos los conjuntos A y B
    Iniciar(A); Iniciar(B);
  
    // Agregamos algunos elementos al conjunto A
    
    Incluir(4, A);
    Incluir(5, A);
    Incluir(2, A);
    Incluir(8, A);
    Incluir(7, A);
    
    printf("A = "); Escribir(A);
    printf("A Binario = "); imprimirBinario(A);
 
	
    // Agregamos al conjunto B los multiplos de 20
    Incluir(0, B);
    Incluir(1, B);
    Incluir(3, B);
    Incluir(4, B);
    Incluir(5, B);
    
    printf("B = "); Escribir(B);
	printf("B Binario = "); imprimirBinario(B);

    // Hallamos la union de A y B en C
    C = Or(A, B);
    printf("funcion OR de A y B = "); Escribir(C);
	printf("funcion OR de A y B Binario = "); imprimirBinario(C);

    // Hallamos la interseccion de A y B en C
    C = And(A, B);
    printf("funcion AND de A y B = "); Escribir(C);
	printf("funcion AND de A y B Binario= "); imprimirBinario(C);
	
    // Hallamos la diferencia de A y B en C
    C = Diferencia(A, B);
    printf("(A-B) = "); Escribir(C);
    printf("(A-B) Binario= "); imprimirBinario(C);
    
    C = Diferencia(B, A);
    printf("(B-A) = "); Escribir(C);
    printf("(B-A) Binario= "); imprimirBinario(C);
    
	printf("(A-B)U(B-A) ="); Escribir(Or(Diferencia(A,B), And(B,A)));
	printf("(A-B)U(B-A) Binario="); imprimirBinario(Or(Diferencia(A,B), And(B,A)));

	Incluir(1, A);
	Incluir(2, A);
	Incluir(5, B);
	Incluir(4, B);
	
	C = Or(A, B);
    printf("Union de A y B = "); Escribir(C);
    printf("Union de A y B Binario= "); imprimirBinario(C);
    
    C = And(A, B);
    printf("Interseccion de A y B = "); Escribir(C);
    printf("Interseccion de A y B Binario= "); imprimirBinario(C);
    
    
 
}

/* ************************************************ */

/* Iniciar el conjunto */
void Iniciar (unsigned char C[])  {
    unsigned char i;
    for (i = 0; i < N; i++)
        C[i] = 0;
}

/* Determinar byte que ocupa el elemento x */
unsigned char byte (unsigned char x)  {
    return (x / 8);
}

/* Determinar el bit del byte que ocupa el elemento */
unsigned char bit (unsigned char x) {
    return (x % 8);
}

/* Incluir un elemento al conjunto */
void Incluir (unsigned char x, unsigned char C[]) {
    C[byte(x)] |= (1 << bit(x));
}

/* Determinar si un elemento pertenece al conjunto */
unsigned char Pertenece (unsigned char x, unsigned char C[]) {
    if (C[byte(x)] & (1 << bit(x)))  return 1;
    else return 0;
}

/* Unión de dos conjuntos */
unsigned char *Or(unsigned char A[], unsigned char B[]) {
unsigned char i, *C, *D;
    C = (unsigned char *)malloc(N);
    D = C;
    for (i = 0; i < N; i++)  {
        *C = A[i] | B[i];
        C++;
    }
    return D;
}

/* Intersección de dos conjuntos */
unsigned char *And (unsigned char A[], unsigned char B[]) {
unsigned char i, *C, *D;
    C = (unsigned char *) malloc(N);
    D = C;
    for (i = 0; i < N; i++)  {
        *C = A[i] & B[i];
        C++;
    }
    return D;
}

/* Diferencia entre dos conjuntos */
unsigned char *Diferencia(unsigned char A[], unsigned char B[]) {
unsigned char i, *C, *D;
    C = (unsigned char *)malloc(N);
    D = C;
    for (i = 0; i < N; i++ )  {
        *C = A[i] & ~B[i];
        C++;
    }
    return D;
}

// Determinar si un conjunto esta vacio
unsigned char Vacio(unsigned char C[]) {
unsigned char x;
    for (x = 0; x < N; x++)
        if (C[x] != 0)  return 0;
    return 1;
}

/* Escribir conjunto */
void Escribir (unsigned char C[]) {
unsigned char x;
    if  (!Vacio(C))  {
        printf("{ ");
        for (x = 0; x < M; x++)
            if (Pertenece(x, C))  printf("%u, ", x);
        printf("\b\b }"); // Borra la coma y el espacio anteriores
    }
    else  printf("{ }");
    printf("\n");
}

void imprimirBinario(unsigned char C[]) {
	unsigned int contador = pow (2,8);
	for (contador ; contador > 0 ; contador >>= 1){
		
		if (contador & C[0] ){
			printf("1");
		}else{
			printf("0");
		}
	}
	printf("\n\n");
}
