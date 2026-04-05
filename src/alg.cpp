// Copyright 2026 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
                break;
            }
        }
    }
    return count;
}

int binarySearch(int *arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // чуть другая запись
        if (arr[mid] == target) return 1;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        int target = value - arr[i];
        if (target < arr[i]) continue;  // отсечение лишних

        if (binarySearch(arr, i + 1, len - 1, target)) count++;
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int l = 0, r = len - 1;

    while (l < r) {
        int sum = arr[l] + arr[r];

        if (sum == value) {
            count++;
            int lv = arr[l], rv = arr[r];
            while (l < len && arr[l] == lv) l++;
            while (r >= 0 && arr[r] == rv) r--;
        } 
        else if (sum < value) l++;
        else r--;
    }
    return count;
}
