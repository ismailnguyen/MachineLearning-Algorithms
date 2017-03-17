#pragma once
#include<vector>
#include<math.h>
typedef std::vector<double> datapoint;

extern "C"
{
	using namespace std;

	RBFNetwork(const std::vector<datapoint> &training_data, const std::vector<int> &training_labels, int num_of_labels);
	~RBFNetwork(void);

	/* Start Training the Radial Basis Function network
	Takes the number of RBF centroids, the learning rate, the number of iteration and a print flag as input
	Saves the output model to be used in testing and single predictions
	return accuracy and mse (by reference)
	*/
	double startTraining(int num_rbf_units, double learning_rate, int num_iterations, double &mse, bool print_flag = false);

	/* Start Testing the RBF Network to make sure it's not overfitting
	(Should be done after training) */
	void startTesting(const std::vector<datapoint> &testing_data, const std::vector<int> &testing_labels);


	/* Predict a single data point support multi-classes (One vs. All method)
	(Should be done after training of course) */
	int predictLabel(const datapoint &data_point, double &error);

	double gamma;
	std::vector< std::vector<double> > rbf_units;
	std::vector< std::vector<double> > layer2_weights;
	std::vector<datapoint> rbf_centroids;

	__declspec(dllexport) void calculateGamma();
	__declspec(dllexport) double distance(const datapoint &a, const datapoint &b);
	__declspec(dllexport) double basisFunction(const datapoint &data_point, const datapoint &centroid);

}