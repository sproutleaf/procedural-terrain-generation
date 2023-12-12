#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxKinect.h"

#include "TerrainGenerator.h"
#include "GUI.h"

#include <vector>

class ofApp : public ofBaseApp {
	private:
		TerrainGenerator terrainGenerator;
		GUI gui;
		bool guiVisibility;
		bool readDepth, drawDepth;
		int step = 4;
		int nearClip = 500;
		int farClip = 3000;
		float maxDepthDiff = 0.1;
		float incrementRandomness = 0.03;
		float lowestTerrain = 0.1;
		float highestTerrain = 0.9;

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
	
		ofxKinect kinect;
		vector<vector<float>> depthMap;
};
