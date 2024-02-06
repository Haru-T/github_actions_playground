#include "quaternion.h"

#include <assert.h>
#include <float.h>
#include <math.h>

int main() {
  struct Quaternion e = {1.0, 0.0, 0.0, 0.0};
  struct Quaternion a = {0.7071, 0.0, 0.7071, 0.0};
  struct Quaternion b;
  quaternion_mul(&e, &a, &b);
  assert(fabs(a.w - b.w) < DBL_EPSILON);
  assert(fabs(a.x - b.x) < DBL_EPSILON);
  assert(fabs(a.y - b.y) < DBL_EPSILON);
  assert(fabs(a.z - b.z) < DBL_EPSILON);
  return 0;
}
