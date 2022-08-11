#include "FuzzyNumber.h"

FuzzyNumber::FuzzyNumber()
	:x(0),l(0),r(0)
{
}

FuzzyNumber::FuzzyNumber(double x, double l, double r) throw(logic_error)
{
	if (!(x > (x - l) && (x + r) > x))
		throw logic_error("Condition is not met");//стандартний


	this->set_x(x);
	this->set_l(x - l);
	this->set_r(x + r);
}

FuzzyNumber::FuzzyNumber(const FuzzyNumber& v)
{
	x = v.x;
	r = v.r;
	l = v.l;
}

FuzzyNumber& FuzzyNumber::operator=(const FuzzyNumber& n)
{
	x = n.x;
	l = n.l;
	r = n.r;
	return *this;
}

FuzzyNumber::operator string() const
{
	stringstream ss;
	ss << "(" << this->l << "; " << this->x << "; " << this->r << ")" << endl;
	return ss.str();
}

FuzzyNumber& FuzzyNumber::operator--() throw(InheritedException)
{
	--l;
	if (l < 0)
		throw new InheritedException();
	return *this;
}

FuzzyNumber& FuzzyNumber::operator++() throw(Exception)
{
	++l;
	if (r > 10)
		throw Exception("Right coordinate is bigger than 10");//власний
	return *this;
}

FuzzyNumber FuzzyNumber::operator--(int) throw(InheritedException)
{
	FuzzyNumber a(*this);
	l--;
	if (l < 0)
		throw InheritedException();//нащадок
	return a;
}

FuzzyNumber& FuzzyNumber::operator++(int) throw(logic_error)
{
	FuzzyNumber a(*this);
		r++;
		if (r > 10)
			throw logic_error("Right coordinate is bigger than 10");//
		return a;
}

FuzzyNumber operator+(const FuzzyNumber a, const FuzzyNumber b)
{
	FuzzyNumber T;
	T.x = a.x + b.x;
	T.l = a.x + b.x - a.l - b.l;
	T.r = a.x + b.x + a.r + b.r;
	return T;
}

FuzzyNumber operator*(const FuzzyNumber a, const FuzzyNumber b)
{
	FuzzyNumber T;
	T.x = a.x + b.x;
	T.l = a.x + b.x - a.l - b.l;
	T.r = a.x + b.x + a.r + b.r;
	return T;
}

ostream& operator<<(ostream& out, const FuzzyNumber& a)
{
	return out << string(a);
}

istream& operator>>(istream& in, FuzzyNumber& a) throw(logic_error)
{
	double x, l, r;
	cout << "x = "; in >> x;
	cout << "l = "; in >> l;
	cout << "r = "; in >> r;

	if (!(x > (x - l) && (x + r) > x))
		throw logic_error("Condition is not met");

	a.set_x(x); a.set_l(x - l); a.set_r(x + r);
	return in;
}
