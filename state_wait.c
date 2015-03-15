#include <stdio.h>
#include "state_machine.h"
#include "state_wait.h"
/* Possible transition to the following state: */
#include "state_pause.h"
#include "state_idle.h"

static void handle_key_1(panel_state_t *ps_state)
{
    printf("(%s)%s()[%d]: \n",__FILE__,__func__,__LINE__); 
    transition_to_wait(ps_state);
}

static void stop(panel_state_t *ps_state)
{
    printf("(%s)%s()[%d]: \n",__FILE__,__func__,__LINE__); 
    transition_to_idle(ps_state);
}

void transition_to_wait(panel_state_t *ps_state)
{
    printf("(%s)%s()[%d]: \n",__FILE__,__func__,__LINE__); 
    /* Initialize with the default implementation before
    specifying the events to be handled in the started state. */
    default_implementation(ps_state);
    ps_state->pu8name  = "Wait";
    ps_state->event_stop  = stop;
    ps_state->event_key_1 = handle_key_1;
}

/* end of file */

