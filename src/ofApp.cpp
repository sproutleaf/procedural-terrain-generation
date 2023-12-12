#include "ofApp.h"
#include "ofMath.h"

#include <cmath>

void ofApp::setup() {
	// Set up Kinect
	kinect.setRegistration(true);
	kinect.init();
	kinect.open();
	kinect.setDepthClipping(nearClip, farClip);

	ofBackground(0);
	guiVisibility = true;
	readDepth = true;
	drawDepth = false;

	// Initialize depth map used to calculate elevation map
	for (int y = 0; y <= kinect.getHeight(); y += step) {
		vector<float> row;
		for (int x = 0; x <= kinect.getWidth(); x += step) {
			row.push_back(0);
		}
		depthMap.push_back(row);
	}
}

void ofApp::update() {
	kinect.update();
	
	float prevD = 0;
	if (readDepth) {
		readDepth = !readDepth;
		ofShortPixels rawDepthPix = kinect.getRawDepthPixels();
		for (int y = 0; y <= rawDepthPix.getHeight(); y += step) {
			for (int x =  0; x <= rawDepthPix.getWidth(); x += step) {
				// Get the point depth from kinec t
				float b = rawDepthPix.getColor(x, y).r;

				// Mapping point depth to raw elevation value, before performing
				// calculations
				float d = ofMap(b, nearClip, farClip,
								lowestTerrain, highestTerrain);
				if (d < lowestTerrain) d = lowestTerrain;
				else if (d > highestTerrain) d = highestTerrain;
				
				// If current depth is not the first one in the row, we need to
				// account for the maximum difference it can have vis-a-vis the
				// previous depth
				if (x != 0) {
					float depthDiff = d - prevD;
					if (std::abs(depthDiff) > maxDepthDiff) {
						float randomInc = ofRandom(-incrementRandomness,
												   incrementRandomness);
						// Terrain rising horizontally
						if (depthDiff > 0) {
							d = prevD + (maxDepthDiff + randomInc);
						} else {
							d = prevD - (maxDepthDiff + randomInc);
						}
					}
				}
				depthMap.at(y / step).at(x / step) = d;
				prevD = d;
			}
		}
	}
	
	drawDepth = !drawDepth;
}

void ofApp::draw() {
	if (drawDepth) {
		terrainGenerator.setup(gui.getSettings(), depthMap);
		terrainGenerator.draw();
	}

	if (guiVisibility) {
		gui.draw();
	}

	readDepth = !readDepth;
	drawDepth = !drawDepth;
}

void ofApp::keyPressed(int key) {
	if (key == 32) { //Space key
		guiVisibility = !guiVisibility;
	}
}
