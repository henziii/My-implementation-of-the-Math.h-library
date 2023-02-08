#include "s21_math.h"

long double s21_atan(double x) {
  long double result = S21_NAN;
  long double temp = 1;
  if (x > -1 && x < 1) {
    result = rows_of_Teylor_for_atan(x);
  } else if (x == 1) {
    result = S21_PI / 4.;
  } else if (x == -1) {
    result = -S21_PI / 4.;
  } else if ((x < -1 || x > 1) && x < 1.7 * s21_pow(10, 153) &&
             x > -1.7 * s21_pow(10, 153)) {
    result = (S21_PI * (s21_sqrt(s21_pow(x, 2.))) / (2. * x)) -
             rows_of_Teylor_for_atan(x);
  } else if (x >= 1.7 * s21_pow(10, 153)) {
    result = S21_M_PI_2;
  } else if (x <= -1.7 * s21_pow(10, 153)) {
    result = -S21_M_PI_2;
  }
  return result;
}

long double rows_of_Teylor_for_atan(double x) {
  long double result = 0.;
  long double temp = 1;
  double px = (x > -1 && x < 1) ? x : 1 / x;
  x = (x > -1 && x < 1) ? x : 1 / x;
  for (int i = 0; s21_fabs((double)temp) > S21_EPS_1; i++) {
    temp = s21_pow(-1, i) * x / (2 * i + 1);
    result += temp;
    x *= px * px;
  }
  return result;
}