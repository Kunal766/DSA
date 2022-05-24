#include <iostream>
#include <vector>
using namespace std;
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int partion(vector<int> &arr, int f, int l)
{
    int x = f - 1;
    int p = arr[f - 1];
    while (f <= l)
    {
        if (arr[f] < p)
        {
            f++;
        }
        if (arr[l] >= p)
        {
            l--;
        }
        if (arr[l] < p && arr[f] >= p)
        {
            swap(arr[f], arr[l]);
        }
    }

    swap(arr[l], arr[x]);

    return l;
}

void quicksort(vector<int> &arr, int f, int l)
{
    int p;
    if (f >= l)
        return;

    p = partion(arr, f, l);

    quicksort(arr, f, p - 1);
    quicksort(arr, p + 2, l);
}

int main()
{

    int N, num;
    cin >> N;
    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        arr.push_back(num);
    }

    quicksort(arr, 1, N - 1);
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}