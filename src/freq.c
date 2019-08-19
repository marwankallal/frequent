#include <stdlib.h>
#include "freq.h"

// Set up the internals (link the lists etc)
void init_freq(struct freq_s *freq){
    // Start with one group, no counters yet
    freq->g_head = freq->groups[0];
    freq->g_tail = freq->groups[0];
    
    // Zero out allocation record
    freq->group_idx = {0};
    freq->counter_idx = {0};

    // Using group 0
    freq->group_idx[0] = 1;
}

// Add int to tracker
void freq_add_int(struct freq_s *freq, int val){
    //Check if value is monitored
    //FIXME: Use hash table
    uint8_t match = 0;
    struct group_s *match_group = NULL;
    struct counter_s *match_counter = NULL;
    // TODO Run through group list then each counter list, check for val


    //Unmonitored, first group is zero
    if (match == 0 && freq->g_head->count == 0){
        freq->g_head->c_head->assigned = 1;
        freq->g_head->c_head->value = val;
    }
    //Unmonitored, first group nonzero: skip value, decrement first group
    else if (match == 0 && freq->g_head->count != 0){
        freq->g_head->count--;
    }
    //If we get here the element must be monitored and has to be incremented
    else{

    }   
}

void display_freq(struct freq_s *freq){

}
