#include <vector>

#ifndef UTILS_H
#define UTILS_H

template <typename T>
void deallocate_pointer_vector(std::vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        delete vec[i];
    }
    vec.clear();
}

#endif
