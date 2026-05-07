//
//  matrizBidimensional.c
//  dinamicaMatrices
//
//  Created by Iván Álvarez Navia on 22/03/13.
//  Copyright (c) 2013 Iván Álvarez Navia. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "matrizBidimensional.h"



matFloatRef
crearMatFloat(int numFil, int numCol, intRef errNum)
{
	matFloatRef temp;
    int i;
    
	if (!(numFil > 0 && numCol > 0 )) {
#ifdef DEBUG
        fprintf(stderr, "Error: dimensiones incorrectas: %d, %d\n",numFil,numCol);
#endif
        *errNum = -1;
        return NULL;
	}
	if (NULL == (temp = malloc(sizeof(matFloat)))){
#ifdef DEBUG
        fprintf(stderr, "Error: fallor reserva memoria tipo matriz\n");
#endif
        *errNum = -2;
        return NULL;
    }
    else if (NULL == (temp->m = malloc(numFil*sizeof(float *)))){
#ifdef DEBUG
        fprintf(stderr, "Error: fallor reserva memoria matriz\n");
#endif
        free(temp);
        *errNum = -3;
        return NULL;
    }
    else {
        temp->numFil = numFil;
        temp->numCol = numCol;
        for (i = 0; i < numFil; i++) {
            if (NULL == (temp->m[i] = malloc(numCol*sizeof(float)))){
                for (i--; i >= 0; i--)
                    free(temp->m[i]);
                free(temp->m);
                free(temp);
#ifdef DEBUG
                fprintf(stderr, "Error: fallor reserva memoria matriz\n");
#endif
                *errNum = -4;
                return NULL;
            }
        }
        *errNum = 0;
        return temp;
    }
}



matIntRef
crearMatInt(int numFil, int numCol, intRef errNum)
{
	matIntRef temp;
    int i;
	if (!(numFil > 0 && numCol > 0)) {
#ifdef DEBUG
        fprintf(stderr, "Error: dimensiones incorrectas: %d, %d\n",numFil,numCol);
#endif
        *errNum = -1;
        return NULL;
	}
	if (NULL == (temp = malloc(sizeof(matInt)))){
#ifdef DEBUG
        fprintf(stderr, "Error: fallo reserva memoria tipo matriz\n");
#endif
        *errNum = -2;
        return NULL;
    }
    else if (NULL == (temp->m = malloc(numFil*sizeof(int *)))){
#ifdef DEBUG
        fprintf(stderr, "Error: fallo reserva memoria matriz\n");
#endif
        free(temp);
        *errNum = -3;
        return NULL;
    }
    else {
        temp->numFil = numFil;
        temp->numCol = numCol;
        for (i = 0; i < numFil; i++) {
            if (NULL == (temp->m[i] = malloc(numCol*sizeof(int)))){
                for (i--; i >= 0; i--)
                    free(temp->m[i]);
                free(temp->m);
                free(temp);
#ifdef DEBUG
                fprintf(stderr, "Error: fallor reserva memoria matriz\n");
#endif
                *errNum = -4;
                return NULL;
            }
        }
        *errNum = 0;
        return temp;
    }
}

int
fallaMatrizFloat(matFloatRef mat)
{
    int i;
    if (mat == NULL) {
#ifdef DEBUG
        fprintf(stderr, "Error: referencia tipo matriz\n");
#endif
        return -1;
    }
    if (mat->numFil <= 0 || mat->numCol <=0 || mat->m == NULL) {
#ifdef DEBUG
        fprintf(stderr, "Error: matriz mal construida\n");
#endif
        return -2;
    }
    for (i = 0; i < mat->numFil; i++)
        if (mat->m[i] == NULL){
#ifdef DEBUG
            fprintf(stderr, "Error: fila %d nula\n",i);
#endif
            return -3;
        }
    return 0;
}

int
fallaMatrizInt(matIntRef mat)
{
    int i;
    
    if (mat == NULL) {
#ifdef DEBUG
        fprintf(stderr, "Error: referencia tipo matriz\n");
#endif
        return -1;
    }
    if (mat->numFil <= 0 || mat->numCol <=0 || mat->m == NULL) {
#ifdef DEBUG
        fprintf(stderr, "Error: matriz mal construida\n");
#endif
        return -2;
    }
    for (i = 0; i < mat->numFil; i++)
        if (mat->m[i] == NULL){
#ifdef DEBUG
            fprintf(stderr, "Error: fila %d nula\n",i);
#endif
            return -3;
        }
    return 0;
}

