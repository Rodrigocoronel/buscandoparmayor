#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INDICEMAYOR 10000

void main() {
	int numeros[INDICEMAYOR]; // se declara el arreglo para guardar los numeros a analizar
	int resultadomayor = 0;  // se declara la variable para guardar la division mayor 
	int nuevoresultado = 0;  // se declara la variable para alvergar las divisiones
	int direccionparmayor = 0;  // se declara la variable para guardar el indice del numero par mayor
	int i = 0;		// se declara el indice en 0
	int numeroimpar = 0;  // se declara el indice del numero siguiente, el numero impar
	int numeroanterior = 0; // se declara la variable para guardar el indice del numero anterior
	int numerosigsig = 0 ; // se declara la variable para guardar el indice del numero segundo siguiente del numero par

	
	srand(time(NULL)); // genera una semilla para los numeros aleatorios

	while(i < INDICEMAYOR){ // ciclo para llenar el arreglo de numeros
		numeros[i++]=rand()%(100);  // genera numeros entre 0 y 99 e incrementar el valor del indice

	}

	i = 0; // poner el valor de i en 0 para el siguiente while
	while(i < INDICEMAYOR - 3) { // ciclo para verificar si el numero cumple con las condiciones establecidas 

		if(! (numeros[i] % 2) && (numeros[i+1] % 2) && (numeros[i-1]+numeros[i+1] == numeros[i]) && ((numeros[i] / 2) == numeros[i+2])) 
			nuevoresultado = numeros[i] / 2;  // se divide el numero par entre 2 

		if(resultadomayor < nuevoresultado) {  // se compara si el numero que teniamos es 
			resultadomayor = nuevoresultado;	// se guarda las veces que es divisible el numero par entre 2
			direccionparmayor = i; // se guarda la direccion del indice del numero par
			numeroimpar = i + 1; // se guarda el numero siguiente
			numeroanterior = i - 1; // se guarda el numero anterior 
			numerosigsig = i + 2; // se guarda el segundo numero siguiente 
		}
		i++; // incremento del indice 
	}	//fin while

	switch(resultadomayor){ // verificar si se encontro un numero con las condiciones 
		case 0 :
			printf("No se encontro un numero con esas condiciones entre %d numeros \n", INDICEMAYOR); // imprime que no se encontro un numero
		break;
		default :
			printf("\n numero par mayor: %d ", numeros[direccionparmayor]); // se imprime el numero par mayor
			printf("\n numero de veces divisible entre 2: %d", resultadomayor);
			printf("\n numero siguiente: %d ", numeros[numeroimpar]);  // se imprime el numero siguiente del par
			printf("\n numero anterior: %d ",  numeros[numeroanterior]); // se imprime el numero anterior del par
			printf("\n numero segundo siguiente: %d \n",numeros[numerosigsig]); // se imprime el numero siguiente segundo del par
		break;
	} // fin del switch 
		
}
