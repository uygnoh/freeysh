### Cortex-M 编译烧写脚本

#!/bin/bash
make
cd Output
st-flash write main.bin 0x8000000
