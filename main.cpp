#include <iostream>
#include <vector>
#include "Neuronet.h"
#include "RealNumber.h"

using namespace std;

using RN = RealNumber;

RN activationFunction(RN x){
    if (x.getValue() < 0)
        return {-1};
    return {1};
}

int main() {
    vector<vector<RN>> images = {{1, 1, 1, 1,
                                  1, -1, -1, 1,
                                  1, 1, 1, 1,
                                  -1, -1, -1, -1},
                                 {1, 1, -1, 1,
                                  1, -1, -1, 1,
                                  1, -1, -1, 1,
                                  1, -1, 1, 1}};
    Neuronet<RN> neuronet(images);
    neuronet.setWorkMode(Net::WorkMode::ASYNCHRONOUS);
    neuronet.setActivationFunction(activationFunction);
    const vector<RN> image = {1, 1, -1, 1,
                              1, -1, -1, 1,
                              1, -1, -1, 1,
                              -1, -1, -1, -1};
    cout << neuronet.recognize(image);
    return 0;
}
