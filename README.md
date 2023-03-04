
# Real time audio processing

*__An introductory project to the wonderful world of real-time audio programming.__*

---

## Author

Thomas Hézard - Audio scientist and developer  
www.thomashezard.com  
thomas.hezard [at] thz.fr

---

## License

This work is licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-nc-sa/4.0/).  
[![Licence Creative Commons](https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png)](http://creativecommons.org/licenses/by-nc-sa/4.0/)

---

## 🎯  Objectives

The goal of this project is to implement a real-time audio signal processing application.  
You will follow the usual steps of such a project:  
- Preliminary step: choice of an audio effect and bibliography.
- S1. Prototyping the audio processing algorithm with `Python`.
- S2. Platform-agnostic implementation of the audio processing module in either `C` or `C++`, testing in a simple non-real-time command-line-interface (CLI) program.
- S3. Integration of the module in real-time audio processing applications coded in either `C` or `C++`.

The main objective here is to work on real-time audio processing algorithms in `C` and/or `C++`. Therefore, other parts of the code (command line or graphical interface, plugging to the system's audio render loop etc.) are provided (coded in `C++` for the most part). However, it is possible to modify everything at will.

For steps S2 and S3, you can choose the language you want to work with: `C` or `C++`. I personally recommend to work on this project in `C++`, but you can work in `C` if you are not familiar with the `C++` language or if you want to specifically work on your `C` skills.

## ☝️  What you'll need

### 📚  Prerequisites

- Baisc knowledge of **_Digital Signal Processing theory_** (digital signal representation, Z-transform, difference equation, digital filtering etc.).
- Basic knowledge of **_Python_** plus **_C_** and/or **_C++_** with their standard tools.
- The last step of the project is based on the [JUCE framework](https://juce.com/). If needed, you can consult the [JUCE repository](https://github.com/juce-framework/JUCE) and the [JUCE documentation](https://juce.com/learn/tutorials) for information and help.

### 💻 📱 🎧  Hardware

- Steps S1 and S2 can be done on __any Linux, macOS or Windows computer__.
- Step S3 can also be done on __any Linux, macOS or Windows computer__, but additionnal hardware may be needed depending on the platform for which you want to build your application:
  - You can run the application on __the same computer__ you are working on, but you will need at least __a mono audio input and a stereo audio output__.
  - You can run the application on an __Android device__, smartphone or tablet, with at least __a mono audio input and a stereo audio output__. 
  - You can run the application on an __iOS device__, smartphone or tablet, with at least __a mono audio input and a stereo audio output__, but you will need to work on __macOS computer__ in that case.
  - __Headphones__, wired or bluetooth, is strongly recommended.
  - You will have the choice to work on a project with audio input to test your audio effect on your own voice, or a project without audio input to test your audio effect on audio files. If you choose to work with audio input, you will need __a microphone__, either integrated in your computer or smartphone, or an external microphone with adaquate connection for your system (analog plug, USB microphone or USB audio interface).

### 🧑‍💻 Softwares

- For step 1, a pre-configured online environment is available on __[replit](https://replit.com)__ and only requires a web browser. If you prefer to work on your own environment, you can use __whatever Python editor you'd like__ (IDLE, Spyder, VSCode, Atom, PyCharm etc.), with __Python >=3.7, numpy and scipy__, and all the other libraries you may want to use for the implementation of your algorithm. 
- For step 2, pre-configured online environments are available on __[replit](https://replit.com)__ and only requires a web browser. If you prefer to work on your own environment, S2 requires either __cmake__ and __make__ or any __C++ compiler__ (__g++ or clang++__ for example), and any __code editor__. Use of a debugger -__gdb__ for example- is strongly recommended but not necessary. Feel free to use you favorite __C/C++ IDE__ (VSCode, Atom, Eclipse, Code::Blocks, Geany, CLion, Visual Studio, XCode, etc.).
- Step 3 requires the [__JUCE framework__](https://juce.com), which you can get for free for personnal use. The project has beend tested and validated with JUCE 7.0.5, it is recommended to use the exact same version. The configuration needed to build the project depends on the platform you are working on, and the platform you are building for:
  - Working on Windows, you'll be able to build for
    - Windows with [__Visual Studio 2015, 2017, 2019 or 2022__](https://visualstudio.microsoft.com) (with the __Desktop Development with C++__ module),
    - Android with [__Android Studio__](https://developer.android.com/studio/).
  - Working on macOS (Intel or ARM), you'll be able to build for
    - macOS and iOS with [__Xcode__](https://developer.apple.com/xcode/) and an __[Apple Developer account](https://developer.apple.com/account/)__,
    - Android with [__Android Studio__](https://developer.android.com/studio/).
  - Working on Linux, you'll be able to build for 
    - Linux with [__make__](https://www.gnu.org/software/make/) or [__Code::Blocks__](https://www.codeblocks.org),
    - Android with [__Android Studio__](https://developer.android.com/studio/) (not fully tested).  
  
    On Linux, the following installation step is needed to run the Projucer and to build the project (tested on Ubuntu 20.04, Debian 10 and Debian 11, X86_64 architecture)
      ```bash
      sudo apt install make g++ libfreetype6-dev libasound2-dev libcurl4-openssl-dev libwebkit2gtk-4.0-dev
      ```


## 🎙️ Example audio files

In order to simplify the platform-agnostic implementation and get rid of the audio decoding and encoding, you'll use WAV audio files throughout this project.  
Some audio file examples are provided in the [`Sounds`](Sounds) directory. All WAV files are mono with a sample rate of 44100 Hz.  
Feel free to use these or your own audio files to test your code.


## 🦶  Project steps

### 📖  Preliminary step: Choice of the audio effect and bibliography

This project can be carried out with any audio processing algorithm, as long as it is real-time compatible. Here is a list of suggestions, from the easiest to the most difficult:

- filters (high-pass, low-pass, band-pass, peaking, shelf etc.),
- delay,
- tremolo (amplitude modulation),
- vibrato (frequency modulation),
- bitcrusher (low-resolution quantization, bits manipulation),
- distortion / overdrive,
- wah-wah,
- phaser,
- dynamic compressor,
- graphical or parametric equalizer,
- reverb,
- pitch-shifting (temporal or frequential methods)
- etc.

Before starting step 1, you need to choose an algorithm and study it by finding the necessary literature to fully understand it and be able to implement it. You'll need at least a graphical representation of your effect, with the corresponding time-domain and frequency-domain equations.     

Here is a selected bibliography on audio effects:
- [DAFX - Digital Audio Effects](http://dafx.de/DAFX_Book_Page/index.html)
- [Julius Orion Smith III website](https://ccrma.stanford.edu/~jos/)


### 🧑‍🔬  S1. Prototyping : [`S1-Python_AudioProcessor`](S1-Python_AudioProcessor)

The goal of this first step if the try and test your algorithm. Python let you implement and test audio processing algorithms quickly, with very few lines of code. You can test and improve your algorithm until you obtain satisfying audio results.

A script `audio_processor.py` is provided, as long as some audio files (see above).  
For the moment, the script simply copies the content of the input audio file to the output audio file without any modification.

What you have to do in this step is to add your processing algorithm in the script where indicated to modify the audio data.  
Check the results, and proceed to the next step when you are satisfied.  

Please refer to the [README.md file](S1-Python_AudioProcessor/README.md) file of the [`S1-Python_AudioProcessor`](S1-Python_AudioProcessor) directory.  


### 👨‍💻  S2. C or C++ Implementation: [`S2-C_OfflineAudioProcessor`](S2-C_OfflineAudioProcessor) or [`S2-CPP_OfflineAudioProcessor`](S2-CPP_OfflineAudioProcessor)

During this second step, your goal is to translate the final algorithm of the previous step in platform-agnostic, real-time-compatible C/C++ code. In order to simplify this task, you will do this in the most simple context: a CLI program called `OfflineAudioProcessor`.  

- `C` version: please refer to the [README.md file](S2-C_OfflineAudioProcessor/README.md) inside the [`S2-C_OfflineAudioProcessor`](S2-C_OfflineAudioProcessor) directory for detailed explanation.
- `C++` version: please refer to the [README.md file](S2-CPP_OfflineAudioProcessor/README.md) inside the [`S2-CPP_OfflineAudioProcessor`](S2-CPP_OfflineAudioProcessor) directory for detailed explanation.

### 🧑‍🎤  S3. Integration inside a real-time application: `AudioLoop` and `AudioProcessor`

The final step aims at integrate the algorithm in a real-time application. More precisely, you will directly integrate the `AudioProcessor` class/struct, the one you modified in the previous step, in one of the simple applications provided: `AudioLoop` and `AudioProcessor`.

`AudioLoop` is a simple example of audio real-time application with audio input and output: it captures the audio input of the device, applies a real-time process on the data, and sends the modified audio data to the audio output. This application is developped using the [JUCE framework](https://juce.com), and can be built for macOS, Linux, Windows, iOS or Android.  
This project requires a microphone, either integrated in your computer or smartphone, or an external microphone with adaquate connection for your system (analog plug, USB microphone or USB audio interface).  
Also, using headphones is strongly recommended to work on this project to avoid larsen effects (audio feedback loop).

`AudioProcessor` is a simple example of audio real-time application with audio output only: it reads an audio file, applies a real-time process on the data, and sends the modified audio data to the audio output. This application is developped using the [JUCE framework](https://juce.com), and can be built for macOS, Linux or Windows.

- If you completed S2 with the `C` version, please refer to [S3-C_JUCE_AudioLoop/README.md file](S3-C_JUCE_AudioLoop/README.md) or [S3-C_JUCE_AudioProcessor/README.md file](S3-C_JUCE_AudioProcessor/README.md) for detailed explanation.
- If you completed S2 with the `C++` version, please refer to the [S3-CPP_JUCE_AudioLoop/README.md file](S3-CPP_JUCE_AudioLoop/README.md) or [S3-CPP_JUCE_AudioProcessor/README.md file](S3-CPP_JUCE_AudioProcessor/README.md) for detailed explanation.
