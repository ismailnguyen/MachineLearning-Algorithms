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
				model->weights[i][j][k] = randomValue(-1, 1);
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
	for (int i = 0; i < model->numLayers; i++)
	{
		if (model->weights != nullptr)
		{
			for (int j = 0; j < model->nlp[i]; j++)
			{
				delete[] model->weights[i][j];
			}
		}

		delete[] model->weights[i];
		delete[] model->computedOutputs[i];
		delete[] model->computedSum[i];
	}

	delete[] model->weights;
	delete[] model->computedOutputs;
	delete[] model->computedSum;
	delete[] model->deltas;
	delete[] model->nlp;
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
	for (int i = 1; i <= model->nlp[0]; ++i)
	{
		model->computedSum[0][i] = input[i - 1];
	}

	for (int l = 1; l <= model->numLayers; ++l)
	{
		for (int j = 1; j <= model->nlp[l]; ++j)
		{
			model->computedOutputs[l][j] = 0;

			for (int k = 0; k <= model->nlp[l - 1]; ++k)
			{
				model->computedOutputs[l][j] += model->weights[l][k][j] * model->computedSum[l - 1][k];
			}

			if (model->numLayers - 1 > 1)
			{
				model->computedSum[l][j] = tanh(model->computedOutputs[l][j]);
			}
			else
			{
				model->computedSum[l][j] = model->computedOutputs[l][j];
			}
		}
	}

	return model->computedOutputs[model->numLayers - 1];
}

double * mlp_predict(MLP * model, double * input, int inputSize)
{
	return nullptr;
}
