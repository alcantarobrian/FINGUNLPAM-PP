#include <stdio.h>

int caracString(char *, char, int);

int main(int argc, char *argv[]) {
	
	char c ,string[100] = "Hola mundo";
	int pos = 0;
	
	c = 'a';
	pos = caracString(string, c, pos);
	
	if (pos != -1){
		printf("El caracter %c se encuentra en la posicion: '%i' de el string: '%s'", c, pos, string);
	}
	else{
		printf("El caracter no se encuentra en el string");
	}
	
	return 0;
}

int caracString(char *str, char c, int pos){
	
	if(*str == '\0'){
		return -1;
	}
	if (*str == c){
		return pos;
	}
	
	return caracString(str+1, c, pos+1);
}

