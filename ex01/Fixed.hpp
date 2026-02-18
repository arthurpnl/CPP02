#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
    private:
        int value;
        const int static  fractionalBits = 8;

    public:
        Fixed();
        ~Fixed();
        Fixed(const int tmp);
        Fixed(const float nb);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &toAssign);
        float   toFloat(void) const;
        int toInt (void) const;
};
        std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif