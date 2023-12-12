#pragma once

#include "ofMain.h"

#include <vector>

class TerrainElevation {
	private:
		int columns, rows;
		int maxElevation;
		float flattenElevation = 1.0;
		float minNoiseZ, maxNoiseZ;
		int mapWidth = 3200;
		int mapHeight = 2400;
	
		vector<vector<float>> elevationMap;

	public:
		TerrainElevation();
		TerrainElevation(int tileSize, int maxElevation);
		void initializeMatrix();
		void calculateElevationMap(const vector<vector<float>>& depthMap);
		vector<vector<float>> getElevationMap();
};
