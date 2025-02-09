//
//  vector_operation.h
//  LKFS
//
//  Created by 何冠勳 on 2021/4/19.
//

#ifndef vector_operation_h
#define vector_operation_h
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <iostream>

template <typename T>
std::vector<T> linspace(T start, T end, size_t num) {
    std::vector<T> linspaced;
    if(num==1) {
        linspaced.push_back(start);
        return linspaced;
    }
    else {
        double delta = (end-start)/(num-1);
        for(size_t i=0;i<num-1;i++)
            linspaced.push_back(T(start+delta*i));
        linspaced.push_back(end);
        return linspaced;
    }
}

double vector_sum(const std::vector<double> &v, const size_t lb, const size_t up) {
    double sum = 0.0;
    for(size_t i=lb;i<up;i++) {
        sum = sum + v[i];
    }
    return sum;
}

void scalar(std::vector<double> &v, const double k) {
    for(size_t i=0;i<v.size();i++) {
        v[i]*=k; }
}

void vector_ele_pow(std::vector<double> &v, const double k) {
    for(size_t i=0;i<v.size();i++) {
        v[i] = pow(v[i], k);
    }
}

double vector_mean(const std::vector<double> &v) {
    double sum = vector_sum(v, 0, v.size());
    return sum/double(v.size());
}

void abs(std::vector<double> &v) {
    for(size_t i=0;i<v.size();i++) {
        if(v[i]<0.0) v[i] *= -1.0;
    }
}

double abs_max_element(const std::vector<double> &v) {
    double temp = 0.0, max = 0.0;
    for(size_t i=0;i<v.size();i++) {
        if(v[i]<0.0) temp = v[i] * -1.0;
        else temp = v[i];
        if(temp>max) max = temp;
    }
    return max;
}

template <typename T>
void vect1D_print(const std::vector<T> &v) {
    std::cout << "{ ";
    for(size_t i=0;i<v.size()-1;i++) {
        std::cout << std::setw(3) << v[i] << ", ";
        if((i%50)==49) std::cout << std::endl;
    }
    std::cout << std::setw(3) << v[v.size()] << " } " << std::endl;
}

#endif /* vector_operation_h */
