#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] ={ 1, 4, 7, 9, 8, 3, 4, 5, 9, 3 }; //1 ,3 ,3 ,4 ,4 ,5 ,7 ,8 ,9 ,9
    int n = sizeof(arr) / sizeof(int);
    sort(arr, arr + n);
    // int *i, *j, *k;
    int s = 20;
    int i, j, k;
    i = 0; //&arr[0];
    // j = n / 2; //&arr[n - 1];
    j = n - 1; //&arr[n / 2];
    while (k < n)
    {
        if (k == i)
        {
            printf(" k%d = i%d \n", k, i);

            i++;
            continue;
        }
        else if (k == j)
        {
            printf("k%d = %dj\n");
            j--;
            continue;
        }

        while (i < j)
        {
            if (arr[i] + arr[j] > s - arr[k])
            {
                //cout<<"arr[i]+arr[j]"<<arr[i] + arr[j]<<"> s - arr[k]"<<s - arr[k];
                j--;
            }
            else if (arr[i] + arr[j] < s - arr[k])
            {
                //cout<<"arr[i]+arr[j]"<<arr[i] + arr[j]<<"< s - arr[k]"<<s - arr[k];
                i++;
            }
            else
            {
                printf("three numbers are : %d %d %d", arr[i], arr[j], arr[k]);
                return 0;
            }
        }
        k++;


    }
    printf("not found");


    return 0;
}