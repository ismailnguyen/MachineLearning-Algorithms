#include <cstdlib>
#include "Source.h"

double random_weight(double min, double max)
{
	double random = (double)rand() / RAND_MAX;
	return min + random * (max - min);
}

double * linear_create_model(int inputDimension)
{
	double * model;

	//  ALLOUER LE MODELE avec new
	for (int i = 0; i < inputDimension; i++)
	{
		model[i] = random_weight(-1, 1);
	}

	return model;
}

void linear_remove_model(double * model)
{
	if (model == nullptr)
	{
		return;
	}

	// DELETE []
	free(model);
}

/*
	W = ((X^T * X)^-1 * X^T)Y    -- en une fois
*/
int linear_fit_regression(double * model, double * inputs, int inputsSize, int inputSize, double * outputs, int outputsSize)
{
	int W = 0;

	double step = 1;

	for (int iteration = 0; iteration < inputsSize; iteration++)
	{
		for (int i = 0; i < inputsSize; i++)
		{
			// Iterer sur les entrees 
			W = W + step * (inputs[i] * model[i]) * linear_predict(model, inputs, inputsSize);
		}
	}

	return W;
}

/*
	W = W + a(Y^k * g(X^k)) X^k
*/
int linear_fit_classification_rosenblatt(double * model, double * inputs, int inputsSize, int inputSize, int iterationNumber, double step)
{
	int W = 0;

	for (int iteration = 0; iteration < iterationNumber; iteration++)
	{
		for (int i = 0; i < inputsSize; i++)
		{
			for (int j = 0; j < inputSize; j++)
				if ///
				W = W + step * (inputs[i * inputSize + j] * model[j]) * outputs[i];
		}
	}

	return W;
}

double linear_classify(double * model, double * input, int inputSize)
{
	double output = 0;

	for (int i = 0; i < inputSize; i++)
	{
		output = output + model[i] * input[i];
	}

	return output > 0 ? 1 : -1;
}

double linear_predict(double * model, double * input, int inputSize)
{
	double W = 0;

	for (int i = 0; i < inputSize; i++)
	{
		W = W + model[i] + input[i];
	}

	return W;
}
