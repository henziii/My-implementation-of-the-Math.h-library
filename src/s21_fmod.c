#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result;
  if (x != x || y != y) {
    result = S21_NAN;
  } else if (y == 0 || s21_fabs(x) == S21_INF) {
    result = S21_NAN;
  } else if (s21_fabs(y) == S21_INF) {
    result = x;
  } else {
    int f = 1;
    if (x < 0) {
      x *= -1;
      f = -1;
    }
    if (y < 0) {
      y *= -1;
    }
    result = x - s21_floor(x / y) * y;
    result *= f;
  }
  return (result);
}