#pragma once

class RealNumber {
public:
    RealNumber();
    RealNumber(double _value);
    static RealNumber sum(RealNumber const &left, RealNumber const &right);
    static RealNumber multiply(RealNumber const &left, RealNumber const &right);
    double getValue() const;
    bool operator==(RealNumber const &right) const;
    bool operator<(RealNumber const &right) const;
    RealNumber& operator=(RealNumber const &right);

private:
    double value;
};
