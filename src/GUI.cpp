#include "GUI.h"

GUI::GUI() {
    isAnySettingChanged = true;

    generalSettingsPanel.setup("General settings");

    generalSettingsPanel.add(seedSlider.setup("Seed", 1, 1, 100));
    seedSlider.addListener(this, &GUI::seedSliderChanged);

    generalSettingsPanel.add(tileSizeSlider.setup("Tile size", 20, 20, 80));
    tileSizeSlider.addListener(this, &GUI::tileSizeSliderChanged);

    noiseSettingsPanel.setup("Noise settings");
    noiseSettingsPanel.setPosition(10, 80);

    noiseSettingsPanel.add(octavesSlider.setup("Octaves", 5, 1, 9));
    octavesSlider.addListener(this, &GUI::octavesSliderChanged);

    noiseSettingsPanel.add(noiseScaleSlider.setup("Noise scale", 1.0, 0.5, 1.5));
    noiseScaleSlider.addListener(this, &GUI::noiseScaleSliderChanged);

    noiseSettingsPanel.add(lacunaritySlider.setup("Lacunarity", 2.0, 1.0, 3.0));
    lacunaritySlider.addListener(this, &GUI::lacunaritySliderChanged);

    noiseSettingsPanel.add(persistenceSlider.setup("Persistence", 0.5, 0.25, 0.75));
    persistenceSlider.addListener(this, &GUI::persistenceSliderChanged);

    elevationSettingsPanel.setup("Elevation settings");
    elevationSettingsPanel.setPosition(10, 180);

    elevationSettingsPanel.add(maxElevationSlider.setup("Max elevation", 500, 1, 1000));
    maxElevationSlider.addListener(this, &GUI::maxElevationSliderChanged);

    elevationSettingsPanel.add(flattenElevationSlider.setup("Flatten elevation", 1.0, 1.0, 3.0));
    flattenElevationSlider.addListener(this, &GUI::flattenElevationSliderChanged);
}

GUI::Settings GUI::getSettings(void) {
    struct Settings s;

    s.seed = seedSlider;
    s.tileSize = tileSizeSlider;
    s.octaves = octavesSlider;
    s.noiseScale = noiseScaleSlider;
    s.lacunarity = lacunaritySlider;
    s.persistence = persistenceSlider;
    s.maxElevation = maxElevationSlider;
    s.flattenElevation = flattenElevationSlider;

    return s;
}

void GUI::draw() {
    ofDisableDepthTest();
    generalSettingsPanel.draw();
    noiseSettingsPanel.draw();
    elevationSettingsPanel.draw();
    ofEnableDepthTest();
}

void GUI::setIsAnySettingChanged() {
    isAnySettingChanged = !isAnySettingChanged;
}

bool GUI::getIsAnySettingChanged() {
    return isAnySettingChanged;
}

void GUI::seedSliderChanged(int& seedSlider) {
    isAnySettingChanged = true;
}

void GUI::tileSizeSliderChanged(int& tileSizeSlider) {
    isAnySettingChanged = true;
}

void GUI::octavesSliderChanged(int& octavesSlider) {
    isAnySettingChanged = true;
}

void GUI::noiseScaleSliderChanged(float& noiseScaleSlider) {
    isAnySettingChanged = true;
}

void GUI::lacunaritySliderChanged(float& lacunaritySlider) {
    isAnySettingChanged = true;
}

void GUI::persistenceSliderChanged(float& persistenceSlider) {
    isAnySettingChanged = true;
}

void GUI::maxElevationSliderChanged(int& maxElevationSlider) {
    isAnySettingChanged = true;
}

void GUI::flattenElevationSliderChanged(float& flattenElevationSlider) {
    isAnySettingChanged = true;
}
