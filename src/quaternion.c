#include "quaternion.h"

void quaternion_add(const struct Quaternion *lhs, const struct Quaternion *rhs,
                    struct Quaternion *out) {
  out->w = lhs->w + rhs->w;
  out->x = lhs->x + rhs->x;
  out->y = lhs->y + rhs->y;
  out->z = lhs->z + rhs->z;
}

void quaternion_sub(const struct Quaternion *lhs, const struct Quaternion *rhs,
                    struct Quaternion *out) {
  out->w = lhs->w - rhs->w;
  out->x = lhs->x - rhs->x;
  out->y = lhs->y - rhs->y;
  out->z = lhs->z - rhs->z;
}

void quaternion_conjugate(const struct Quaternion *lhs,
                          struct Quaternion *out) {
  out->w = lhs->w;
  out->x = -lhs->x;
  out->y = -lhs->y;
  out->z = -lhs->z;
}

void quaternion_mul(const struct Quaternion *restrict lhs,
                    const struct Quaternion *restrict rhs,
                    struct Quaternion *restrict out) {
  out->w =
      lhs->w * rhs->w - lhs->x * rhs->x - lhs->y * rhs->y - lhs->z * rhs->z;
  out->x =
      lhs->w * rhs->x + lhs->x * rhs->w + lhs->y * rhs->z - lhs->z * rhs->y;
  out->y =
      lhs->w * rhs->y + lhs->y * rhs->w + lhs->z * rhs->x - lhs->x * rhs->z;
  out->z =
      lhs->w * rhs->z + lhs->z * rhs->w + lhs->x * rhs->y - lhs->y * rhs->x;
}
