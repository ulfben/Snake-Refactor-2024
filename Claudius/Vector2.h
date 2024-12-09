#pragma once
//TODO: make vector2 a Coordinate of ints.
struct Vector2 final{
    float x{};
    float y{};
    constexpr Vector2(const Vector2& rhs) noexcept : x(rhs.x), y(rhs.y){}
    constexpr Vector2(const float x, const float y) noexcept : x(x), y(y){}
    constexpr Vector2& operator=(const Vector2& rhs) noexcept {
        x = rhs.x;
        y = rhs.y;
        return *this;
    }
    constexpr Vector2 operator+(const Vector2& rhs) const noexcept{
        return Vector2(x + rhs.x, y + rhs.y);
    }
    constexpr Vector2 operator-(const Vector2& rhs) const noexcept{
        return Vector2(x - rhs.x, y - rhs.y);
    }
    constexpr Vector2 operator*(const Vector2& rhs) const noexcept{
        return Vector2(x * rhs.x, y * rhs.y);
    }
    constexpr Vector2 operator/(const Vector2& rhs) const noexcept{
        return Vector2(x / rhs.x, y / rhs.y);
    }
    constexpr Vector2 operator*(const float rhs) const noexcept{
        return Vector2(x * rhs, y * rhs);
    }
    constexpr Vector2 operator/(const float rhs) const noexcept{
        return Vector2(x / rhs, y / rhs);
    }
    constexpr bool operator==(const Vector2& rhs) const noexcept{
        return (this->x == rhs.x && this->y == rhs.y);
    }
    constexpr Vector2& operator-=(const Vector2& rhs) noexcept{
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    };
    constexpr Vector2& operator+=(const Vector2& rhs) noexcept{
        x += rhs.x;
        y += rhs.y;
        return *this;
    };
};