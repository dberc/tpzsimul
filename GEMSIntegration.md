

# Step 1: Get the interface #
There is two ways, to get the interface between GEMS and TOPAZ: using our modified code or patching the original one. Lets assume you are starting with the easy one (you have a untouched GEMS version, which will be unlikely) . Our modified source code is [GEMS Version 2.1.1](http://www.cs.wisc.edu/gems/). The original `.tar.gz` has been uncompressed and added our interfaz. To get that code you should do:
```
hg clone https://code.google.com/p/tpzsimul.gems/ tpzsimul-gems 
```

This will create a directory with the original GEMS tree. If you want to see the modifications in the code, you can use mercurial **diff tool** or accessing [googleCode](http://code.google.com/p/tpzsimul/source/list?repo=gems). Future changes in the interface will be pushed to this repository.

# Step 2: Compile GEMS #

We will assume Simics 3.0.XX will be used. Although there is a Virtutech patch to make GEMS compatible with Simics 4.XX, for sake of simplicity we will keep using the original distribution. Following the guide available for [Simics 3.0.X](http://www.cs.wisc.edu/gems/doc/gems-wiki/moin.cgi/Setup_for_Simics_3.0.X), you configure all GEMS. That should be straightforward (be advised that you need a valid license to compile Simics modules). For some reason, our simics workspace-setup does not create a link to installation src. So, at the end of the steps you have to do:
```
shell$ ln -s $SIMICS_INSTALL/src/ $GEMS/simics/
```

Then, you have to modify where TOPAZ source code is located. In order to do it, you have to modify `$GEMS/common/Makefile.topaz`. This makefile controls the compilation process:

```
#  
#
#Place here your topaz  *absolute* path.
TOPAZ_ROOT :=/afs/atc.unican.es/u/v/vpuente/tpzsimul/

#If you want to run TOPAZ -u option, set TOPAZ_TRACE to "yes" and put the absolute path of trace file
TOPAZ_TRACE ?= no

# NOTE: You are using TOPAZ if USE_TOPAZ is defined. If you don't want to use TOPAZ comment the following line.
# NOTE2: When you comment/uncomment USE_TOPAZ flag, run "make clean" before recompiling. 
#        Alternatively, you can run ruby/touch_topaz.sh
USE_TOPAZ = yes

```

Other TOPAZ specific features are controlled by topaz Makefile itself. For example, to run multithreaded versions (1 thread for GEMS and 1 thread for TOPAZ) you have to modify TOPAZ makefile.

Once this has been done we are ready to go. for example in `$GEMS/` you can run:

```
shell$ cd $GEMS/ruby/
shell$ make -j 8 make PROTOCOL=MOESI_CMP_token DESTINATION=MOESI_CMP_token 
shell$ cd ../opal/
shell$ make -j 8 DESTINATION=MOESI_CMP_token
```

At the end, the modules will be constructed and ready to be executed.

# Step 3: Configure the Simulators #

Before to get into the full burden, we suggest to check if ´tester´ runs ok. To do it, you need to create a TPZSimul.ini file in your running directory. Remember that this file indicates where TOPAZ SGML files are located. You can use relative or absolute paths.For example, let assume that  `tpzsimul-gems` and `tpzsimul` are in the same directory and we want to run the `tester` from `$GEMS/ruby/` directory. Then, this file should include something like:

```
<RouterFile      id="../../tpzsimul/sgm/Router.sgm"  >
<NetworkFile     id="../../tpzsimul/sgm/Network.sgm" >
<SimulationFile  id="../../tpzsimul/sgm/Simula.sgm"  >

```

After that, you should indicate what simulation you want to run. This is controlled by the parameters defined in `ruby/config/rubyconfig.defaults. More information about those parameters [here](GEMSParameters.md). Let say, we want to use 'M44-WH-NOC' which represents a mesh 4x4 using worm-hole. Looking at ´Simula.sgm´ we find that simulation has the following parameters (most SGML parameters explained [here](SGML.md)):

```
<Simulation id="M44-WH-NOC">
   <Network            id="M44_WH_NOC">
   <SimulationCycles   id=20000000000000000>
   <StopInjectionAfterMsg id=200000000000>
   <TrafficPattern     id="MODAL" type=EMPTY numMessTypes=4>
   <Seed               id=113>
   <Load               id=0.1>
   <MessageLength      id=1>
   <PacketLength       id=5>
   <LinkWidth          id=16>
   <FlitSize           id=5>
   <NetworkClockRatio  id=1>
   <UnifyNetworks      id=1>
</Simulation>
```

As we can see, this simulation is using the following network topology 'M44\_WH\_NOC' which can be found at ´Network.sgm´ with the following parameters:
```
<MeshNetwork id="M44_WH_NOC" sizeX=4  sizeY=4  router="MESH-WH-NOC" delay=0>
```

Which uses the simple router MESH-WH-NOC defined at Router.sgm:

```
<Router id="MESH-WH-NOC" inputs=4 outputs=4 bufferSize=10 bufferControl=WH routingControl="MESH-DOR">
   <Injector id="INJ" numHeaders=1 typeInj="WH" numMessTypes=5>
   <Consumer id="CONS">

   <SimpleRouter id="ROUTER" inputs="5" outputs="5" headerDelay=0 dataDelay=0 vnets=5 >
      <Input  id=1  type="X+">
      <Input  id=2  type="X-">
      <Input  id=3  type="Y+">
      <Input  id=4  type="Y-">
      <Input  id=5  type="Node">
      <Output id=1  type="X+">
      <Output id=2  type="X-">
      <Output id=3  type="Y+">
      <Output id=4  type="Y-">
      <Output id=5  type="Node">
   </SimpleRouter>

   <Connection id="C01" source="INJ" destiny="ROUTER.5">
   <Connection id="C02" source="ROUTER.5" destiny="CONS">

   <Input id="1" type="X+"   wrapper="ROUTER.1">
   <Input id="2" type="X-"   wrapper="ROUTER.2">
   <Input id="3" type="Y+"   wrapper="ROUTER.3">
   <Input id="4" type="Y-"   wrapper="ROUTER.4">

   <Output id="1" type="X+"   wrapper="ROUTER.1">
   <Output id="2" type="X-"   wrapper="ROUTER.2">
   <Output id="3" type="Y+"   wrapper="ROUTER.3">
   <Output id="4" type="Y-"   wrapper="ROUTER.4">
</Router>
```

The easiest way to instantiate the right networt is to define **g\_TOPAZ\_SIMULATION: M44-WH-NOC** at `rubyconfig.defaults` and recompile ruby. Initially you do not need to do it because the repository is tuned to simplify this initial steps. Ruby assumes 16 processors, 16 L2 banks and 16 Memory controllers. These parameters will force ruby to use  `network/simple/Network_Files/TOKEN_CMP_Procs-16_ProcsPerChip-16_L2Banks-16_Memories-16.txt` topology definition file.

# Step 3: Running the Simulation #

Just do:
```
shell$ cd $GEMS/ruby
shell$ amd64-linux/generated/MOESI_CMP_token/bin/tester.exec -p 16 -l 100
```

You get the output of both simulators getting TOPAZ stats within ruby's.. You will get something like ...

```
Parsing command line arguments:
  length of run = 100
Ruby Timing Mode
Creating event queue...
Creating event queue done
Creating system...
  Processors: 16
MODAL
MODAL
... ruby stuff

<TOPAZ> +++++++ Topaz Enabled! +++++++ </TOPAZ>
....more ruby stuff

 -----------------------------------------------
| <TOPAZ>: network performance and configuration|
 -----------------------------------------------

Ratio Processor Clock/Network Clock = 1
Flit size in bytes                  = 16 bytes
Command packets size                = 1 flits
Data packet size                    = 5 flits

******************* NET CONFIGURATION *********************
 Network        : Mesh(4,4,1)
 Buffer control : WH
 Routing control: MESH-DOR
 Started at     : Mon Feb  6 13:52:21 2012
 Ended at       : Mon Feb  6 13:52:21 2012
***********************************************************
 Simulation time         = 00:00:37 (37 secs)
 Memory Footprint        = 20.9414 MBytes)
 Traffic Pattern         =  Empty
 Seed                    = 113
 Cycles simulated        = 500113
 Cycles deprecated       = 0
 Buffers size            = 10
 Messages length         = 1 packet(s)
 Packets length          = 5 flits
************************ PERFORMANCE ***********************
 Supply Thr. Norm        = 0.000894548 flits/cycle/router 
 Accept Thr. Norm        = 0.000894548 f/c/r (m: 0.000137969, M:0.000821814)
 Supply Thr.             = 0.0143128 f/c
 Throughput              = 0.0143128 f/c (m: 0.0022075, M:0.013149)
 Average Distance        = 2.64007
 Messages generated      = 5226
 Messages received       = 5226
 Messages to inject      = 0
 Total message latency   = 20.8299
 Network message latency = 19.8299
 Buffer message latency  = 1
 Maximum message latency = 62
 Last Message cycle      = 3509
***********************************************************
**********************************************************
Time    f/c/r   f/c     TotLat  NetLat  AverDist
**********************************************************
344     0.207   3.314   20.817  19.629   2.614
857     0.177   2.838   22.277  21.280   2.679
1208    0.231   3.692   21.110  19.923   2.755
1723    0.174   2.788   20.593  19.740   2.623
2826    0.084   1.342   19.680  18.888   2.568
**********************************************************
        Hops     Message Count   Percent
**********************************************************
        0        1045            19.996
        1        1519            29.066
        2        1418            27.134
        3        831             15.901
        4        342             6.544
        5        71              1.359
TIME=500112

</TOPAZ>

... continue

```

# Step 4: Running with Simics #
`$GEMS/prepare_simics_home.sh´ create automatically *`TPZsimul.ini`* in `simics/home/DESTINATION` directory. It uses ´$(TOPAZ_ROOT)/sgm/*Gems.sgm` as SGML files. You can follow the guide available at [GEMS wiki](http://www.cs.wisc.edu/gems/doc/gems-wiki/moin.cgi/QuickStart)