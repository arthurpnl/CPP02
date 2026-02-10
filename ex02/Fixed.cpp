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

Fixed &Fixed::operator=(const Fixed &toAssign)
{
    this->value = toAssign.value;
    //std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float   Fixed::toFloat(void) const
{
    return (float)this->value / (1 << this->fractionalBits);
}

int Fixed::toInt (void) const
{
    return this->value >> this->fractionalBits;
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
    o << fixed.toFloat();
    return o;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

bool Fixed::operator<(const Fixed &other) const
{
    if (this->getRawBits() < other.getRawBits())
        return (1);
    else
        return (0);
}

bool Fixed::operator>(const Fixed &other) const
{
    if (this->getRawBits() > other.getRawBits())
        return (1);
    else
        return (0);
}

bool Fixed::operator<=(const Fixed &other) const
{
    if (this->getRawBits() <= other.getRawBits())
        return (1);
    else
        return (0);
}

bool Fixed::operator>=(const Fixed &other) const
{
    if (this->getRawBits() >= other.getRawBits())
        return (1);
    else
        return (0);
}

bool Fixed::operator==(const Fixed &other) const
{
    if (this->getRawBits() == other.getRawBits())
        return (1);
    else
        return (0);
}

bool Fixed::operator!=(const Fixed &other) const
{ 
    if (this->getRawBits() != other.getRawBits())
        return (1);
    else
        return (0);
}

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

Fixed   &Fixed::operator++()
{
    ++this->value;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed tmp = *this;

    this->value++;
    return (tmp);
}

Fixed   &Fixed::operator--()
{
    --this->value;
    return (*this);
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp = *this;

    this->value--;
    return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed  &Fixed::max(Fixed &a, Fixed &b)
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