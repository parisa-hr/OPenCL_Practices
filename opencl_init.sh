export QUARTUS_ROOTDIR=/opt/intelFPGA_pro/19.1/quartus
export QUARTUS_ROOTDIR_OVERRIDE=/opt/intelFPGA_pro/19.1/quartus
export INTELFPGAOCLSDKROOT=/opt/intelFPGA_pro/19.1/hld
export LD_LIBRARY_PATH=$INTELFPGAOCLSDKROOT/linux64/lib:$INTELFPGAOCLSDKROOT/host/linux64/lib:$INTELFPGAOCLSDKROOT/board/a10_ref/linux64/lib
export PATH=$PATH:$INTELFPGAOCLSDKROOT/bin:$INTELFPGAOCLSDKROOT/host/linux64/bin:$QUARTUS_ROOTDIR/bin
#export PATH=$PATH:/opt/intel/opencl-sdk/bin:/opt/intelFPGA_pro/18.0/hld/bin:/opt/intelFPGA_pro/18.0/hld/host/linux64/bin
export CL_CONTEXT_EMULATOR_DEVICE_INTELFPGA=1
