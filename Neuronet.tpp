#include <iostream>
#include <iomanip>

template<typename T>
Neuronet<T>::Neuronet() {}

template<typename T>
Neuronet<T>::Neuronet(std::vector<std::vector<T>> _images) : images(_images) {
    init();
}

template<typename T>
void Neuronet<T>::setWorkMode(Net::WorkMode _workMode) {
    workMode = _workMode;
}

template<typename T>
void Neuronet<T>::setImagesVector(std::vector<std::vector<T>> _images) {
    images = _images;
}

template<typename T>
void Neuronet<T>::setActivationFunction(T (*_activationFunction)(T)) {
    activationFunction = _activationFunction;
}

template<typename T>
bool Neuronet<T>::init() {
    if (images.empty()) return false;
    N = images[0].size();
    M = images.size();
    weights = std::vector<std::vector<T>> (N, std::vector<T>(N, T(0)));
    for (int d = 0; d < M; d++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                weights[i][j] = T::sum(weights[i][j], T::multiply(images[d][i], images[d][j]));
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) weights[i][j] = 0;
            else weights[i][j] = T::multiply(weights[i][j], T(1. / N));
            std::cout << weights[i][j].getValue() << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    neurons = std::vector<T> (N, T(0));
    axons = std::vector<T> (N, T(0));
    return true;
}

template<typename T>
int Neuronet<T>::recognize(std::vector<T> const image) {
    if (image.size() != N) return -2;
    switch (workMode) {
        case Net::ASYNCHRONOUS:
            return recognizeAsynchronousWorkMode(image);
        default:
            return -1;
    }
}

template<typename T>
int Neuronet<T>::recognizeAsynchronousWorkMode(std::vector<T> const image) {
    for (int i = 0; i < image.size(); i++) {
        neurons[i] = image[i];
        axons[i] = activationFunction(neurons[i]);
    }
    while(true) {
        for (int i = 0; i < N; i++) {
            std::cout << std::fixed << std::setprecision(2) << axons[i].getValue() << ":";
            neurons[i] = T(0);
            for (int j = 0; j < N; j++) {
                if (i != j) neurons[i] = T::sum(neurons[i], T::multiply(weights[i][j], axons[j]));
            }
            std::cout << neurons[i].getValue() << ' ';
        }
        std::cout << "\n";
        int countStableNeurones = 0;
        for (int i = 0; i < N; i++) {
            T newAxon = activationFunction(neurons[i]);
            if (axons[i] == newAxon) countStableNeurones++;
            axons[i] = newAxon;
        }
        if (countStableNeurones == N) break;
    }
    for (int i = 0; i < M; i++) {
        if (images[i] == axons) return i;
    }
    return -3;
}
