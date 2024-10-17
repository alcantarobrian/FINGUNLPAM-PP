#include <stdio.h>

/*
2.- Escribir las declaraciones necesarias para 
almacenar los datos del Documento Nacional de Identidad.
*/
    
struct dni
{    
    char nombre[20];
    char apellido[20];
    char nacionalidad[20];
    int genero;
    int edad;
    unsigned int nro_dni;
};


int main()
{
    struct dni datos;

    printf("Ingrese el nombre");
    scanf("%s", datos.nombre);

    printf("Ingrese el apellido");
    scanf("%s", datos.apellido);

    printf("Ingrese la nacionalidad");
    scanf("%s", datos.nacionalidad);

    printf("Ingrese el genero");
    scanf("%i", &datos.genero);

    printf("Ingrese la edad");
    scanf("%i", &datos.edad);

    printf("Ingrese el numero de documento");
    scanf("%u", &datos.nro_dni);

    return 0;
}
