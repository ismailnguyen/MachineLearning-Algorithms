extern "C"
{
	using namespace std;

	struct MLP
	{
		double*** weights;
		double** computedOutputs;
		double** computedSum;
		double** deltas;
		int numLayers;
	};

	__declspec(dllexport) MLP * mlp_create_model(int numLayers, int * nlp);
	__declspec(dllexport) void mlp_remove_model(MLP * model);
	__declspec(dllexport) int mlp_fit_regression_backdrop(MLP * model, double * inputs, int inputsSize, int inputSize, double * outputs, int outputsSize, int outpoutSize, int iterationNumber, double step);
	__declspec(dllexport) int mlp_fit_classification_backdrop(MLP * model, double * inputs, int inputsSize, int inputSize, double * outputs, int outputsSize, int outpoutSize, int iterationNumber, double step);
	__declspec(dllexport) double * mlp_classify(MLP * model, double * input, int inputSize);
	__declspec(dllexport) double * mlp_predict(MLP * model, double * input, int inputSize); 
}