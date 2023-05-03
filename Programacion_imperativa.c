#include <stdio.h>

int suma_elementos_vector(int vector[], int longitud){
/**
 * @brief Suma los elementos de un vector
 * @param vector[] Vector de enteros
 * @param longitud Longitud del vector
 * @return int Suma de los elementos del vector
 */

    int suma = 0;
    for(int i = 0; i < longitud; i++){
        suma += vector[i];
    }
    return suma;
}

int main(){
    int vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int longitud = sizeof(vector)/sizeof(vector[0]);
    printf("La suma del vector es: %i\n", suma_elementos_vector(vector, longitud));
    return 0;
}