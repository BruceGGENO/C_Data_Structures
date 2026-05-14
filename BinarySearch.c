#include <stdio.h>

int binary_search(int *arr, int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int targets[] = {12, 45, 100, 2, 67};
    int num_targets = sizeof(targets) / sizeof(targets[0]);

    for (int i = 0; i < num_targets; i++)
    {
        int result = binary_search(arr, n, targets[i]);
        if (result != -1)
        {
            printf("Target %d found at index %d\n", targets[i], result);
        }
        else
        {
            printf("Target %d not found\n", targets[i]);
        }
    }

    return 0;
}