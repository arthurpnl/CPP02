#include "Fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
}

Fixed::Fixed(int const n)
{
    this->value = n * (1 << this->fractionalBits);
}

Fixed::Fixed(const float nb)
{
    this->value = roundf(nb * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &toAssign)
{
    this->value = toAssign.value;
    return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->value / (1 << this->fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->value >> this->fractionalBits;
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
    o << fixed.toFloat();
    return o;
}

// Comparison operators
bool Fixed::operator<(const Fixed &other) const
{
    return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->getRawBits() != other.getRawBits());
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(toFloat() / other.toFloat());
}

// Increment/Decrement
Fixed &Fixed::operator++()
{
    ++this->value;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    this->value++;
    return (tmp);
}

Fixed &Fixed::operator--()
{
    --this->value;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->value--;
    return (tmp);
}

// Min/Max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}