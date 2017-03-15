#include "MLP.h"

MLP * mlp_create_model(int numLayers, int * nlp)
{
	return nullptr;
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
