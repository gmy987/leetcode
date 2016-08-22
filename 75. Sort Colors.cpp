// Bubble Sort
class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int len = nums.size();
        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; j < len - i - 1; j++) {
                if (nums[j] > nums[j + 1])
                    swap(nums[j], nums[j + 1]);
            }
        }
    }
};

// Merge Sort
class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int len = nums.size();
        mergeSort(nums, 0, len - 1);
    }

    void mergeSort(vector<int> &nums, int l, int r) {
        if (l + 1 > r)
            return;
        int mid = l + r >> 1;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge_(nums, l, mid, r);
    }

    void merge_(vector<int> &nums, int l, int mid, int r) {
        int i1 = l, i2 = mid + 1, i3 = 0;
        vector<int> tmp(r - l + 1);
        while (i1 <= mid && i2 <= r) {
            if (nums[i1] > nums[i2])
                tmp[i3++] = nums[i2++];
            else
                tmp[i3++] = nums[i1++];
        }
        while (i1 <= mid)
            tmp[i3++] = nums[i1++];
        while (i2 <= r)
            tmp[i3++] = nums[i2++];
        for (int i = 0, j = l; i < i3; i++, j++) {
            nums[j] = tmp[i];
        }
    }
};

// Quick Sort
class Solution {
  public:
    void sortColors(vector<int> &nums) { quickSort(nums, 0, nums.size() - 1); }

    void quickSort(vector<int> &nums, int low, int high) {
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
            quickSort(nums, low, i - 1);
            quickSort(nums, i + 1, high);
        }
    }
};
