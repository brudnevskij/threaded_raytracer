#include "functions.h"



void init(){

  materials[0].diffuse.red = 1;
  materials[0].diffuse.green = 0;
  materials[0].diffuse.blue = 0;
  materials[0].reflection = 0.2;

  materials[1].diffuse.red = 0;
  materials[1].diffuse.green = 1;
  materials[1].diffuse.blue = 0;
  materials[1].reflection = 0.5;

  materials[2].diffuse.red = 0;
  materials[2].diffuse.green = 0;
  materials[2].diffuse.blue = 1;
  materials[2].reflection = 0.9;

  spheres[0].pos.x = 200;
  spheres[0].pos.y = 300;
  spheres[0].pos.z = 0;
  spheres[0].radius = 100;
  spheres[0].material = 0;

  spheres[1].pos.x = 400;
  spheres[1].pos.y = 400;
  spheres[1].pos.z = 0;
  spheres[1].radius = 100;
  spheres[1].material = 1;

  spheres[2].pos.x = 500;
  spheres[2].pos.y = 140;
  spheres[2].pos.z = 0;
  spheres[2].radius = 100;
  spheres[2].material = 2;


  lights[0].pos.x = 0;
  lights[0].pos.y = 240;
  lights[0].pos.z = -100;
  lights[0].intensity.red = 1;
  lights[0].intensity.green = 1;
  lights[0].intensity.blue = 1;

  lights[1].pos.x = 3200;
  lights[1].pos.y = 3000;
  lights[1].pos.z = -1000;
  lights[1].intensity.red = 0.6;
  lights[1].intensity.green = 0.7;
  lights[1].intensity.blue = 1;

  lights[2].pos.x = 600;
  lights[2].pos.y = 0;
  lights[2].pos.z = -100;
  lights[2].intensity.red = 0.3;
  lights[2].intensity.green = 0.5;
  lights[2].intensity.blue = 1;

}