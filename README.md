# Arduino Wave Player

Sketch and schematic for playing audio waves in Arduino Mega 1280/2560.

![alt screenshot](https://raw.githubusercontent.com/lrusso/ArduinoWavePlayer/master/ArduinoWavePlayer.png)


## How to Guide:

1) Convert your WAV file into a new 8 bits, 8000 MHz and Mono WAV file.

```
sox mywave.wav -c 1 -b 8 -r 8000 myfinalwave.wav
```

2) Convert the new WAV file into an array.

```
wav2c myfinalwave.wav
```

3) Copy the content of the array that is in the new file myfinalwave.c

4) Paste that content into the array SoundData located in the file Sample/SoundData.h

## Available at:

https://playground.arduino.cc/Code/PCMAudioTimer5/

## Based on the work of:

https://playground.arduino.cc/Code/PCMAudio
