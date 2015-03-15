#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "state_machine.h"

panel_state_t *create_state_machine(void)
{
    panel_state_t *ps_sm_instance = malloc(sizeof *ps_sm_instance);

    if(NULL != ps_sm_instance)
    {
        printf("(%s)%s()[%d]: set initial state to idle. \n",__FILE__,__func__,__LINE__); 
        
        /* Specify the initial state. */
        transition_to_idle(ps_sm_instance);
        /* Initialize the other attributes here... */
    }
    return ps_sm_instance;
}

void destroy_state_machine(panel_state_t *ps_sm_instance)
{
    printf("(%s)%s()[%d]: \n",__FILE__,__func__,__LINE__); 
    free(ps_sm_instance);
}

void handle_event_key_pause(panel_state_t *ps_sm_instance)
{
    printf("(%s)%s()[%d]: \n",__FILE__,__func__,__LINE__); 
    ps_sm_instance->event_key_pause(ps_sm_instance);
}

void handle_event_stop(panel_state_t *ps_sm_instance)
{
    printf("(%s)%s()[%d]: \n",__FILE__,__func__,__LINE__); 
    ps_sm_instance->event_stop(ps_sm_instance);
}

void handle_event_key_1(panel_state_t *ps_sm_instance)
{
    printf("(%s)%s()[%d]: \n",__FILE__,__func__,__LINE__); 
    ps_sm_instance->event_key_1(ps_sm_instance);
}

void main(void)
{
    panel_state_t *ps_sm_ptr = NULL;

    ps_sm_ptr = create_state_machine();

    printf("(%s)%s()[%d]: got key 1\n",__FILE__,__func__,__LINE__); 
    handle_event_key_1(ps_sm_ptr);
    printf("(%s)%s()[%d]: got key pause\n",__FILE__,__func__,__LINE__); 
    handle_event_key_pause(ps_sm_ptr);
    printf("(%s)%s()[%d]: got key stop\n",__FILE__,__func__,__LINE__); 
    handle_event_stop(ps_sm_ptr);
    destroy_state_machine(ps_sm_ptr);
}

/* end of file */

