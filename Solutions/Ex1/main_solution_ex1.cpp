#include <math.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <iostream>

#include "CL/opencl.hpp"
#include "../../SimpleOpenCL/utility.h"

static const cl_uint  vectorSize = 4096; // must be evenly divisible by workSize
static const cl_uint  workSize   = 256;

#define EXERCISE1

int  main(void)
{
    cl_int  err;

    // Setup Platformd
    // Get Platform ID
    std::vector<cl::Platform>  PlatformList;

	////////////// Exercise 1 Step 2.3
    err = cl::Platform::get(&PlatformList);
    checkErr(err, "Get Platform List");
    checkErr(PlatformList.size() >= 1 ? CL_SUCCESS : -1, "cl::Platform::get");
    print_platform_info(&PlatformList);

    // Look for Fast Emulation Platform
    uint  current_platform_id = get_platform_id_with_string(&PlatformList, "Emulation");

    printf("Using Platform: %d\n\n", current_platform_id);

    // Setup Device
    // Get Device ID
    std::vector<cl::Device>  DeviceList;

	////////////// Exercise 1 Step 2.5
    err = PlatformList[0].getDevices(CL_DEVICE_TYPE_ALL, &DeviceList);
// std::cout << "ERROR = " << get_platform_id_with_string(&PlatformList, "Emulation") << std::endl;

    checkErr(err, "Get Devices");
    print_device_info(&DeviceList);

    // Create Context
    ////////////// Exercise 1 Step 2.6
    cl::Context  mycontext(DeviceList, NULL, NULL, NULL, &err);

    checkErr(err, "Context Constructor");

    // Create Command queue
	////////////// Exercise 1 Step 2.7
    cl::CommandQueue  myqueue(mycontext, DeviceList[0], 0, &err);

    checkErr(err, "Queue Constructor");

    // Create Buffers for input and output
	////////////// Exercise 1 Step 2.8
    cl::Buffer  Buffer_In(mycontext, CL_MEM_READ_ONLY, sizeof(cl_float) * vectorSize);
    cl::Buffer  Buffer_In2(mycontext, CL_MEM_READ_ONLY, sizeof(cl_float) * vectorSize);
    cl::Buffer  Buffer_Out(mycontext, CL_MEM_WRITE_ONLY, sizeof(cl_float) * vectorSize);

    // Inputs and Outputs to Kernel, X and Y are inputs, Z is output
    // The aligned attribute is used to ensure alignment
    // so that DMA could be used if we were working with a real FPGA board
    cl_float  X[vectorSize] __attribute__((aligned(64)));
    cl_float  Y[vectorSize] __attribute__((aligned(64)));
    cl_float  Z[vectorSize] __attribute__((aligned(64)));

    // Allocates memory with value from 0 to 1000
    cl_float  LO = 0;
    cl_float  HI = 1000;

	fill_generate(X, Y, Z, LO, HI, vectorSize);

    // Write data to device
	////////////// Exercise 1 Step 2.9
    err = myqueue.enqueueWriteBuffer(Buffer_In, CL_FALSE, 0, sizeof(cl_float) * vectorSize, X);
    checkErr(err, "WriteBuffer");
    err = myqueue.enqueueWriteBuffer(Buffer_In2, CL_FALSE, 0, sizeof(cl_float) * vectorSize, Y);
    checkErr(err, "WriteBuffer 2");
    myqueue.finish();

#ifndef EXERCISE1
	// create the kernel
	const char *kernel_name = "SimpleKernel";

    // Read in binaries from file
    std::ifstream  aocx_stream("../SimpleKernel.aocx", std::ios::in | std::ios::binary);

    checkErr(aocx_stream.is_open() ? CL_SUCCESS : -1, "SimpleKernel.aocx");

    std::string            prog(std::istreambuf_iterator<char>(aocx_stream), (std::istreambuf_iterator<char>()));
    cl::Program::Binaries  mybinaries(1, std::make_pair(prog.c_str(), prog.length()));

	// Create the Program from the AOCX file.
	////////////////////// Exercise 2 Step 2.3    ///////////////////
	cl::Program
      checkErr(err, "Program Constructor");

	// build the program
	//////////////      Compile the Kernel.... For Intel FPGA, nothing is done here, but this conforms to the standard
	//////////////       Exercise 2   Step 2.4    ///////////////////
    err = checkErr(err, "Build Program");

	// create the kernel
	//////////////       Find Kernel in Program
	//////////////       Exercise 2   Step 2.5    ///////////////////
	cl::Kernel
      checkErr(err, "Kernel Creation");

	//////////////     Set Arguments to the Kernels
	//////////////       Exercise 2   Step 2.6    ///////////////////
    err = checkErr(err, "Arg 0");
    err = checkErr(err, "Arg 1");
    err = checkErr(err, "Arg 2");
    err = checkErr(err, "Arg 3");

	printf("\nLaunching the kernel...\n");

	// Launch Kernel
	//////////////       Exercise 2   Step 2.7    ///////////////////
    err = checkErr(err, "Kernel Execution");

	// read the output
	//////////////       Exercise 2   Step 2.8    ///////////////////
    err = checkErr(err, "Read Buffer");

    err = myqueue.finish();
	checkErr(err, "Finish Queue");

    float  CalcZ[vectorSize];

    for (uint i = 0; i < vectorSize; i++)
	{
		//////////////  Equivalent Code running on CPUs
		//////////////       Exercise 2   Step 2.9    ///////////////////
        CalcZ[i] = }

    // Print Performance Results
    verification(X, Y, Z, CalcZ, vectorSize);

#endif

    return 1;
}
