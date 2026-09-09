#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <vector>
#include <memory>
#include <stdexcept>
#include <utility>
#include <initializer_list>
#include <algorithm>

class Tensor_Broadcasting
{
private:
    std::vector<float> data;
    std::vector<int> shape;
    int indexing;
    int ndim;

    std::vector<float> A;
    std::vector<float> B;

    std::vector<int> shape_A;
    std::vector<int> shape_B;

public:
    Tensor_Broadcasting();

    std::vector<int> shape_tensor(
        std::vector<int> &shape_A,
        std::vector<int> &shape_B);

    std::vector<float> stride_tensor(
        std::vector<int> &shape_A,
        std::vector<int> &shape_B);

    std::vector<float> indexing_tensor(
        std::vector<float> &data,
        std::vector<int> &shape);
};

#endif
