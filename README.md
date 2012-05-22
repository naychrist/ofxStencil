ofxStencil
==========

Simple addon for using stencil buffer. Code adapted from:  
http://www.videotutorialsrock.com/opengl_tutorial/reflections/video.php  

You need to enable stencil buffer in main.cpp, for example:

ofAppGlutWindow window;
window.setGlutDisplayString("stencil~2 rgba double samples>=4 depth");

Usage:

ofxStencil stencil;
stencil.beginDrawingStencil();
//draw your mask
stencil.beginUsingStencil(); 
//draw what you want masked
stencil.endUsingStencil();
