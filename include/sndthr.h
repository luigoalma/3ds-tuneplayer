#pragma once
#include <3ds.h>
#include <stdio.h>
#include <xmp.h>

#define CHANNEL 0x10
#define SAMPLE_RATE 44100

#define N3DS_BLOCK 4096
#define O3DS_BLOCK 8192
// can someone find sweet spot?

#define MS_TO_PCM16_SIZE(s, c, ms) ((u32)((s) / 1000.0f * (c) * (ms)))

Result setup_ndsp();
void soundThread(void *arg);

struct thread_data {
    xmp_context c;
    int model;
};

static inline void _debug_pause() {
    printf("Press start.\n");
    while (1) {
        hidScanInput();
        u32 kDown = hidKeysDown();
        if (kDown & KEY_START) break;
    }
}