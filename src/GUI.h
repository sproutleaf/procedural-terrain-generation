#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class GUI {
	private:
		bool isAnySettingChanged;

		ofxPanel generalSettingsPanel;
		ofxIntSlider seedSlider;
		ofxIntSlider tileSizeSlider;

		ofxPanel noiseSettingsPanel;
		ofxIntSlider octavesSlider;
		ofxFloatSlider noiseScaleSlider;
		ofxFloatSlider lacunaritySlider;
		ofxFloatSlider persistenceSlider;

		ofxPanel elevationSettingsPanel;
		ofxIntSlider maxElevationSlider;
		ofxFloatSlider flattenElevationSlider;

	public:
		GUI();

		struct Settings {
			int seed;
			int tileSize;
			int mapWidth;
			int mapHeight;
			int octaves;
			float noiseScale;
			float lacunarity;
			float persistence;
			int maxElevation;
			float flattenElevation;
		};

		struct Settings getSettings();

		void draw();

		void setIsAnySettingChanged();
		bool getIsAnySettingChanged();

		void seedSliderChanged(int& seedSlider);
		void tileSizeSliderChanged(int& tileSizeSlider);
		void octavesSliderChanged(int& octavesSlider);
		void noiseScaleSliderChanged(float& noiseScaleSlider);
		void lacunaritySliderChanged(float& lacunaritySlider);
		void persistenceSliderChanged(float& persistenceSlider);
		void maxElevationSliderChanged(int& maxElevationSlider);
		void flattenElevationSliderChanged(float& flattenElevationSlider);
};