int
leerMatFloat(matFloatRef mat, charRef c)
{
    int i,j,res;
	
	if (!(res = fallaMatrizFloat(mat))) {
        if (NULL == c)
            c = "m";
        for (i=0; i < mat->numFil; i++) {
            for (j=0; j < mat->numCol; j++) {
                printf("%s[%d][%d] = ",c,i,j);
                scanf("%f%*c",&(mat->m[i][j]));
                //scanf("%f%*c",(*(mat->m + i) + j));
            }
        }
        return 0;
    }
    else
        return res;
}

int
leerMatInt(matIntRef mat, charRef c)
{
    
    int i,j,res;
	
	if (!(res = fallaMatrizInt(mat))) {
        if (NULL == c)
            c = "m";
        for (i=0; i < mat->numFil; i++) {
            for (j=0; j < mat->numCol; j++) {
                printf("%s[%d][%d] = ",c,i,j);
                scanf("%d%*c",&(mat->m[i][j]));
                //scanf("%d%*c",(*(mat->m + i) + j));
            }
        }
        return 0;
    }
    else
        return res;
}


int
mostrarMatFloat(matFloatRef mat, charRef c)
{
    int res,i,j;
	
    if (!(res = fallaMatrizFloat(mat))) {
        if (NULL == c) {
            c = " %g ";
        }
        for (i = 0; i < mat->numFil; i++) {
            printf("| ");
            for (j = 0; j < mat->numCol; j++) {
                printf(c,mat->m[i][j]);
                //printf(c,*(*(mat->m + i) + j));
            }
            printf(" |\n");
        }
        return 0;
    }
	else
        return res;
}



int
mostrarMatInt(matIntRef mat, charRef c)
{
    int i,j,res;
	
    if (!(res = fallaMatrizInt(mat))) {
        if (NULL == c) {
            c = " %g ";
        }
        for (i = 0; i < mat->numFil; i++) {
            printf("| ");
            for (j = 0; j < mat->numCol; j++) {
                printf(c,mat->m[i][j]);
                //printf(c,*(*(mat->m + i) + j));
            }
            printf(" |\n");
        }
        return 0;
    }
    else
        return res;
}


int
liberarMatFloat(matFloatRef mat)
{
    int res,i;
    
	if (!(res = fallaMatrizFloat(mat))) {
		for(i = 0; i < mat->numFil ; i++)
			free(mat->m[i]);
        free(mat->m);
        mat->m = NULL;
        mat->numFil = -1;
        mat->numCol = -1;
        return 0;
    }
	else
        return res;
}

int
liberarMatInt(matIntRef mat)
{
    int res,i ;
    
	if (!(res = fallaMatrizInt(mat))) {
		for(i = 0; i < mat->numFil ; i++)
			free(mat->m[i]);
        free(mat->m);
        mat->m = NULL;
        mat->numFil = -1;
        mat->numCol = -1;
        return 0;
    }
	else
        return res;
}

matFloatRef
sumarMatFloat(matFloatRef a, matFloatRef b, intRef errNum)
{
	int i,j, res;
    matFloatRef c;
    
    if (!(res =fallaMatrizFloat(a)) && !(res = fallaMatrizFloat(b))) {
        if (!(a->numFil == b->numFil && a->numCol == b->numCol)) {
#ifdef DEBUG
            fprintf(stderr, "Error: dimensiones incorrectas\n\n");
#endif
            *errNum = -5;
            return NULL;
        }
        else {
            if (NULL != (c = crearMatFloat(a->numFil, a->numCol, &res))) {
                for (i=0; i < a->numFil; i++) 
                    for (j = 0; j < a->numCol; j++) 
                        c->m[i][j] = a->m[i][j] + b->m[i][j];
                *errNum = 0;
                return c;
            }
            else {
                *errNum = res;
                return NULL;
            }
        }
	}
    else {
        *errNum = res;
        return NULL;
    }
}

