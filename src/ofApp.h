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
		bool readDepth;

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
	
		ofxKinect kinect;
		vector<vector<float>> depthMap;
};
