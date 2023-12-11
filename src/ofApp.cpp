#include "ofApp.h"

void ofApp::setup() {
	// Set up Kinect
	kinect.setRegistration(true);
	kinect.init();
	kinect.open();
	// kinect.setDepthClipping(500, 2500);

	ofBackground(0);
	guiVisibility = true;
	readDepth = true;

	// Initialize depth map used to calculate elevation map
	for (int y = 0; y <= kinect.getHeight(); y++) {
		vector<float> row;
		for (int x = 0; x <= kinect.getWidth(); x++) {
			row.push_back(0);
		}
		depthMap.push_back(row);
	}
}

void ofApp::update() {
	kinect.update();
	
	if (kinect.isFrameNew() && readDepth) {
		readDepth = false;
		ofShortPixels rawDepthPix = kinect.getRawDepthPixels();
		for (int y = 0; y < rawDepthPix.getHeight(); y++) {
			for (int x =  0; x < rawDepthPix.getWidth(); x++) {
				// Get the point depth from kinect
				float b = rawDepthPix.getColor(x, y).r;

				// Mapping point depth to raw elevation value, before performing
				// calculations
				float d = ofMap(b, 500, 2500, 0.4, 1.6);
				if (d < 0.4) {
					d = 0.4;
				} else if (d > 1.6) {
					d = 1.6;
				}
				depthMap.at(y).at(x) = d;
			}
		}
	}
}

void ofApp::draw() {
	if (gui.getIsAnySettingChanged()) {
		terrainGenerator.setup(gui.getSettings());
		gui.setIsAnySettingChanged();
	}

	terrainGenerator.draw();

	if (guiVisibility) {
		gui.draw();
	}

	readDepth = true;
}

void ofApp::keyPressed(int key) {
	if (key == 32) { //Space key
		guiVisibility = !guiVisibility;
	}
}
