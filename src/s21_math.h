#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdlib.h>

#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0
#define S21_EPS 1e-6
#define S21_EPS_1 1e-20
#define S21_M_PI_2 1.57079632679489661923
#define S21_PI 3.14159265358979323846

long double s21_ceil(double x);
long double s21_fabs(double x);
long double s21_fmod(double x, double y);
long double s21_exp(double x);
long double s21_log(double x);
int s21_abs(int x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_floor(double x);
long double s21_sqrt(double x);
long double s21_asin(double x);
long double s21_acos(double x);

long double s21_atan(double x);
long double rows_of_Teylor_for_atan(double x);

long double s21_pow(double base, double exp);
double powfi(double x, int p);

#endif  // SRC_S21_MATH_H_
