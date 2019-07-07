#ifndef SORT_BENCH_INTERFACE
#define SORT_BENCH_INTERFACE

#include <vector>
#include <tuple>
#include <chrono>
#include <array>
#include <stdexcept>

#include "genfunc.hpp"
#include "array_element.hpp"

namespace srtbch
{


struct CmpAsgn
{
    size_t cmp;
    size_t asgn;
};


using SortStats = std::vector<std::tuple<
                  size_t,                     // array length
                  std::chrono::nanoseconds,   // sorting duration
                  CmpAsgn                     // comparisons and assignments
                  >>;


template <
    typename T,
    template <typename> typename SortFunctor,
    typename GenFunc = unlimited_mtgenf<T>
    >
// look forward to thread safety
// look forward to array + - and so on operations on ArrayElement, for sortings like RadixSort
class SortBench
{
    SortStats stats;

    SortFunctor<T> time_sort;
    SortFunctor<ArrayElement<T>> cmp_asgn_sort;
    GenFunc gen {};

    std::vector<std::vector<T>> sort_arrs;
    bool is_inited {false};
    bool keep {false};
public:
    SortBench(bool keep = true); // true default

    void keep_arrays(bool should = true); // default true

    SortStats operator()(std::vector<size_t> array_sizes);
    SortStats operator()(size_t array_size, size_t measure_num);

    std::vector<std::vector<T>> arrays();
private:

    void measure(size_t sz);

    std::pair<size_t, size_t> test_single_cmp_asgn(std::vector<ArrayElement<T>>&);
    std::chrono::nanoseconds  test_single_time(std::vector<T>&);
};


};
#endif