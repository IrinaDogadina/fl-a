#include <stdio.h>
#include <math.h>
#include <malloc.h>

double dependence(double x) {
  double y = 3 - 2*(x^2);
  return y;
}

double angle (int angle_degree) {
  double angle = (double)angle_degree * 0.017;
  return angle;
}

double sin_angle (double angle_radian) {
  double sin_angle = sin(angle_radian);
  return sin_angle;
}

double dot_A (double sin_angle) {
  double A_x = sqrt((3-sin_angle)/2);
  return A_x;
}

int count_dots (double delta_x, double A_x) {
  int count_dots = (A_x/delta_x) + 1;
  return count_dots;
}

double dots (double sin_angle, double dot_x) {
  double dot_y = asin(sin_angle/dot_x);
  return dot_y;
}

int main(int argc, char const *argv[]) {
  double** coordinates;
  double delta_x;
  double angle_radian;
  int angle_degree;
  double sin_angle;
  double A_x;
  int count_dots;
  printf ("angle = \n");
  scanf ("%d", &angle_degree);
  angle_radian = angle(angle_degree);
  printf ("step = \n");
  scanf ("%f", &delta_x);
  sin_angle = sin_angle(angle_radian);
  A_x = dot_A(sin_angle);
  count_dots = count_dots(delta_x, A_x);
  coordinates = (double**)malloc(2*sizeof(double*));
  for (int i = 0; i < count_dots; i++) {
		coordinates[i]=(double*)malloc(count_dots*sizeof(double));
  }
  for (int i = 0; i <= A_x; i+delta_x) {
    double dot_x = dependence(i);
    dot_y = dots(sin_angle, dot_x);
    //тут в массив надо все точки записать
  }
  return 0;
}
