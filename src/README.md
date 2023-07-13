## Compile and flash for the Atreus

Clone the repository of Kaleidoscope.

```
git clone https://github.com/keyboardio/Kaleidoscope
cd Kaleidoscope
```

Make sure you are in the Atreus directory.

```
cd examples/Devices/Keyboardio/Atreus
```

Replace the content of the `Atreus.ino` file with the attached one.

Make sure to have correct dependencies, and then compile and flash it.

```
KALEIDOSCOPE_DIR=/home/<user>/lab/github.com/keyboardio/Kaleidoscope make compile
KALEIDOSCOPE_DIR=/home/<user>/lab/github.com/keyboardio/Kaleidoscope make flash
```
