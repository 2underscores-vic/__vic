// Iterator range readers
//
// Platform: ISO C++ 98/11
// $Id$
//
// (c) __vic 2011

#ifndef __VIC_READERS_ITERATOR_H
#define __VIC_READERS_ITERATOR_H

#include<__vic/defs.h>
#include<iterator>

namespace __vic {

//////////////////////////////////////////////////////////////////////////////
template<class Iter, class T = typename std::iterator_traits<Iter>::value_type>
class iterator_reader
{
    Iter p, end;
public:
    iterator_reader(Iter begin, Iter end) : p(begin), end(end) {}
    bool read(T &v)
    {
        if(p == end) return false;
        v = *p++; // move?
        return true;
    }
    Iter position() const { return p; }
};
//////////////////////////////////////////////////////////////////////////////
template<class Iter, class T = typename std::iterator_traits<Iter>::value_type>
class iterator_reader_n
{
    Iter p;
    size_t n;
public:
    iterator_reader_n(Iter begin, size_t n) : p(begin), n(n) {}
    bool read(T &v)
    {
        if(n == 0) return false;
        v = *p++; // move?
        n--;
        return true;
    }
    Iter position() const { return p; }
};
//////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------
template<class Iter>
inline iterator_reader<Iter> make_iterator_reader(Iter begin, Iter end)
{
    return iterator_reader<Iter>(begin, end);
}
//----------------------------------------------------------------------------
template<class T, class Iter>
inline iterator_reader<Iter,T> make_iterator_reader_for(Iter begin, Iter end)
{
    return iterator_reader<Iter,T>(begin, end);
}
//----------------------------------------------------------------------------
template<class Iter>
inline iterator_reader_n<Iter> make_iterator_reader_n(Iter begin, size_t n)
{
    return iterator_reader_n<Iter>(begin, n);
}
//----------------------------------------------------------------------------
template<class T, class Iter>
inline iterator_reader_n<Iter,T> make_iterator_reader_n_for(Iter begin, size_t n)
{
    return iterator_reader_n<Iter,T>(begin, n);
}
//----------------------------------------------------------------------------

} // namespace

#endif // header guard
