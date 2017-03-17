#pragma once
#include <vector>
#include <random>
#include <assert.h>
typedef std::vector<double> datapoint;

extern "C"
{
	using namespace std;

	std::vector<int> nearest_cluster_idx;
	std::vector<double> nearest_cluster_dist;
	std::vector<datapoint>initial_centroids_;
	std::vector<datapoint> cur_centroids_;
	std::vector<datapoint> prev_centroids_;

	__declspec(dllexport) KmeansPP(const std::vector<datapoint> &input_data);
	__declspec(dllexport) ~KmeansPP(void);

	__declspec(dllexport) void init();
	__declspec(dllexport) void updateNearestClusters(const std::vector<datapoint> &centroids_);
	__declspec(dllexport) void updateCentroids(const std::vector<datapoint> &centroids_);
	__declspec(dllexport) int getNextInitialCentroidIndex();
	__declspec(dllexport) int getClosestCentroidIndex(int data_point_idx, const std::vector<datapoint> &centroids_);
	__declspec(dllexport) double distance(const datapoint &a, const datapoint &b);
	__declspec(dllexport) bool equalCentroids(const std::vector<datapoint> &a, const std::vector<datapoint> &b);
	__declspec(dllexport) datapoint getMeanCentroid(const std::vector<datapoint> &centroids_);
}
