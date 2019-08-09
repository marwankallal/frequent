#define NUM_BINS 10 // The top NUM_BINS elements will be stored

struct group_s{
    // Keep track of this groups count
    float val;
    int count;
    struct group_s *next;
    struct group_s *prev;
};


struct freq_s {
    struct group_s groups[NUM_BINS];
    struct group_s *g_head;
    struct group_s *g_tail;
};

void init_freq(struct freq_s *freq);
