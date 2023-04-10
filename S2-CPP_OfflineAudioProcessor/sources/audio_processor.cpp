//
// Created by Thomas Hezard on 2019/01/28
// thomas.hezard@mwm.io
//

#include "audio_processor.h"
#include <assert.h>
#include <cmath>

AudioProcessor::AudioProcessor() {
}

void AudioProcessor::Prepare() {
}

void AudioProcessor::Process(float* input_buffer, float* output_buffer, int number_frames) {
    assert(number_frames >= 0);
    for (int i=0; i<number_frames; ++i) {
        output_buffer[i] = input_buffer[i];
    }
}

void AudioProcessor::setDistoGain(int gain) {
    distoGain = gain;
}

void AudioProcessor::setDistoMix(float mix) {
    distoMix = mix;
}

void AudioProcessor::Distortion(float* input_buffer, float* output_buffer, int number_frames, int gain, float mix) {
    
    if (gain!=AudioProcessor::distoGain) {
        AudioProcessor::setDistoGain(gain);
    }

    if (mix!=AudioProcessor::distoMix) {
        AudioProcessor::setDistoMix(mix);
    }
    
    assert(number_frames >= 0);
    for (int i=0; i<number_frames; ++i) {
        //output_buffer[i] = input_buffer[i];
        // Distortion effect
        /*
        mix = 0.5
        gain = 100 # amount of distortion
        x = input_data
        q = x * gain / max(abs(x))
        z = np.sign(q) * (1 - np.exp(np.sign(-q) * q))
        output_data = mix * z * max(abs(x)) / max(abs(z)) + (1 - mix) * x
      
        */
       /*
        float q=input_buffer[i]*distoGain/(std::abs(input_buffer[i]));
        float z=std::signbit(q) ? (1-expf(std::signbit(-q)*q)) : (1-expf(-q));
        output_buffer[i] = distoMix*z*std::abs(input_buffer[i])/std::abs(z) + (1-distoMix)*input_buffer[i];
        */
       output_buffer[i] = std::signbit(input_buffer[i]) ? mix*(1-expf(-distoGain*input_buffer[i])) : mix*(-1+expf(distoGain*input_buffer[i]));

       /*
        if (input_buffer[i] > 0) {
            output_buffer[i] = (1-distoMix)*input_buffer[i] + mix*(1-exp(-distoGain*input_buffer[i]));
        } else {
            output_buffer[i] = (1-distoMix)*input_buffer[i] + mix*(-1+exp(distoGain*input_buffer[i]));
        }
œ       */
    }
}
