#include "FuzzyNumber.h"

void _unexpected_to_bad()
{
	cerr << "bad_exception" << endl;
	throw;
}

void Call_Bad() throw(bad_exception)
{
	throw bad_exception();
}

int main()
{
	set_unexpected(_unexpected_to_bad);

	cout << "Number of elements of class FuzzyNumber : " << FuzzyNumber::Count() << endl;

	try
	{
		FuzzyNumber A;
		cin >> A;
		cout << A;

		cout << "Size of class: " << sizeof(A) << endl;

		FuzzyNumber B(5, 1, 7);
		cout << B << endl;

		cout << "Number of elements of class FuzzyNumber : " << FuzzyNumber::Count() << endl;

		FuzzyNumber C = A + B;
		cout << "C = " << C << endl;

		FuzzyNumber D = A * B;
		cout << "D = " << D << endl;
		try
		{
			A--;
		}
		catch (InheritedException a)
		{
			cerr << a.What() << endl << endl;
		}
		catch (InheritedException* a)
		{
			cerr << a->What() << endl << endl;
		}
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	cout << "Number of elements of class FuzzyNumber : " << FuzzyNumber::Count() << endl;

	FuzzyNumber N;
	cin >> N;
	cout << N;

	cout << "Number of elements of class FuzzyNumber : " << FuzzyNumber::Count() << endl;

	try
	{
		N++;
	}
	catch (Exception& a)
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Call_Bad();
	}
	catch (bad_exception)
	{
		cerr << "catch (bad_exception)" << endl;
	}
}