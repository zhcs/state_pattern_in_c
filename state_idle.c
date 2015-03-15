#include <stdio.h>
#include "state_machine.h"
#include "state_idle.h"
/* Possible transition to the following state: */
#include "state_pause.h"

static void handle_pause_key_event(panel_state_t *ps_state)
{
    printf("(%s)%s()[%d]: \n",__FILE__,__func__,__LINE__); 
    transition_to_pause(ps_state);
}

void transition_to_idle(panel_state_t *ps_state)
{
    printf("(%s)%s()[%d]: \n",__FILE__,__func__,__LINE__); 
    /* Initialize with the default implementation before
    specifying the events to be handled in the idle state. */
    default_implementation(ps_state);
    ps_state->pu8name = "[idle state]";
    ps_state->event_key_pause = handle_pause_key_event;
}

/* end of file */

