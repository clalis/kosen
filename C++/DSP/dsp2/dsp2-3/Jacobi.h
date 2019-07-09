#pragma once

#include<cmath>
#include<iostream>
#include"../Eigen/Core"


using namespace std;
using namespace Eigen;

class Jacobi
{
public:
	Jacobi();
	~Jacobi();
	void calc_jacobi();

private:
	Matrix3d a;
	Vector3d x0;
	Vector3d x1;
	const double epsilon = 0.0001;
	double lambda;
};

inline Jacobi::Jacobi()
{
	a <<
		2, 1, 3,
		1, 2, 3,
		3, 3, 20;
	x0 = Vector3d::UnitX();
	x1 = Vector3d::Zero();
	lambda = 0;
}

inline Jacobi::~Jacobi()
{
}

void Jacobi::calc_jacobi()
{
	for (size_t i = 0; i < a.rows(); i++)
	{
		while (true)
		{
			bool finish = true;

			x1 = a * x0;
			lambda = x1.transpose() * x0;
			x1.normalize();
			if ((x1 - x0).norm() > epsilon)	finish = false;
			x0 = x1;

			//cout << "lambda= " << lambda << endl << "Eigenvecor:" << endl << x1 << endl << endl;
			if (finish) break;
		}
		a -= lambda * x1 * x1.transpose();
		cout << "lambda= " << lambda << endl << "Eigenvecor:" << endl << x1 << endl << endl;
	}
}
