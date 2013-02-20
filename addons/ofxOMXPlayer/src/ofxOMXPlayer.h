#pragma once

#include "ofMain.h"
#include "ofAppEGLWindow.h"

extern "C" 
{
	#include <libavformat/avformat.h>
	#include <libavutil/avutil.h>
};

#include "RBP.h"
#include "OMXClock.h"
#include "OMXPlayerVideo.h"


class ofxOMXPlayer 
{
public:
	ofxOMXPlayer();
	void loadMovie(string filepath);
	void update();
	
	void 				play();
	void 				stop();
	
	float				duration;
	float 				getDuration();
	
	void 				setPosition(float pct);
//	void 				setVolume(float volume); // 0..1
	
	ofTexture &			getTextureReference();
	void 				draw(float x, float y, float w, float h);
	void 				draw(float x, float y);
	
	void 				setPaused(bool doPause);
	
	int					getCurrentFrame();
	int					getTotalNumFrames();
	
	
	float 				getHeight();
	float 				getWidth();
	
	bool				isPaused();
	bool				isPlaying();
		
	GLuint textureID;

	int videoWidth;
	int videoHeight;
	

	EGLImageKHR eglImage;
	
	string getVideoDebugInfo();
	void generateEGLImage();
	void openPlayer();
	double getMediaTime();
	void close();
	bool doVideoDebugging;
	bool doLooping;
private:
	
	CRBP                  rbp;
	COMXCore              omxCore;
	OMXClock * clock;
	
	OMXPlayerVideo    omxPlayerVideo;
	OMXReader         omxReader;
	
	COMXStreamInfo    streamInfo;
	
	bool isMPEG;
	bool hasVideo;
	
	DllBcmHost        bcmHost;
	
	
	OMXPacket* packet;
	
	ofTexture tex;
	ofTexture * playerTex; // a seperate texture that may be optionally implemented by the player to avoid excessive pixel copying.
	ofPixelFormat internalPixelFormat;
	string moviePath;
	int nFrames;
	bool bPlaying;
	EGLDisplay display;
	EGLContext context;
};
