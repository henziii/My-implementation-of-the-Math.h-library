#include "s21_math.h"

long double s21_fabs(double x) {
  long double result = x;
  if (x == S21_INF) {
    result = S21_INF;
  } else if (x != x) {
    result = S21_NAN;
  } else if (x < 0) {
    result = -1 * x;
  }
  return (result);
}