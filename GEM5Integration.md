#summary Guide for GEMS integration


# Step 1: Get a patched  [GEM5](http://www.gems.org/) #
You can get a modified clone of gem5-devel repository at:

```
shell$ hg clone https://code.google.com/p/tpzsimul.gem5/ gem5 
```

If you are want to have a updated gem5 (to the latest stable version), to incorporate our interface you should do:


```
shell$ hg clone https://code.google.com/p/tpzsimul.gem5/ gem5
shell$ cd gem5
shell$ hg pull http://repo.gem5.org/gem5
shell$ hg merge
shell$ hg ci -m "topaz interface added to gem5"
```

The modifications of Topaz patch are fairly small and localized in 4 files of ruby. Therefore in most cases, there will be a clean merge. Nevertheless, sometimes Gem5 guys changes key parts, such as statistics, or similar. In such occasions, to compile successfully the tool, it will be needed to "modify" the gem5-topaz interface.

Even if you want to use gem5-stable repository, you can use Topaz. The procedure, although "unelegant",  it might works (with some effort in the patch):

```
shell$ hg clone http://repo.gem5.org/gem5-stable/
shell$ hg clone https://code.google.com/p/tpzsimul.gem5/
shell$ cd tpzsimul.gem5/
shell$ hg diff 8811:tip  > ../patch  #We asume latest gem5 devel change-set is 8811
shell$ cd ../gem-stable/
shell$ cat ../patch | patch -p1       #(at least) up to changeset 8642 the patch applies clearly
shell$ hg ci -m "Topaz interface added to gem5-stable"
```

# Step 2: Obtain TOPAZ #

In order to get TOPAZ, you have to download it directly to the directory `gem5/ext` using:

```
cd gem5/ext
hg clone https://code.google.com/p/tpzsimul/ TOPAZ/ 
cd ..
```

