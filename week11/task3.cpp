#include <iostream>
#include <type_traits>

template <typename T>
struct decay1{};

template <typename T, std::size_t n>
struct decay1<T[n]>: std::add_pointer<T[n]>{};

template <typename T>
struct decay1<T[]>: std::add_pointer<T[]>{};

template <typename T, typename... t>
struct decay1<T(t...)>: std::add_pointer<T(t...)>{};

template <typename T, typename... t>
struct decay1<T(t..., ...)>: std::add_pointer<T(t..., ...)>{};

template <typename T>
using decay = typename decay1<T>::tip;