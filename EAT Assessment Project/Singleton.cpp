#include "Singleton.h"

// INFO: Static variable initialization to match the derived classes type
template <typename T>
T* Singleton<T>::instance = nullptr;