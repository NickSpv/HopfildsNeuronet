/*
 * Нейронная сеть Хопфилда
 */
#pragma once

#include <vector>
#include "constants.h"
#include "RealNumber.h"

template<typename T>
class Neuronet {
public:
    Neuronet();
    explicit Neuronet(std::vector<std::vector<T>> _images);
    void setWorkMode(Net::WorkMode _workMode);
    void setImagesVector(std::vector<std::vector<T>> _images);
    bool init();
    void setActivationFunction(T (*_activationFunction) (T));
    int recognize(std::vector<T> image);

private:
    int recognizeAsynchronousWorkMode(std::vector<T> image);

private:
    std::vector<std::vector<T>> weights;
    std::vector<T> axons;
    std::vector<T> neurons;
    std::vector<std::vector<T>> images;
    Net::WorkMode workMode;
    int N;
    int M;
    T (*activationFunction) (T);
};

#include "Neuronet.tpp"