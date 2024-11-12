#include <stdio.h>
#include <string.h>
#define ARCH1 "Tp8_act3-1.dat"
#define ARCH2 "Tp8_act3-2.dat"
#define ARCH3 "Tp8_act3-3.dat"

/*
3.- Escribir un programa que permita cargar dos archivos de números enteros en orden ascendente. Y 
por medio de un procedimiento de mezcla generar un tercer archivo con todos los elementos de los 
archivos cargados debiendo este nuevo archivo tener sus elementos en orden ascendente. 
Nota: Hacer una función de listado para ver el contenido de cada uno de los tres archivos. 
*/

void set_arch1(FILE *);
void set_arch2(FILE *);
void show_arch(FILE *);
void merge_arch3(FILE *, FILE *, FILE *);
void ordenar(FILE *);

int main() {
	FILE *arch1;
	FILE *arch2;
	FILE *arch3;
	
	arch1 = fopen("ARCH1", "wb+");
	arch2 = fopen("ARCH2", "wb+");
	arch3 = fopen("ARCH3", "wb+");
	
	if(arch1 != NULL && arch2 != NULL && arch3 != NULL){
		set_arch1(arch1);
		set_arch2(arch2);
		
		printf("archivo(1):\n");
		show_arch(arch1);
		
		printf("\n");
		
		printf("archivo(2):\n");
		show_arch(arch2);
		
		ordenar(arch1);
		ordenar(arch2);
		
		printf("\narchivo(3): \n");
		
		merge_arch3(arch1, arch2, arch3);
		show_arch(arch3);
		
	}
	else{
		printf("Hubo un error al abrir algun archivo");
	}
	
	fclose(arch1);
	fclose(arch2);
	fclose(arch3);
	
	return 0;
}

void set_arch1(FILE *arch1){
	int bcle;
	int num;
	bcle = 1;
	
	printf("Ingrese los numeros enteros archivo(1): ");
	while(bcle){
		scanf("%i", &num);
		if(num != 0){
			fwrite(&num, sizeof(int), 1, arch1);
		}
		
		else{
			bcle = 0;
		}
	}
}

void set_arch2(FILE *arch2){
	int bcle;
	int num;
	bcle = 1;
		
	printf("Ingrese los numeros enteros archivo(2): ");
	while(bcle){
		scanf("%i", &num);
		if(num != 0){
			fwrite(&num, sizeof(int), 1, arch2);
		}
			
		else{
			bcle = 0;
		}
	}
}

void show_arch(FILE *arch){
	int num, i;
	long tam;
	
	fseek(arch, 0, SEEK_END);
	tam = ftell(arch)/sizeof(int);
	rewind(arch);
	
	for(i = 0; i < tam; i++){
		fread(&num, sizeof(int), 1, arch);
		printf("\n%i", num);
	}
}
	
void ordenar(FILE *arch){
	int tam, i, j;
	int num1, num2;
	
	fseek(arch, 0, SEEK_END);
	tam = ftell(arch)/sizeof(int);
	rewind(arch);
	
	for(i = 0; i < tam-1; i++){
		for(j = 0; j < tam-i-1; j++){
			fseek(arch, sizeof(int) * j, SEEK_SET);
			fread(&num1, sizeof(int), 1, arch);
			
			fseek(arch, sizeof(int) * (j+1), SEEK_SET);
			fread(&num2, sizeof(int), 1, arch);
			
			if(num1 > num2){
				fseek(arch, sizeof(int) * j, SEEK_SET);
				fwrite(&num2, sizeof(int), 1, arch);
				
				fseek(arch, sizeof(int) * (j+1), SEEK_SET);
				fwrite(&num1, sizeof(int), 1, arch);
			}
		}
	}
	
}

void merge_arch3(FILE *arch1, FILE *arch2, FILE *arch3){
	int i = 0, j = 0, k = 0, num1, num2;
	long tam1, tam2;
	
	fseek(arch1, 0, SEEK_END);
	tam1 = ftell(arch1)/sizeof(int);
	rewind(arch1);
	
	fseek(arch2, 0, SEEK_END);
	tam2 = ftell(arch2)/sizeof(int);
	rewind(arch2);
	
	while(i < tam1 && j < tam2){
		fseek(arch1, sizeof(int)*i, SEEK_SET);
		fread(&num1, sizeof(int), 1, arch1);
		fseek(arch2, sizeof(int)*j, SEEK_SET);
		fread(&num2, sizeof(int), 1, arch2);
		
		if(num1 < num2){
			fseek(arch3, sizeof(int) * k, SEEK_SET);
			fwrite(&num1, sizeof(int), 1, arch3);
			i++;
		}
		else{
			fseek(arch3, sizeof(int) * k, SEEK_SET);
			fwrite(&num2, sizeof(int), 1, arch3);
			j++;
		}
		k++;
	}
	
	while(i < tam1){
		fread(&num1, sizeof(int), 1, arch1);
		fwrite(&num1, sizeof(int), 1, arch3);
		i++;
	}
	
	while(j < tam2){
		fread(&num2, sizeof(int), 1, arch2);
		fwrite(&num2, sizeof(int), 1, arch3);
		j++;
	}
}