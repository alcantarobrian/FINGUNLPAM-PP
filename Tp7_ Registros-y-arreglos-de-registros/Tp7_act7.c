#include <stdio.h>
#define MAX_PERSONAS 50

// Registro
typedef struct
{
	int nroCuenta;
	char nombre[30];
	long int saldo;
}regPersona;

// Vector de registros
typedef regPersona p[MAX_PERSONAS];

// Funciones
void ingresar(p personas, int);
int opIngreso(p personas, int, int, long int);
int opRetiro(p personas, int, int, long int);
void mostrar(p personas, int, int);

int main()
{
	int cantidad, bcle, op;
	int nroCuenta, operacion, estado, j;
	long int monto;
	p personas;
	bcle = 1;
	
	printf("Cuantas cuentas quiere cargar?: ");
	scanf("%i", &cantidad);
	ingresar(personas, cantidad);
	
	while(bcle)
	{
		printf("\nQue quiere hacer?");
		printf("\n1. Realizar una operación");
		printf("\n2. Imprimir una cuenta");
		printf("\n3. Salir\n");
		scanf("%i", &op);
		
		if(op == 1)
		{
				printf("ingrese el numero de cuenta: ");
				scanf("%i", &nroCuenta);
				
				printf("Ingrese el monto: ");
				scanf("%ld", &monto);
				
				printf("\nQue operacion va a realizar: ");
				printf("\n1. Ingreso");
				printf("\n2. Retiro");
				scanf("%i", &operacion);
				
				if(operacion == 1)
				{
					estado = opIngreso(personas, nroCuenta, cantidad, monto);
					
					if(estado == 0)
					{
						printf("No se encontro la cuenta. Desea agregar una nueva?");
						printf("1. Si");
						printf("2. No");
						scanf("%i", &j);
						
						if(j == 1)
							ingresar(personas, 1);
					}
				}
				
				else
				{
					estado = opRetiro(personas, nroCuenta, cantidad, monto);
				}
		}		
		else if (op == 2)
		{
				printf("\nQue cuenta le gustaria imprimir?");
				printf("\nIngrese el numero de cuenta: ");
				scanf("%i", &nroCuenta);
				
				mostrar(personas, cantidad, nroCuenta);
		}	
		
		else if (op == 3)
		{
			bcle = 0;
		}
	}
}

void ingresar(p personas, int cantidad)
{
	int i;
	
	for(i = 0; i < cantidad; i++)
	{
		printf("Ingrese el numero de cuenta: ");
		scanf("%i", &personas[i].nroCuenta);
		fflush(stdin);
		
		printf("Ingrese el nombre: ");
		gets(personas[i].nombre);
		fflush(stdin);
		
		printf("Ingrese el saldo: ");
		scanf("%ld", &personas[i].saldo);
		fflush(stdin);
	}
}

int opIngreso(p personas, int nroCuenta, int cantidad, long int monto)
{
	int i, estado;
	estado = 0;
	
	for(i = 0; i < cantidad; i++)
	{
		if(personas[i].nroCuenta == nroCuenta)
		{
			estado = 1;
			personas[i].saldo += monto;
		}
	}
	return estado;
}

int opRetiro(p personas, int nroCuenta, int cantidad, long int monto)
{
	int i, estado;
	estado = 0;
	
	for (i = 0; i < cantidad; i++)
	{
		if(personas[i].nroCuenta == nroCuenta)
		{
			estado = 1;
			
			if(personas[i].saldo - monto < -1500)
			{
				while(personas[i].saldo - monto < -1500)
				{
					printf("\nSe excedio el minimo de -1500. Por favor retira menos dinero\n");
					scanf("%ld", &monto);
				}
			
			}
			personas[i].saldo -= monto;
		}
	}
	return estado;
}

void mostrar(p personas, int cantidad, int nroCuenta)
{
	int i;
	
	for(i = 0; i < cantidad; i++)
	{
		if(personas[i].nroCuenta == nroCuenta)
			printf("\nEl saldo en la cuenta es de: %ld\n", personas[i].saldo);
	}
}
