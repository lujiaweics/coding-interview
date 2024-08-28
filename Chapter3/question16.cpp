#include <iostream>

double PowerofUnsigned(double base, unsigned int exponent) {
  double ret = 0.0;
  double base_pow = base;
  unsigned int idx = 1;
  unsigned int currentExponent = 0;
  while (exponent != currentExponent) {
    if (exponent & idx) {
      ret += base_pow;
      currentExponent += idx;
    }
    idx <<= 1;
    base_pow *= base_pow;
  }

  return ret;
}

double Power(double base, int exponent) {
  // handle boundary
  if (base == 0.0 && exponent == 0) {
    return 0.0;
  }
  if (base == 0.0) {
    return 0.0;
  }
  if (exponent == 0) {
    return 1.0;
  }

  double ret = 0.0;
  if (exponent < 0) {
    ret = 1.0 / PowerofUnsigned(base, -exponent);
  } else {
    ret = PowerofUnsigned(base, exponent);
  }

  return ret;
}

int main() {
  std::cout << Power(5.0, 2) << std::endl;

  return 0;
}