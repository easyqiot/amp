# WIFI controller for audio amplifier


### Build

Follow [this](https://github.com/easyqiot/esp-env) instruction 
to setup your environment.


```bash
source esp-env/nonos/activate.sh

cd esp-env/nonos/sdk/
git clone git@github.com:easyqiot/amp.git
cd amp
make clean
./gen.sh
make flash
```

