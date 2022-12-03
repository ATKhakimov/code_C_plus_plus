#include <iostream>

template <bool condition, typename ttype>
struct enable_if1{using type = ttype;};
template <typename ttype>
struct enable_if1 <false, ttype>{};
template <bool condition, typename ttype>
using enable_if = typename enable_if1 <condition, ttype>::type;