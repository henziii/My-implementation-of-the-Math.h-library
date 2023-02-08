#include "s21_math.h"

long double s21_asin(double x) {
  long double result = S21_NAN;
  if (x < -S21_M_PI_2 || x > S21_M_PI_2) {
    result = S21_NAN;
  } else {
    result = s21_atan((long double)x / s21_sqrt(1 - s21_pow(x, 2.)));
  }
  return result;
}