//
//  ofxOnsetDetection.h
//  example
//
//  Created by Akira Hayasaka on 3/30/12.
//  Copyright (c) 2012 ﾟ･:,｡ﾟ･:,｡★ﾟ･:,｡ﾟ･:,｡☆ﾟ･:,｡ﾟ･:,｡★ﾟ･:,｡ﾟ･:,｡☆. All rights reserved.
//

#ifndef example_ofxOnsetDetection_h
#define example_ofxOnsetDetection_h

#include "ofMain.h"
#include "onsetsds.h"

/*
 http://onsetsds.sourceforge.net/
 */

const static int sampleRate = 44100;

class ofxOnsetDetection 
{
public:
    void setup(string file)
    {
        int odftype = ODS_ODF_RCOMPLEX;
        float* odsdata = (float*) malloc( onsetsds_memneeded(odftype, 512, 11) );
        onsetsds_init(&ods, odsdata, ODS_FFT_FFTW3_HC, odftype, 512, 11, sampleRate);
        
        snd.loadSound(file);
        snd.setLoop(true);
        snd.play();        
    }
    
    bool isOnsetting()
    {
        ofSoundUpdate();
        return onsetsds_process(&ods, ofSoundGetSpectrum(1024));
    }
    
private:
    ofSoundPlayer   snd;
    OnsetsDS        ods;    
};

#endif
