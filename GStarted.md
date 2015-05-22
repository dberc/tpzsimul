

# Guide to Compile `TOPAZ network simulator` #

### Step 1: Get It ###
> You will need a **[Mercurial](http://mercurial.selenic.com/)** client in order to do so. If you have little idea about DVCS, we suggest to take a look at the best **[Mercurial tutorial](http://hginit.com/)** out there.

```
  hg clone https://code.google.com/p/tpzsimul/ tpzsimul 
```

### Step 2: Compile It ###

> The code is structured in 4 directories:

  * **src** includes the implementation of all classes, i.e., _.cpp_
  * **inc** includes the specification of all classes, i.e., _.hpp_
  * **sgm** includes _SGML_ samples of different router microarchitectures, networks, etc...
  * **mak** is where the simulator has to be compiled

> Therefore, we do the following

```
shell$ cd tpzsimul/mak
shell$ make -j 8
```

> The host class will be identified and suitable compilation options are set. By default, `Makefile` assumes _gcc_. You can change it editing the `$(HOST_TYPE)` entry in Makefile.

> When the compilation ends, a `tpzsimul/mak/$(HOST_TYPE)/` directory with all objects and **`tpzlib.a`** is created.  The final executable is copied to `tpzsimul/mak/` as **`TPZSimul`**.

### Step 3: Use It ###

> To use it, you have to edit **`TPZSimul.ini`** file. This file indicates to TOPAZ where the SGML configuration files are located. It admits relative or absolute paths. This file should be located in the `$(PWD)` where you want to run the simulation. By default it contains:

```
<!-- See http://www.atc.unican.es/topaz/ for more information -->
<RouterFile      id="../sgm/Router.sgm"  >
<NetworkFile     id="../sgm/Network.sgm" >
<SimulationFile  id="../sgm/Simula.sgm"  >
```

> You have to indicate at **`TPZSimul.ini`** which simulation do you want to run (which is one of the entries of the file `<SimulationFile  id="..."  >`).  If you do not indicate the simulation, TOPAZ will list all of them.

```
shell$ ./TPZSimul 
 File=     ../src/TPZBuilder.cpp
 Line=     282
 Text=     TPZBuilder: Does not exist any SGML component with id="(null) " (cont...)
 Help=     Avaliable Simulation (M44-CT-NOC , M44-CT-MC-NOC , M44-WH-NOC , M44-WH-MC-NOC , 
M44-DAMQ-NOC , M44-DAMQ-MC-NOC , M44-FAST-CT-NOC , M44-FAST-CT-MC-NOC , T44-CT-NOC , T48-CT-MC-NOC , T44-BLESS-NOC , M44-BIDIR-NOC , M44-TEST , M44-MUXED-TEST , M44-MC-TEST , 
T44-MUXED-DOR , T44-MUXED-ADAP , T88-MUXED-DOR , T88-MUXED-ADAP , T44-TEST , T44-MC-TEST , 
M44-WH-BASE , M44-VC-22 , M44-VC-OPT-22 , M44-VC-MUX-22 , M44-VC-MUX-OPT-22 , T44-VC-22 , 
T44-VC-MUX-22 , MW16-CT-NOC , MW32-WH-NOC , SMW64-CT-NOC , SMW64-VC-22 , M44-CT-BUF-XBAR ,  )
```

> Lets assume we want to use the first simulation, overwriting `Simula.sgm` simulation cycles, applied load and traffic pattern (more info about [command line options](SimulationConfiguration.md)). We have to write:

```
shell$ ./TPZSimul -s M44-CT-NOC -c 100000 -l 0.1 -t RANDOM -D
```

The output will be:

```
Simulating..
************
******************* NET CONFIGURATION *********************
 Network        : Mesh(4,4,1)
 Buffer control : CT
 Routing control: MESH-DOR
 Started at     : Fri Feb  3 14:11:09 2012
 Ended at       : Fri Feb  3 14:11:09 2012
***********************************************************
 Simulation time         = 00:00:08 (8 secs)
 Memory Footprint        = 16.5781 MBytes)
 Traffic Pattern         =  Random
 Seed                    = 113
 Cycles simulated        = 100000
 Cycles deprecated       = 0
 Buffers size            = 11
 Messages length         = 1 packet(s)
 Packets length          = 5 flits
************************ PERFORMANCE ***********************
 Supply Thr. Norm        = 0.199238 flits/cycle/router 
 Accept Thr. Norm        = 0.199219 f/c/r (m: 0.1938, M:0.2058)
 Supply Thr.             = 3.1878 f/c
 Throughput              = 3.1875 f/c (m: 3.1008, M:3.2928)
 Average Distance        = 2.6562
 Messages generated      = 63756
 Messages received       = 63750
 Messages to inject      = 2
 Total message latency   = 22.6377
 Network message latency = 21.1245
 Buffer message latency  = 1.51324
 Maximum message latency = 58
 Last Message cycle      = 99997
***********************************************************

```

If you want extended output:

```
shell$ ./TPZSimul -s M44-CT-NOC -c 100000 -l 0.1 -t RANDOM -D -X
```

The output will be:
```
Simulating..
************
******************* NET CONFIGURATION *********************
 Network        : Mesh(4,4,1)
 Buffer control : CT
 Routing control: MESH-DOR
 Started at     : Fri Feb  3 14:12:18 2012
 Ended at       : Fri Feb  3 14:12:18 2012
***********************************************************
 Simulation time         = 00:00:08 (8 secs)
 Memory Footprint        = 16.5625 MBytes)
 Traffic Pattern         =  Random
 Seed                    = 113
 Cycles simulated        = 100000
 Cycles deprecated       = 0
 Buffers size            = 11
 Messages length         = 1 packet(s)
 Packets length          = 5 flits
************************ PERFORMANCE ***********************
 Supply Thr. Norm        = 0.199238 flits/cycle/router 
 Accept Thr. Norm        = 0.199219 f/c/r (m: 0.1938, M:0.2058)
 Supply Thr.             = 3.1878 f/c
 Throughput              = 3.1875 f/c (m: 3.1008, M:3.2928)
 Average Distance        = 2.6562
 Messages generated      = 63756
 Messages received       = 63750
 Messages to inject      = 2
 Total message latency   = 22.6377
 Network message latency = 21.1245
 Buffer message latency  = 1.51324
 Maximum message latency = 58
 Last Message cycle      = 99997

****************** VIRTUAL NETWORK 1 *********************
Average_distance_vn_1        = 2.65487
Messages_generated_vn_1      = 12522
Messages_received_vn_1       = 12520
Total_message_latency_vn_1   = 22.8965
Network_message_latency_vn_1 = 21.3847
Buffer_message_latency_vn_1  = 1.51182
Maximin_message_latency_vn_1 = 56
**********************************************************

****************** VIRTUAL NETWORK 2 *********************
Average_distance_vn_2        = 2.66391
Messages_generated_vn_2      = 12941
Messages_received_vn_2       = 12940
Total_message_latency_vn_2   = 22.6938
Network_message_latency_vn_2 = 21.1926
Buffer_message_latency_vn_2  = 1.50124
Maximin_message_latency_vn_2 = 52
**********************************************************

****************** VIRTUAL NETWORK 3 *********************
Average_distance_vn_3        = 2.65021
Messages_generated_vn_3      = 12861
Messages_received_vn_3       = 12859
Total_message_latency_vn_3   = 22.5755
Network_message_latency_vn_3 = 21.0713
Buffer_message_latency_vn_3  = 1.50416
Maximin_message_latency_vn_3 = 58
**********************************************************

****************** VIRTUAL NETWORK 4 *********************
Average_distance_vn_4        = 2.66315
Messages_generated_vn_4      = 12795
Messages_received_vn_4       = 12795
Total_message_latency_vn_4   = 22.6188
Network_message_latency_vn_4 = 21.0904
Buffer_message_latency_vn_4  = 1.52841
Maximin_message_latency_vn_4 = 55
**********************************************************

****************** VIRTUAL NETWORK 5 *********************
Average_distance_vn_5        = 2.6487
Messages_generated_vn_5      = 12637
Messages_received_vn_5       = 12636
Total_message_latency_vn_5   = 22.4062
Network_message_latency_vn_5 = 20.8854
Buffer_message_latency_vn_5  = 1.52081
Maximin_message_latency_vn_5 = 54
**********************************************************

******************* INJECION MAP (flits/cycle) ***********

************************** Z=0 **************************
0.2058	0.2006	0.20025	0.1938
0.20245	0.20255	0.20035	0.19585
0.20085	0.1995	0.1961	0.19775
0.196	0.19405	0.2024	0.1995


****************** CONSUMPTION MAP (flits/cycle) ********

************************** Z=0 **************************
0.1966	0.2015	0.19675	0.195
0.20045	0.20035	0.2047	0.19755
0.1971	0.2033	0.19805	0.1944
0.203	0.19645	0.2018	0.2005


****************** LINK USAGE MAP (%) *******************

************************** Z=0 **************************
0.080955	0.132587	0.1325	0.078475
0.133187	0.18665	0.184812	0.13045
0.133637	0.185625	0.184695	0.13085
0.078475	0.132025	0.132937	0.078925
```