#include <stdlib.h>
#include "freq.h"

// Set up the internals (link the lists etc)
void init_freq(struct freq_s *freq){
    // Set head and tail groups
    freq->g_head = &(freq->groups[0]);
    freq->g_tail = &(freq->groups[NUM_BINS - 1]);
    
    // Skip using for loop for head and tail to avoid
    // lots of checks when NUM_BINS is high
    freq->g_head->prev = NULL;
    freq->g_head->next = &(freq->groups[1]);
    freq->g_head->count = 0;
    freq->g_tail->prev = &(freq->groups[NUM_BINS - 2]);
    freq->g_tail->next = NULL;
    freq->g_tail->count = 0;

    // Link the rest of the group list, make counter list
    for (int i = 1; i < NUM_BINS - 1; i++){
        freq->groups[i].next = &(freq->groups[i + 1]);
        freq->groups[i].prev = &(freq->groups[i - 1]);
        freq->groups[i].count = 0;

        //Every group has no counters yet
    }
    

}

// Add int to tracker
void freq_add_int(struct freq_s *freq, int val){
    //Check if value is monitored
    //FIXME: Use hash table
    uint8_t match = 0;
    struct group_s *match_group = NULL;
    struct counter_s *match_counter = NULL;
    // TODO Run through group list then counter list, check for assigned value


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
