#ifndef switches_included
#define switches_included

#define SW1 BIT0		/* switch1 is p1.3 */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (BIT0|BIT1|BIT2|BIT3)    /* only 1 switch on this board */

void switch_init();
void switch_interrupt_handler();

extern char state_changed, s1, s2, s3, s4; /* effectively boolean */

#endif // included
