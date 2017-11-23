
void gluPerspective(GLfloat fovy, GLfloat aspect,
					GLfloat zNear, GLfloat zFar);
                    
typedef struct {
	int draw_style;
} GLUquadricObj;

#define GLU_LINE 0

GLUquadricObj *gluNewQuadric(void);
void gluQuadricDrawStyle(GLUquadricObj *obj, int style);

void gluSphere(GLUquadricObj *qobj,
			   double radius, int slices, int stacks);
void gluCylinder(GLUquadricObj *qobj,
				 GLfloat baseRadius, GLfloat topRadius, GLfloat height,
				 GLint slices, GLint stacks);
void gluDisk(GLUquadricObj *qobj,
			 GLfloat innerRadius, GLfloat outerRadius,
			 GLint slices, GLint loops);
             
void drawTorus(double rc, int numc, double rt, int numt);
