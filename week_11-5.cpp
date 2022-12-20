#include <iostream>
#include <vector>

template <size_t Dimension, size_t... args>
class Tensor {
};

template <size_t Dimension, size_t N1, size_t... args>
class Tensor<Dimension, N1, args...> {
    std::vector<Tensor<Dimension - 1, args...>> T;
    Tensor() = default;
    ~Tensor() = default;
    Tensor(const Tensor&) = default;
    Tensor(Tensor&&) noexcept = default;
    
    friend std::ostream& operator<< (const Tensor<Dimension, N1, args...>& A, std::ostream& output) {
        for (size_t i = 0; i < N1; ++i) {
            output << A[i];
        }
        return output;
    }
};

template<>
class Tensor<1> {
    std::vector<int64_t> T;

};

template <size_t Dimension, size_t N1, size_t... args>
Tensor<Dimension, N1, args...> operator+ (const Tensor<Dimension, N1, args...>& A, const Tensor<Dimension, N1, args...>& B) {
    Tensor<Dimension, N1,  args...> C(A);
    for (size_t i = 0; i < N1; ++i) {
        C.T[i] = A.T[i] + B.T[i];
    }
    return C;
}

template <size_t Dimension, size_t N1, size_t... args>
Tensor<Dimension, N1, args...> operator- (const Tensor<Dimension, N1, args...>& A, const Tensor<Dimension, N1, args...>& B) {
    Tensor<Dimension, N1,  args...> C(A);
    for (size_t i = 0; i < N1; ++i) {
        C.T[i] = A.T[i] - B.T[i];
    }
    return C;
}
