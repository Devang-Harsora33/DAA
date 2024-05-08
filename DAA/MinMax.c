#include <stdio.h>

int arr[50];

void minMax(int low, int high, int *min, int *max)
{
    if (low == high)
    {
        *min = *max = arr[low];
    }
    else if (low == high - 1)
    {
        if (arr[low] < arr[high])
        {
            *min = arr[low];
            *max = arr[high];
        }
        else
        {
            *min = arr[high];
            *max = arr[low];
        }
    }
    else
    {
        int mid = (low + high) / 2;
        int leftmax, leftmin, rightmax, rightmin;
        minMax(low, mid, &leftmin, &leftmax);
        minMax(mid + 1, high, &rightmin, &rightmax);

        *min = (rightmin < leftmin) ? rightmin : leftmin;
        *max = (rightmax > leftmax) ? rightmax : leftmax;
    }
}

int main()
{
    int n, min, max;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    minMax(0, n - 1, &min, &max);
    printf("largest number is: %d\n", max);
    printf("smallest number is: %d\n", min);
}