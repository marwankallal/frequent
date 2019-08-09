#include <stdlib.h>
#include "freq.h"

// Set up the internals (link the lists etc)
void init_freq(struct freq_s *freq){
    // Set head and tail
    freq->g_head = &(freq->groups[0]);
    freq->g_tail = &(freq->groups[NUM_BINS - 1]);
    
    // Skip using for loop for head and tail to avoid
    // lots of checks when NUM_BINS is high
    freq->g_head->prev = NULL;
    freq->g_head->next = &(freq->groups[1]);
    freq->g_tail->prev = &(freq->groups[NUM_BINS - 2]);
    freq->g_tail->next = NULL;

    // Link the rest of the list
    for (int i = 1; i < NUM_BINS - 1; i++){
        freq->groups[i].next = &(freq->groups[i + 1]);
        freq->groups[i].prev = &(freq->groups[i - 1]);
    }
}
