#include "stdio.h"
#include "audio.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>

float* reverseArray(float* arr, int N) {
    float* rev = new float[N];
    for (int i = 0; i < N; i++) {
        rev[N-i-1] = arr[i];
    }
    return rev;
}

int main(int argc, char* argv[]) {
    wav_hdr wavHeader = getAudioHeader(argv[1]);
    size_t N;
    float* audio = getAudio(argv[1], &N);
    float* rev = reverseArray(audio, N);
    writeAudio(argv[2], rev, N, wavHeader);
    delete[] audio;
    delete[] rev;
    return 0;
}
