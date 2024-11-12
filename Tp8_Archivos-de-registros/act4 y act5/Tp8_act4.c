#include <stdio.h>
#include <string.h>
#define CLI "clientes.dat"
#define MED "medicamento.dat"
#define ENF "enfermedad.dat"

typedef struct {
	int historiaClinica;
	int medicamento;
	int dosis;
}med;

typedef struct {
	int historiaClinica;
	int enfermedad;
}enf;

typedef struct {
	int historiaClinica;
	char apeNom[30];
	char nacimiento[30];
	char sexo;
	char obraSocial[30];
}datos;

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
	clientes = fopen(CLI, "wb+");
	medicamentos = fopen(MED, "wb+");
	enfermedades = fopen(ENF, "wb+");
	
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
				//buscar_cliente(clientes);
				break;
			case 5:
				bcle = 0;
				break;
			}
		}
	} 
	else {
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
		for(i = 0; i < 4 && bcle1; i++){
			printf("Ingrese enfermedad(%i)", i+1);
			scanf("%i", &enfermedad.enfermedad);
			fflush(stdin);
			if(enfermedad.enfermedad != 0){
				enfermedad.historiaClinica = cont;
				fwrite(&enfermedad, sizeof(enf), 1, enfermedades);
			}
			else{
				bcle1 = 0;
			}
		}
		rewind(enfermedades);
		for(j = 0; j < 3 && bcle2; j++){
			printf("Ingrese medicamento(%i): ", j+1);
			scanf("%i", &medicamento.medicamento);
			fflush(stdin);
			if(medicamento.medicamento != 0){
				printf("Ingrese dosis(%i): ", j);
				scanf("%i", &medicamento.dosis);
				fflush(stdin);
				medicamento.historiaClinica = cont;
				fwrite(&medicamento, sizeof(med), 1, medicamentos);
			}
			else{
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
	tam1 = ftell(clientes)/sizeof(datos);
	rewind(clientes);
	
	fseek(enfermedades, 0, SEEK_END);
	tam2 = ftell(enfermedades)/sizeof(enf);
	rewind(enfermedades);
	
	fseek(medicamentos, 0, SEEK_END);
	tam3 = ftell(medicamentos)/sizeof(med);
	rewind(medicamentos);
	
	printf("Ingrese el numero de historia clinica: ");
	scanf("%i", &num);
	
	for (i = 0; i < tam1 && bcle1; i++) {
		fread(&cliente, sizeof(datos), 1, clientes);
		if (cliente.historiaClinica == num) {
			printf("¿Quiere modificar el nombre y apellido?");
			scanf("%i", &op);
			fflush(stdin);
			
			if(op == 1){
				printf("Ingrese el nuevo nombre y apellido: ");
				gets(cliente.apeNom);
				fflush(stdin);
			}
			printf("¿Quiere modificar la fecha de nacimiento?");
			scanf("%i", &op);
			fflush(stdin);
			if(op == 1){
				printf("Ingrese la nueva fecha de nacimiento: ");
				gets(cliente.nacimiento);
				fflush(stdin);
				fwrite(&cliente, sizeof(datos)*i, 1, clientes);
			}
			
			printf("¿Quiere modificar el sexo: ?");
			scanf("%i", &op);
			fflush(stdin);
			if(op == 1){
				printf("Ingrese el nuevo sexo: ");
				cliente.sexo = getchar();
				fflush(stdin);
				fwrite(&cliente, sizeof(datos)*i, 1, clientes);
			}
			
			printf("¿Quiere modificar medicamentos?: ");
			scanf("%i", &op);
			fflush(stdin);
			if(op == 1){
				fread(&medicamento, sizeof(med), 1, medicamentos);
				for(j = 0; j < tam3; j++){
					if(medicamento.historiaClinica == cliente.historiaClinica){
						printf("¿Quiere modificar el medicamento(%i)?: ", j+1);
						scanf("%i", &op);
						fflush(stdin);
						if(op == 1){
							printf("Ingrese el nuevo medicamento: ");
							scanf("%i", &medicamento.medicamento);
							fflush(stdin);
							printf("Ingrese la dosis(%i)", j+1);
							scanf("%i", &medicamento.dosis);
							fflush(stdin);
							
							fseek(medicamentos, sizeof(med) * j, SEEK_SET);
							fwrite(&medicamento, sizeof(med), 1, medicamentos);
						}
					}
				}
			}
			printf("¿Quiere modificar enfermedades?: ");
			scanf("%i", &op);
			fflush(stdin);
			if(op == 1){
				fread(&enfermedad, sizeof(enf), 1, enfermedades);
				for(k = 0; k < tam2; k++){
					if(enfermedad.historiaClinica == cliente.historiaClinica){
						printf("¿Quiere modificar la enfermedad(%i)?: ", k+1);
						scanf("%i", &op);
						fflush(stdin);
						if(op == 1){
							printf("Ingrese la nueva enfermedad: ");
							scanf("%i", &enfermedad.enfermedad);
							fflush(stdin);
							fseek(enfermedades, sizeof(enf) * k, SEEK_SET);
							fwrite(&enfermedad, sizeof(enf), 1, enfermedades);
						}
					}
				}
			}
			printf("¿Quiere modificar la obra social: ?");
			scanf("%i", &op);
			fflush(stdin);
			if(op == 1){
				printf("Ingrese la nueva obra social: ");
				gets(cliente.obraSocial);
				fflush(stdin);
			}
			
			bcle1 = 0;
			
			fseek(clientes, sizeof(datos) * i, SEEK_SET);
			fwrite(&cliente, sizeof(datos), 1, clientes);
		}
	}
	if (bcle1 == 1 && i >= tam1){
		printf("\nCLIENTE NO ENCONTRADO\n");
	}
}

void show_cliente(FILE *clientes, FILE *enfermedades, FILE *medicamentos) {
	int i, j, k, n1, n2;
	long tam1, tam2, tam3;
	
	datos cliente;
	enf enfermedad;
	med medicamento;
	
	n1 = 0;
	n2 = 0;
	
	fseek(clientes, 0, SEEK_END);
	tam1 = ftell(clientes) / sizeof(datos);
	rewind(clientes);
	
	fseek(enfermedades, 0, SEEK_END);
	tam2 = ftell(enfermedades) / sizeof(enf);
	rewind(enfermedades);
	
	fseek(medicamentos, 0, SEEK_END);
	tam3 = ftell(medicamentos) / sizeof(med);
	rewind(medicamentos);
	
	for (i = 0; i < tam1; i++) {
		fread(&cliente, sizeof(datos), 1, clientes);
		printf("\nNombre: %s", cliente.apeNom);
		printf("\nNacimiento: %s", cliente.nacimiento);
		printf("\nSexo: %c", cliente.sexo);
		
		while(fread(&enfermedad, sizeof(enf), 1, enfermedades)){
			if(enfermedad.historiaClinica == cliente.historiaClinica){
				printf("\nEnfermedad(%i) %i", n1+1 ,enfermedad.enfermedad);
				n1++;
			}
		}
		
		while(fread(&medicamento, sizeof(med), 1, medicamentos)){
			if(medicamento.historiaClinica == cliente.historiaClinica){
				printf("\nMedicamento(%i): %i", n2+1, medicamento.medicamento);
				printf("\nDosis(%i): %i", n2+1, medicamento.dosis);
			}
		}
		
		/*
		for(j = 0; j < tam2; j++){
			fread(&enfermedad, sizeof(enf), 1, enfermedades);
			if(enfermedad.historiaClinica == cliente.historiaClinica){
				if(enfermedad.enfermedad != 0){
					printf("\nEnfermedad(%i): %i", j+1, enfermedad.enfermedad);
				}
			}
			rewind(enfermedades);
		}
		for(k = 0; k < tam3; k++){
			fread(&medicamento, sizeof(med), 1, medicamentos);
			if(medicamento.historiaClinica == cliente.historiaClinica){
				if(medicamento.medicamento != 0){
					printf("\nMedicamento(%i): %i", k+1, medicamento.medicamento);
					printf("\nDosis(%i): %i", k+1, medicamento.dosis);
				}
			}
			rewind(medicamentos);
		}
		*/
		
		if (strcmp(cliente.obraSocial, "") != 0) {
			printf("\nObra social: %s", cliente.obraSocial);
		}
	}
}
/*
void buscar_cliente(FILE *archivo) {
	int i, bcle;
	char nombre[30];
	long tam;
	datos cliente;
	bcle = 1;
	i = 0;
	
	fseek(archivo, 0, SEEK_END);
	tam = ftell(archivo) / sizeof(datos);
	rewind(archivo);
	
	printf("Ingrese el nombre: ");
	fflush(stdin);
	gets(nombre);
	
	for (i = 0; i < tam && bcle; i++) {
		fread(&cliente, sizeof(datos), 1, archivo);
		if (strcmp(nombre, cliente.apeNom) == 0) {
			printf("Numero de historia clinica: %i", cliente.historiaClinica);
			bcle = 0;
		}
	}
}
*/