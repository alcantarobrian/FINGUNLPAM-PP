#include <stdio.h>

void elmBlanco(char *);

int main(){
	char string[] = "Hola como estas";
	
	elmBlanco(string);
	
	printf("El string sin espacios en blanco es: %s", string);
	return 0;
}

void elmBlanco(char *str){
	int i;
	i = 0;
	
	if (*str != '\0') {
		if (*str == ' ') {
			while (str[i] != '\0') {
				str[i] = str[i + 1];
				i++;
			}
			elmBlanco(str);
		} else {
			elmBlanco(str + 1);
		}
	}
}