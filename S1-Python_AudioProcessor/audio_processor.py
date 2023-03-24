import numpy as np
import scipy.io.wavfile as wavfile


# Parameters
# **********

# This must be an audio file readable by scipy.io.wavfile.read() function
input_file = 'Marimba.wav'
output_file = 'output.wav'


# Read input file
# ***************

fs, input_data = wavfile.read(input_file, mmap=True)
# convert to float
max_value = float(-np.iinfo(input_data.dtype).min)
input_data = input_data.astype('float32') / max_value
# convert to mono if not already
if len(input_data.shape) > 1:
    input_data = np.mean(input_data, axis=1)
input_data = input_data.flatten()


# Audio data process
# ******************

output_data = np.zeros(len(input_data))

# *************************
# * PROCESSING COMES HERE *
# *************************
a = 0.5
d = 30000
f = 4000
selectEffect = 3

if selectEffect == 1:
    for i in range(d):
        output_data[i] = input_data[i]
    for n in range(d, len(output_data)):
        output_data[n] = input_data[n] + a * output_data[n - d]

if selectEffect == 2:
    for i in range(len(output_data)):
        output_data[i] = (1 + a * np.cos(2 * np.pi * f * i/fs)) * input_data[i]
        
        

# Source : DAFX.pdf
# Distortion based on an exponential function 
# x - input
# gain - amount of distortion
# mix - mix of original and distorted sound, 1=only distorted, 0.5=equal mix, 0=only original
# q=x*gain/max(abs(x));
# z=sign(q).*(1-exp(sign(-q).*q));
# y=mix*z*max(abs(x))/max(abs(z))+(1-mix)*x;
# y=y*max(abs(x))/max(abs(y));

if selectEffect == 3:
    mix = 0.5
    gain = 100 # amount of distortion
    x = input_data
    q = x * gain / max(abs(x))
    z = np.sign(q) * (1 - np.exp(np.sign(-q) * q))
    output_data = mix * z * max(abs(x)) / max(abs(z)) + (1 - mix) * x
    #No need to normalize  
    #output_data = output_data * max(abs(x)) / max(abs(output_data))

"""

if selectEffect==3:
    mix = 1
    x = input_data
    output_data = (1-mix)*x + mix*np.sign(x)*np.log(1+255*np.abs(x))/np.log(256)

# distorsion effect based on exponential function

if selectEffect==3:
    gain=1
    exponent=1
    output_data = gain * np.power(np.abs(input_data), exponent) * np.sign(input_data)
    #output_signal /= np.max(np.abs(output_signal))
"""


# *************************


# Save output
# ***********
output_data = 0.99 * output_data / max(abs(output_data))
wavfile.write(output_file, int(fs), (output_data*np.iinfo(np.int16).max).astype(np.int16))
