#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <vector>
#include "../Eigen/Core"
#include "../Eigen/StdVector"


using namespace std;
using namespace Eigen;

class DWT
{
public:
	DWT(VectorXf raw) :data(raw) { cout << "Starting DWT..." << endl; }
	~DWT() { cout << "Finishing DWT..." << endl; }

	VectorXf enDWT(VectorXf scaling);
	VectorXf deDWT(VectorXf scaling, VectorXf wavelet);
	VectorXf data;
	vector<VectorXf, aligned_allocator<VectorXf>> scalings;
	vector<VectorXf, aligned_allocator<VectorXf>> wavelets;
};


VectorXf DWT::enDWT(VectorXf scaling)
{
	VectorXf scaling_ans, wavelet_ans;
	Map<VectorXf, 0, InnerStride<2>> even(scaling.data(), scaling.size() / 2);
	Map<VectorXf, 0, InnerStride<2>> odd(scaling.data() + 1, scaling.size() / 2);
	scaling_ans = ((even + odd) * M_SQRT1_2);
	wavelet_ans = ((even - odd) * M_SQRT1_2);
	cout << "scaling:\t" << scaling_ans.transpose() << endl
		<< "wavelet:\t" << wavelet_ans.transpose() << endl;

	scalings.push_back(scaling_ans);
	wavelets.push_back(wavelet_ans);


	//if (scaling_ans.size() >= 2)	enDWT(scaling_ans);
	//else
	return scaling_ans;
}


VectorXf DWT::deDWT(VectorXf scaling, VectorXf wavelet)
{
	VectorXf ans(scaling.size() + wavelet.size()), even(scaling.size()), odd(wavelet.size());
	even = ((scaling + wavelet) * M_SQRT1_2);
	odd = ((scaling - wavelet) * M_SQRT1_2);

	for (size_t i = 0; i < ans.size(); i++)
	{
		if ((i % 2) == 0)	ans(i) = even(i / 2);
		else	ans(i) = odd(i / 2);
	}
	cout << "decoded:\t" << ans.transpose() << endl;

	//if (scaling_ans.size() >= 2)	deDWT(ans, wavelets.at());
	//else
	return ans;
}
