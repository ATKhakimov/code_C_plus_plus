
#include <iostream>

//#include <vector>

using std::cout;
using std::endl;
//using std::string;
using std::cin;

void printarr(int *array, int n)
{
    for (int i = 0; i < n; i++)
        cout << array[i] << endl;
}

bool cmp(int a, int b, bool r){
    if (r == false){
        return a < b;
    } else {
        return a > b;
    }
}

void qqsort(int * arr, int start, int end, bool reverse) {
  int mid, count;
  int f = start, l = end;
  mid = arr[(f + l) / 2]; 
  do {
    while (cmp(mid, arr[f], reverse)) f++;
    while (cmp(arr[l], mid, reverse)) l--;
    if (f <= l) 
    {
      count = arr[f];
      arr[f] = arr[l];
      arr[l] = count;
      f++;
      l--;
    }
  } while (f < l);
  if (start < l) qqsort(arr, start, l, reverse);
  if (f < end) qqsort(arr, f, end, reverse);
}

int main()
{
    int n;
    bool reverse;
    int arr[] = {1,16 ,79 ,29, 40, 38, 39, 32, 38, 26, 95, 57, 77, 22, 57, 86, 15, 69, 87, 47};
    n = 19;
    cout<<"Unsorted massive" << endl;
    printarr(arr,n+1);
    cout << "Do you want to sort in descending (0) or ascending (1)?" << endl;
    cin >> reverse;
    cout << "Sorted massive"<< endl;
    qqsort(arr, 0, n, reverse);
    printarr(arr,n+1);
    return 0;
}