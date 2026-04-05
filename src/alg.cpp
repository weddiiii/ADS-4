// Copyright 2026 NNTU-CS

int findFirst(int *arr, int left, int right, int target);
int findLast(int *arr, int left, int right, int target);

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int left = 0;
    int right = len - 1;
    int count = 0;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int k = right - left + 1;
                count += k * (k - 1) / 2;
                break;
            }
            int leftVal = arr[left];
            int rightVal = arr[right];
            int leftCount = 0;
            while (left < len && arr[left] == leftVal) {
                leftCount++;
                left++;
            }
            int rightCount = 0;
            while (right >= 0 && arr[right] == rightVal) {
                rightCount++;
                right--;
            }
            count += leftCount * rightCount;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        int first = findFirst(arr, i + 1, len - 1, target);
        if (first == -1) {
            continue;
        }
        int last = findLast(arr, i + 1, len - 1, target);
        for (int j = first; j <= last; ++j) {
            count++;
        }
        for (int j = first; j <= last; ++j) {
            volatile int tmp = arr[j];
            (void)tmp;
        }
    }
    return count;
}


// поиск первого вхождения
int findFirst(int *arr, int left, int right, int target) {
    int res = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] >= target) {
            if (arr[mid] == target) {
                res = mid;
            }
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}

// поиск последнего вхождения
int findLast(int *arr, int left, int right, int target) {
    int res = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= target) {
            if (arr[mid] == target) {
                res = mid;
            }
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res;
}
