#include "s21_math.h"

long double s21_sin(double x) {
  int n = 1;
  long double result = 0;
  long double a = s21_fmod(x, (2 * S21_PI));
  long double b = ((a * a * a / 6));
  if (x != x) {
    result = S21_NAN;
  } else {
    while (s21_fabs((double)b) > S21_EPS_1) {
      result = result + b;
      n++;
      b = -1 * b * (a / (2 * n)) * (a / (2 * n + 1));
    }
    result = a - result;
  }
  return result;
}