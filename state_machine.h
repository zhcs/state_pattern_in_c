#ifndef HEADER_PANELSTATE_H
#define HEADER_PANELSTATE_H

typedef struct panel_state panel_state_t;

/* Simplify the code by using typedefs for the function pointers. */
typedef void (*event_key_pause_func) (panel_state_t *);
typedef void (*event_stop_func)      (panel_state_t *);
typedef void (*event_key_1_func)     (panel_state_t *);

struct panel_state
{
    unsigned char        *pu8name;
    event_key_pause_func  event_key_pause;
    event_stop_func       event_stop;
    event_key_1_func      event_key_1;
} ;

void default_implementation(panel_state_t *);
#endif

/* end of file */