matIntRef
sumarMatInt(matIntRef a, matIntRef b, intRef errNum)
{
	int i, j, res;
    matIntRef c;
    
    if (!(res =fallaMatrizInt(a)) && !(res = fallaMatrizInt(b))) {
        if (!(a->numFil == b->numFil && a->numCol == b->numCol)) {
#ifdef DEBUG
            fprintf(stderr, "Error: dimensiones incorrectas\n\n");
#endif
            *errNum = -5;
            return NULL;
        }
        else {
            if (NULL != (c = crearMatInt(a->numFil, a->numCol, &res))) {
                for (i=0; i < a->numFil; i++)
                    for (j = 0; j < a->numCol; j++)
                        c->m[i][j] = a->m[i][j] + b->m[i][j];
                *errNum = 0;
                return c;
            }
            else {
                *errNum = res;
                return NULL;
            }
        }
	}
    else {
        *errNum = res;
        return NULL;
    }
}


// EJERCICIO 3: MULTIPLICACIÓN DE MATRICES Y OBTENCIÓN DE COLUMNA MÁXIMA
matIntRef multiplicarMatInt(matIntRef a, matIntRef b, intRef errNum){
    int i, j, k, res;
    matIntRef c;
    if (!(res =fallaMatrizInt(a)) && !(res = fallaMatrizInt(b))) {  // fallamatriz devuelve por retorno 0 si la matriz es correcta, por lo que se niega para entrar al if
        if (a->numCol != b->numFil) {
#ifdef DEBUG            
            fprintf(stderr, "Error: dimensiones incorrectas\n\n");
#endif
            *errNum = -5;
            return NULL;    
        }
        else {
            if (NULL != (c = crearMatInt(a->numFil, b->numCol, &res))) { // multiplicación de matrices: filas de a por columnas de b. crearMatInt no es NULL si la matriz es correcrta.
                for (i=0; i < a->numFil; i++)
                    for (j = 0; j < b->numCol; j++) {
                        c->m[i][j] = 0;
                        for (k = 0; k < a->numCol; k++) // a->numCol == b->numFil
                            c->m[i][j] += a->m[i][k] * b->m[k][j];
                    }
                *errNum = 0;
                return c; // MATRIZ CORRECTA !
            }
            else {
                *errNum = res; // res es el código de error devuelto por crearMatInt
                return NULL;
            }
        }   
    }
    else {
        *errNum = res; // res es el código de error devuelto por fallaMatrizInt
        return NULL;
    }
}

matFloatRef multiplicarMatFloat(matFloatRef a, matFloatRef b, intRef errNum){
    int i, j, k, res;
    matFloatRef c;
    if(!(res =fallaMatrizFloat(a)) && !(res = fallaMatrizFloat(b))) {  // fallamatriz devuelve por retorno 0 si la matriz es correcta, por lo que se niega para entrar al if
        if (a->numCol != b->numFil){
            *errNum = -5;
            return NULL;
        }
        else {
            if (NULL != (c = crearMatFloat(a->numFil, b->numCol, &res))) { // res es de crearMatFloat, no es NULL si la matriz es correcrta.
                for (i=0; i < a->numFil; i++)
                    for (j = 0; j < b->numCol; j++) {
                        c->m[i][j] = 0;
                        for (k = 0; k < a->numCol; k++) // a->numCol == b->numFil
                            c->m[i][j] += a->m[i][k] * b->m[k][j];
                    }
                *errNum = 0;
                return c;
            }
            else {
                *errNum = res;
                return NULL;
            }
        }

    }
    else {
        *errNum = res; // res es el código de error devuelto por fallaMatrizFloat
        return NULL;
        }
}

int *obtenerColumnaMaxMatInt(matIntRef mat, intRef errNum){
    int i, j, res;
    int *colMax; // vector en el que copiaremos la columna máxima de la matriz. 
    if (!(res = fallaMatrizInt(mat))) { 
        if (NULL != (colMax = malloc(mat->numCol * sizeof(int)))) { // reservamos memoria para el vector columna máxima. Si no es NULL, la reserva fue correcta.
            for (j = 0; j < mat->numCol; j++) { // recorremos las columnas de la matriz
                colMax[j] = mat->m[0][j]; // inicializamos el máximo de cada columna con el primer elemento de la columna j-ésima
                for (i = 1; i < mat->numFil; i++) { // recorremos las filas de la columna j
                    if (mat->m[i][j] >= colMax[j]) { // si encontramos un elemento mayor que el máximo actual (en el primer caso es mat->m[0][j]), lo actualizamos
                        colMax[j] = mat->m[i][j];
                    }
                }
            }
            *errNum = 0;
            return colMax; // devolvemos el vector columna máxima
        }
        else {
            *errNum = -5; // error en reserva memoria para el vector columna máxima
            return NULL;
        }
    
    }
    else {
        *errNum = res; // res es el código de error devuelto por fallaMatrizInt
        return NULL;
    }
}



