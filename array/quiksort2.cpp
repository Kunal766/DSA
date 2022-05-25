// NOT complited

#include <iostream>
#include <vector>
using namespace std;
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int partion(vector<int> &arr, int f, int l)
{
    int s1 = f + 1;
    int s2 = f + 1;
    while (s1 <= l)
    {
        if (arr[s1] < arr[f])
        {
            s1++;
        }
        if (arr[s2] > arr[f])
        {
            s2++;
        }

        if (arr[s1] >= arr[f] && arr[s2] <= arr[f])
        {
            swap(arr[s1], arr[s2]);
            s1++;
            s2++;
        }
    }
    swap(arr[f], arr[s1]);
    return s1 - 1;
}

void quicksort(vector<int> &arr, int f, int l)
{
    int p = partion(arr, f, l);
    if (l == f)
        return;
    quicksort(arr, f, p - 1);
    quicksort(arr, p + 1, l);
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

    quicksort(arr, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}