#include <iostream>

template <typename T>
struct add_const1{using tip = T const;};

template <typename T>
using add_const = typename add_const1<T>::tip;

template<typename T>
struct remove_const1{};

template <typename T>
struct remove_const1<T const>{using tip = T;};

template <typename T>
using remove_const = typename remove_const1<T>::tip;