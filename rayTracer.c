#include "functions.h"

// declaration of global variables
material materials[3];
light lights[3];
sphere spheres[3];
int thread_number = 1;
int pixelcount = 0;
pthread_mutex_t writeflag;

int main(int argc, char * argv[]) {


// User input
  printf("How many threads you would like to use? Number must divide %d without decimals\n", HEIGHT);
  scanf("%d", &thread_number);
  if(HEIGHT%thread_number != 0){
    printf("You failed the input chalenge, You are not worthy user, programm will be executed with 1 thread");
    thread_number = 1;
  }

//declaration of local variables
  unsigned char imgout[3 * WIDTH * HEIGHT];

  th_input th_data_array[thread_number];

  pthread_t threads[thread_number];

//initialization of image data
  init();

  pthread_mutex_init(&writeflag, NULL);

  //filling structs with positions and link to local array
for(int i = 0; i < thread_number; i++){
  th_data_array[i].outarr = imgout;
  th_data_array[i].position = i*HEIGHT/thread_number;
}


//checking which position thread struct received 
for(int i = 0; i < thread_number; i++){
  printf("thread number: %d, starts from position %d\n", i+1, th_data_array[i].position);
}

  for(int i = 0; i < thread_number; i++){
    pthread_create(&threads[i], NULL, (void*)&threadstuff, (void*)&th_data_array[i]);
  }

  /* Will contain the raw image */
 for(int i = 0; i < thread_number; i++){
   pthread_join(threads[i], NULL);
 } 
  
  pthread_mutex_destroy(&writeflag);
  
  printf("area: %d, counter: %d",AREA , pixelcount);

  saveppm("image.ppm", imgout, WIDTH, HEIGHT);

  return 0;
}