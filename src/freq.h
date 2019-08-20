#include <inttypes.h>

#define NUM_BINS 10 // The top NUM_BINS elements will be stored

struct counter_s{
    int value;
    struct group_s *group;
    struct counter_s *next;
    struct counter_s *prev;
};

struct group_s{
    // Keep track of this groups count
    int count;
    struct counter_s *c_head;
    struct counter_s *c_tail;
    struct group_s *next;
    struct group_s *prev;
};

struct freq_s {
    struct group_s groups[NUM_BINS];
    struct counter_s counters[NUM_BINS];
    struct group_s *g_head;
    struct group_s *g_tail;

    // Change counter_idx to fit NUM_BINS if needed
    uint32_t counter_idx;
};

struct freq_s init_freq(void);
void freq_add_int(struct freq_s *freq, int val);
int most_freq(struct freq_s *freq);
