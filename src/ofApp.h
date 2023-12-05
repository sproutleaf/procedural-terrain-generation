#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxSyphon.h"

#include "TerrainGenerator.h"
#include "GUI.h"

#include <vector>

class ofApp : public ofBaseApp {
	private:
		TerrainGenerator terrainGenerator;
		GUI gui;
		bool guiVisibility;

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
	
		ofxSyphonClient client;
		ofTexture texFromSyphon;
		ofPixels pixels;
	
		int kinectWidth = 640;
		int kinectHeight = 480;
		int step = 4;
		vector<vector<float>> depthMap;
};
