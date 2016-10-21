#include <iostream>
#include <vector>
using namespace std;

int getDis(vector<int> A, int n)
{
    int i = 0, j = 0;
    int arr[n];
    for(i = 0; i < n; i++)
    {
        arr[i] = 0;
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 2, arr[i] = A[i + 1]; j < n; j++)
        {
            if(A[j] > arr[i])
                arr[i] = A[j];
        }
    }

    for(i = 0; i < n; i++)
        cout << "arr[" << i << "]" << "=" << arr[i] << endl;

    int res = 0;
    for(i = 0; i < n; i++)
    {
        if(res < (arr[i] - A[i]))
            res = arr[i] - A[i];
    }

    return res;
}

int main()
{
    vector<int> A;
    A.push_back(5);
    A.push_back(3);
    A.push_back(6);
    A.push_back(9);
    cout << getDis(A, 4) << endl;
    return 0;
}
