#include <stdio.h>
#define DISTANCIA 5000

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

typedef datos d_p[100];
typedef carrera rtdos[100];

int ingresar_datos(d_p datos_personas);
void ingresar_resultados(rtdos resultados, int);
int calcSegundos(s_tiempo tiempo);
float calcVelocidad(int);
void ordenar(rtdos resultados, int);
void mostrar(d_p datos_personas, rtdos resultados, int);

int main()
{
	int bcle, op, cantidad;
	
	d_p datos_maratonistas;
	rtdos resultados;
	
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
			ingresar_resultados(resultados, cantidad);
			break;
			
		case 3:
			ordenar(resultados, cantidad);
			mostrar(datos_maratonistas, resultados, cantidad);
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

void ingresar_resultados(rtdos resultados, int cantidad)
{
	int i;
	
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

int calcSegundos(s_tiempo tiempo)
{
	return ((tiempo.minutos * 60) + tiempo.segundos);
}

float calcVelocidad(int tiempo_segundos)
{
	return (float)DISTANCIA / tiempo_segundos;
}

void ordenar(rtdos resultados, int cantidad)
{
	int i, j, tiempo1, tiempo2;
	carrera temp;
	
	for(i = 0; i < cantidad-1; i++){
		for(j = i + 1; j < cantidad; j++){
			tiempo1 = calcSegundos(resultados[i].tiempo);
			tiempo2 = calcSegundos(resultados[j].tiempo);
			if(tiempo1 > tiempo2){
				temp = resultados[i];
				resultados[i] = resultados[j];
				resultados[j] = temp;
			}
		}
	}
}

void mostrar(d_p datos_personas, rtdos resultados, int cantidad)
{
	int i, tiempoSeg;
	float velocidad;
	
	printf("\n%s %10s %10s %10s %15s %15s\n", "Posicion", "Nro.", "Tiempo", "Velocidad", "Apellido", "Nombre");
	
	for(i = 0; i < cantidad; i++)
	{
		tiempoSeg = calcSegundos(resultados[i].tiempo);
		velocidad = calcVelocidad(tiempoSeg);
		
	
		printf("%-10d %-10d %2d:%02d      %-10.2f %-15s %-15s\n", i + 1,resultados[i].nro_corredor,resultados[i].tiempo.minutos,resultados[i].tiempo.segundos,velocidad, datos_personas[i].apellido,datos_personas[i].nombre);
	}
}
