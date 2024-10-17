#include <stdio.h>

void setArray(int [], int);
void sortSelec(int [], int);
void showArray(int [], int);

int main()
{
    int a[15], count;

    printf("Cuantos elementos desea ingresar...? ");
    scanf("%i", &count);

    if(count <= 15)
    {
        printf("Ingrese los elementos: \n");
        setArray(a, count);

        printf("\n");

        printf("El arreglo ordenado es: \n");
        sortSelec(a, count);
        
        printf("\n");
        
        showArray(a, count);
    }

    else
        printf("Excediste la cantidad de elementos que se podian ingresar");
}

void setArray(int a[], int count)
{
    int i;
    
    for (i = 0; i < count; i++)
        scanf("%i", &a[i]);
}

void showArray(int a[], int count)
{
    int i;

    for(i = 0; i < count; i++)
        printf("%i\n", a[i]);
}

void sortSelec(int a[], int count)
{
    int j = 0, i, minimum, posMinimum, temp;
    while (j < count)
    {
        minimum = a[j];
        posMinimum = j;
        for (i = j + 1; i < count; i++) 
        {
            if (minimum > a[i])
            {
                minimum = a[i];
                posMinimum = i;
            }
        }

        temp = a[j];
        a[j] = a[posMinimum];
        a[posMinimum] = temp;
        
        j++;
    }
}  










