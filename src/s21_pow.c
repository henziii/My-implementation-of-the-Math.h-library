#include "s21_math.h"

long double s21_pow(double base, double exp) {
  int flag = 0;
  long double result = 0;
  if (base < 0) {
    flag = 1;
  }
  if (base == 1. && exp != exp) {  // base = 1, a = nan;
    result = 1;
  } else if (s21_fabs(exp - (int)exp) > S21_EPS && base < 0.) {
    result = S21_NAN;
  } else if (exp == 1.) {
    result = base;
  } else if (exp == -1.) {
    result = 1 / base;
  } else if (exp == 0.) {
    result = 1;
  } else {
    base = s21_fabs(base);
    int int_power = s21_fabs(exp);
    long double int_pow_result = powfi(base, int_power);
    double remaining_power = exp - int_power;
    long double remaining_result =
        s21_exp(remaining_power * (double)s21_log(base));
    result = flag == 1 && s21_fmod(exp, 2) > S21_EPS
                 ? int_pow_result * remaining_result * -1
                 : int_pow_result * remaining_result;
  }
  return result;
}

// Super fast x^p (integer power) using Exponentiation by Squaring.
double powfi(double x, int p) {
  double result = 1;
  while (p) {
    if (p & 0x1) {
      result *= x;
    }
    x *= x;
    p >>= 1;
  }
  return result;
}