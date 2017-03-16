#include <cstdlib>
#include <iostream>
#include "MLP.h"

double randomValue(double min, double max)
{
	double random = (double)rand() / RAND_MAX;
	return min + random * (max - min);
}

MLP * mlp_create_model(int numLayers, int * nlp)
{
	MLP * model = new MLP();
	model->weights = new double**[numLayers];
	model->computedOutputs = new double*[numLayers];
	model->computedSum = new double*[numLayers];
	model->deltas = new double*[numLayers];
	model->numLayers = numLayers;
	model->nlp = nlp;

	for (int i = 0; i < numLayers; ++i)
	{
		model->weights[i] = new double*[nlp[i - 1] + 1];

		for (int j = 0; j <= nlp[i - 1]; ++j)
		{
			model->weights[i][j] = new double[nlp[i] + 1];

			for (int k = 0; k < nlp[i]; ++k)
			{
				model[i][j][k] = randomValue(-1, 1);
			}
		}
	}

	for (int i = 0; i < numLayers; i++)
	{
		model->computedOutputs[i] = new double[nlp[i] + 1];

		model->computedOutputs[i][0] = 1;

		model->computedSum[i] = new double[nlp[i] + 1];
		model->computedSum[i][0] = 1;
	}

	return model;
}

void mlp_remove_model(MLP * model)
{
}

int mlp_fit_regression_backdrop(MLP * model, double * inputs, int inputsSize, int inputSize, double * outputs, int outputsSize, int outpoutSize, int iterationNumber, double step)
{
	return 0;
}

int mlp_fit_classification_backdrop(MLP * model, double * inputs, int inputsSize, int inputSize, double * outputs, int outputsSize, int outpoutSize, int iterationNumber, double step)
{
	return 0;
}

double * mlp_classify(MLP * model, double * input, int inputSize)
{
	return nullptr;
}

double * mlp_predict(MLP * model, double * input, int inputSize)
{
	return nullptr;
}
