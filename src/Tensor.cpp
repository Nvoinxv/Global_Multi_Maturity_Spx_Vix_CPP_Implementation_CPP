#include "Tensor.hpp"

Tensor_Broadcasting::Tensor_Broadcasting() : data(), shape(),
                                             indexing(0), ndim(0), A(), B(),
                                             shape_A(), shape_B()
{
    // kosong
}

std::vector<int> Tensor_Broadcasting::shape_tensor(
    std::vector<int> &shape_A,
    std::vector<int> &shape_B)
{
    A.clear();
    B.clear();

    A.reserve(shape_A.size());
    A.insert(A.end(), shape_A.begin(), shape_A.end());

    B.reserve(shape_B.size());
    B.insert(B.end(), shape_B.begin(), shape_B.end());

    std::vector<int> return_program;

    int ndim_A = A.size();
    int ndim_B = B.size();

    int ndim = std::max(ndim_A, ndim_B);

    for (int i = 0; i < ndim; i++)
    {
        int index_A = ndim_A - 1 - i;
        int index_B = ndim_B - 1 - i;

        int shape_value_A = 1;
        int shape_value_B = 1;

        if (index_A >= 0)
        {
            shape_value_A = A[index_A];
        }

        if (index_B >= 0)
        {
            shape_value_B = B[index_B];
        }

        if (shape_value_A == shape_value_B)
        {
            return_program.push_back(shape_value_A);
        }
        else if (shape_value_A == 1)
        {
            return_program.push_back(shape_value_B);
        }
        else if (shape_value_B == 1)
        {
            return_program.push_back(shape_value_A);
        }
        else
        {
            throw std::invalid_argument(
                "Shape doesn't works broadcasting");
        }
    }

    std::reverse(
        return_program.begin(),
        return_program.end());

    return return_program;
}

std::vector<float> Tensor_Broadcasting::stride_tensor(
    std::vector<int> &shape_A,
    std::vector<int> &shape_B)
{
    std::vector<int> shape_object_tensor = shape_tensor(shape_A, shape_B);

    std::vector<float> return_strides_tensor;
    return_strides_tensor.reserve(shape_object_tensor.size());

    float stride = 1.0f;
    for (int i = shape_object_tensor.size() - 1; i >= 0; i--)
    {
        return_strides_tensor.insert(return_strides_tensor.begin(), stride);
        stride *= shape_object_tensor[i];
    }

    for (int i = 0; i < return_strides_tensor.size(); i++)
    {
        if (shape_object_tensor[i] == 1)
        {
            return_strides_tensor[i] = 0.0f;
        }
    }

    return return_strides_tensor;
}

std::vector<float> Tensor_Broadcasting::indexing_tensor(
    std::vector<float> &data,
    std::vector<int> &shape)
{
    A.clear();
    B.clear();

    A.reserve(data.size() * 2);
    A.insert(A.end(), data.begin(), data.end());

    B.reserve(data.size() * 2);
    B.insert(B.end(), data.begin(), data.end());

    std::vector<float> result;

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            float val = A[i] * 3 + B[j];
            result.push_back(val);
        }
    }

    return result;
}