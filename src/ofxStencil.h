/*

code adapted from:  
http://www.videotutorialsrock.com/opengl_tutorial/reflections/video.php  

@note: need to enable stencil buffer in main.cpp

ofAppGlutWindow window;
window.setGlutDisplayString("stencil~2 rgba double samples>=4 depth");

*/

#pragma once

#include "ofMain.h"  

class ofxStencil {  
public:  
    
    ofxStencil(){}  
    
    //set up to draw stencil  
    void beginDrawingStencil() {  
        glClear(GL_STENCIL_BUFFER_BIT);  
        glEnable(GL_STENCIL_TEST); //Enable using the stencil buffer  
        glColorMask(0, 0, 0, 0); //Disable drawing colors to the screen  
        glStencilFunc(GL_ALWAYS, 1, 1); //Make the stencil test always pass  
        //Make pixels in the stencil buffer be set to 1 when the stencil test passes  
        glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);  
        //Set all of the pixels below to be 1 in the stencil buffer...  
    }  
    
    //switch from drawing stencil to scene to be masked  
    void beginUsingStencil() {  
        glColorMask(1, 1, 1, 1); //Enable drawing colors to the screen  
        //Make the stencil test pass only when the pixel is 1 in the stencil buffer  
        glStencilFunc(GL_EQUAL, 1, 1);  
        glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP); //Make the stencil buffer not change  
        //Draw all pixels where the stencil buffer is 1...  
    }  
    
    //back to normal unmasked drawing  
    void endUsingStencil() {  
        glDisable(GL_STENCIL_TEST); //Disable using the stencil buffer  
    }  
    
};//class ofxStencil  
    
