#include <stdio.h>
#include <string.h>
#define CLI "clientes.dat"
#define MED "medicamento.dat"
#define ENF "enfermedad.dat"

typedef struct {
	int historiaClinica;
	int medicamento;
	int dosis;
} med;

typedef struct {
	int historiaClinica;
	int enfermedad;
} enf;

typedef struct {
	int historiaClinica;
	char apeNom[30];
	char nacimiento[30];
	char sexo;
	char obraSocial[30];
} datos;

void agregar_cliente(FILE *, FILE *, FILE *);
void mod_cliente(FILE *, FILE *, FILE *);
void show_cliente(FILE *, FILE *, FILE *);
void buscar_cliente(FILE *);

int main() {
	int bcle, op;
	bcle = 1;
	
	FILE *clientes;
	FILE *medicamentos;
	FILE *enfermedades;
	clientes = fopen(CLI, "rb+");
	medicamentos = fopen(MED, "rb+");
	enfermedades = fopen(ENF, "rb+");
	
	if (clientes == NULL) {
		clientes = fopen(CLI, "wb+");
	}
	if (medicamentos == NULL) {
		medicamentos = fopen(MED, "wb+");
	}
	if (enfermedades == NULL) {
		enfermedades = fopen(ENF, "wb+");
	}
	
	if (clientes != NULL && medicamentos != NULL && enfermedades != NULL) {
		while (bcle) {
			printf("\nMENU");
			printf("\n1. Agregar clientes: ");
			printf("\n2. Modificar datos: ");
			printf("\n3. Listar informacion de clientes: ");
			printf("\n4. Encontrar número de historia clinica de cliente");
			printf("\n5. Salir\n");
			scanf("%i", &op);
			
			switch (op) {
			case 1:
				agregar_cliente(clientes, enfermedades, medicamentos);
				break;
			case 2:
				mod_cliente(clientes, enfermedades, medicamentos);
				break;
			case 3:
				show_cliente(clientes, enfermedades, medicamentos);
				break;
			case 4:
				buscar_cliente(clientes);
				break;
			case 5:
				bcle = 0;
				break;
			}
		}
	} else {
		printf("Ocurrió un error al abrir el archivo");
	}
	fclose(medicamentos);
	fclose(enfermedades);
	fclose(clientes);
	return 0;
}

void agregar_cliente(FILE *clientes, FILE *enfermedades, FILE *medicamentos) {
	int i, j, k, cant1, cont, bcle1, bcle2;
	bcle1 = 1;
	bcle2 = 1;
	cont = 1;
	datos cliente;
	enf enfermedad;
	med medicamento;
	
	printf("¿Cuantos clientes ingresara?: ");
	scanf("%i", &cant1);
	fflush(stdin);
	
	for (k = 0; k < cant1; k++) {
		cliente.historiaClinica = cont;
		bcle1 = 1;
		bcle2 = 1;
		printf("\nIngrese nombre y apellido: ");
		gets(cliente.apeNom);
		fflush(stdin);
		
		printf("\nIngrese la fecha de nacimiento: ");
		gets(cliente.nacimiento);
		fflush(stdin);
		
		printf("\nIngrese sexo: ");
		scanf("%c", &cliente.sexo);
		fflush(stdin);
		
		for (i = 0; i < 4 && bcle1; i++) {
			printf("Ingrese enfermedad(%i): ", i + 1);
			scanf("%i", &enfermedad.enfermedad);
			fflush(stdin);
			if (enfermedad.enfermedad != 0) {
				enfermedad.historiaClinica = cont;
				fwrite(&enfermedad, sizeof(enf), 1, enfermedades);
			} else {
				bcle1 = 0;
			}
		}
		
		rewind(enfermedades);
		
		for (j = 0; j < 3 && bcle2; j++) {
			printf("Ingrese medicamento(%i): ", j + 1);
			scanf("%i", &medicamento.medicamento);
			fflush(stdin);
			if (medicamento.medicamento != 0) {
				printf("Ingrese dosis(%i): ", j);
				scanf("%i", &medicamento.dosis);
				fflush(stdin);
				medicamento.historiaClinica = cont;
				fwrite(&medicamento, sizeof(med), 1, medicamentos);
			} else {
				bcle2 = 0;
			}
		}
		
		printf("Ingrese la obra social: ");
		gets(cliente.obraSocial);
		fflush(stdin);
		
		fwrite(&cliente, sizeof(datos), 1, clientes);
		cont++;
	}
}

