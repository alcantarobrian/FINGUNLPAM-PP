#include <stdio.h>


//registros:
typedef struct
{
	char apellido[20];
	char nombre[20];
	int edad;
	int sexo;
}p;

typedef p ag[50];


//funciones:
void ingresar_datos(p ag[], int cantidad);
void cant_h_m(p ag[], int cantidad);
void edades(p ag[], int cantidad);
void mostrar_vector(p ag[], int cantidad);
void mostrar_uno(p ag[], int cantidad);

int main()
{
	int cantidad, bcle, op;
	ag agenda;
	
	bcle = 1;
	
	printf("Cuantas personas desea ingresar:");
	scanf("%i", &cantidad);
	
	ingresar_datos(agenda, cantidad);
	
	while (bcle)
	{
		printf("\n\n### MENU ###");
		printf("\n1. Calcular la cantidad de hombre y mujeres ingresados");
		printf("\n2. Mostrar apellido de personas que tengan entre 25 y 50 años");
		printf("\n3. Mostrar todo el vector");
		printf("\n4. Mostrar una persona");
		printf("\n¿Que quiere hacer?...");
		scanf("%i", &op);
		
		switch(op)
		{
		case 1:
			cant_h_m(agenda, cantidad);
			break;
			
		case 2:
			edades(agenda, cantidad);
			break;
		
		case 3:
			mostrar_vector(agenda, cantidad);
			break;
			
		case 4:
			mostrar_uno(agenda, cantidad);
			break;
		}
	}
}

// permite ingresar datos de personas
void ingresar_datos(p ag[], int cantidad)
{
	int i;
	
	for (i = 0; i < cantidad; i++)
	{
		printf("\nIngrese apellido: ");
		scanf("%20s", ag[i].apellido);
		
		printf("\nIngrese nombre: ");
		scanf("%20s", ag[i].nombre);
		
		printf("\nIngrese edad: ");
		scanf("%i", &ag[i].edad);
		
		printf("\nIngrese sexo: ");
		scanf("%i", &ag[i].sexo);
	}
}


//calula la cantidad de hombres y mujeres en el vector
void cant_h_m(p ag[], int cantidad)
{
	int mujeres, hombres, i;
	
	mujeres = 0;
	hombres = 0;
	
	for(i = 0; i < cantidad; i++)
	{
		if (ag[i].sexo == 1)
			hombres++;
		else 
			mujeres++;
	}
	
	printf("\nCantidad de hombres: %i", hombres);
	printf("\nCantidad de mujeres: %i", mujeres);
}

// Muestra a la personas que tengan entre 25 y 50 año;
void edades(p ag[], int cantidad)
{
	int i;
	
	for (i = 0; i < cantidad; i++)
	{
		if (ag[i].edad >= 25 && ag[i].edad <= 50)
			printf("%s, ", ag[i].apellido);
	}
}

// Muestra en grupos de 2
void mostrar_vector(p ag[], int cantidad)
{
	int i;
	
	for (i = 0; i < cantidad; i++)
	{
		printf("\nApellido: %s", ag[i].apellido);
		printf("\nNombre: %s", ag[i].nombre);
		printf("\nEdad: %i", ag[i].edad);
		printf("\nSexo: %i", ag[i].sexo);
		printf("\n");
		
		if ((i + 1) % 2 == 0)
		{
			printf("<ENTER>");
			getchar();
		}
	}
}

// Muestra de uno en uno
void mostrar_uno(p ag[], int cantidad)
{
	int i;
	
	for (i = 0; i < cantidad; i++)
	{
		printf("\nApellido: %s", ag[i].apellido);
		printf("\nNombre: %s", ag[i].nombre);
		printf("\nEdad: %i", ag[i].edad);
		printf("\nSexo: %i", ag[i].sexo);
		printf("\n Precione <ENTER> para continuar");
		getchar();
	}
}
