#include "ofApp.h"

void ofApp::setup() {
	ofBackground(0);
	guiVisibility = true;
	
	// Set up Syphon client
	client.setup();
	client.set("Kinect Depth", "crowd-control");
	
	// Initialize depth map used to calculate elevation map
	for (int y = 0; y <= kinectHeight / step; y++) {
		vector<float> row;
		for (int x = 0; x <= kinectWidth / step; x++) {
			row.push_back(0);
		}
		depthMap.push_back(row);
	}
	
	pixels.setImageType(OF_IMAGE_GRAYSCALE);
}

void ofApp::update() {
	// Need to surround the texture with bind & unbind for it to work
	client.bind();
	texFromSyphon = client.getTexture();
	
	// Convert texture to pixels for processing
	pixels.clear();
	depthMap.clear();
	texFromSyphon.readToPixels(pixels);
	for (int y = 0; y < pixels.getHeight(); y += step) {
		for (int x =  0; x < pixels.getWidth(); x += step) {
			float b = pixels.getColor(x, y).getBrightness();
			float d = ofMap(b, 0, 255, 0.4, 1.6);
			depthMap.at(y/step).at(x/step) = d;
		}
	}
	client.unbind();
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
}

void ofApp::keyPressed(int key) {
	if (key == 32) { //Space key
		guiVisibility = !guiVisibility;
	}
}
