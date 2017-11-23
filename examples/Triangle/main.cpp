#include "Triangle.h"



struct OpenGLExample : GLCtrl {
	typedef OpenGLExample CLASSNAME;
	TimeStop ts;
	Point point;
	GLfloat h;
	
	OpenGLExample() {PostCallback(THISBACK(Refresh0));}
	
	void Refresh0() {Refresh(); PostCallback(THISBACK(Refresh0));}
	
	virtual void GLPaint() {
		// Clear color buffer
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glFrustum(-1.0, 1.0, -h, h, 1.0, 65.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glRotatef(-90, 1,0,0);
        glTranslatef(0,0,-1.0f);
        
		// Draw a rotating colorful triangle
		glTranslatef( 0.0f, 14.0f, 0.0f );
		glRotatef( ts.Elapsed() * 0.1, 0.0, 0.0, 1.0 );
		glBegin( GL_TRIANGLES );
		glColor3f( 1.0f, 0.0f, 0.0f );
		glVertex3f( -5.0f, 0.0f, -4.0f );
		glColor3f( 0.0f, 1.0f, 0.0f );
		glVertex3f( 5.0f, 0.0f, -4.0f );
		glColor3f( 0.0f, 0.0f, 1.0f );
		glVertex3f( 0.0f, 0.0f, 6.0f );
		glEnd();
	}
	
	virtual void GLResize(int width, int height) {
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glViewport(0, 0, width, height);
		glEnable(GL_DEPTH_TEST);
		
		h = (GLfloat) height / (GLfloat) width;
	}

	virtual void MouseMove(Point p, dword) {
		point = p;
		Refresh();
	}
};


GUI_APP_MAIN
{
	Ctrl::GlobalBackPaint();
	TopWindow win;
	OpenGLExample gl;
	gl.SetFrame(InsetFrame());
	win.Title("Triangle");
	win.Add(gl.HSizePos(10, 10).VSizePos(10, 10));
	win.Sizeable().Zoomable();
	win.Open();
	win.Run();
}

