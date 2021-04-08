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

void state_advance()		/* alternate between toggling red & green */
{
  /*
  char changed = 0;  

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
  */
}

void state2(){
  char changed = 0;

  if(switch_state_changed = 1){
    changed = toggle_red();
    buzzer_set_period(0);
  }else if(switch_state_changed = 2){
    changed = toggle_red();
    buzzer_set_period(2000);
  }else if(switch_state_changed = 3){
    changed = toggle_green();
    buzzer_set_period(3000);
  }else if(switch_state_changed = 4){
    changed = toggle_red();
    buzzer_set_period(4000);
  }
  led_changed = changed;
  led_update();
}

