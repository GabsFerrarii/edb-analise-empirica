#include "SearchAlgorithms.hpp"

namespace Search {
    int sequentialSearch(const std::vector<int>& arr, int target) {
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[i] == target) return i;
        }
        return -1;
    }

    int binarySearch(const std::vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
}