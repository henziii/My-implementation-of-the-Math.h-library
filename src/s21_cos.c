#include "s21_math.h"

long double s21_cos(double x) {
  int n = 1;
  long double result = 0;
  long double a = s21_fmod(x, (2 * S21_PI));
  long double b = -((a * a) / 2);
  if (x != x) {
    result = S21_NAN;
  } else {
    while (s21_fabs((double)b) > S21_EPS_1) {
      result = result + b;
      n++;
      b = -1 * b * (a / (2 * n - 1)) * (a / (2 * n));
    }
    result = 1 + result;
  }
  return result;
}