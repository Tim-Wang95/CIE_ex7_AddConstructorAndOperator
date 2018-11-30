#include <iostream>
#include <algorithm>

namespace cie {
	class DoubleVector {
	public:
		DoubleVector(int n);
		DoubleVector(const DoubleVector& other);
		DoubleVector();
		~DoubleVector();
		double& at(int i);
		int size();
		void resize(int ns);
		void push_back(double v);
		DoubleVector& operator= (const DoubleVector& other);
		double& operator[] (int i);

	private:
		int size_; //double& Re;
		double* vec; double* temp;
	};

	void print(DoubleVector& v);
	void userInput(DoubleVector& v);
	double dotProduct(DoubleVector& v1, DoubleVector& v2);

}


