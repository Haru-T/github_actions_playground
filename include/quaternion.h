#ifndef QUATERNION_H
#define QUATERNION_H

struct Quaternion {
  double w;
  double x;
  double y;
  double z;
};

void quaternion_add(const struct Quaternion *lhs, const struct Quaternion *rhs,
                    struct Quaternion *out);
void quaternion_sub(const struct Quaternion *lhs, const struct Quaternion *rhs,
                    struct Quaternion *out);
void quaternion_conjugate(const struct Quaternion *lhs, struct Quaternion *out);
void quaternion_mul(const struct Quaternion *restrict lhs,
                    const struct Quaternion *restrict rhs,
                    struct Quaternion *restrict out);

#endif
