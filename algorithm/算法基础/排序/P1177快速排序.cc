#include <iostream>
#include <algorithm>

#define SIZE 100010
static long long int a[SIZE];


static void quick_sort(long long int l, long long int r)
{
    if (l > r)   return;
    long long int base = a[l], left = l, right = r;
    while (left < right)    {
        while (a[right] > base && left < right)    
            right--;
        if (left < right) {a[left] = a[right];left++;}
        while (a[left] < base && left < right)    
            left++;
        if (left < right) {a[right] = a[left];right--;}
    }
    a[left] = base;
    quick_sort(l, left-1);
    quick_sort(left+1, r);
}


int main(int argc, char** argv) 
{  
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long int N;
    std::cin >> N;
    for (long long int i = N-1; i >= 0; --i)
        std::cin >> a[i];
    // std::random_shuffle(a, a+N);
    // quick_sort(0, N-1);
    std::sort(a, a+N);
    for (long long int i = 0; i < N; ++i)
        std::cout << a[i] << ' ';
    std::cout << std::endl;

    return 0;
}