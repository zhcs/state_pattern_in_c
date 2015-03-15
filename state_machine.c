#include <stdio.h>
#include "state_machine.h"

static void handle_default_stop_event(panel_state_t *ps_state)
{
    /* We'll get here if the stop event isn't supported
    in the concrete state. */
    printf("(%s)%s()[%d]: %s\n",__FILE__,__func__,__LINE__,ps_state->pu8name); 
}

static void handle_default_key_1_event(panel_state_t *ps_state)
{
    /* We'll get here if the start event isn't supported
    in the concrete state. */
    printf("(%s)%s()[%d]: %s\n",__FILE__,__func__,__LINE__,ps_state->pu8name); 
}

static void handle_default_key_pause_event(panel_state_t *ps_state)
{
    printf("(%s)%s()[%d]: %s\n",__FILE__,__func__,__LINE__,ps_state->pu8name); 
}

void default_implementation(panel_state_t *ps_state)
{
    ps_state->event_key_pause = handle_default_key_pause_event;
    ps_state->event_stop      = handle_default_stop_event;
    ps_state->event_key_1     = handle_default_key_1_event;
}

/* end of file */

