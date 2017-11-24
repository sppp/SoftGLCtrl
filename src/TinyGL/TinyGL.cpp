#include "TinyGL.h"

namespace Upp {


GLCtrl::GLCtrl() {
	
}

GLCtrl::~GLCtrl() {
	CloseGL();
}

void GLCtrl::OpenGL(int width, int height) {
	if (is_open) CloseGL();
	
	this->width = width;
	this->height = height;
	frameBuffer = ZB_open(width, height, ZB_MODE_RGBA, 0, 0, 0, 0);
	glInit(frameBuffer);
	
	ctx = gl_ctx;
	gl_ctx = NULL;
	
	is_open = true;
}

void GLCtrl::CloseGL() {
	if (!is_open) return;
	
	gl_ctx = ctx;
	glClose();
	ZB_close(frameBuffer);
	ctx = NULL;
	
	is_open = false;
}

void GLCtrl::Layout() {
	Size sz = GetSize();
	OpenGL(sz.cx, sz.cy);
	
	gl_ctx = ctx;
	GLResize(sz.cx, sz.cy);
	gl_ctx = NULL;
}

void GLCtrl::Paint(Draw& w) {
	if (!is_open)
		return;
	
	#if TGL_FEATURE_RENDER_BITS == 32
	gl_ctx = ctx;
	GLPaint();
	gl_ctx = NULL;
	
	SetSurface(w, 0, 0, frameBuffer->xsize, frameBuffer->ysize, (RGBA*)frameBuffer->pbuf);
	#else
		#error "Not implemented"
	#endif
}

void GLCtrl::StdView() {
	
}

}

