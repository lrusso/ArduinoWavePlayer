# Arduino Wave Player

Sketch for playing audio waves in Arduino Mega 1280/2560

# How to Guide:

Convert your WAV file to a 8000 MHz Mono WAV file.

```
sox mywave.wav -r 8000 myfinalwave.wav
```

Convert the new WAV file into an array.

```
wav2c myfinalwave.wav
```

## Available at:

https://playground.arduino.cc/Code/PCMAudioTimer5/

## Based on the work of:

https://playground.arduino.cc/Code/PCMAudio
