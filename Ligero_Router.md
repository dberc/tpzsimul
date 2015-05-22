# Introduction #

<p align='justify'>
A link to the paper describing this router can be found <a href='https://sites.google.com/site/atcgalerna/home-1/all_pubs/publications'>here</a>.<br>
LIGERO employs as starting point the original ideas introduced by the Rotary Router, a radically new microarchitecture. It is a fully modular architecture without centralized arbitration or switching fabric. Each input-output pair in the same direction and dimension has a similar structure, named Basic Building Block, which is composed of a dual-port FIFO buffer (DFIFO) and reception and ejection stages. Network interface is connected to Ejection (Injector) and Reception (Consumer) stages, while DFIFOs of each Block are interconnected forming a loop in order to create a communication path between any input and output router ports.<br>
</p>
![http://dl.dropboxusercontent.com/u/6395469/LigeroSketch.png](http://dl.dropboxusercontent.com/u/6395469/LigeroSketch.png)
<p align='justify'>
LIGERO implements a deadlock avoidance mechanism based on the utilization, under certain conditions, of a deterministic escape path (ring) traversing every network router to reach destination. LIGERO also implements additional connectivity for bypass router traversals, providing lower latencies under low load conditions. Multicast traffic is also efficiently supported in this router, being the internal buffer loop an adequate structure to naturally perform packet replication. Finally, in-order delivery mechanism has been added to the router, allowing LIGERO to support large fractions of ordered traffic with minimal impact.<br>
</p>
<p align='justify'>
Normal Packet traversal can be described as follows. A packet reaches the router from a neighbor position and is buffered at the reception stage. Once buffered, packet has to choose between three different alternative outputs, Consumption (if it has reached destination), bypass (if is reachable following the same dimension and direction) or DFIFO (if previous conditions are not met). When advance is produced through DFIFO, packet is forced to move continuously in the internal loop until reaching a profitable and available output port. If a certain number of loops is completed packet is marked for misrouting, being able to leave the router through any port from that moment. When a message has been marked for misrouting a certain amount of times it is then marked as “on escape”, being forced from that moment to only use escape path to reach destination. In order to leave the router packets must move through the ejection stage.  This stage regulates the access from three different paths (bypass DFIFO loop or injection) to the output port. On a round-robin basis this stage chooses which packet can progress to the output link.<br>
</p>

# Simulating with LIGERO #
<p align='justify'>
We have performed a strong effort programming LIGERO in order to make it friendly for novel TOPAZ users. For this reason the router has been developed as a SimpleRouter structure, joining all router code in a single file. This fact has significantly improved simulation times, being now able to run larger simulations (in terms of network size or cycles simulated) in a lower amount of time. Making use of SimpleRouter structure also simplifies sgml description of the router. sgml Definition of LIGERO router is shown next<br>
</p>

```
<Router id="LIGERO" inputs=4 outputs=4 bufferSize=12 bufferControl=CT routingControl="LIGERO">
   <Injector id="INJ" numHeaders=1 typeInj="CT-UC" numMessTypes=6>
   <Consumer id="CONS">

   <SimpleRouter id="ROUTER" inputs="5" outputs="5" headerDelay=0 dataDelay=0 vnets=6 IsSize=6 OsSize=11 MpSize=16 MissLoops=2 MissLimit=3 >
      <Input  id=1  type="X+">
      <Input  id=2  type="Y+">
      <Input  id=3  type="X-">
      <Input  id=4  type="Y-">
      <Input  id=5  type="Node">
      <Output id=1  type="X+">
      <Output id=2  type="Y+">
      <Output id=3  type="X-">
      <Output id=4  type="Y-">
      <Output id=5  type="Node">
   </SimpleRouter>

   <Connection id="C01" source="INJ" destiny="ROUTER.5">
   <Connection id="C02" source="ROUTER.5" destiny="CONS">

   <Input id="1" type="X+"   wrapper="ROUTER.1">
   <Input id="2" type="Y+"   wrapper="ROUTER.2">
   <Input id="3" type="X-"   wrapper="ROUTER.3">
   <Input id="4" type="Y-"   wrapper="ROUTER.4">

   <Output id="1" type="X+"   wrapper="ROUTER.1">
   <Output id="2" type="Y+"   wrapper="ROUTER.2">
   <Output id="3" type="X-"   wrapper="ROUTER.3">
   <Output id="4" type="Y-"   wrapper="ROUTER.4">
</Router>
```

<p align='justify'>
As well as the common configuration parameters, some additional ones are provided for this router, which are described here:<br>
<ul><li>Buffer Size can be fixed to a single value for all router components through bufferSize value, but can also have different values for the different stages if we make use of IsSize (size of reception buffering), OsSize (size of ejection buffering) and MpSize (size of DFIFO buffer).<br>
</li><li>The number of complete turns a packet performs at the DFIFO loop before being marked for misrouting is also a configurable number, making use of MissLoops param. Also, we can also fix the number of times a packet is missrouted before being forced to use the escape path, through MissLimit value.<br>
</p>
<p align='justify'>
Finally, some limitations that should be taken into account when working with the router. Flow control must always be CT, limiting the minimal buffer size to the size of a network packet. For the moment router only supports bi-dimensional topologies, both meshes or tori.<br>
</p></li></ul>

# Developing with LIGERO #
<p align='justify'>
For those people who want to develop new features for LIGERO we will soon add a small description of code structure in order to help them to understand how the router has been programmed.<br>
</p>