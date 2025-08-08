#include <stdio.h>
#include <stdbool.h>

#define CACHE_SIZE 8
#define BLOCK_SIZE 4
#define NUM_SETS 4

struct CacheLine {
    bool valid;
    int tag;
    int data[BLOCK_SIZE];
};

struct CacheSet {
    struct CacheLine lines[2]; // 2-way set-associative
};

struct Cache {
    struct CacheSet sets[NUM_SETS];
};

int cacheHits = 0;
int cacheMisses = 0;

int cacheLookup(struct Cache* cache, int address) {
    int setIndex = address % NUM_SETS, i;

    for (i = 0; i < 2; i++) { // 2-way set-associative
        if (cache->sets[setIndex].lines[i].valid && cache->sets[setIndex].lines[i].tag == address) {
            cacheHits++;
            return cache->sets[setIndex].lines[i].data[address % BLOCK_SIZE];
        }
    }

    cacheMisses++;
    return -1; // Cache miss
}

void cacheInsert(struct Cache* cache, int address, int data) {
    int setIndex = address % NUM_SETS;

    int i;
    for (i = 0; i < 2; i++) { // 2-way set-associative
        if (!cache->sets[setIndex].lines[i].valid) {
            cache->sets[setIndex].lines[i].valid = true;
            cache->sets[setIndex].lines[i].tag = address;
            cache->sets[setIndex].lines[i].data[address % BLOCK_SIZE] = data;
            return;
        }
    }
    // If all lines are occupied, you can use a replacement policy (e.g., LRU).
    // In this simplified example, we don't handle replacements.
}

int main() {
    struct Cache cache;

    // Initialize the cache
    int i, j;
    for (i = 0; i < NUM_SETS; i++) {
        for (j = 0; j < 2; j++) {
            cache.sets[i].lines[j].valid = false;
        }
    }

    // Simulate cache accesses
    int addresses[] = {2, 6, 10, 3, 7, 11, 14, 2, 3};

    for (i = 0; i < sizeof(addresses) / sizeof(addresses[0]); i++) {
        int address = addresses[i];
        int data = cacheLookup(&cache, address);

        if (data != -1) {
            printf("Cache hit for address %d, Data: %d\n", address, data);
        } else {
            printf("Cache miss for address %d\n", address);
            // Simulate fetching data from memory and updating the cache
            data = address * 2; // Replace with actual data retrieval
            cacheInsert(&cache, address, data);
        }
    }

    float hitMissRatio = (float)cacheHits / (cacheHits + cacheMisses);
    printf("Cache Hits: %d\n", cacheHits);
    printf("Cache Misses: %d\n", cacheMisses);
    printf("Hit/Miss Ratio: %.2f\n", hitMissRatio);

    return 0;
}
