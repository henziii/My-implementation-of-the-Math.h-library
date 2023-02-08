#include "s21_math.h"

long double s21_ceil(double x) {
  long double result;
  if (x != x) {
    result = S21_NAN;
  } else if (s21_fabs(x) == S21_INF) {
    result = S21_INF;
  } else if (x == 0) {
    result = 0;
  } else {
    if (x > 0) {
      result = (x - (int)x != 0) ? (int)x + 1 : x;
    } else if (x < 0) {
      result = (int)x;
    }
  }
  return result;
}