float *obtenerColumnaMaxMatFloat(matFloatRef mat, intRef errNum){
    int i, j, res;
    float *colMax; // vector de floats en el que copiaremos la columna máxima de la matriz.
    if (!(res = fallaMatrizFloat(mat))){
        if (NULL != (colMax = malloc(mat->numCol * sizeof(float)))) {
        for (j = 0; j < mat->numCol; j++) { // recorremos las columnas de la matriz
            colMax[j] = mat->m[0][j]; // inicializamos el máximo de cada columna con el primer elemento de la columna j-ésima
            for (i = 1; i < mat->numFil; i++) { // recorremos las filas de la columna j
                if (mat->m[i][j] >= colMax[j]) { // si encontramos un elemento mayor que el máximo actual (en el primer caso es mat->m[0][j]), lo actualizamos
                    colMax[j] = mat->m[i][j];
                }
            }
        }
        *errNum = 0;
        return colMax;
        }
        else {
        *errNum = -5; // error en reserva memoria para el vector columna máxima
        return NULL;
        }

    }
    else {
        *errNum = res; // res es el código de error devuelto por fallaMatrizFloat
        return NULL;
    }

}

//EJERCICIO 4: SUBMATRICES SIMÉTRICAS.
matIntRef devolverPrimeraSimetrica(matIntRef mat, int orden, intRef errNum){
    int i, j, k, l, p, res;
    matIntRef sim; // submatriz simétrica que devolveremos.
    if (!(res = fallaMatrizInt(mat))) {
        if (orden > mat->numFil || orden > mat->numCol) { // el orden de la submatriz simétrica no puede ser mayor que el número de filas o columnas de la matriz original
#ifdef DEBUG
            fprintf(stderr, "Error: orden de la submatriz simétrica mayor que el número de filas o columnas de la matriz original\n");
#endif
            *errNum = -5;
            return NULL;      
    if (NULL != (sim = crearMatInt(orden, orden, &res))) { // res es de crearMatInt, no es NULL si la matriz es correcrta.
        for (i = 0; i < mat->numFil - orden + 1; i++) { // recorremos las filas de la matriz original hasta el número de filas menos el orden de la submatriz simétrica más 1
            for (j = 0; j < mat->numCol - orden + 1; j++) { // recorremos las columnas de la matriz original hasta el número de columnas menos el orden de la submatriz simétrica más 1
                if (mat->m[i][j] == mat->m[j][i]) { // si el elemento de la posición (i,j) es igual al elemento de la posición (j,i), entonces la submatriz que empieza en (i,j) y tiene orden "orden" es simétrica.
                    for (k = 0; k < orden; k++)
                        for (l = 0; l < orden; l++)
                            sim->m[k][l] = mat->m[i+k][j+l];
                    *errNum = 0;
                    return sim;
                }
            }
        }
        /* for (i = 0; i < mat->numFil - orden + 1; i++) {
                for (j = 0; j < mat->numCol - orden + 1; j++) {
                    esSimetrica = 1;
                    
                    for (k = 0; k < orden && esSimetrica; k++) {
                        for (l = 0; l < orden && esSimetrica; l++) {
                            if (mat->m[i+k][j+l] != mat->m[i+l][j+k]) {
                                esSimetrica = 0;
                            }
                        }
                    }
                    
                    if (esSimetrica) {
                        for (k = 0; k < orden; k++)
                            for (l = 0; l < orden; l++)
                                sim->m[k][l] = mat->m[i+k][j+l];
                        *errNum = 0;
                        return sim;
                    }
                }
            }*/
 // Si no encontramos ninguna submatriz simétrica, liberar memoria MANUALMENTE
            for (p = 0; p < orden; p++) {
                free(sim->m[p]);  // Liberar cada fila
            }
            free(sim->m);  // Liberar el array de punteros
            free(sim);     // Liberar la estructura
            *errNum = -6;
            return NULL;
    }
    else {
        *errNum = res; // res es el código de error devuelto por crearMatInt
        return NULL;
    }
    }
    else {
        *errNum = res; // res es el código de error devuelto por fallaMatrizInt
        return NULL;
    }





}

}




