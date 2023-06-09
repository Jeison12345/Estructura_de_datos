#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

char* invertir_cadena_apuntada(char *cadena){
/**
 * @brief Invierte una cadena apuntada
 * @param cadena Cadena apuntada
 * @return char* Cadena invertida
 */

    int longitud = 0;
    while(cadena[longitud] != '\0'){
        longitud++;
    }
    char *cadena_invertida = (char*) malloc(longitud * sizeof(char));
    for(int i = 0; i < longitud; i++){
        cadena_invertida[i] = cadena[longitud - i - 1];
    }
    cadena_invertida[longitud] = '\0'; // Agrega el terminador
    return cadena_invertida;
}

int* invertir_vector(int vector[], int longitud){
/**
 * @brief Invierte un vector
 * @param vector[] Vector de enteros
 * @param longitud Longitud del vector
 * @return int* Vector invertido
 */

    int *vector_invertido = (int*) malloc(longitud * sizeof(int));
    for(int i = 0; i < longitud; i++){
        vector_invertido[i] = vector[longitud - i - 1];
    }
    return vector_invertido;
}

int ultima_posicion_numero(int vector[], int longitud, int numero){
/**
 * @brief Devuelve la ultima posicion de un numero en un vector
 * @param vector[] Vector de enteros
 * @param longitud Longitud del vector
 * @param numero Numero a buscar
 * @return int Ultima posicion del numero en el vector
 */

    for(int i = longitud - 1; i >= 0; i--){
        if(vector[i] == numero){
            return i;
        }
    }
    return -1;
}

int main(){
    int vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int longitud = sizeof(vector)/sizeof(vector[0]);
    int numero;
    char *cadena = "Hola mundo";
    printf("La suma del vector es: %i\n", suma_elementos_vector(vector, longitud));
    printf("Introduce un numero: ");
    scanf("%i", &numero);
    printf("El numero %i %s esta en el vector\n", numero, encontrar_numero(vector, longitud, numero) ? "si" : "no");
    printf("La cadena invertida es: %s\n", invertir_cadena_apuntada(cadena));
    printf("La ultima posicion del numero %i en el vector es: %i\n", numero, ultima_posicion_numero(vector, longitud, numero));
    printf("El vector invertido es: ");
    int *vector_invertido = invertir_vector(vector, longitud);
    for(int i = 0; i < longitud; i++){
        printf("%i ", vector_invertido[i]);
    }
    printf("\n");
    free(vector_invertido);
    return 0;
}