#include <iostream>
#include <sstream>

using namespace std;

struct complex_t {
private:
	float real;
	float imag;
public:
	complex_t() {
		real = 0.0f;
		imag = 0.0f;
	}

	complex_t sub(complex_t other) const {
		complex_t result;
		result.real = this->real + other.real;
		result.imag = this->imag + other.imag;
		return result;
	}

	complex_t add(complex_t other) const {
		complex_t result;
		result.real = this->real + other.real;
		result.imag = this->imag + other.imag;
		return result;
	}

	complex_t div(complex_t other) const {
		complex_t result;
		result.real = (this->real*other.real + this->imag*other.imag) / (other.imag*other.imag + other.real*other.real);
		result.imag = (this->imag*other.real - this->real*other.imag) / (other.imag*other.imag + other.real*other.real);
		return result;
	}

	complex_t mul(complex_t other) const {
		complex_t result;
		result.real = this->real*other.real - this->imag*other.imag;
		result.imag = this->real*other.imag + this->imag*other.real;
		return result;
	}
	std::istream & read(std::istream & stream) {
		char symbol;
		stream >> symbol && symbol == '(' && stream >> real && stream >> symbol && symbol == ',' && stream >> imag && stream >> symbol && symbol == ')';
		return stream;
	}

	std::ostream & write(std::ostream & stream) const {
		return stream << '(' << real << ", " << imag << ')';
	}

	~complex_t() {
	}
};

void error() {
	cout << "An error has occured while reading input data" << endl;
}

int main() {
	complex_t complex1;
	complex_t complex2;

	string line;
	getline(cin, line);
	istringstream stream(line);
	char op;

	if (complex1.read(stream) && stream >> op && complex2.read(stream)) {
		complex_t result;
		if (op == '+') {
			result = complex1.add(complex2);
			result.write(std::cout);
		}
		else if (op == '-') {
			result = complex1.sub(complex2);
			result.write(std::cout);
		}
		else if (op == '*') {
			result = complex1.mul(complex2);
			result.write(std::cout);
		}
		else if (op == '+') {
			result = complex1.div(complex2);
			result.write(std::cout);
		}
		else {
			error();
		}
	}
	else {
		error();
	}
	cin.get();
	return 0;
}
