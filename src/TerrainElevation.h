#pragma once

#include "ofMain.h"
#include "GUI.h"

class TerrainElevation {
	private:
		int seed;
		int columns, rows;
		int octaves;
		float noiseScale;
		float lacunarity;
		float persistence;
		int maxElevation;
		float flattenElevation;
		float minNoiseZ, maxNoiseZ;
		int mapWidth = 3200;
		int mapHeight = 2400;
	
		vector<vector<float>> elevationMap;

	public:
		TerrainElevation();
		TerrainElevation(GUI::Settings s);
		void initializeMatrix();
		void calculateNoise();
		void calculateElevationMap();
		vector<vector<float>> getElevationMap();
};
