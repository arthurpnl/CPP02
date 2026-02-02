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
        Fixed(const Fixed &src);
        Fixed &operator=(const Fixed &toAssign);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif