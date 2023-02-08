#include "s21_math.h"

long double s21_sqrt(double x) {
  long double result = 0;
  if (x < 0 || x != x) {
    return S21_NAN;
  } else if (x == S21_INF) {
    return S21_INF;
  } else {
    result = s21_pow(x, 0.5);
  }
  return result;
}
