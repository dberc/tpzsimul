# Introduction #

<p align='justify'>
"SimulationSGML" file is a sgml file employed to set general parameters needed to run a simulation. This file specifies mainly all those aspects of the simulation not specific of the network configuration. These parameters include traffic-related parameters (such as traffic-pattern, message and packet length), generic parameters (such as simulation cycles, load applied) and GEMS-related parameters (such as Network/Cache clock ratio or virtual/physical networks). An example of a simulation description is provided below.<br>
</p>

```
<Simulation id="M44-CT-NOC">
   <Network            id="M44_CT_NOC">
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
   <ResetStats            id=1000> 
</Simulation>
```


---

# Elements #
#### Simulation ####
<p align='justify'>This tag specifies the simulation name. We need this name to execute a simulation. This is the only parameter that mandatory must be passed to Topaz through command line using the '-s' option.<br>
<br>
<h4>Network</h4>
<p align='justify'>For each simulation, this tag tells Topaz which of the network elements at the <a href='networkSGML.md'>Network SGML file</a> has to be used.<br>
<br>
<h4>SimulationCycles</h4>
<p align='justify'>This element sets the simulation length in cycles. This value can be overridden  through command line using the '-c' option.<br>
<br>
<h4>StopInjectionAfterMsg</h4>
<p align='justify'>An alternative way to set simulation length. In this case, its value determines the number of messages that are injected to the network. When TOPAZ reaches the limit given by this element value, it will no longer generate any message (except for reactive traffic patterns). Simulation is stopped when every message generated has reached a consumer port, and the network becomes completely empty.<br>
<br>
<h4>TrafficPattern</h4>
<p align='justify'>This element specifies which traffic pattern will be used in this simulation. The shape of the pattern employed is highly configurable, this tag is deeply explained in <a href='Traffic_Patterns.md'>Traffic Pattern</a>.<br>
<br>
<h4>Seed</h4>
<p align='justify'>Specifies the value that will initialize the pseudo random number generator. For debugging, keeping this parameter to a fixed value allows us to reproduce error situations.<br>
<br>
<h4>Load</h4>
<p align='justify'>Sets the normalized traffic load. The value of this parameter is the load applied to the network in flits/cycle/router. For this reason, its value must be between 0.0 and 1.0. This value can be overridden using the command line option '-l'. This tag and the next one (Probability) cannot be used simultaneously as load must be defined in a unique way).<br>
<br>
<h4>Probability</h4>
<p align='justify'>Similar to the previous parameter. Sets the injection probability as a fraction of the total bisection bandwidth. This value must also be between 0.0 and 1.0. This tag and the previous one cannot be used simultaneously as load must be defined in a unique way.<br>
<br>
<h4>MessageLength</h4>
<p align='justify'>Sets the number of packets a message has. Messages can be both multi-packet or uni-packet. In On-chip environments messages are built through a single packet in most cases.<br>
<br>
<h4>PacketLength</h4>
<p align='justify'>Sets the number of flits a packet has. In TOPAZ, the flit is the minimal unit of information transferred through a link in a single cycle. In the literature, a further division of flits can be found, in units called phits. In TOPAZ case, flits cannot be divided, so 1 flit= 1 phit.<br>
This value can be overridden using the command line option '-L'.<br>
<br>
<h4>LinkWidth</h4>
<p align='justify'>Working with GEMS, this value can be useful to automatically calculate the number of flits required by a packet given a fixed link width value. Currently this tag has no real utility.<br>
<br>
<h4>FlitSize</h4>
<p align='justify'>Working with GEMS, this value can be useful to automatically calculate the number of flits required by a packet given a fixed link width value. Currently this tag has no real utility.<br>
<br>
<h4>NetworkClockRatio</h4>
<p align='justify'>This parameter determines the relation between the operation frequency of network components and the rest of memory hierarchy components (GEMS/GEM5). A value of 2 means that the network components operate two times faster than caches (two TOPAZ cycles are simulated for each RUBY cycle simulated). Non integer values are also supported.<br>
<br>
<h4>UnifyNetworks</h4>
<p align='justify'>This parameter determines whether our simulation with GEMS/GEM5 will employ virtual or physical networks. When set to false, a number of simulations equal to the number of message types is initiated.<br>
<br>
<h4>ResetStats</h4>
<p align='justify'>This parameter instructs the simulator to reset all stats at the specified clock cycle.