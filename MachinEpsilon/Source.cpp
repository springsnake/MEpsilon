#include <iostream>
#include <stdint.h>
#include <iomanip>

template<typename float_t, typename int_t>
float_t machine_eps()
{
	union {
		float_t f;
		int_t   i;
	} one, one_plus, little, last_little;

	one.f = 1.0;
	little.f = 1.0;
	last_little.f = little.f;

	while (true) {
		one_plus.f = one.f;
		one_plus.f += little.f;
		if (one.i != one_plus.i)
		{
			last_little.f = little.f;
			little.f /= 2.0;
		} else {
			return last_little.f;
		}
	}
}

int main()
{
	using namespace std;
	cout << "machine epsilon:\n";
	cout << "float: " << setprecision(18) << machine_eps<float, uint32_t>() << endl;
	cout << "double: " << setprecision(18) << machine_eps<double, uint64_t>() << endl;
}