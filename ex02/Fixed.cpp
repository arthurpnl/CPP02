#include "Fixed.hpp"

Fixed::Fixed()
{
    //std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed (int const n)
{
    //std::cout << "Int constructor called" << std::endl;
    this->value = n * (1 << this->fractionalBits);
}

Fixed::Fixed (const float nb)
{
    //std::cout << "Float constructor called" << std::endl;
    this->value = roundf(nb * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    //std::cout << "Copy constructor called" << std::endl;
    this->value = other.value;
}

Fixed &Fixed::operator=(const Fixed &toAssign)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &toAssign)
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
    Fixed result;
    result.setRawBits(this->value + other.value);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->value - other.value);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->value * other.value) >> fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->value << fractionalBits) / other.value);
    return result;
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