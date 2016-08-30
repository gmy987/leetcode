#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    cout << "Hello World";
    return 0;
}

void quickSort(int low, int high, vector<int> &nums) {
    if (low < high) {
        int i = low, j = high, p = nums[i];
        while (i < j) {
            while (i < j && nums[j] >= p)
                j--;
            nums[i] = nums[j];
            while (i < j && nums[i] <= p)
                i++;
            nums[j] = nums[i];
        }
        nums[i] = p;
        quickSort(low, i - 1, nums);
        quickSort(i + 1, high, nums);
    }
}

void merge_(int l, int mid, int r, vector<int> &nums) {
    int i1 = l, i2 = mid, i3 = 0;
    vector<int> tmp(r - l + 1);
    while (i1 <= mid && i2 <= r) {
        if (nums[i2] > nums[i1])
            tmp[i3++] = nums[i1++];
        else
            tmp[i3++] = nums[i2++];
    }
    while (i1 <= mid)
        tmp[i3++] = nums[i1++];
    while (i2 <= r)
        tmp[i3++] = nums[i2++];
    for (int i = 0, j = l; i < i3; i++, j++)
        nums[j] = tmp[i];
}

void mergeSort(int l, int r, vector<int> &nums) {
    if (l + 1 > r)
        return;
    int mid = l + r >> 1;
    mergeSort(l, mid, nums);
    mergeSort(mid + 1, r, nums);
    merge_(l, mid, r, nums);
}
