//
//  main.c
//  dinamicaMatrices
//
//  Created by Iván Álvarez Navia on 22/03/13.
//  Copyright (c) 2013 Iván Álvarez Navia. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "matrizBidimensional.h"

int
main (int argc, const char * argv[])
{
	char menu[] = "Suma de matrices: A) Leer datos B) Sumar matrices C) Ver resultados D) Liberar matrices Q) Salir";
	char opcion;
    int numFil, numCol,errNum;
    
	matFloatRef A, B, C;
    
    A = B = C = NULL;
    
	do {
		printf("%s ",menu);
        scanf("%c%*c",&opcion);
		opcion = toupper(opcion);
		switch (opcion) {
			case 'A':
                if (A != NULL || B != NULL) {
                    printf("Ya existen matrices ... opciones C o D\n\n");
                    break;
                }
				printf("\n\nDimensiones de las matrices:\n\n");
                printf("Número de filas: ");
                scanf("%d%*c",&numFil);
                printf("Número de columnas: ");
                scanf("%d%*c",&numCol);
                
                printf("Primera matriz: \n");
                if (NULL != (A = crearMatFloat(numFil, numCol, &errNum)))
                    leerMatFloat(A, "Matriz A");
                else
                    printf("Fallo creación matriz: %d\n",errNum);
                
                printf("Segunda matriz: \n");
				if (NULL != (B = crearMatFloat(numFil, numCol, &errNum)))
                    leerMatFloat(B, "Matriz B");
                else
                    printf("Fallo creación matriz: %d\n",errNum);
                break;
			case 'B':
				printf("\n\nSuma...");
                if (NULL != C){
                    liberarMatFloat(C);
                    free(C);
                }
				if (NULL == (C = sumarMatFloat(A, B, &errNum)))
                    printf("... no realizada %d\n",errNum);
                else
                    printf("efectuada.\n\n");
				break;
			case 'C':
				printf("\n\nVisualización de resultados\n\n");
				printf("\n\nPrimera matriz\n\n");
				mostrarMatFloat(A, " %6.2lf ");
				printf("\n\nSegunda matriz\n\n");
				mostrarMatFloat(B, " %6.2lf ");
				printf("\n\nMatriz suma\n\n");
				mostrarMatFloat(C, " %6.2lf ");
				break;
			case 'D':
				printf("\n\nLiberación de matrices...");
				liberarMatFloat(A);
				free(A);
				A = NULL;
				liberarMatFloat(B);
				free(B);
				B = NULL;
				liberarMatFloat(C);
				free(C);
				C = NULL;
				printf("efectuada.\n\n");
                break;
			case 'Q':
				printf("\n\nSaliendo.\n\n");
				break;
			default:
				printf("\n\nOpción incorrecta!\a\n\n");
				break;
		}
	} while ('Q' != opcion);
	printf("\n\nTerminación normal del programa.\n\n");
    return 0;
}


