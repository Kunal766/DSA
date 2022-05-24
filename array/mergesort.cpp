#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int f, int mid, int l)
{
    int s1 = f;
    int s2 = mid + 1;
    vector<int> temp;
    while (s1 <= mid && s2 <= l)
    {
        if (arr[s1] <= arr[s2])
        {
            temp.push_back(arr[s1]);
            s1++;
        }
        if (arr[s1] > arr[s2])
        {
            temp.push_back(arr[s2]);
            s2++;
        }
    }

    while (s1 <= mid)
    {
        temp.push_back(arr[s1]);
        s1++;
    }

    while (s2 <= l)
    {
        temp.push_back(arr[s2]);
        s2++;
    }

    for (int i = f; i <= l; i++)
    {
        arr[i] = temp[i - f];
    }
}

void mergesort(vector<int> &arr, int f, int l)
{
    int mid = (f + l) / 2;
    if (f == l)
        return;

    mergesort(arr, f, mid);
    mergesort(arr, mid + 1, l);
    merge(arr, f, mid, l);
}

int main()
{
    vector<int> arr;
    int N, num;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        arr.push_back(num);
    }

    mergesort(arr, 0, N - 1);
    cout << endl;
    for (int i = 0; i < N; i++)
    {

        cout << arr[i] << endl;
    }

    return 0;
}
