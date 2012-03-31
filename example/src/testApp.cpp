#include "testApp.h"

void testApp::setup()
{
    ofSetVerticalSync(true);
    
    onsetD.setup();
    snd.loadSound("snd/1085.mp3");
    snd.setLoop(true);
    snd.play();    
}

void testApp::update()
{
    ofSoundUpdate();    
}

void testApp::draw()
{    
    if (onsetD.isOnsetting(ofSoundGetSpectrum(nBands)))
    {
        ofBackground(ofColor::red);
    }
    else 
    {
        ofBackground(ofColor::black);
    }
}

void testApp::keyPressed(int key){}
void testApp::keyReleased(int key){}
void testApp::mouseMoved(int x, int y ){}
void testApp::mouseDragged(int x, int y, int button){}
void testApp::mousePressed(int x, int y, int button){}
void testApp::mouseReleased(int x, int y, int button){}
void testApp::windowResized(int w, int h){}
void testApp::gotMessage(ofMessage msg){}
void testApp::dragEvent(ofDragInfo dragInfo){}