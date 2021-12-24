#include <stdio.h>

#include <stdbool.h> /* Needed for boolean datatype */

#include <math.h>

#include <pthread.h>



#define min(a, b)(((a) < (b)) ? (a) : (b))
/* Width and height of out image */
#define WIDTH 800
#define HEIGHT 600
#define AREA WIDTH*HEIGHT




typedef struct {
  float x, y, z;
}
vector;

typedef struct 
{
  int position;
  unsigned char* outarr;
}
th_input;


/* The sphere */
typedef struct {
  vector pos;
  float radius;
  int material;
}
sphere;

/* The ray */
typedef struct {
  vector start;
  vector dir;
}
ray;

/* Colour */
typedef struct {
  float red, green, blue;
}
colour;

/* Material Definition */
typedef struct {
  colour diffuse;
  float reflection;
}
material;

/* Lightsource definition */
typedef struct {
  vector pos;
  colour intensity;
}
light;

extern material materials[3];
extern light lights[3];
extern sphere spheres[3];
extern int thread_number;

extern int pixelcount ;
extern pthread_mutex_t writeflag;

vector vectorSub(vector*, vector*);
float vectorDot(vector*, vector*); 
vector vectorScale(float, vector*);
vector vectorAdd(vector*, vector*);
bool intersectRaySphere(ray*, sphere*, float*);

void threadstuff( void*);

void init();

void saveppm(char*, unsigned char*, int, int);