# Step 3: Use TOPAZ within GEM5 Ruby Network tester #
**NOTE:  GEM5 Network tester is broken since this changeset [10089](http://comments.gmane.org/gmane.comp.emulators.m5.users/16287). Network-only mode Doesn't work anymore (last time checked was with dec 2014 stable version).**

To perform this compilation you should have a file at the 'build\_opt' directory where the env variable `USE_TOPAZ` is set to `True`. For example, a simple network tester can be compiled using the 'ALPHA\_Network\_Topaz\_test' configuration file already created which contains:

```
SS_COMPATIBLE_FP = 1
CPU_MODELS = 'AtomicSimpleCPU,TimingSimpleCPU,O3CPU,InOrderCPU'
PROTOCOL = 'Network_test'
USE_TOPAZ = True
```

To compile ´ALPHA\_Network\_Topaz\_test´ (you need a g++ > 4.3 and the remaining dependencies listed [here](http://gem5.org/Dependencies)):

```
scons build/ALPHA_Network_Topaz_test/gem5.opt -j 8 
```

After a bit, you get the build and to test topaz, you'll have to run a command like the following:

```
./build/ALPHA_Network_Topaz_test/gem5.opt ./configs/example/ruby_network_test.py --num-cpus=16 --num-dirs=16 \
--topology=Mesh --mesh-rows=4 --sim-cycles=1000 --injectionrate=0.1 --synthetic=0 --fixed-pkts \
--maxpackets=10000 --topaz-network=T44-CT-NOC 
```

This may report an error indicating that the SGML component does not exist. This occurs because Topaz requires an ini file indicating which [sgml](SGML.md) files to use. You need to make use of [Parameters](GEM5Parameters.md) to specify, among other parameters, where the initialization file of TOPAZ is. The option by default is _./TPZSimul.ini_, so we have two options: creating a file in the directory where GEM5 is invoked and repeat the previous command or creating it somewhere else indicating where it is.
For the first option you should create a file called  **TPZSimul.ini** in the directory where gem5 is invoked with the following content:

```
<!-- Paths can be absolute or relative. In this case, we are assuming -->
<!-- that TPZSimul.ini is located in gem5 root                                   -->
<RouterFile      id="./ext/TOPAZ/sgm/RouterGem5.sgm"  >
<NetworkFile     id="./ext/TOPAZ/sgm/NetworkGem5.sgm" >
<SimulationFile  id="./ext/TOPAZ/sgm/SimulaGem5.sgm"  >
```

The downloaded Topaz already provides a file with this content.
For the second option you need to use one of the command line options of gem5 to make Topaz point to the appropriate directory. This command line option is 'topaz-init-file'. Let's suppose you create this file at top **gem5** directory, then you will have to indicate this directory to the topaz-init-file parameter when invoking gem5. If you do so from its parent directory, this would be the command (notice the new paremeter at the end of the line):

```
./build/ALPHA_Network_Topaz_test/gem5.opt ./configs/example/ruby_network_test.py --num-cpus=16 --num-dirs=16\
  --topology=Mesh --mesh-rows=4 --sim-cycles=1000 --injectionrate=0.1 --synthetic=0 --fixed-pkts --maxpackets=10000\ 
--topaz-network=T44-CT-MC --topaz-init-file="./TPZSimul.ini"
```

Either of both options is correct and it is your choice which one to use.

Please, take a look at the 4 network [configurations](gem5conf.md) availabe in ./ext/TOPAZ/sgm/SimulaGem5.sgm. For sake of simplicity we restrict to 4 configurations, but all of the depicted in ./ext/TOPAZ/sgm/Simula.sgm can be used.  Any of these can be passed through _--topaz-network_ variable. Let's check a different network:

```
./build/ALPHA_Network_Topaz_test/gem5.opt ./configs/example/ruby_network_test.py --num-cpus=16 --num-dirs=16\
  --topology=Mesh --mesh-rows=4 --sim-cycles=1000 --injectionrate=0.1 --synthetic=0 --fixed-pkts --maxpackets=10000\
  --topaz-network=M44-CT-MC --topaz-init-file="./TPZSimul.ini"
```

After the simulation, TOPAZ results are printed at the end of gem5/ruby.stats file.

_If at some point you want to center your attention in network simulation, TOPAZ is able to work standalone (with higher level of flexibility).  Just follow this [guide](http://code.google.com/p/tpzsimul/wiki/GStarted) . We do not recommend to use GEM5 wrap-up to work with synthetic traffic or traces._


# Step 4: Use TOPAZ within a GEM5 Ruby Protocol #

We can use any of the Ruby config files. For example, if we want to use MOESI\_CMP\_token protocol (multicast and inordered traffic) we should create a file such as `build_opt/ALPHA_token_topaz`:

```
SS_COMPATIBLE_FP = 1
CPU_MODELS = 'AtomicSimpleCPU,TimingSimpleCPU,O3CPU,InOrderCPU'
PROTOCOL = 'MOESI_CMP_token'
USE_TOPAZ = True
```

We compile then with:

```
scons build/ALPHA_token_topaz/gem5.opt -j 8 
```

And eventually, we can check it with:

```
./build/ALPHA_token_topaz/gem5.opt ./configs/example/ruby_mem_test.py --maxloads 1000  --num-cpus=16 --num-dirs=16 \ 
   --topology=Mesh --num-l2caches=16 --mesh-rows=4  --topaz-network=T44-CT-UC --topaz-flit-size=16 \
   --topaz-adaptive-interface-threshold=0 > m5out/topaz.out
```


If everything was is correct, you should see something like:

```
<TOPAZ> +++++++ Topaz Enabled! +++++++ </TOPAZ>
info: Entering event queue @ 0.  Starting simulation...
system.cpu14: completed 1000 read, 540 write accesses @327673
hack: be nice to actually delete the event here
Exiting @ tick 327673 because maximum number of loads reached
```

And you can see Topaz out at m5out/topaz.out (sorry but not unified stats with m5 ATT)

```
.....
.....
.....

block_inputs: 0
block_outputs: 512
<TOPAZ>
Ratio Processor Clock/Network Clock = 1
Flit size in bytes                  = 16 bytes

******************* NET CONFIGURATION *********************
 Network        : Torus(4,4,1)
 Buffer control : CT
 Routing control: TORUS-DOR
 Started at     : Wed Apr 17 20:37:28 2013
 Ended at       : Wed Apr 17 20:37:28 2013
***********************************************************
 Simulation time         = 00:00:11 (11 secs)
 Memory Footprint        = 370.871 MBytes)
 Traffic Pattern         =  Empty
 Seed                    = 113
 Cycles simulated        = 123376
 Cycles deprecated       = 0
 Buffers size            = 31
 Messages length         = 1 packet(s)
 Packets length          = 5 flits
************************ PERFORMANCE ***********************
 Supply Thr. Norm        = 0.146074 flits/cycle/router
 Accept Thr. Norm        = 0.353563 f/c/r (m: 0.334984, M:0.365728)
 Supply Thr.             = 2.33718 f/c
 Throughput              = 5.65702 f/c (m: 5.35975, M:5.85164)
 Average Distance        = 2.13373
 Messages generated      = 99064
 Messages received       = 508736
 Messages to inject      = 94
...
...
...
TIME=123316


TOPAZ NETWORK USAGE
Usage TOPAZ network: 99%
Total TOPAZ messages: 518680
Total Number of messages: 518680

</TOPAZ>

SimpleNetwork Stats: The traffic you see here should be null
if your are not using the adaptive-interfaz)

```

## Speeding up the Simulation ##

It is possible to disable TOPAZ on-the-fly if the network is lightly loaded.  In such situations, the network contention will be almost zero, being therefore the effect of using the original simple network model in network latency almost negligible. When the applications changes from a compute-intensive phase to a communication-intensice phase, the load will be higher and TOPAZ will be reenabled on-the-fly. This feature is very important, specially when highly detailed models are used for the routers (otherwise, the slowdown will be  substantial). (more [info](GEMSAdaptiveRun.md)):

```
./build/ALPHA_token_topaz/gem5.opt ./configs/example/ruby_mem_test.py -l 1000  --num-cpus=16 --num-dirs=16
   --topology=Mesh --num-l2caches=16 --mesh-rows=4  --topaz-network=T44-CT-UC 
--topaz-flit-size=16 --topaz-adaptive-interface-threshold=100
```

## Pending Extensions ##

Although `topology=` is ignored internally by TOPAZ, it is required to perform the map of ruby components to TOPAZ routers. Since we are using a 4x4 torus, a 4x4 Mesh will be enough to have correct mapping. Because GEM5 does not support the flexibility of GEMS, in terms of topology construction, at this point there is not possible to use File\_specified topologies. In the future it could be interesting to add such feature, since in SoC context, could be very useful.

Good luck!