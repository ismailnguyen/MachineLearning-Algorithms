#include <cstdlib>
#include "Source.h"

double random_weight(double min, double max)
{
	double random = (double)rand() / RAND_MAX;
	return min + random * (max - min);
}

double * linear_create_model(int inputDimension)
{
	double * model = new double[inputDimension];

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

	delete[] model;
}

/*
	W = ((X^T * X)^-1 * X^T)Y    -- en une fois
*/
int linear_fit_regression(double * model, double * inputs, int inputsSize, int inputSize, double * outputs, int outputsSize)
{
	// Use eigen, inverse matrix

	return 0;
}

/*
	W = W + a(Y^k * g(X^k)) X^k
*/
int linear_fit_classification_rosenblatt(double * model, double * inputs, int inputsSize, int inputSize, int iterationNumber, double step, double * outputs)
{
	int success = 0;

	for (int iteration = 0; iteration < iterationNumber; iteration++)
	{
		for (int i = 0; i < inputsSize; i++)
		{
			for (int j = 0; j < inputSize; j++)
			{
				if (outputs[i] != linear_classify(model, inputs, inputSize))
				{
					model[i] = model[i] + step * (inputs[i * inputSize + j] - outputs[i]) * model[j];

					success = 1;
				}
			}
		}
	}

	return success;
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
