#include <stdio.h>

// registros
typedef struct
{
	int minutos;
	int segundos;
}s_tiempo;

typedef struct
{
	int nro_corredor;
	s_tiempo tiempo;
}carrera;

typedef struct
{
	int nro_corredor;
	char apellido[20];
	char nombre[20];
	char direccion[30];
}datos;

// arreglo de registros
typedef datos d_p[100];
typedef carrera rtdos[100];

int ingresar_datos(d_p datos_personas);
void ingresar_resultados(rtdos resultados, int);
void calcular_velocidad(rtdos resultados, int);

int main()
{
	int bcle, op, cantidad;

	d_p datos_maratonistas;
	
	bcle = 1;
	
	while(bcle){
		printf("\n1. Ingresar datos de maratonistas inscriptos");
		printf("\n2. Ingresar datos del resultado de la maratón");
		printf("\n3. Mostrar un listado con los resultados de la maratón");
		printf("\n4. Salir");
		printf("\nSeleccion: ");
		scanf("%i", &op);
		
		switch(op){
		case 1:
			cantidad = ingresar_datos(datos_maratonistas);
			break;
		case 2:
			break;

		case 3:
			break;

		case 4:
			printf("FIN DE PROGRAMA");
			bcle = 0;
			break;
		}
	}
	
	return 0;
}

int ingresar_datos(d_p datos_personas)
{
	int i, cantidad;
	
	printf("¿Cuantos maratonistas ingresará?: ");
	scanf("%i", &cantidad);
	
	for(i = 0; i < cantidad; i++)
	{
		printf("Ingrese el número del corredor: ");
		scanf("%i", &datos_personas[i].nro_corredor);
		fflush(stdin);
		
		printf("Ingrese el apellido: ");
		scanf("%s", datos_personas[i].apellido);
		fflush(stdin);
		
		printf("Ingrese el nombre: ");
		scanf("%s", datos_personas[i].nombre);
		fflush(stdin);
		
		printf("Ingrese la direccion: ");
		gets(datos_personas[i].direccion);
		fflush(stdin);
	}
	
	return cantidad;
}

int ingresar_resultados(rtdos resultados, int cantidad)
{
	int i;
	float velocidad;
	
	for(i = 0; i < cantidad; i++)
	{
		printf("Ingrese el numero del corredor: ");
		scanf("%i", &resultados[i].nro_corredor);
		
		printf("Ingrese los minutos tardados: ");
		scanf("%i", &resultados[i].tiempo.minutos);
		
		printf("Ingrese los segundos tardados: ");
		scanf("%i", &resultados[i].tiempo.segundos);
	}
}

