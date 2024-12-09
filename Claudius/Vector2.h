#pragma once
//TODO: make vector2 a Coordinate of ints.
struct Vector2 final{
    int x{};
    int y{};
    constexpr Vector2(const Vector2& rhs) noexcept : x(rhs.x), y(rhs.y){}
    constexpr Vector2(int x, int y) noexcept : x(x), y(y){}
    constexpr Vector2& operator=(const Vector2& rhs) noexcept {
        x = rhs.x;
        y = rhs.y;
        return *this;
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