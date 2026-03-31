#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed (int const n)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = n * (1 << this->fractionalBits);
}

Fixed::Fixed (const float nb)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(nb * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = other.value;
}
Fixed &Fixed::operator=(const Fixed &toAssign)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &toAssign)
        this->value = toAssign.value;
    return (*this);
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
    std::cout << "Destructor called" << std::endl;
}
