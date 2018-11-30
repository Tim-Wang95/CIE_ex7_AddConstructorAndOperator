#include "DoubleVector.hpp"

namespace cie {

	DoubleVector::DoubleVector(int n):
		size_(n), vec(new double[size_]) {
		for (int i = 0; i < n; i++) { vec[i] = 0; }
	}

	DoubleVector::DoubleVector(const DoubleVector& other):
		vec(new double[other.size_]), size_(other.size_) {
		std::copy(other.vec, other.vec + size_, vec);
	}

	DoubleVector::DoubleVector():
		size_(0), vec(nullptr) {}

	DoubleVector::~DoubleVector() {
		delete[] vec;
	}

	double& DoubleVector::at(int i) {
		double& Re = vec[i]; return Re;
	}

	int DoubleVector::size() {
		return size_;
	}

	void DoubleVector::resize(int ns) {
		// len = _msize(vec) / sizeof(vec[0]); 
		if (ns != size_) {
			temp = new double[size_]; for (int i = 0; i < size_; i++) { temp[i] = vec[i]; }
			vec = new double[ns];

			if (ns > size_) {
				for (int i = 0; i < size_; i++) { vec[i] = temp[i]; }
				for (int i = size_; i < ns; i++) { vec[i] = 0; }
			}
			else if (ns < size_) {
				for (int i = 0; i < ns; i++) { vec[i] = temp[i]; }
			}
		}
		size_ = ns;
	}

	DoubleVector& DoubleVector::operator= (const DoubleVector& other) {
		double* newVec = new double[other.size_];
		std::copy(other.vec, other.vec + other.size_, newVec);
		delete[] vec;
		size_ = other.size_;
		vec = newVec;

		return *this;
	}

	double& DoubleVector::operator[] (int i) {
		double& Re = vec[i]; return Re;
	}


	void DoubleVector::push_back(double v) {
		// len = _msize(vec) / sizeof(vec[0]);
		temp = new double[size_]; for (int i = 0; i < size_; i++) { temp[i] = vec[i]; }
		vec = new double[size_+1];
		for (int i = 0; i < size_; i++) { vec[i] = temp[i]; }
		vec[size_] = v;
		size_ += 1;
	}

	void print(DoubleVector& v) {
		int length = v.size();
		std::cout << "[ ";
		for (int i = 0; i < length; i++) {
			std::cout << v.at(i) << " ";
		}
		std::cout << "]" << std::endl;
	}
	void userInput(DoubleVector& v) {
		int length = v.size(); double* t = new double[length];
		std::cout << "Input the values of the double vector [" << length << "]: ";
		for (int i = 0; i < length; i++) {
			std::cin >> t[i]; v.at(i) = t[i];
		}
		std::cout << std::endl;
	}
	double dotProduct(DoubleVector& v1, DoubleVector& v2) {
		double sum = 0;
		for (int i = 0; i < v1.size(); i++) {
			sum += v1.at(i) * v2.at(i);
		}
		return sum;
	}
}


