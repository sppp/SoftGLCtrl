#include "TinyGL.h"

namespace Upp {


GLCtrl::GLCtrl() {
	ASSERT_(gl_get_context() == NULL, "Multiple gl contextes is not supported yet");
	
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
	
	is_open = true;
}

void GLCtrl::CloseGL() {
	if (!is_open) return;
	
	glClose();
	ZB_close(frameBuffer);
	
	is_open = false;
}

void GLCtrl::Layout() {
	Size sz = GetSize();
	OpenGL(sz.cx, sz.cy);
	GLResize(sz.cx, sz.cy);
}

void GLCtrl::Paint(Draw& w) {
	if (!is_open)
		return;
	
	GLPaint();
	
	ImageBuffer buf(width, height);
	#if TGL_FEATURE_RENDER_BITS == 32
	byte* argb = (byte*)frameBuffer->pbuf;
	RGBA* cur = buf.Begin();
	RGBA* end = buf.End();
	while (cur != end) {
		RGBA& red = *cur;
		red.b = argb[0];
		red.g = argb[1];
		red.r = argb[2];
		red.a = 0xff;
		cur++;
		argb+=4;
	}
	#else
		#error "Not implemented"
	#endif
	
	w.DrawImage(0, 0, buf);
}

void GLCtrl::StdView() {
	
}

}

