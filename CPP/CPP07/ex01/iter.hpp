#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void iter(T * array, size_t const length, void (* func)(F &))
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);

    return ;
}

#endif
    