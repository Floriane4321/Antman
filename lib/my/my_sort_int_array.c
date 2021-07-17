/*
** EPITECH PROJECT, 2020
** my_sort_int_array.c
** File description:
** sort and list of int
*/

void my_putchar(char );

int array_sort(int *arr, int size, int i)
{
    if (i == size - 1)
        return (1);
    if (arr[i] > arr[i + 1])
        return (0);
    else
        return (array_sort(arr, size, i + 1));
}

void my_sort_int_array(int *arr, int size)
{
    int tmp = 0;

    for (int i = 0; 1 + i < size; i++)
        if ( arr[i] > arr[i + 1]) {
            tmp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = tmp;
        }
    if (array_sort(arr, size, 0) == 1)
        return;
    else
        my_sort_int_array(arr, size);
}
