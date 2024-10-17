#include <stdio.h>

// Registros:
typedef struct
{
	char apellido[20];
	char nombre[20];
	char direccion[10];
	int telefono;
	int cuenta;
}p;

typedef p ag[50];

// Funciones:
void ingresar(p ag[], int cantidad);
void ordenar(p ag[], int cantidad);
void imprimir(p ag[], int cantidad);

int main()
{
	ag agenda;
	int cantidad;
	
	printf("Cuantas personas desea ingresar: ");
	scanf("%i", &cantidad);
	
	ingresar(agenda, cantidad);
	
	ordenar(agenda, cantidad);
	imprimir(agenda, cantidad);
}

void ingresar(p ag[], int cantidad)
{
	int i;
	
	for (i = 0; i < cantidad; i++)
	{
		printf("Ingrese apellido: ");
		scanf("%s", ag[i].apellido);
		
		printf("Ingrese nombre: ");
		scanf("%s", ag[i].nombre);
		
		printf("Ingrese direccion: ");
		scanf("%s", ag[i].direccion);
		
		printf("Ingrese telefono: ");
		scanf("%i", &ag[i].telefono);
		
		printf("Ingrese numero de cuenta: ");
		scanf("%i", &ag[i].cuenta);
		printf("\n");
	}
}

// Ordena el vector de registros
void ordenar(p ag[], int cantidad)
{
	p temp;
	int i, j;
	for(i = 0; i < cantidad-1; i++)
	{
		for(j = 0; j < cantidad-1-i; j++)
		{
			if(ag[j].cuenta > ag[j+1].cuenta)
			{
				temp = ag[j];
				ag[j] = ag[j+1];
				ag[j+1] = temp;
			}
		}
	}
}

// Imprimir vector
void imprimir(p ag[], int cantidad)
{
	int i;
	
	for (i = 0; i < cantidad; i++)
	{
		printf("\nApellido: %s", ag[i].apellido);
		printf("\nNombre: %s", ag[i].nombre);
		printf("\nDireccion: %s", ag[i].direccion);
		printf("\nTelefono: %i", ag[i].telefono);
		printf("\nNumero de cuenta: %i", ag[i].cuenta);
		printf("\n");
	}
}
