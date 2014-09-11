#include "VideoMover.h"

void VideoMover::load(string filepath) {
    player.loadMovie(filepath);
}

void VideoMover::draw() {
    player.nextFrame();
    player.update();
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    player.draw(0, 0);
    ofPopMatrix();
}