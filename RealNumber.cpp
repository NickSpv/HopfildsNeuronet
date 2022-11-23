#include "RealNumber.h"

RealNumber::RealNumber() {
    value = 0;
};

RealNumber::RealNumber(double _value) : value(_value) {}

double RealNumber::getValue() const {
    return value;
}

RealNumber RealNumber::sum(RealNumber const &left, RealNumber const &right) {
    return {left.getValue() + right.getValue()};
}

RealNumber RealNumber::multiply(RealNumber const &left, RealNumber const &right) {
    return {left.getValue() * right.getValue()};
}

bool RealNumber::operator==(RealNumber const &right) const {
    return this->getValue() == right.getValue();
}

RealNumber &RealNumber::operator=(RealNumber const &right) {
    if (this == &right) {
        return *this;
    }
    value = right.getValue();
    return *this;
}

bool RealNumber::operator<(const RealNumber &right) const {
    return this->getValue() < right.getValue();
}
