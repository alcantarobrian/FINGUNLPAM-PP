#include <stdio.h>
#include <string.h>
#define MAX_AUTORES 10

// Registro
typedef struct
{
	char titulo[30];
	int cantAutores;
	char autores[10][20];
	char editorial[30];
	int fPublicacion;
	int nCatalogo;

}reglibro;

// Arreglos de registros
typedef reglibro libros[50];

// Funciones
void ingresarLibros(libros biblioteca, int);
void mostrarLibros(libros biblioteca, int);
void ordenar(libros biblioteca, int);
void buscarAutor(libros biblioteca, int, char []);
void buscarEditorial(libros biblioteca, int, char []);
void imprimir(libros biblioteca, int, int, int);

int main()
{
	libros biblioteca;
	
	int cantidad, bcle1, bcle2, op1, op2, principio, fin;
	char autorBuscar[20];
	char editorialBuscar[30];
	bcle1 = 1;
	bcle2 = 1;
	
	//Ingreso de libros
	printf("Cuantos libros ingresará?: ");
	scanf("%i", &cantidad);
	ingresarLibros(biblioteca, cantidad);

	while(bcle1)
	{
		printf("\n\n1. Imprimir ordenados por fecha de publicacion");
		printf("\n2. Imprimir libros segun autores o editoriales");
		printf("\n3. Imprimir libros comprendidos entre 2 numeros de catalogos");
		printf("\n4. Salir");
		printf("\ningrese opcion: ");
		scanf("%i", &op1);
		
		switch(op1)
		{
		case 1:
			ordenar(biblioteca, cantidad);
			mostrarLibros(biblioteca, cantidad);
			break;
			
		case 2:
			while(bcle2)
			{
				printf("\nComo quiere buscar?");
				printf("\n1. Por autor");
				printf("\n2. Por editoral");
				printf("\n3. salir\n");
				scanf("%i", &op2);
				
				switch(op2)
				{
					case 1:
						printf("\nIngrese el nombre del autor: ");
						scanf("%s", autorBuscar);
						buscarAutor(biblioteca, cantidad, autorBuscar);
						break;
						
					case 2:
						printf("\nIngrese el nombre de la editorial: ");
						scanf("%s", editorialBuscar);
						buscarEditorial(biblioteca, cantidad, editorialBuscar);
						break;
				
					case 3:
						bcle2 = 0;
						break;
				}
			}
		
		case 3:
				printf("Ingrese el principio");
				scanf("%i", &principio);
				
				printf("Ingrese el fin");
				scanf("%i", &fin);

				imprimir(biblioteca, cantidad, principio, fin);
				break;
			
		case 4:
			bcle1 = 0;
			break;
		}
	}
	return 0;
}

void ingresarLibros(libros biblioteca, int cantidad)
{
	int i, j;
	
	for(i = 0; i < cantidad; i++)
	{
		printf("\nIngrese el titulo: ");
		scanf("%s", biblioteca[i].titulo);
		
		printf("\nCuantos autores ingresara?: ");
		scanf("%i", &biblioteca[i].cantAutores);

		if(biblioteca[i].cantAutores > MAX_AUTORES)
		{
			printf("Se excedio la cantidad de autores permitidos, el valor ingresado se cambiara a %i\n", MAX_AUTORES);
			biblioteca[i].cantAutores = MAX_AUTORES;
		}
		
		for(j = 0; j < biblioteca[i].cantAutores; j++)
		{
			printf("Ingrese el autor %i: ", j+1);
			scanf("%s", biblioteca[i].autores[j]);
		}
		
		printf("\nIngrese la editorial: ");
		scanf("%s", biblioteca[i].editorial);
		
		printf("\nIngrese la fecha de publicacion: ");
		scanf("%i", &biblioteca[i].fPublicacion);
		
		printf("\nIngrese el numero de catalogo: ");
		scanf("%i", &biblioteca[i].nCatalogo);
	}
}

void mostrarLibros(libros biblioteca, int cantidad)
{
	int i, j;
	
	for(i = 0; i < cantidad; i++)
	{
		printf("\n\nTitulo: %s", biblioteca[i].titulo);
		printf("\nCantidad de autores: %i", biblioteca[i].cantAutores);
		
		for (j = 0; j < biblioteca[i].cantAutores; j++)
		{
			printf("\nAutor %i: %s", j+1, biblioteca[i].autores[j]);
		}
		
		printf("\nEditorial: %s", biblioteca[i].editorial);
		printf("\nFecha de publicacion: %i", biblioteca[i].fPublicacion);
		printf("\nNumero de catalogo: %i", biblioteca[i].nCatalogo);
	}
}

void ordenar(libros biblioteca, int cantidad)
{
	int i, j, bandera;
	reglibro temp;
	
	for(i = 0; i < cantidad && bandera; i++)
	{
		bandera = 0;
		
		for(j = 0; j < cantidad-1-i; j++)
		{
			if(biblioteca[j].fPublicacion > biblioteca[j+1].fPublicacion)
			{
				temp = biblioteca[j];
				biblioteca[j] = biblioteca[j+1];
				biblioteca[j+1] = temp;
				bandera = 1;
			}
		}
	}
}

void buscarAutor(libros biblioteca, int cantidad, char bAutor[])
{
	int i, j;
	
	for (i = 0; i < cantidad; i++)
	{
		for(j = 0; j < biblioteca[i].cantAutores; j++)
		{
			if(strcmp(biblioteca[i].autores[j], bAutor) == 0)
			{
				printf("\nTitulo: %s", biblioteca[i].titulo);
			}
		}
	}
}

void buscarEditorial(libros biblioteca, int cantidad, char bEditorial[])
{
	int i;
	
	for (i = 0; i < cantidad; i++)
	{
		if(strcmp(biblioteca[i].editorial, bEditorial) == 0)
		{
			printf("\nTitulo: %s", biblioteca[i].titulo);
		}
	}
}

void imprimir(libros biblioteca, int cantidad, int principio, int fin)
{
	int i;
	
	for (i = 0; i < cantidad; i++)
	{
		if (principio < biblioteca[i].nCatalogo && fin > biblioteca[i].nCatalogo)
			printf("\nTitulo: %s", biblioteca[i].titulo);
	}
}
