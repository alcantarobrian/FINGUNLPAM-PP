#include <stdio.h>

void concat(char *, char *, char *);

int main() {
	char s1[] = "Hola, ";
	char s2[] = "Mundo";
	char s3[100];
	
	concat(s1 ,s2 ,s3);
	
	printf("La cadena final es: %s", s3);
	
	return 0;
}

void concat(char *s1, char *s2, char *s3){
	
	if(*s1 != '\0'){
		*s3 = *s1;
		concat(s1 + 1, s2, s3 + 1);
	}
	else{
		if (*s2 != '\0'){
			*s3 = *s2;
			concat(s1, s2 + 1, s3 + 1);
		}
		else{
			*s3 = '\0';
		}
	}
}
