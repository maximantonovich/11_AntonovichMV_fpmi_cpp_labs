#include "fraction.h"


fraction::fraction (int numerator, int denominator) : numerator (0), denominator (1)    
{
    this -> numerator = numerator;
    if (denominator != 0)
    {
        this -> denominator = denominator;
    }
    else
    {
        throw "denominator is 0";
    }
}

    fraction fraction::simplifier(int &num, int &denom)
    {
        bool flag;
        do
        {
            flag = false;
            for (int i = 2; i <= 9; i++)
            {
                if (num % i == 0 && denom % i == 0)
                {
                    num /= i;
                    denom /= i;
                    flag = true;
                }
            }
            
        }
        while (flag);
        return fraction(num,denom);
    }

    int fraction::get_numerator () const
    {
        return numerator;
    }
    int fraction::get_denominator () const
    {
        return denominator;
    }

    void fraction::set_numerator (int num)
    {
        numerator = num;
    }
    void fraction::set_denominator (int num)
    {
        denominator = num;
    }

    fraction fraction::operator+(const fraction& other)
    {
        int num, denom;
        if (other.denominator != this -> denominator)
        {
            num = this -> numerator * other.denominator + other.numerator * this -> denominator;
            denom = this -> denominator * other.denominator;
            
            return fraction::simplifier(num, denom);
        }
        else
        {
            num = other.numerator + this -> numerator;
            denom = other.denominator;
            return fraction::simplifier(num, denom);
        }

    }
    fraction fraction::operator-(const fraction& other)
    {
        int num, denom;
        if (other.denominator != this -> denominator)
        {
            num = this -> numerator * other.denominator - other.numerator * this -> denominator;
            denom = this -> denominator * other.denominator;
            
            return fraction::simplifier(num, denom);
        }
        else
        {
            num = this -> numerator - other.numerator;
            denom = other.denominator;
            return fraction::simplifier(num, denom);
        }
    }
    fraction fraction::operator*(const fraction& other)
    {
        int num, denom;
        num = this -> numerator * other.numerator;
        denom = this -> denominator * other.denominator;
        return fraction::simplifier(num, denom);
    }
    fraction fraction::operator/(const fraction& other)
    {
        int num, denom;
        num = this -> numerator * other.denominator;
        denom = this -> denominator * other.numerator;
        return fraction::simplifier(num, denom);
    }
    bool fraction::operator>(const fraction& other) const
    {
       return (this->numerator * other.denominator > other.numerator * this->denominator);
    }
    bool fraction::operator<(const fraction& other) const
    {
        return (this->numerator * other.denominator < other.numerator * this->denominator);
    }

    fraction fraction::operator+=(const fraction& other)
    {
        
        if (other.denominator != this -> denominator)
        {
            this -> numerator = this -> numerator * other.denominator + other.numerator * this -> denominator;
            this->denominator= this -> denominator * other.denominator;
            
            return fraction::simplifier(this->numerator, this->denominator);
        }
        else
        {
            this -> numerator += other.numerator;
            return fraction::simplifier(this->numerator, this->denominator);
        }
    }
    fraction fraction::operator-=(const fraction& other)
    {
         if (other.denominator != this -> denominator)
        {
            this -> numerator = this -> numerator * other.denominator - other.numerator * this -> denominator;
            this->denominator *= other.denominator;
            
            return fraction::simplifier(this->numerator, this->denominator);
        }
        else
        {
            this -> numerator -= other.numerator;
            return fraction::simplifier(this->numerator, this->denominator);
        }
    }
    fraction fraction::operator*=(const fraction& other)
    {
        this -> numerator *= other.numerator;
        this -> denominator *= other.denominator;
        return fraction::simplifier(this->numerator, this->denominator);
    }
    fraction fraction::operator/=(const fraction& other)
    {
        this -> numerator *= other.denominator;
        this -> denominator *= other.numerator;
        return fraction::simplifier(this->numerator, this->denominator);
    }


    bool fraction::operator==(const fraction& other) const
    {
        return (this->numerator * other.denominator == other.numerator * this->denominator);
    }
    bool fraction::operator!=(const fraction& other) const
    {
        return (this->numerator * other.denominator != other.numerator * this->denominator);
    }
    bool fraction::operator>=(const fraction& other) const
    {
        return (this->numerator * other.denominator >= other.numerator * this->denominator);
    }
    bool fraction::operator<=(const fraction& other) const
    {
        return (this->numerator * other.denominator <= other.numerator * this->denominator);
    }