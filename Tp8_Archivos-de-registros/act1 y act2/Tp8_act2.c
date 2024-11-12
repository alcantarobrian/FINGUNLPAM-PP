#include <stdio.h>
#define ACT1 "C:\\Users\\yziyn\\Documents\\Programando en C\\FINGUNLPAM-PP\\Tp8_Archivos-de-registros\\ACT1"
#define ACT2 "Tp8_act2.dat"

/*
2.- Escribir un programa que a partir del archivo del punto anterior genere otro archivo el cual este 
ordenado por Numero de Legajo en orden creciente y al finalizar liste el mismo. 
*/

typedef struct {
	int legajo;
	char apeNom[30];
	int ingreso;
	int nota1;
	int nota2;
}datos;

void act1ToAct2(FILE *act1, FILE *act2);
void ordenar(FILE *act2);
void show(FILE *act2);

int main(){
	FILE *act1;
	FILE *act2;
	act1 = fopen("ACT1", "rb");
	act2 = fopen("ACT2", "wb+");
	
	if(act1 != NULL && act2 != NULL){
		act1ToAct2(act1, act2);
		ordenar(act2);
		show(act2);
	}
	else{
		printf("Error al leer algun archivo");
	}
	
	fclose(act1);
	fclose(act2);
}
	
void act1ToAct2(FILE *act1, FILE *act2){
	int i, tam;
	datos alu1;
	
	fseek(act1, 0, SEEK_END);
	tam = ftell(act1)/sizeof(datos);
	rewind(act1);
	
	for(i = 0; i < tam; i++){
		fread(&alu1, sizeof(datos), 1, act1);
		fwrite(&alu1, sizeof(datos), 1, act2);
	}
}
	
void show(FILE *act2){
	int i;
	long tam;
	datos alumno;
	
	fseek(act2, 0, SEEK_END);
	tam = ftell(act2)/sizeof(datos);
	rewind(act2);
	
	for(i = 0; i < tam; i++){
		fread(&alumno, sizeof(datos), 1, act2);
		printf("\nNumero de legajo: %i", alumno.legajo);
		printf("\nNombre y apellido: %s", alumno.apeNom);
		printf("\nAño de ingreso: %i", alumno.ingreso);
		printf("\nNota parcial 1: %i", alumno.nota1);
		printf("\nNota parcial 2: %i", alumno.nota2);
	}
}
	
void ordenar(FILE *act2){
	int i, j;
	long tem;
	datos alu1, alu2;
	
	fseek(act2, 0, SEEK_END);
	tem = ftell(act2)/sizeof(datos);
	rewind(act2);
	
	for(i = 0; i < tem-1; i++){
		for(j = 0; j < tem-i-1; j++){
			fseek(act2, sizeof(datos)*j, SEEK_SET);
			fread(&alu1, sizeof(datos), 1, act2);
			
			fseek(act2, sizeof(datos)*(j+1), SEEK_SET);
			fread(&alu2, sizeof(datos), 1, act2);
			
			if(alu1.ingreso > alu2.ingreso){
				fseek(act2, sizeof(datos)*j, SEEK_SET);
				fwrite(&alu2, sizeof(datos), 1,act2);
				
				fseek(act2, sizeof(datos)*j+1, SEEK_SET);
				fwrite(&alu1, sizeof(datos), 1, act2);
			}
		}
	}
}