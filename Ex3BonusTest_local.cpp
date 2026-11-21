#include "Vector.h"
#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;

std::string getVectorString(const Vector& v)
{
	return
		"[capacity: " + std::to_string(v.capacity()) +
		", size: " + std::to_string(v.size()) +
		", resize factor: " + std::to_string(v.resizeFactor()) + "]";
}

void addElementsToVector(Vector& v, const int elements[], const int numberOfElements)
{
	int element;
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
		v.push_back(elements[i]);
	}
}

std::string getVectorElementsString(Vector& v)
{
	std::string result = "";
	for (unsigned int i = 0; i < v.size(); i++)
	{
		result += std::to_string(v[i]) + ",";
	}
	if (v.size() > 0)
		result = result.substr(0, result.length() - 1);
	return result;
}

std::string getStreamOperatorString(Vector& v)
{
	std::stringstream ss;
	ss << v;
	return ss.str();
}

int testBonus()
{

	try
	{
		// Tests Ex3 Bonus - More operators

		cout <<
			"********************************************\n" <<
			"Test Bonus - operators +,+=,-,-=,<< \n" <<
			"********************************************\n" << endl;

		cout <<
			"Initializing Vector v1 with n=5 ... \n" << endl;

		Vector v1(5);
		std::string expected = "[capacity: 5, size: 0, resize factor: 5]";
		std::string got = getVectorString(v1);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			std::cout << " \n" << endl;
			return 3101;
		}


		cout <<
			"Initializing Vector v2 with n=5 ... \n" << endl;

		Vector v2(5);
		expected = "[capacity: 5, size: 0, resize factor: 5]";
		got = getVectorString(v2);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			std::cout << " \n" << endl;
			return 3101;
		}

		cout <<
			"Adding 3 elements to vector v1 (20,30,40) ... \n" << endl;

		const int v1elements[] = { 20,30,40 };
		addElementsToVector(v1, v1elements, 3);

		cout <<
			"Adding 3 elements to vector v2 (2,3,4) ... \n" << endl;

		const int v2elements[] = { 2,3,4 };
		addElementsToVector(v2, v2elements, 3);

		expected = "v1: 20,30,40\n";
		expected += "v2: 2,3,4";
		got = "v1: " + getVectorElementsString(v1) + "\nv2: " + getVectorElementsString(v2);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected:\n" << expected << endl;
			cout << "Got     :\n" << got << std::endl;
			std::cout << " \n" << endl;
			std::cout << " \n" << endl;
			return 3105;
		}

		cout <<
			"\nInitializing Vector v3, using operator+ with v1 and v2\n" << 
			 "Vector v3 = v1 + v2\n" << endl;
		Vector v3 = v1 + v2;

		expected = "v1: 20,30,40\n";
		expected += "v2: 2,3,4\n";
		expected += "v3: 22,33,44";
		got = "v1: " + getVectorElementsString(v1) + "\nv2: " 
			+ getVectorElementsString(v2) + "\nv3: " + getVectorElementsString(v3);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected:\n" << expected << endl;
			cout << "Got     :\n" << got << std::endl;
			std::cout << " \n" << endl;
			std::cout << " \n" << endl;
			return 3119;
		}

		cout <<
			"\nUsing operator+= with v3 and v2\n" <<
			"v3 += v2\n" << endl;
		v3 += v2;
		expected = "v2: 2,3,4\n";
		expected += "v3: 24,36,48";
		got = "v2: " + getVectorElementsString(v2) + "\nv3: " + getVectorElementsString(v3);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected:\n" << expected << endl;
			cout << "Got     :\n" << got << std::endl;
			std::cout << " \n" << endl;
			std::cout << " \n" << endl;
			return 3120;
		}

		cout <<
			"\nInitializing Vector v4, using operator- with v1 and v2\n" <<
			"Vector v4 = v1 - v2\n" << endl;
		Vector v4 = v1 - v2;

		expected = "v1: 20,30,40\n";
		expected += "v2: 2,3,4\n";
		expected += "v4: 18,27,36";
		got = "v1: " + getVectorElementsString(v1) + "\nv2: "
			+ getVectorElementsString(v2) + "\nv4: " + getVectorElementsString(v4);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected:\n" << expected << endl;
			cout << "Got     :\n" << got << std::endl;
			std::cout << " \n" << endl;
			std::cout << " \n" << endl;
			return 3121;
		}

		cout <<
			"\nUsing operator-= with v4 and v1\n" <<
			"v4 -= v1\n" << endl;
		v4 -= v1;
		expected = "v1: 20,30,40\n";
		expected += "v4: -2,-3,-4";
		got = "v1: " + getVectorElementsString(v1) + "\nv4: " + getVectorElementsString(v4);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected:\n" << expected << endl;
			cout << "Got     :\n" << got << std::endl;
			std::cout << " \n" << endl;
			std::cout << " \n" << endl;
			return 3122;
		}

		cout <<
			"\nUsing operator<< with v1\n" <<
			"std::cout << v1\n" << endl;
		expected = "Vector info:\nCapacity is 5\nSize is 3\ndata is {20,30,40}\n";
		got = getStreamOperatorString(v1);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			std::cout << " \n" << endl;
			return 3123;
		}


	}
	catch (...)
	{
		std::cerr << "\033[1;31mTest crashed\033[0m\n \n" << endl;
		std::cerr << "\033[1;31mFAILED: The program crashed, check the following things:\n\033[0m\n \n" <<
			"1. Did you delete a pointer twice?\n2. Did you access index out of bounds?\n" <<
			"3. Did you remember to initialize array before accessing it?";
		return 2;
	}

	return 0;

}

int main()
{
	std::cout <<
		"###################\n" <<
		"Exercise 3 - Vector\n" <<
		"Bonus - more operators \n" <<
		"###################\n" << std::endl;

	int testResult = testBonus();

	cout << (testResult == 0 ? "\033[1;32m \n****** Ex3 Bonus Tests Passed ******\033[0m\n \n" : "\033[1;31mEx3 Bonus Tests Failed\033[0m\n \n") << endl;

	return testResult;
}
