using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public static class MachineLearningLibWrapper {

	public static class Linear {
		
		[DllImport("LinearModelLib")]
		public static extern System.IntPtr linear_create_model(int inputDimension);

		[DllImport("LinearModelLib")]
		public extern void linear_remove_model(System.IntPtr model);

		[DllImport("LinearModelLib")]
		public static extern int linear_fit_regression(System.IntPtr model, System.IntPtr inputs, int inputsSize, int inputSize, System.IntPtr outputs, int outputsSize);

		[DllImport("LinearModelLib")]
		public static extern int linear_fit_classification_rosenblatt(System.IntPtr model, System.IntPtr inputs, int inputsSize, int inputSize, int iterationNumber, double step, System.IntPtr outputs);
		
		[DllImport("LinearModelLib")]
		public static extern double linear_classify(System.IntPtr model, System.IntPtr input, int inputSize);
		
		[DllImport("LinearModelLib")]
		public static extern double linear_predict(System.IntPtr model, System.IntPtr input, int inputSize);
	}

	public static class MLP {

		[DllImport("MLPLib")]
		public static extern System.IntPtr[] mlp_create_model(int numLayers, System.IntPtr nlp);
		
		[DllImport("MLPLib")]
		public static extern void mlp_remove_model(MLP * model);
		
		[DllImport("MLPLib")]
		public static extern int mlp_fit_regression_backdrop(System.IntPtr[] model, System.IntPtr inputs, int inputsSize, int inputSize, System.IntPtr outputs, int outputsSize, int outpoutSize, int iterationNumber, double step);
		
		[DllImport("MLPLib")]
		public static extern int mlp_fit_classification_backdrop(System.IntPtr[] model, System.IntPtr inputs, int inputsSize, int inputSize, System.IntPtr outputs, int outputsSize, int outpoutSize, int iterationNumber, double step);
		
		[DllImport("MLPLib")]
		public static extern System.IntPtr mlp_classify(System.IntPtr[] model, System.IntPtr input, int inputSize);
		
		[DllImport("MLPLib")]
		public static extern System.IntPtr mlp_predict(System.IntPtr[] model, System.IntPtr input, int inputSize); 
	}

	public static class RBF {

		//[DllImport("RBFLib")]
	}
}