matFloatRef devolverPrimeraSimetrica(matFloatRef mat, int orden, intRef errNum){
int i, j, k, l, p, res;
    matFloatRef sim; // submatriz simétrica que devolveremos.
    if (!(res = fallaMatrizFloat(mat))) {
        if (orden > mat->numFil || orden > mat->numCol) { // el orden de la submatriz simétrica no puede ser mayor que el número de filas o columnas de la matriz original
#ifdef DEBUG
            fprintf(stderr, "Error: orden de la submatriz simétrica mayor que el número de filas o columnas de la matriz original\n");
#endif
            *errNum = -5;
            return NULL;      
    if (NULL != (sim = crearMatFloat(orden, orden, &res))) { // res es de crearMatInt, no es NULL si la matriz es correcrta.
        for (i = 0; i < mat->numFil - orden + 1; i++) { // recorremos las filas de la matriz original hasta el número de filas menos el orden de la submatriz simétrica más 1
            for (j = 0; j < mat->numCol - orden + 1; j++) { // recorremos las columnas de la matriz original hasta el número de columnas menos el orden de la submatriz simétrica más 1
                if (mat->m[i][j] == mat->m[j][i]) { // si el elemento de la posición (i,j) es igual al elemento de la posición (j,i), entonces la submatriz que empieza en (i,j) y tiene orden "orden" es simétrica.
                    for (k = 0; k < orden; k++)
                        for (l = 0; l < orden; l++)
                            sim->m[k][l] = mat->m[i+k][j+l];
                    *errNum = 0;
                    return sim;
                }
            }
        }
        /* for (i = 0; i < mat->numFil - orden + 1; i++) {
                for (j = 0; j < mat->numCol - orden + 1; j++) {
                    esSimetrica = 1;
                    
                    for (k = 0; k < orden && esSimetrica; k++) {
                        for (l = 0; l < orden && esSimetrica; l++) {
                            if (mat->m[i+k][j+l] != mat->m[i+l][j+k]) {
                                esSimetrica = 0;
                            }
                        }
                    }
                    
                    if (esSimetrica) {
                        for (k = 0; k < orden; k++)
                            for (l = 0; l < orden; l++)
                                sim->m[k][l] = mat->m[i+k][j+l];
                        *errNum = 0;
                        return sim;
                    }
                }
            }*/
 // Si no encontramos ninguna submatriz simétrica, liberar memoria MANUALMENTE
            for (p = 0; p < orden; p++) {
                free(sim->m[p]);  // Liberar cada fila
            }
            free(sim->m);  // Liberar el array de punteros
            free(sim);     // Liberar la estructura
            *errNum = -6;
            return NULL;
    }
    else {
        *errNum = res; // res es el código de error devuelto por crearMatInt
        return NULL;
    }
    }
    else {
        *errNum = res; // res es el código de error devuelto por fallaMatrizInt
        return NULL;
    }





}






}



// DANI: 3,5,6

