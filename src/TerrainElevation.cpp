#include "TerrainElevation.h"
#include <vector>

TerrainElevation::TerrainElevation() {

}

TerrainElevation::TerrainElevation(int tileSize, int maxElevation) {
    this->columns = mapWidth / tileSize;
    this->rows = mapHeight / tileSize;
    this->maxElevation = maxElevation;
}

void TerrainElevation::initializeMatrix() {
    elevationMap.clear();
    for (int y = 0; y <= rows; y++) {
        vector<float> row;
        for (int x = 0; x <= columns; x++)
            row.push_back(0);
        elevationMap.push_back(row);
    }
}

void TerrainElevation::calculateElevationMap
							(const vector<vector<float>>& depthMap) {
	// Center to corner: sqrt(0.5^2 + 0.5^2)
    float maxEuclideanDistance = pow(0.5, 0.5);
    for (int y = 0; y <= rows; y++) {
        for (int x = 0; x <= columns; x++) {
			elevationMap.at(y).at(x) = pow(ofMap(depthMap.at(y).at(x),
								minNoiseZ, maxNoiseZ, 0, 1), flattenElevation);
            elevationMap.at(y).at(x) = ofMap(depthMap.at(y).at(x), 0, 1,
											 -maxElevation, maxElevation);
        }
    }
}

vector<vector<float>> TerrainElevation::getElevationMap() {
    return elevationMap;
}
