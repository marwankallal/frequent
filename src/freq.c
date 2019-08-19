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

        // Make counter linked list
        //Make head and tail
        freq->groups[i].c_head = &(freq->groups[i].counters[0]);
        freq->groups[i].c_head->next = &(freq->groups[i].counters[1]);
        freq->groups[i].c_head->prev = NULL;
        freq->groups[i].c_head->value = 0;
        freq->groups[i].c_head->assigned = 0;
        freq->groups[i].c_tail = &(freq->groups[i].counters[NUM_BINS - 1]);
        freq->groups[i].c_tail->next = NULL;
        freq->groups[i].c_tail->prev = &(freq->groups[i].counters[NUM_BINS - 2]);
        freq->groups[i].c_tail->value = 0;
        freq->groups[i].c_tail->assigned = 0;
         
        for(int k = 1; k < NUM_BINS - 1; k++){
            freq->groups[i].counters[k].group = &(freq->groups[i]);
            freq->groups[i].counters[k].next = &(freq->groups[i].counters[k + 1]);
            freq->groups[i].counters[k].prev = &(freq->groups[i].counters[k - 1]);
            freq->groups[i].counters[k].assigned = 0;
        }
    }
    

}

// Add int to tracker
void freq_add_int(struct freq_s *freq, int val){
    //Check if value is monitored
    //TODO: Use hash table
    uint8_t match = 0;
    struct group_s *match_group = NULL;
    struct counter_s *match_counter = NULL;
    for (int g = 0; g < NUM_BINS; g++){
        for (int c = 0; c < NUM_BINS; c++){
            if (freq->groups[g].counters[c].value == val){
                match_group = &(freq->groups[g]);
                match_counter = &(freq->groups[g].counters[c]);
                match = 1;
            }
        }
    }

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
