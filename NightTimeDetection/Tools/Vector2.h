#ifndef VECTOR2_H
#define VECTOR2_H
#include <math.h>
template <class V = float> class Vector2
{
public:
  /** The vector values */
  V x, y;

  /** Default constructor. */
  inline Vector2<V>() : x(V()) , y(V()) {}

  /** Constructor. */
  inline Vector2<V>(V x, V y) : x(x), y(y) {}

  /** Copy constructor
  *\param other The other vector that is copied to this one
  */
  inline Vector2<V>(const Vector2<V>& other) : x(other.x), y(other.y) {}

  /** Copy constructor from different element type
   *\param O The type of other's elements
   *\param other The other vector that is copied to this one
   */
  template<typename O> inline explicit Vector2<V>(const Vector2<O>& other) : x((V) other.x), y((V) other.y) {}

  /** Assignment operator
  *\param other The other vector that is assigned to this one
  *\return A reference to this object after the assignment.
  */
  #include <math.h>
  inline Vector2<V>& operator=(const Vector2<V>& other)
  {
    x = other.x;
    y = other.y;
    return *this;
  }


  /** Addition of another vector to this one.
  *\param other The other vector that will be added to this one
  *\return A reference to this object after the calculation.
  */
  inline Vector2<V>& operator+=(const Vector2<V>& other)
  {
    x += other.x;
    y += other.y;
    return *this;
  }

  /** Substraction of this vector from another one.
  *\param other The other vector this one will be substracted from
  *\return A reference to this object after the calculation.
  */
  inline Vector2<V>& operator-=(const Vector2<V>& other)
  {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  /** Multiplication of this vector by a factor.
  *\param factor The factor this vector is multiplied by
  *\return A reference to this object after the calculation.
  */
  inline Vector2<V>& operator*=(const V& factor)
  {
    x *= factor;
    y *= factor;
    return *this;
  }

  /** Division of this vector by a factor.
  *\param factor The factor this vector is divided by
  *\return A reference to this object after the calculation.
  */
  inline Vector2<V>& operator/=(const V& factor)
  {
    if(factor == V()) return *this;
    x /= factor;
    y /= factor;
    return *this;
  }

  /** Addition of another vector to this one.
  *\param other The other vector that will be added to this one
  *\return A new object that contains the result of the calculation.
  */
  inline Vector2<V> operator+(const Vector2<V>& other) const
  {
    return Vector2<V>(*this) += other;
  }

  /** Subtraction of another vector to this one.
  *\param other The other vector that will be added to this one
  *\return A new object that contains the result of the calculation.
  */
  inline Vector2<V> operator-(const Vector2<V>& other) const
  {
    return Vector2<V>(*this) -= other;
  }

  /** Negation of this vector.
  *\return A new object that contains the result of the calculation.
  */
  inline Vector2<V> operator-() const
  {
    return Vector2<V>(-x, -y);
  }

  /** Inner product of this vector and another one.
  *\param other The other vector this one will be multiplied by
  *\return The inner product.
  */
  inline V operator*(const Vector2<V>& other) const
  {
    return x * other.x + y * other.y;
  }

  /** Multiplication of this vector by a factor.
  *\param factor The factor this vector is multiplied by
  *\return A new object that contains the result of the calculation.
  */
  inline Vector2<V> operator*(const V& factor) const
  {
    return Vector2<V>(*this) *= factor;
  }

  /** Division of this vector by a factor.
  *
  *\param factor The factor this vector is divided by
  *\return A new object that contains the result of the calculation.
  */
  inline Vector2<V> operator/(const V& factor) const
  {
    return Vector2<V>(*this) /= factor;
  }

  /** Comparison of another vector with this one.
  *\param other The other vector that will be compared to this one
  *\return Whether the two vectors are equal.
  */
  inline bool operator==(const Vector2<V>& other) const
  {
    return x == other.x && y == other.y;
  }

  /** Comparison of another vector with this one.
  *\param other The other vector that will be compared to this one.
  *\return Whether the two vectors are unequal.
  */
  inline bool operator!=(const Vector2<V>& other) const
  {
    return x != other.x || y != other.y;
  }

  /** Calculation of the length of this vector.
  *\return The length.
  */

};

#endif // VECTOR2_H
