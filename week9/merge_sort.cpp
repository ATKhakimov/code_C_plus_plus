#include <functional>

#include <iostream>

#include <iterator>

template < typename T >
void printArray(T* arr, std::size_t n)
{   
    for (auto i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
template < typename T, typename C >
    void merge_sort(T * arr, std::size_t n, C & cmp) {
        if (n - 1) {
            std::size_t
            left = n / 2;
            std::size_t
            right = n - left;

            merge_sort( & arr[0], left, cmp);
            merge_sort( & arr[left], right, cmp);

            std::size_t l_shift = 0;
            std::size_t r_shift = left;
            std::size_t i = 0;

            T * shifted_arr = new T[n];

            while (r_shift < n || l_shift < left) {
                if (cmp(arr[l_shift], arr[r_shift])) {
                    shifted_arr[i++] = std::move(arr[l_shift]);
                    l_shift++;
                } else {
                    shifted_arr[i++] = std::move(arr[r_shift]);
                    r_shift++;
                }

                if (l_shift == left) {
                    std::copy( & arr[r_shift], &
                        arr[n], &
                        shifted_arr[i]);
                    break;
                }
                if (r_shift == n) {
                    std::copy( & arr[l_shift], &
                        arr[left], &
                        shifted_arr[i]);
                    break;
                }
            }

            std::copy(shifted_arr, &
                shifted_arr[n],
                arr);

            delete[] shifted_arr;
        }
    }

int main() {
    std::size_t n = 10;
    auto cmp = [](int a, int b)->bool { return a < b; };
    int arr[n] = {10,9,8,7,6,5,4,3,2,1};
    int *darr = new int[n];
    for (int i = 0; i < n; i++){
        darr[i] = 2 - i;
    }
    std::cout<< "Start arrays :" << std::endl;
    printArray(arr, n);
    printArray(darr, n);
    merge_sort(arr,n,cmp);
    merge_sort(darr,n, cmp);
    std::cout<< "Sorted arrays :" << std::endl;
    printArray(arr, n);
    printArray(darr, n);
    
    return 0;
}