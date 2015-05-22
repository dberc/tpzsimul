# Introduction #
<p align='justify'>
<i>Simple</i> routers present the peculiarity of being built through a single component. This means that appart from Injector, Consumer and input/output ports, only one additional component must be defined. The code below corresponds to the definition of a Bi-dimensional router of the <i>Simple</i> type.<br>
</p>

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




---

# Components #

#### Router ####
<p align='justify'>
This first tag corresponds to the definition of some of the main characteristics of the router. First of all we find  the router identifier (<b>id</b>), which must be different for each configuration in Router.sgml file. Second, the number of <b>inputs</b> and <b>outputs</b> of the router are specified. This number must match with the amount of dimensions of the topology selected. Each network dimension requires two inputs/outputs, one for each direction (+/-). In the previous example, 4 ports means we must work with a bi-dimensional topology. <b>bufferSize</b> parameter fixes the amount of buffering in flits at each router input-port. <b>bufferControl</b> specifies the <i>Flow Control</i> policy selected for buffer operation. Finally, <b>routingControl</b> determines routing policy followed by every packet traversing the network.<br>
</p>

#### Injector/Consumer ####
<p align='justify'>
These components are in charge of message generation and consumption. When connected to external simulation tools, communication between simulators is performed through these two components. These two components are also parametrizable, and a deeper explanation can be found in<br>
</p>

#### SimpleRouter ####
<p align='justify'>
This single component implements the whole functionality of the router (buffers, arbiters, crossbar). This component must have always one more input and output port than the <b>Router</b>, because both <b>Injector</b> and <b>Consumer</b> are considered internal components of the <b>Router</b>. Through <b>headerDelay</b> and <b>dataDelay</b> we are able to configure the delay experienced by flits to traverse this component (emulating router pipeline). Finally, <b>vnets</b> parameter indicates how many virtual channels with exclusive buffering we are simulating at each router port.<br>
</p>
<p align='justify'>
Every <b>SimpleRouter</b> must define each of its input and output ports with an individual tag line. Each port definition requires a number to identify it as well as its dimension/direction information.<br>
</p>

#### Connection ####
<p align='justify'>
After defining every router component, we must determine how these components will be interconnected, and how they will be connected to router ports. Every connection defined in this file must have a unique name, source and destination. Otherwise, prepare for a debugging nightmare. <b>source</b> and <b>destination</b> determine the way in which flits move between two components. Connections are not bi-directional!.<br>
</p>

#### Input/Output ####
<p align='justify'>
These are the interfaces to interconnect multiple routers. They represent router ports and are connected to links between neighbor routers. The definition of each router port implies always three parameters; an identifier (<b>id</b>), its direction/dimension definition (<b>type</b>) and the internal component connected to that port (<b>wrapper</b>).<br>
</p>