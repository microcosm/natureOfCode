#pragma once

#include "Mover.h"

class VideoMover : public Mover {
    
public:
    void draw();
    void load(string filepath);
    
protected:
    ofVideoPlayer player;
};