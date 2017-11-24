#ifndef _TinyGL_TinyGL_h_
#define _TinyGL_TinyGL_h_

#include <CtrlLib/CtrlLib.h>
using namespace Upp;

#include <GL/gl.h>
#include <zbuffer.h>

#include "ZGl.h"

namespace Upp {


class GLCtrl : public Ctrl {
	ZBuffer *frameBuffer = NULL;
	int width = 0, height = 0;
	bool is_open = false;
	GLContext *ctx = NULL;
	
	
	void OpenGL(int w, int h);
	void CloseGL();
	
public:
	GLCtrl();
	~GLCtrl();
	
	virtual void Paint(Draw& w);

public:
	Callback WhenGLPaint;

	virtual void Layout();
	virtual void GLPaint() {}
	virtual void GLResize(int w, int h) {}

	void StdView();
};

}

#endif
