#pragma once
struct Cell final{
    int x{};
    int y{};
    constexpr Cell(int x, int y) noexcept : x(x), y(y){}  
    constexpr Cell(const Cell& rhs) noexcept : x(rhs.x), y(rhs.y){}      
    constexpr bool operator==(const Cell& rhs) const noexcept{
        return (this->x == rhs.x && this->y == rhs.y);
    }
    constexpr Cell& operator+=(const Cell& rhs) noexcept{
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
};