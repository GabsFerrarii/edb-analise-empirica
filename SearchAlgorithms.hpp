#ifndef SEARCH_ALGORITHMS_HPP
#define SEARCH_ALGORITHMS_HPP

#include <vector>

namespace Search {
    int sequentialSearch(const std::vector<int>& arr, int target);

    int binarySearch(const std::vector<int>& arr, int target);
}

#endif