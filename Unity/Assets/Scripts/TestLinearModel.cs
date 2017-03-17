using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TestLinearModel : MonoBehaviour {

	[SerializeField]
	private Transform[] spheresTransform;

	// Modèle
	private System.IntPtr model;

	// Use this for initialization
	void Start () {
		// Initialisation du modèle
		model = MachineLearningLibWrapper.linear_create_model(2); // 2 dimensions

		foreach (var sphere in spheresTransform) {
			sphere.position += Vector3.up * 2;

			//MachineLearningLibWrapper.linear_fit_classification_rosenblatt(model, inputs, inputsSize, inputSize, iterationNumber, step, outputs);

			MachineLearningLibWrapper.linear_classify( model, input, inputSize);
		}

		MachineLearningLibWrapper.linear_remove_model(model);
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
