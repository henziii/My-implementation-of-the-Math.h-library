#include "s21_math.h"

long double s21_floor(double x) {
  long double result = x;
  if (x == S21_INF) {
    result = S21_INF;
  } else if (x == -S21_INF) {
    result = -S21_INF;
  } else if (x != x) {
    result = S21_NAN;
  } else if (x == 0) {
    result = 0;
  } else if (x > 0) {
    result = (long long int)x;
  } else if (x < 0 && s21_fabs((int)x - x) > S21_EPS_1) {
    result = (long long int)x - 1;
  } else if (x < 0 && s21_fabs((int)x - x) <= S21_EPS_1) {
    result = (long long int)x;
  }
  return result;
}