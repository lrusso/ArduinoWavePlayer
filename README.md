# Arduino Wave Player

Sketch and schematic for playing audio waves in Arduino Mega 1280/2560.

![alt screenshot](https://raw.githubusercontent.com/lrusso/ArduinoWavePlayer/master/ArduinoWavePlayer.png)


## How to Guide:

Convert your WAV file into a new 8 bits, 8000 MHz and Mono WAV file.

```
sox mywave.wav -c 1 -b 8 -r 8000 myfinalwave.wav
```

Convert the new WAV file into an array.

```
wav2c myfinalwave.wav
```

## Available at:

https://playground.arduino.cc/Code/PCMAudioTimer5/

## Based on the work of:

https://playground.arduino.cc/Code/PCMAudio
