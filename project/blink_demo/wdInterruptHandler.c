#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  if(++blink_count == 50){
    char changed = 0;
    state_advance();
    /*    switch(switch_state_changed){
    case 1:
      state1();
      blink_count = 0;
      break;
    case 2:
      state2();
      blink_count = 0;
      break;
    case 3:
      state3();
      blink_count = 0;
      break;
    case 4:
      state4();
      blink_count = 0;
      break;
    default: state1(); blink_count = 0;
    }
    */
  }
}
  void
  __interrupt_vec(PORT2_VECTOR) Port_2(){
    if(P2IFG & SWITCHES){
      P2IFG &= ~SWITCHES;
      switch_interrupt_handler();
    }
  }
//void
//__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  // static char blink_count = 0;
  //if (++blink_count == 90) {
  //state1();
  //state_advance();
  //blink_count = 0;
  //}
