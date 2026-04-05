// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < len; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
  int left = 0;
    int right = len - 1;
    int count = 0;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == value)
        {
            if (arr[left] == arr[right])
            {
                int k = right - left + 1;
                count += k * (k - 1) / 2;
                break;
            }

            int leftVal = arr[left];
            int leftCount = 0;
            while (left < len && arr[left] == leftVal)
            {
                leftCount++;
                left++;
            }

            int rightVal = arr[right];
            int rightCount = 0;
            while (right >= 0 && arr[right] == rightVal)
            {
                rightCount++;
                right--;
            }

            count += leftCount * rightCount;
        }
        else if (sum < value)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return count;
}
// вспомогательный бинарный поиск (количество вхождений)
int countOccurrences(int *arr, int left, int right, int target)
{
    int first = -1, last = -1;

    int l = left, r = right;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] >= target)
        {
            if (arr[mid] == target) first = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (first == -1) return 0;

    l = left; r = right;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] <= target)
        {
            if (arr[mid] == target) last = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return last - first + 1;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;

    for (int i = 0; i < len; ++i)
    {
        int target = value - arr[i];

        int occurrences = countOccurrences(arr, i + 1, len - 1, target);
        count += occurrences;
    }

    return count;
}
