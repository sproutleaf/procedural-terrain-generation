#pragma once

#include "ofMain.h"

class TerrainColor {
    private:
        ofColor triangleColor;
		ofColor oceanColor = ofColor(100, 90, 255);
		ofColor coastColor = ofColor(60, 190, 255);
		ofColor beachColor = ofColor(240, 240, 170);
		ofColor plainColor = ofColor(140, 190, 90);
		ofColor forestColor = ofColor(14, 140, 0);
		ofColor hillColor = ofColor(10, 100, 30);
		ofColor mountainColor = ofColor(0, 70, 20);

        float triangleElevation;
		float oceanElevation = 0.0;
		float coastElevation = 0.4;
		float beachElevation = 0.5;
		float plainElevation = 0.55;
		float forestElevation = 0.75;
		float hillElevation = 0.85;
		float mountainElevation = 1.0;
		
    public:
	    TerrainColor();
	    void calculateColor(float triangleElevation);
        void interpolateColor(float lowElevation, float highElevation,
							  ofColor lowColor, ofColor highColor);
        ofColor getColor();
};
