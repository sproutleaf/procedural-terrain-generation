#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxKinect.h"

#include "TerrainGenerator.h"

#include <vector>

class ofApp : public ofBaseApp {
	private:
		TerrainGenerator terrainGenerator;
		bool readDepth, drawDepth;
		int step = 4;
		int nearClip = 500;
		int farClip = 3500;
		float maxDepthDiff = 0.1;
		float incrementRandomness = 0.03;
		float lowestTerrain = 0.05;
		float highestTerrain = 0.95;

	public:
		void setup();
		void update();
		void draw();
	
		ofxKinect kinect;
		vector<vector<float>> depthMap;
};
