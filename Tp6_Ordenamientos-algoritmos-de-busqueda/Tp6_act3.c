#include <stdio.h>

void setArray(int [], int);
void showArray(int [], int);
void sortBubble(int [], int);

int main()
{
    int a[50], count;
    printf("Ingrese la cantidad de elementos: ");
    scanf("%i", &count);
    setArray(a, count);

    printf("El arreglo ordenado es: \n");
    sortBubble(a, count);
    showArray(a, count);
}  

void setArray(int a[], int count)
{
    int i; 

    for(i = 0; i < count; i++)
    {
        scanf("%i", &a[i]);
    }
}

void showArray(int a[], int count)
{
    int i;

    for(i = 0; i < count; i++)
        printf("%i", a[i]);
}

void sortBubble(int a[], int count)
{
    int i, j, temp, control = 0;

    for(i = 0; i< count - 1; i++)
    {
        for(j = 0; j < count - 1; j++)
            if (a[i] > a[i+1])
            {
                control = 1;
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
    if (control == 0)
        i = count;
    }    
}
