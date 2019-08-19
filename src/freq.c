#include <stdlib.h>
#include "freq.h"

// Set up the internals (link the lists etc)
struct freq_s init_freq(void){
    // C Standard guarantees this will zero
    struct freq_s freq = {0};

    // Start with one group, no counters yet
    freq.g_head = &(freq.groups[0]);
    freq.g_tail = &(freq.groups[0]);
    
    // Using group 0
    freq.group_idx[0] = 1;

    return freq;
}

// Add int to tracker
void freq_add_int(struct freq_s *freq, int val){
    //Check if value is monitored
    //FIXME: Use hash table of monitored values?
    uint8_t match = 0;
    struct group_s *match_group = freq->g_head;
    struct counter_s *match_counter = freq->g_head->c_head;
    
    // Run through group list then each counter list, check for val
    // We can use match counters to do this and avoid using extra memory
    // While loops are generally bad and I want to change this to hash table
    while(match_group != NULL && match == 0){
        while(match_counter != NULL){
            if(match_counter->value == val){
                match = 1;
                break;
            }
            match_counter = match_counter->next;
        }
        match_group = match_group->next;
    }
    
    

    
    //Guaranteed that there will always be at least one active group

    //Unmonitored, first group is zero: add and increment
    if (match == 0 && freq->g_head->count == 0){
    }
    //Unmonitored, first group nonzero: skip value, decrement first group
    else if (match == 0 && freq->g_head->count != 0){
        freq->g_head->count--;
    }
    //If we get here the element must be monitored and has to be incremented
    else{
        if (match_group->next != NULL && match_group->next->count == 1){    
            // Next element has diff of 1, move counter
        }
        else if (match_group->next != NULL){
            //Make group between this one and next one
        }
        else{  
            //Add group if not out of groups
        }
    }   
}

void display_freq(struct freq_s *freq){

}
