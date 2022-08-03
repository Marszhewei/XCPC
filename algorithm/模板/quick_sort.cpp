#include <bits/stdc++.h>

typedef long long LL;
using namespace std;
LL a[100000+10];

// 升序
void quick_sort(LL l, LL r)    {

    // if (l > r)   return;
    // LL base = a[l], left = l, right = r;
    // while (left < right)    {
    //     while (a[right] > base && left < right)    
    //         right--;
    //     if (left < right) {a[left] = a[right];left++;}
    //     while (a[left] < base && left < right)    
    //         left++;
    //     if (left < right) {a[right] = a[left];right--;}
    // }
    // a[left] = base;
    // quick_sort(l, left-1);
    // quick_sort(left+1, r);

    if (l > r) return;
    LL mid = a[l];
    LL left = l, right = r;
    do{
        while(a[left] < mid) left++;
        while(a[right] > mid) right--;
        if(left <= right)
        {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }while(left <= right);
//     quick_sort(l, right);
//     quick_sort(left, r);
}


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL N;
    cin >> N;
    for (int i = N-1; i >= 0; --i)    cin >> a[i];
    // random_shuffle(a, a+N); // 打乱（防止卡你）
    quick_sort(0, N-1);
    for (int i = 0; i < N; ++i)    cout << a[i] << " ";
    cout << "\n";

    return 0;
}