/*!
 \file
 */
#ifndef QUATERNION_H
#define QUATERNION_H

/*! Quaternion struct. */
struct Quaternion {
  double w;
  double x;
  double y;
  double z;
};

/*!
 * Add quaternions.
 *
 * \param lhs left-hand side quaternion.
 * \param rhs right-hand side quaternion.
 * \param[out] out \a lhs + \a rhs.
 */
void quaternion_add(const struct Quaternion *lhs, const struct Quaternion *rhs,
                    struct Quaternion *out);
/*!
 * Subtract quaternions.
 *
 * \param lhs left-hand side quaternion.
 * \param rhs right-hand side quaternion.
 * \param[out] out \a lhs - \a rhs.
 */
void quaternion_sub(const struct Quaternion *lhs, const struct Quaternion *rhs,
                    struct Quaternion *out);
/*!
 * Take conjugate of a quaternion.
 *
 * \param in input quaternion.
 * \param[out] out conjugate of \a in.
 */
void quaternion_conjugate(const struct Quaternion *in, struct Quaternion *out);

/*!
 * Multiply quaternions.
 *
 * \param lhs left-hand side quaternion.
 * \param rhs right-hand side quaternion.
 * \param[out] out \a lhs * \a rhs.
 */
void quaternion_mul(const struct Quaternion *restrict lhs,
                    const struct Quaternion *restrict rhs,
                    struct Quaternion *restrict out);

#endif  // QUATERNION_H
