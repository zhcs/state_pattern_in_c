#include <stdio.h>
#include "state_machine.h"
#include "state_pause.h"
/* Possible transition to the following state: */
#include "state_idle.h"

static void handle_stop_event(panel_state_t *ps_state)
{
    printf("(%s)%s()[%d]: \n",__FILE__,__func__,__LINE__); 
    transition_to_idle(ps_state);
}

void transition_to_pause(panel_state_t *ps_state)
{
    printf("(%s)%s()[%d]: \n",__FILE__,__func__,__LINE__); 
    /* Initialize with the default implementation before
    specifying the events to be handled in the started
    state. */
    default_implementation(ps_state);
    ps_state->pu8name    = "[pause state]";
    ps_state->event_stop = handle_stop_event;
}

/* end of file */

