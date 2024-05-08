#include <iostream>
#include <cmath>
#include "sort.h"

double calcularMedia(int array[], int tamanho) {
    double soma = 0.0;
    for (int i = 0; i < tamanho; ++i) {
        soma += array[i];
    }
    return soma / tamanho;
}

double calcularMediana(int array[], int tamanho) {
    optimizedBubbleSort(array, tamanho);

    if (tamanho % 2 == 0) {
        return (array[tamanho / 2 - 1] + array[tamanho / 2]) / 2.0;
    } else {
        return array[tamanho / 2];
    }
}

double calcularModa(int array[], int tamanho) {
    optimizedBubbleSort(array, tamanho);

    int frequenciaMaxima = 0;
    int modaAtual = array[0];
    int contagemAtual = 1;
    for (int i = 1; i < tamanho; ++i) {
        if (array[i] == array[i - 1]) {
            ++contagemAtual;
        } else {
            if (contagemAtual > frequenciaMaxima) {
                frequenciaMaxima = contagemAtual;
                modaAtual = array[i - 1];
            }
            contagemAtual = 1;
        }
    }
    if (contagemAtual > frequenciaMaxima) {
        frequenciaMaxima = contagemAtual;
        modaAtual = array[tamanho - 1];
    }
    return modaAtual;
}

double calcularDesvioPadrao(int array[], int tamanho) {
    double media = calcularMedia(array, tamanho);
    double somaQuadradosDiferenca = 0.0;
    for (int i = 0; i < tamanho; ++i) {
        somaQuadradosDiferenca += (array[i] - media) * (array[i] - media);
    }
    return std::sqrt(somaQuadradosDiferenca / tamanho);
}