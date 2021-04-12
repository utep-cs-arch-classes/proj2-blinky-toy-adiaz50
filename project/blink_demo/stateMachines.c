#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

void state1()		/* alternate between toggling red & green */
{
  char changed = 0;  

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
  
}

void state2(){
  buzzer_set_period(1000);
  toggle_red();
  led_changed = 1;
  led_update();
}

void state3(){
  char changed;

  switch(changed){
  case 0:
    red_on = 1;
    green_on = 0;
    changed = 1;
    buzzer_set_period(500);
    break;
  case 1:
    red_on = 0;
    green_on = 1;
    changed = 2;
    buzzer_set_period(1000);
    break;
  }
  led_changed = 1;
  led_update();
}

void dim_25(){
  char dimState;
  switch(dimState){
  case 0:
    red_on = 1;
    dimState = 1;
    break;
  case 1:
    red_on = 1;
    dimState = 2;
    break;
  case 2:
    red_on = 0;
    dimState = 3;
    break;
  case 3:
    red_on = 0;
    dimState = 0;
    break;
  }
  led_changed = 1;
  led_update();
}

void dim_50(){
  char changed;
  switch(changed){
  case 0:
    red_on = 1;
    changed = 1;
    break;
  case 1:
    red_on = 0;
    changed = 0;
    break;
  }
  led_changed = 1;
  led_update();
}

void dim_75(){
  char changed;
  switch(changed){
  case 0:
    red_on = 1;
    changed = 1;
    break;
  case 1:
    red_on = 1;
    changed = 2;
    break;
  case 2:
    red_on = 1;
    changed = 3;
    break;
  case 3:
    red_on = 0;
    changed = 0;
    break;
  }
  led_changed = 1;
  led_update();
}
// still working on this
void state4(){
  char changed;
  switch(changed){
  case 0:
    dim_25();
    break;
  }
}
//testing dim
void state_advance(){
  dim_25();
  dim_50();
  
  char changed;
  
  /*
  if(s1){
    state1();
   
  }
  else if(s2){
    state2();
   
  }
  else if(s3){
    state3();
   
  }
  else if(s4){
    state4(); 
  }
  */
  // same thing 
  switch(state_changed){
  case 1:
    state1();
    break;
  case 2:
    state2();
    break;
  case 3:
    state3();
    break;
  case 4:
    state4();
    break; 
  }
}