//EJERCICIO 3: MULTIPLICACIÓN DE MATRICES .
    matIntRef multiplicarMatInt(matIntRef a, matIntRef b, intRef errNum)
{
    int i,j,k;
    matIntRef c;

    //VERIFICACIÓN A Y B
    if(a==NULL || b==NULL)
    {
        *errNum=-1;
        return NULL;
    }

    if(a->m==NULL || b->m==NULL || a->numFil<=0 || a->numCol<=0 || b->numFil<=0 || b->numCol<=0)
    {
        *errNum=-2;
        return NULL;
    }


    for(i=0;i<a->numFil;i++)
    {
        if(NULL==a->m[i])
        {
            for(j=i;j>=0;j++)
            free(a->m[i]);
            free(a->m);
            free(a);
            *errNum=-3;
            return NULL;
        }


    }
     for(i=0;i<b->numFil;i++)
    {
        if(NULL==b->m[i])
        {
            for(j=i;j>=0;j--)
            free(b->m[i]);
            free(b->m);
            free(b);
            *errNum=-3;
            return NULL;
        }


    }
    if(a->numCol!=b->numFil)
    {
        *errNum=-5;
        return NULL;
    }

    //CREACIÓN MATRIZ C
    if(NULL!=(c=malloc(sizeof(matInt))))
    {
        c->numFil=a->numFil;
        c->numCol=b->numCol;
        if(NULL!=(c->m=malloc(c->numFil*sizeof(int *))))
        {
            for(i=0;i<c->numFil;i++)
            {
                if(NULL!=(c->m[i]=malloc(c->numCol*sizeof(int))))
                {   
                    for(i=0;i<a->numFil;i++)
                    {
                        for(k=0;k<c->numCol;k++)
                        {
                            for(j=0;j<a->numCol;j++)
                            {
                                c->m[i][k]+=(a->m[i][j])*(b->m[j][i]);
                            }
                        }
                        
                    }
                }   

                for(j=i;j>=0;j--)
                {
                    free(c->m[i]);
                    free(c->m);
                    free(c);
                }
            }
        }
        *errNum=-6;
        return NULL;
    }
    *errNum=-4;
    return NULL;


}
// EJERCICIO 3:  OBTENCIÓN DE COLUMNA MÁXIMA
int *obtenerColumnaMaxMatInt(matIntRef mat, intRef errNum)
{
    int i,j, *v,max,col_max;



    if(mat==NULL)
    {
        *errNum=-1;
        return NULL;
    }

    if(mat->numFil<=0 || mat->numCol<=0 || mat->m==NULL)
    {
        *errNum=-2;
        return NULL;
    }

    for(i=0;i<mat->numFil;i++)
    {
        if(mat->m[i]==NULL)
        {
            *errNum=-3;
            return NULL;
        }
    }

    if(NULL==(v=malloc(mat->numFil*sizeof(int))))
    {
        *errNum=-5;
        return NULL;
    }

    max=mat->m[0][0];
    for (j=0;j<mat->numCol;j++)
    {
        
        for(i=0;i<mat->numFil;i++)
        {
            if(mat->m[i][j]>=max)
            {
                max=mat->m[i][j];
                col_max=j;
            }
        }
    }

    for(i=0;i<mat->numCol;i++)
    {
        v[i]=mat->m[i][col_max];
    }

    //LIBERAR SI PIDIERAN EN OTRA FUNCIÓN
    free(v);

    for(i=0;i<mat->numFil;i++)
    {
        free(mat->m[i]);
    }

    free(mat->m);

    free(mat);
}


// EJERCICIO 5 : ELIMINAR FILAS DE UNA MATRIZ BIDIMENSIONAL.
int eliminarFilasMatInt(matInt *matriz)
{
    int i,j,k,flag,dim,eliminadas,contador;
    int **res;

    if(NULL==matriz)
    {
        return -1;
    }

    if(matriz->m==NULL || matriz->numFil<=0 || matriz->numCol<=0)
    {
        return -2;
    }

    eliminadas=0;
    dim=0;
    for (i=0;i<matriz->numFil;i++)
    {
        flag=0;
        for(j=0;j<matriz->numCol;j++)
        {
            if(matriz->m[i][j]<0)
            {
                flag=1;
                eliminadas++;
            }
        }
        if(flag==0)
            {
                dim++;
            }
    }
    if(dim==0)
    {
        return 0;
    }

    if(dim==matriz->numFil)
    {
        for(i=0;i<matriz->numFil;i++)
        {
            free(matriz->m[i]);
        }
        matriz->m=NULL;
        matriz->numFil=0;
        return eliminadas;
    }
    
    if(NULL!=(res=malloc(dim*sizeof(int *))))
    {
        for(i=0;i<matriz->numFil;i++)
        {
            flag=0;
            for(j=0;j<matriz->numCol;j++)
            {
                 if(matriz->m[i][j]<0)
                 {
                    flag=1;
                    j=matriz->numCol;
                    free(matriz->m[i]);
                 }
            }
            if(flag==0)
            {
                res[contador]=matriz->m[i];
                contador++;
            }
        }

        free(matriz->m);
        matriz->m=res;
        matriz->numFil=dim;

        return eliminadas;

    }
    return -3;
}

