//
// Created by Thomas Hezard on 2019/01/28
//

#ifndef OFFLINE_AUDIO_PROCESSOR_AUDIO_PROCESSOR_H
#define OFFLINE_AUDIO_PROCESSOR_AUDIO_PROCESSOR_H




class AudioProcessor {

    public:

    // Constructors and destructors
    AudioProcessor();
    ~AudioProcessor() = default;

    // Prepare function
    void Prepare();

    // Process
    void Process(float* input_buffer, float* output_buffer, int number_frames);

    // Distortion
    void setDistoGain(int gain);
    void setDistoMix(float mix);
    void Distortion(float* input_buffer, float* output_buffer, int number_frames, int gain, float mix);


    private:
    // persistent data members
    // ex: float        sampleRate;
    int distoGain=300;
    float distoMix=0.5;
    // pre-allocated memory
    // ex: | float *    memoryBuffer;
    //     | int        memoryBufferLength;

};


#endif //OFFLINE_AUDIO_PROCESSOR_AUDIO_PROCESSOR_H
