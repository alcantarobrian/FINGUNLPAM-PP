#include <stdio.h>

/*

.- Hacer un programa que ingrese dos vectores de dimensiones n y m, los ordene de menor a mayor
por el método burbuja y luego los mezcle en un tercero también ordenado. Debe imprimirse los dos
vectores ingresados, ya ordenados y el vector resultante de la mezcla.

*/

void setArray(int [], int);
void sortMerge(int [], int [], int[], int, int);
void sortBubble(int [], int);
void showArray(int [], int);

int main()
{
    int a[50], b[50], c[100], countA, countB, countC;

    printf("Cuantos elementos tendrá el vector A...?: ");
    scanf("%i", &countA);
    printf("Ingrese los elementos: ");
    setArray(a, countA);

    printf("Cuantos elementos tendrá el vector B...?: ");
    scanf("%i", &countB);
    printf("Ingrese los elementos: ");
    setArray(b, countB);

    printf("\n");

	countC = countA + countB;
	
    printf("El vector A ordenado es: ");
    sortBubble(a, countA);
    showArray(a, countA);

    printf("\n");

    printf("El vector B ordenado es: ");
    sortBubble(b, countB);
    showArray(b, countB);

    printf("\n");

    printf("El vector C ordenado es: ");
    sortMerge(a, b, c, countA, countB);
    showArray(c, countC);

    return 0;
}

void setArray(int a[], int count)
{
    int i;
    for(i = 0; i < count; i++)
        scanf("%i", &a[i]);
}

void showArray(int a[], int count)
{
    int i;

    for(i = 0; i < count; i++)
        printf("%i\n", a[i]);
}

void sortBubble(int a[], int count)
{
    int i, j, temp;

    for(j = 0; j < count - 1; j++)
    {
        for(i = 0; i < count - 1; i++)
        {
            if (a[i] > a[i+1])
            {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
}

void sortMerge(int a[], int b[], int c[], int countA, int countB) 
{
    int i = 0, j = 0, n = 0;

    while (i < countA && j < countB)
    {
        if(a[i] <= b[j])
        {
            c[n] = a[i];
            i++;
        }
        else
        {
            c[n] = b[j];
            j++;
        }
		n++;
    }

    while (i < countA)
    {
        c[n] = a[i];
        i++;
        n++;
    }

    while (j < countB)
    {
        c[n] = b[j];
        j++;
        n++;
    }

}
