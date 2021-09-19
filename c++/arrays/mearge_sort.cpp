#include <bits/stdc++.h>
using namespace std;
int n;
void mearge(int arr[], int l, int m, int r)
{
    printf("\nentering mearge :- ");
    int n1, n2;
    n1 = m - l + 1;
    n2 = r - m;
    int i, j, k;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        else if (R[j] < L[i])
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    printf("\narray is now :-");
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    printf("...\n");
}

void meargesort(int arr[], int l, int h)
{
    if (l != h)
    {
        printf("\nentering mearge sort :-");
        int m = l + (h - l) / 2;

        meargesort(arr, l, m);
        printf("\narray is now :-");
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        printf("...\n");

        meargesort(arr, m + 1, h);
        printf("\narray is now :-");
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        printf("...\n");

        mearge(arr, l, m, h);
    }
}

int main()
{

    printf("\nsorting the array :-");
    int arr[] = {1, 4, 3, 5, 6, 7, 8, 9, 30, 99, 78};

    n = sizeof(arr) / sizeof(arr[0]);

    meargesort(arr, 0, n - 1);
    cout << "\nelements of array : \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}