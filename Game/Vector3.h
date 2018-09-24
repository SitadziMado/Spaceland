#pragma once

#include <tuple>

#include "Utility.h"

namespace Core
{
    class Vector3
    {
    public:
        constexpr Vector3() : x_(0.), y_(0.), z_(0.) {}
        constexpr Vector3(Float x, Float y, Float z) 
            : x_(x), y_(y), z_(z) {}

        static constexpr Vector3 zero();
        static constexpr Vector3 one();
        static Vector3 normalize(const Vector3& value);

        constexpr Vector3& operator+=(const Vector3& rhs);
        constexpr Vector3& operator-=(const Vector3& rhs);
        constexpr Vector3& operator*=(Float rhs);
        constexpr Vector3& operator/=(Float rhs);

        Float length() const;
        constexpr Float lengthSq() const;
        Vector3& normalize();
        constexpr std::tuple<Float, Float, Float> asTuple() const;

        constexpr Float getX() const;
        constexpr Float getY() const;
        constexpr Float getZ() const;
        constexpr Vector3& setX(Float value);
        constexpr Vector3& setY(Float value);
        constexpr Vector3& setZ(Float value);

    private:
        Float x_;
        Float y_;
        Float z_;
    };

    constexpr Vector3 Vector3::zero()
    {
        return {};
    }

    constexpr Vector3 Vector3::one()
    {
        return { 1., 1., 1. };
    }

    constexpr Vector3& Vector3::operator+=(const Vector3& rhs)
    {
        setX(getX() + rhs.getX());
        setY(getY() + rhs.getY());
        setZ(getZ() + rhs.getZ());
        return *this;
    }

    constexpr Vector3& Vector3::operator-=(const Vector3& rhs)
    {
        setX(getX() - rhs.getX());
        setY(getY() - rhs.getY());
        setZ(getZ() - rhs.getZ());
        return *this;
    }

    constexpr Vector3& Vector3::operator*=(Float rhs)
    {
        setX(getX() * rhs);
        setY(getY() * rhs);
        setZ(getZ() * rhs);
        return *this;
    }

    constexpr Vector3& Vector3::operator/=(Float rhs)
    {
        return *this *= (1. / rhs);
    }

    constexpr Float Vector3::lengthSq() const
    {
        return x_ * x_ + y_ * y_;
    }

    constexpr std::tuple<Float, Float, Float> Vector3::asTuple() const
    {
        return { x_, y_, z_ };
    }

    constexpr Float Vector3::getX() const
    {
        return x_;
    }

    constexpr Float Vector3::getY() const
    {
        return y_;
    }

    constexpr Float Vector3::getZ() const
    {
        return z_;
    }

    constexpr Vector3& Vector3::setX(Float value)
    {
        x_ = value;
        return *this;
    }

    constexpr Vector3& Vector3::setY(Float value)
    {
        y_ = value;
        return *this;
    }

    constexpr Vector3& Vector3::setZ(Float value)
    {
        z_ = value;
        return *this;
    }

    constexpr Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
    {
        return Vector3(lhs) += rhs;
    }

    constexpr Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
    {
        return Vector3(lhs) -= rhs;
    }

    constexpr Vector3 operator*(const Vector3& lhs, Float rhs)
    {
        return Vector3(lhs) *= rhs;
    }

    constexpr Vector3 operator*(Float lhs, const Vector3& rhs)
    {
        return Vector3(rhs) *= lhs;
    }

    constexpr Vector3 operator/(const Vector3& lhs, Float rhs)
    {
        return Vector3(lhs) /= rhs;
    }

    constexpr Float operator*(const Vector3& lhs, const Vector3& rhs)
    {
        return lhs.getX() * rhs.getX() + 
            lhs.getY() * rhs.getY() + 
            lhs.getZ() * rhs.getZ();
    }

    /**
     * \brief Векторное произведение векторов.
     * \param lhs Левый вектор.
     * \param rhs Правый вектор.
     * \return Псевдовектор, по длине равный площади параллелограмма,
     * построенного на входных векторах.
     */
    constexpr Vector3 operator^(const Vector3& lhs, const Vector3& rhs)
    {
        return {
            lhs.getY() * rhs.getZ() - lhs.getZ() * rhs.getY(),
            lhs.getZ() * rhs.getX() - lhs.getX() * rhs.getZ(),
            lhs.getX() * rhs.getY() - lhs.getY() * rhs.getX()
        };
    }
}
