#include <stdio.h>
#include <stdlib.h>
#include "audio.h"

/**
 * @param x The original audio
 * @param N Length of audio
 * @param delay Lag of loop
 */
float* makeEcho(float* x, int N, int delay) {
    float* y = new float[N+delay];
    // Copy over original audio
    for (int i = 0; i < N+delay; i++) {
        if (i < N) {
            y[i] = x[i];
        }
        else {
            y[i] = 0;
        }
    }
    // Add echo
    for (int i = 0; i < N; i++) {
        y[i+delay] += x[i];
    }
    return y;
}

int main(int argc, char* argv[]) {
    // Warn the user if they don't input the correct number of parameters
    if (argc < 4) {
        printf("Usage: ./echo <input filename> <output filename> <length of lag>\n");
        return 1;
    }
    wav_hdr wavHeader = getAudioHeader(argv[1]);
    int delay = atoi(argv[3]); // Convert from a character array to an int
    printf("delay = %i\n", delay);
    size_t N;
    float* audio = getAudio(argv[1], &N);
    float* echo = makeEcho(audio, N, delay);
    writeAudio(argv[2], echo, N+delay, wavHeader);
    delete[] audio;
    delete[] echo;
    return 0;
}
