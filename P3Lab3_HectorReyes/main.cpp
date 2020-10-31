/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Onasis Reyes
 *
 * Created on 30 de octubre de 2020, 01:30 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;
using std::endl;
using std::cout;
using std::cin;

void generarMatrizRandom(double**&, int);
void imprimirMatriz(double**&, int);
double submatrices(double**&, int, int, int);
double determinante(double**&, double**&, int);
void matrizAdjunta(double**&, int);
double** matrizInversa(double**&, int);
double determinanteCofactor(double**&, int, int);
double determinante_Matriz(double**&, double**&, int);
double determinanteMatriz2x2(double**&);

/*
 * 
 */
int main(int argc, char** argv) {
    bool continuar = true;
    int opcion = 0;
    while (continuar) {
        cout << "0. Salir" << endl
                << "1. Determinante" << endl
                << "2. Matriz Adjunta" << endl
                << "3. Matriz Inversa" << endl
                << "-> Que desea calcular: ";
        cin >> opcion;
        cout << endl;
        switch (opcion) {
            case 1:
            {
                int size = 0;
                double** matriz_A = NULL;
                double** matriz_A_Temporal = NULL;
                while (size < 2) {
                    cout << "Ingrese tamaño de la matriz NxN donde N >= 2: ";
                    cin >> size;
                }
                cout << endl;
                matriz_A = new double*[size];
                generarMatrizRandom(matriz_A, size);
                imprimirMatriz(matriz_A, size);
                matriz_A_Temporal = matriz_A;
                submatrices(matriz_A_Temporal, size, 0, 0);
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 0:
            {
                continuar = false;
                break;
            }
            default:
            {
                cout << "Opcion inexistente." << endl;
            }//fin default
        }//fin switch
    }//fin while
    return 0;
}//fin main

double submatrices(double**& matriz_A_Temporal, int size, int fila, int columna) {
    double** matrizTemporal = NULL;
    int tamañoSubMatriz = size - 1;
    while (tamañoSubMatriz >= 2) {
        matrizTemporal = new double*[tamañoSubMatriz];
        for (int i = 0; i < tamañoSubMatriz; i++) {
            matrizTemporal[i] = new double[tamañoSubMatriz];
        }//fin for
        int fila_actual = 0, columna_actual = 0;
        for (int i = 0; i < tamañoSubMatriz + 1; i++) {
            for (int j = 0; j < tamañoSubMatriz + 1; j++) {
                if (i != fila && columna != j) {
                    matrizTemporal[fila_actual][columna_actual] = matriz_A_Temporal[i][j];
                    columna_actual++;
                }//fin if
            }//fin for
            if (i != fila) {
                fila_actual++;
            }//fin if
            columna_actual = 0;
        }//fin for
        imprimirMatriz(matrizTemporal, tamañoSubMatriz);
        matriz_A_Temporal = matrizTemporal;
        tamañoSubMatriz--;
    }//fin while
    return determinanteMatriz2x2(matriz_A_Temporal);
}//fin void

/*double determinanteCofactor(double**& matrizTemporal, int fila, int col) {
    double valor_Multiplicar = 1.0;
    for (int i = 0; i < fila - 2; i++) {
        for (int j = 0; j < col - 2; j++) {
            if (i == 0 && j == 0) {
                valor_Multiplicar *= matrizTemporal[i][j];
            }
        }
    }
    return valor_Multiplicar;
}*/

double determinanteMatriz2x2(double**& matrizTemporal) {
    return (matrizTemporal[0][0] * matrizTemporal[1][1]) - (matrizTemporal[0][1] * matrizTemporal[1][0]);
}

void generarMatrizRandom(double**& matriz_A, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        matriz_A[i] = new double[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matriz_A[i][j] = 1 + (rand() % 19 - 9);
        }
    }
}

void imprimirMatriz(double**& matriz, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "[" << matriz[i][j] << "] ";
        }
        cout << endl;
    }
    cout << endl;
}

double** matrizInversa(double**& matrizAdjunta, double determinante, int size) {
    double** matrizInversa = NULL;
    matrizInversa = new double*[size];
    for (int i = 0; i < size; i++) {
        matrizInversa[i] = new double[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrizInversa[i][j] = (1 / determinante) * matrizAdjunta[i][j];
        }
    }
    return matrizInversa;
}

/* */

double determinante_Matriz(double**& matrizAdjunta, double**& matriz_A, int size) {
    double determinante = 0.0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            determinante += (matrizAdjunta[i][j] * matriz_A[i][j]);
        }
    }
    return determinante;
}