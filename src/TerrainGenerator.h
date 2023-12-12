#pragma once

#include "ofMain.h"
#include "TerrainElevation.h"
#include "TerrainColor.h"

#include <vector>

class TerrainGenerator {
	private:
		int mapWidth = 3200;
		int mapHeight = 2400;
		vector<vector<float>> elevationMap;

		TerrainElevation terrainElevation;
		TerrainColor terrainColor;

		ofMesh mesh;
		ofLight light;
		ofEasyCam camera;

	public:
		TerrainGenerator();
		void setup(const vector<vector<float>>& depthMap);
		void addTriangle(ofVec3f p1, ofVec3f p2, ofVec3f p3);
		void addVertex(ofVec3f p, float triangleElevation);
		void calculateNormals();
		void draw();
	
		const int tileSize = 25;
		const int maxElevation = 500;
};
