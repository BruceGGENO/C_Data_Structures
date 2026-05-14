#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int size;
    int capacity;
} DynArray;

void dyn_append(DynArray *da, int value)
{
    if (da->size == da->capacity)
    {
        int *new_data = (int *)realloc(da->data, da->capacity * 2 * sizeof(int));
        if (new_data == NULL)
        {
            exit(1);
        }
        da->data = new_data;
        da->capacity = da->capacity * 2;
    }
    da->data[da->size] = value;
    da->size++;
}

int main()
{
    DynArray da;
    da.size = 0;
    da.capacity = 2;
    da.data = (int *)malloc(da.capacity * sizeof(int));

    printf("Appending values: ");
    for (int i = 1; i <= 5; i++)
    {
        dyn_append(&da, i);
        printf("%d ", i);
    }

    printf("\nFinal array: ");
    for (int i = 0; i < da.size; i++)
    {
        printf("%d ", da.data[i]);
    }
    printf("\nCapacity: %d\n", da.capacity);

    free(da.data);
    return 0;
}