void mod_cliente(FILE *clientes, FILE *enfermedades, FILE *medicamentos) {
	int num, bcle1, i, j, op, k;
	long tam1, tam2, tam3;
	datos cliente;
	med medicamento;
	enf enfermedad;
	
	bcle1 = 1;
	
	fseek(clientes, 0, SEEK_END);
	tam1 = ftell(clientes) / sizeof(datos);
	rewind(clientes);
	
	fseek(enfermedades, 0, SEEK_END);
	tam2 = ftell(enfermedades) / sizeof(enf);
	rewind(enfermedades);
	
	fseek(medicamentos, 0, SEEK_END);
	tam3 = ftell(medicamentos) / sizeof(med);
	rewind(medicamentos);
	
	printf("Ingrese el numero de historia clinica: ");
	scanf("%i", &num);
	
	for (i = 0; i < tam1 && bcle1; i++) {
		fread(&cliente, sizeof(datos), 1, clientes);
		if (cliente.historiaClinica == num) {
			printf("¿Quiere modificar el nombre y apellido? (1: Si / 0: No): ");
			scanf("%i", &op);
			fflush(stdin);
			
			if (op == 1) {
				printf("Ingrese el nuevo nombre y apellido: ");
				gets(cliente.apeNom);
				fflush(stdin);
			}
			
			printf("¿Quiere modificar la fecha de nacimiento? (1: Si / 0: No): ");
			scanf("%i", &op);
			fflush(stdin);
			if (op == 1) {
				printf("Ingrese la nueva fecha de nacimiento: ");
				gets(cliente.nacimiento);
				fflush(stdin);
			}
			
			printf("¿Quiere modificar el sexo? (1: Si / 0: No): ");
			scanf("%i", &op);
			fflush(stdin);
			if (op == 1) {
				printf("Ingrese el nuevo sexo: ");
				cliente.sexo = getchar();
				fflush(stdin);
			}
			
			printf("¿Quiere modificar medicamentos? (1: Si / 0: No): ");
			scanf("%i", &op);
			fflush(stdin);
			if (op == 1) {
				for (j = 0; j < tam3; j++) {
					fread(&medicamento, sizeof(med), 1, medicamentos);
					if (medicamento.historiaClinica == cliente.historiaClinica) {
						printf("¿Quiere modificar el medicamento(%i)? (1: Si / 0: No): ", j + 1);
						scanf("%i", &op);
						fflush(stdin);
						if (op == 1) {
							printf("Ingrese el nuevo medicamento: ");
							scanf("%i", &medicamento.medicamento);
							fflush(stdin);
							printf("Ingrese la nueva dosis(%i): ", j + 1);
							scanf("%i", &medicamento.dosis);
							fflush(stdin);
							
							fseek(medicamentos, sizeof(med) * j, SEEK_SET);
							fwrite(&medicamento, sizeof(med), 1, medicamentos);
						}
					}
				}
			}
			
			printf("¿Quiere modificar enfermedades? (1: Si / 0: No): ");
			scanf("%i", &op);
			fflush(stdin);
			if (op == 1) {
				for (k = 0; k < tam2; k++) {
					fread(&enfermedad, sizeof(enf), 1, enfermedades);
					if (enfermedad.historiaClinica == cliente.historiaClinica) {
						printf("¿Quiere modificar la enfermedad(%i)? (1: Si / 0: No): ", k + 1);
						scanf("%i", &op);
						fflush(stdin);
						if (op == 1) {
							printf("Ingrese la nueva enfermedad: ");
							scanf("%i", &enfermedad.enfermedad);
							fflush(stdin);
							fseek(enfermedades, sizeof(enf) * k, SEEK_SET);
							fwrite(&enfermedad, sizeof(enf), 1, enfermedades);
						}
					}
				}
			}
			
			printf("¿Quiere modificar la obra social? (1: Si / 0: No): ");
			scanf("%i", &op);
			fflush(stdin);
			if (op == 1) {
				printf("Ingrese la nueva obra social: ");
				gets(cliente.obraSocial);
				fflush(stdin);
			}
			
			fseek(clientes, sizeof(datos) * i, SEEK_SET);
			fwrite(&cliente, sizeof(datos), 1, clientes);
			bcle1 = 0;
		}
	}
}

void show_cliente(FILE *clientes, FILE *enfermedades, FILE *medicamentos) {
	int i, bcle1, bcle2;
	datos cliente;
	enf enfermedad;
	med medicamento;
	
	fseek(clientes, 0, SEEK_END);
	long tam1 = ftell(clientes) / sizeof(datos);
	rewind(clientes);
	
	fseek(enfermedades, 0, SEEK_END);
	long tam2 = ftell(enfermedades) / sizeof(enf);
	rewind(enfermedades);
	
	fseek(medicamentos, 0, SEEK_END);
	long tam3 = ftell(medicamentos) / sizeof(med);
	rewind(medicamentos);
	
	for (i = 0; i < tam1; i++) {
		fread(&cliente, sizeof(datos), 1, clientes);
		printf("\nCliente: %s", cliente.apeNom);
		printf("\nHistoria clínica: %i", cliente.historiaClinica);
		
		printf("\nEnfermedades: ");
		bcle1 = 1;
		for (int j = 0; j < tam2 && bcle1; j++) {
			fread(&enfermedad, sizeof(enf), 1, enfermedades);
			if (enfermedad.historiaClinica == cliente.historiaClinica) {
				printf("%i ", enfermedad.enfermedad);
				bcle1 = 0;
			}
		}
		
		printf("\nMedicamentos: ");
		bcle2 = 1;
		for (int k = 0; k < tam3 && bcle2; k++) {
			fread(&medicamento, sizeof(med), 1, medicamentos);
			if (medicamento.historiaClinica == cliente.historiaClinica) {
				printf("%i-%i ", medicamento.medicamento, medicamento.dosis);
				bcle2 = 0;
			}
		}
		
		printf("\nObra social: %s", cliente.obraSocial);
	}
}

void buscar_cliente(FILE *clientes){
	int i;
	long tam;
	char nombre[30];
	datos cliente;
	
	fseek(clientes, 0, SEEK_END);
	tam = ftell(clientes)/sizeof(datos);
	rewind(clientes);
	
	fflush(stdin);
	printf("Ingrese el nombre del paciente: ");
	gets(nombre);
	fflush(stdin);
	
	for(i = 0; i < tam; i++){
		fread(&cliente, sizeof(datos), 1, clientes);
		if(strcmp(nombre, cliente.apeNom) == 0){
			printf("El numero de historia clinica es: %i", cliente.historiaClinica);
		}
	}
}
