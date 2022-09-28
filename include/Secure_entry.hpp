#ifndef SECURE_ENTRY_HPP
#define SECURE_ENTRY_HPP

#include "Secure_entry.tpp"

template<ReadObject T>
void secure_entry(T& var);

template <ReadObject T, typename Predicat> requires std::predicate<Predicat, T>
void secure_entry(T& var, Predicat predicat);


#endif