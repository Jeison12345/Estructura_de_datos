#include <stdio.h>
#include <stdbool.h>

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

bool encontrar_numero(int vector[], int longitud, int numero){
/**
 * @brief Busca un numero en un vector
 * @param vector[] Vector de enteros
 * @param longitud Longitud del vector
 * @param numero Numero a buscar
 * @return bool True si el numero esta en el vector, False si no esta
 */

    for(int i = 0; i < longitud; i++){
        if(vector[i] == numero){
            return true;
        }
    }
    return false;
}

int main(){
    int vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int longitud = sizeof(vector)/sizeof(vector[0]);
    int numero;
    printf("La suma del vector es: %i\n", suma_elementos_vector(vector, longitud));
    printf("Introduce un numero: ");
    scanf("%i", &numero);
    printf("El numero %i %s esta en el vector\n", numero, encontrar_numero(vector, longitud, numero) ? "si" : "no");
    return 0;
}