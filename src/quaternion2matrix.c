#include "quaternion.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
  if (argc != 5) {
    fprintf(stderr, "usage: %s qw qx qy qz\n", argv[0]);
    return 1;
  }

  struct Quaternion quat;
  quat.w = strtod(argv[1], NULL);
  quat.x = strtod(argv[2], NULL);
  quat.y = strtod(argv[3], NULL);
  quat.z = strtod(argv[4], NULL);

  double s = 2 / hypot(hypot(quat.w, quat.x), hypot(quat.y, quat.z));
  double xs = quat.x * s;
  double ys = quat.y * s;
  double zs = quat.z * s;

  double wx = quat.w * xs;
  double wy = quat.w * ys;
  double wz = quat.w * zs;
  double xx = quat.x * xs;
  double xy = quat.x * ys;
  double xz = quat.x * zs;
  double yy = quat.y * ys;
  double yz = quat.y * zs;
  double zz = quat.z * zs;

  printf("%f\t%f\t%f\n%f\t%f\t%f\n%f\t%f\t%f\n",
         1.0 - yy - zz, xy - wz, xz + wy,
         xy + wz, 1.0 - xx - zz, yz - wx,
         xz - wy, yz + wx, 1.0 - xx - yy);
 return 0;
}
