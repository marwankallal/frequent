# frequent
Uses a modified version of Demaine's algorithm (Paper Title:
Frequency Estimation of Internet Packet Streams with Limited Space). This
project is written in POSIX compliant C, without dynamic memory allocation. This
is meant to be used in embedded systems or systems with very limited memory
where dynamic allocation is not allowed. Memory use in this library is
deterministic and depends only on the number of top elements you want to keep
track of. See "Limitations" for why you
shouldn't use this library if you don't care about using `malloc`.

## Usage
As this is a single header single source file library, you can simply add it to
your source and include it as any other source and header. If you want to made
it a static library for some reason I leave that as an exercise for the reader.

You MUST use `init_freq()` to get a new frequency tracker, unless you want to 
set it up yourself. For example: `struct freq_s my_freq = init_freq();`

## Limitations
Because we can't use `malloc` and the algorithm relies on linked lists for its
really good asymptotic performance of O(1), we have to "fake" a linked list.
This means that we need to check if elements are already in use before adding
them to the linked list. In reality then, this modified algorithm runs in O(m),
where m is the number of most frequent elements you want to keep track of, which
is usually a small number.