// EJERCICIO 6: EXTRAER SUBMATRIZ CUADRADA DE UNA MATRIZ BIDIMENSIONAL.
matInt *extraerSubMatIntCuadrada(matInt *matrizOrigen, int filOrigen, int colOrigen, int dimension, int *codError)
{
    int i,j,fil,col;
    matInt *c;

    if(matrizOrigen==NULL)
    {
        *codError=-1;
        return NULL;
    }

    if(matrizOrigen->m==NULL || matrizOrigen->numFil<=0 || matrizOrigen->numCol<=0)
    {
        *codError=-2;
        return NULL;
    }

    for(i=0;i<matrizOrigen->numFil;i++)
    {
        if(matrizOrigen->m[i]==NULL)
        *codError=-3;
        return NULL;
    }

    if(filOrigen>=0 && colOrigen>=0 && filOrigen+dimension<=matrizOrigen->numFil && colOrigen+dimension<=matrizOrigen->numCol)
    {
        if(NULL!=(c=malloc(sizeof(matInt))))
        {
            c->numFil=dimension;
            c->numCol=dimension;
            if(NULL!=(c->m=malloc(sizeof(dimension*sizeof(int *)))))
            {
                for(i=0;i<c->numFil;i++)
                {
                    if(NULL==c->m[i])
                    {
                        for(j=i;j>=0;j++)
                        {
                            free(c->m[j]);
                        }
                        free(c->m);
                        free(c);
                        *codError=-5;
                        return NULL;
                    }
                }
                for(i=filOrigen;i<filOrigen+dimension;i++)
                {
                    for(j=colOrigen;j<colOrigen+dimension;j++)
                    {
                        c->m[][]=matrizOrigen->m[i][j];
                    }
                }

                *codError=0;
                return NULL;
            }
            *codError=-5;
            return NULL;

        }
        *codError=-5;
        return NULL;
    }
    *codError=-4;
    return NULL;
}

//EJERCICIO 5:ELIMINAR FILAS DE UNA MATRIZ BIDIMENSIONAL.
/* JAVI int eliminarFilasMatInt(matInt *matriz)
{
	int i, j, flag, k;
	int pos, neg;
	**m2;
	//VALIDACIONES
	
	if(matriz==NULL)
	return -1;
	
	if(numCol<=0 || numFil<=0 || matriz->m == NULL)
	{
	return -2;
	}
	
	for(i=0;i<numFil;i++)
	{
		if(matriz->m[i]==NULL)
		{
		return -3;
		}
	}

	//RECUENTO FILAS (1º RECORRIDO)
	pos=0;
	neg=0;
	
	for(i=0;i<matriz->numFil;i++)
	{
		flag=0;
		for(j=0;j<matriz->numCol && !flag;j++)
		{
			if(matriz->m[i][j]<0)
			flag=1;
		}
		if(!flag)
		neg++;
		
		pos++;
	}
	
	//POSIBLES SIMPLES OPCIONES
	
	if(pos==matriz->numFil)		//NINGUNA NEGATIVA
		return 0;
	
	if(neg==matriz->numFil)		//TODAS NEGATIVAS
	{
		for(i=0;i<numFil;i++)
		{
			free(matriz->m[i]);
		}
		
		free(matriz->m);
		matriz->m=NULL;
		
		matriz->numFil=0;
		matriz->numCol=0;
		
		return neg;
	}
	
	//RESERVA NUEVA MATRIZ
	
	m2=malloc(pos*sizeof(*int));
	
	
	//COPIAR AL NUEVO PUNTERO (2º RECORRIDO)
	
	for(i=0;i<matriz->numFil;i++)
	{
		flag=0;
		for(j=0;j<matriz->numCol && !flag;j++)
		{
			if(matriz->m[i][j]<0)
			{
				free(matriz->m[i]);
				flag=1;
			}
		}
		
		if(flag==0)
		{
			m2[k++]=matriz->m[i];
		}	
	}
	
	free(matriz->m);
	matriz->m = m2;*/