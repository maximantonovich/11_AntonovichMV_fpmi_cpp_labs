#ifndef FRACTION_H
#define FRACTION_H

struct fraction
{
    private:
    int numerator;
    int denominator;
    public:
    fraction (int = 0, int = 1);

    fraction simplifier(int &, int &);

    int get_numerator () const;
    int get_denominator () const;

    void set_numerator (int num);
    void set_denominator (int num);

    fraction operator+(const fraction&);
    fraction operator-(const fraction&);
    fraction operator*(const fraction&);
    fraction operator/(const fraction&);
    bool operator>(const fraction&) const;
    bool operator<(const fraction&) const;

    fraction operator+=(const fraction&);
    fraction operator-=(const fraction&);
    fraction operator*=(const fraction&);
    fraction operator/=(const fraction&);
    bool operator==(const fraction&) const;
    bool operator!=(const fraction&) const;
    bool operator>=(const fraction&) const;
    bool operator<=(const fraction&) const;
};



#endif