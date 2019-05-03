#ifndef AOS_LAB2_ARRAY_ELEMENT
#define AOS_LAB2_ARRAY_ELEMENT

#include <utility> // for std::move

#include "array_element_interface.hpp"

namespace ArrEl
{
template <typename T>
ulong ArrayElement<T>::comparisons = 0;
template <typename T>
ulong ArrayElement<T>::assignments = 0;

template <typename T>
bool ArrayElement<T>::cmp_on = true;
template <typename T>
bool ArrayElement<T>::asgn_on = true;

template <typename T>
ArrayElement<T>::ArrayElement()
{
}

template <typename T>
ArrayElement<T>::ArrayElement(const T &el)
    : elem{el}
{
}

template <typename T>
ArrayElement<T>::ArrayElement(const ArrayElement<T> &el)
    : elem{el.elem}
{
}

template <typename T>
ArrayElement<T>::ArrayElement(T &&el)
    : elem{std::move(el)}
{
}

template <typename T>
ArrayElement<T>::ArrayElement(ArrayElement<T> &&el)
    : elem{std::move(el.elem)}
{
}

template <typename T>
ArrayElement<T> &ArrayElement<T>::operator=(const ArrayElement<T> &el)
{
    if (asgn_on)
        assignments++;
    elem = el.elem;

    return (*this);
}

template <typename T>
ArrayElement<T> &ArrayElement<T>::operator=(const T &el)
{
    if (asgn_on)
        assignments++;
    elem = el;

    return (*this);
}

template <typename T>
ArrayElement<T> &ArrayElement<T>::operator=(ArrayElement<T> &&el)
{
    if (asgn_on)
        assignments++;
    elem = std::move(el.elem);

    return (*this);
}

template <typename T>
ArrayElement<T> &ArrayElement<T>::operator=(T &&el)
{
    if (asgn_on)
        assignments++;
    elem = std::move(el);

    return (*this);
}

template <typename T>
inline void ArrayElement<T>::reset()
{
    comparisons = 0;
    assignments = 0;
}

template <typename T>
inline ulong ArrayElement<T>::get_cmp()
{
    return comparisons;
}

template <typename T>
inline ulong ArrayElement<T>::get_asgn()
{
    return assignments;
}

template <typename T>
inline void ArrayElement<T>::off_on_cmp_count(bool b)
{
    cmp_on = b;
}

template <typename T>
inline void ArrayElement<T>::off_on_asgn_count(bool b)
{
    asgn_on = b;
}

template <typename T>
inline bool operator==(const ArrayElement<T> &a, const ArrayElement<T> &b)
{
    if (a.cmp_on)
        a.comparisons++;
    return a.elem == b.elem;
}

template <typename T>
inline bool operator!=(const ArrayElement<T> &a, const ArrayElement<T> &b)
{
    if (a.cmp_on)
        a.comparisons++;
    return a.elem != b.elem;
}

template <typename T>
inline bool operator>(const ArrayElement<T> &a, const ArrayElement<T> &b)
{
    if (a.cmp_on)
        a.comparisons++;
    return a.elem > b.elem;
}

template <typename T>
inline bool operator<(const ArrayElement<T> &a, const ArrayElement<T> &b)
{
    if (a.cmp_on)
        a.comparisons++;
    return a.elem < b.elem;
}

template <typename T>
inline bool operator>=(const ArrayElement<T> &a, const ArrayElement<T> &b)
{
    if (a.cmp_on)
        a.comparisons++;
    return a.elem >= b.elem;
}

template <typename T>
inline bool operator<=(const ArrayElement<T> &a, const ArrayElement<T> &b)
{
    if (a.cmp_on)
        a.comparisons++;
    return a.elem <= b.elem;
}

} // namespace ArrEl
#endif