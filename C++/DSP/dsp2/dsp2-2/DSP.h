#pragma once

#define _USE_MATH_DEFINES

#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "../Eigen/Dense"
#include "bitmap/bitmap_image.h"


using namespace Eigen;
using namespace std;

class DCT
{
public:
	DCT(unsigned int size) :N(size)
	{
		cout << "Starting DCT..." << endl;
	}

	~DCT()
	{
		cout << "\nClosing DCT..." << endl;
	}

	MatrixXf cnk();

private:
	unsigned int N;
};

MatrixXf DCT::cnk()
{
	MatrixXf m = MatrixXf::Zero(N, N);

	for (size_t n = 0; n < N; n++)
		for (size_t k = 0; k < N; k++)
		{
			if (k == 0)
				m(k, n) = 1 / sqrtf(static_cast<float>(N));
			else
				m(k, n) = M_SQRT2 / sqrtf(static_cast<float>(N)) * cosf((2 * n + 1) * k * M_PI_2 / N);
		}

	return m;
}

class MyBMP
{
public:
	MyBMP() :r(0.0), g(0.0), b(0.0), y(0.0), cb(0.0), cr(0.0) {}
	MyBMP(rgb_t colour) :y(0.0), cb(0.0), cr(0.0)
	{
		r = static_cast<double>(colour.red);
		g = static_cast<double>(colour.green);
		b = static_cast<double>(colour.blue);
	}

	~MyBMP()
	{
	}

	inline double rgbtToInt(char v) { return static_cast<unsigned int>(v); }

	inline double getY()
	{
		rgb_to_ycbcr(1, &r, &g, &b, &y, &cb, &cr);
		y = (static_cast<int>(y) + 112) >> 8;
		y += 16;

		return y;
	}


private:
	double r, g, b, y, cb, cr;
};
