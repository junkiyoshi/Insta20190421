#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	int size = 30;
	for (int x = -ofGetWidth(); x <= ofGetWidth(); x += size) {

		for (int y = -ofGetHeight(); y <= ofGetHeight(); y += size) {

			float z = ofMap(ofNoise(glm::length(glm::vec2(x, y)) * 0.003 - ofGetFrameNum() * 0.01), 0, 1, -300, 300);

			ofSetColor(239);
			ofFill();
			ofDrawBox(glm::vec3(x, y, z), size - 2);

			ofSetColor(39);
			ofNoFill();
			ofDrawBox(glm::vec3(x, y, z), size);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}