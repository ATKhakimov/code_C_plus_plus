#include <iostream>

template <bool condition, typename tip>
struct enable_if1{using type = tip;};

template <typename tip>
struct enable_if1 <false, tip>{};

template <bool condition, typename tip>
using enable_if = typename enable_if1<condition, tip>::type;


template< typename type_1, typename type_2 >
struct result
{
    template<typename T1 = type_1, typename T2 = type_2>
    result( type_1 f, 
            typename std::enable_if<!std::is_same<T1, T2>::value>::type * = nullptr )
       : foo{f} {}
    template<typename T1 = type_1, typename T2 = type_2>
    result( type_2 b, 
           typename std::enable_if<!std::is_same<T1, T2>::value, int >::type * = nullptr )
       : bar{b} {}                                       
    template<typename T1 = type_1, typename T2 = type_2>
    result( type_1 f, type_2 b,
            typename std::enable_if<std::is_same<T1, T2>::value>::type * = nullptr ) 
       : foo{f}, bar{b} {}

    type_1 foo;
    type_2 bar;
};

int main()
{
   result<int, double> r(100.1);
}