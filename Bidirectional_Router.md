# Introduction #
<p align='justify'>
This router represents the architecture required to work with interconnection networks in which the direction of inter-router links is configurable. The behavior of this router tries to emulate the one presented <a href='http://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=5071476'>here</a>, making use of a simpler model for link arbitration. The main peculiarity of this router is found in the crossbar size required, with twice the number of ports compared to a router with unidirectional links.<br>
</p>

```
<Router id="MESH-BINOC" inputs=8 outputs=8 bufferSize=16 bufferControl=CT routingControl="MESH-DOR-BINOC">
   <Injector id="INJ" numHeaders=1 typeInj="CT-UC" numMessTypes=4>
   <Consumer id="CONS">
   
   <SimpleRouter id="ROUTER" inputs="9" outputs="9" headerDelay=0 dataDelay=0 vnets=4 >
      <Input  id=1  type="X+" tipoReverse="0">
      <Input  id=2  type="X-" tipoReverse="0">
      <Input  id=3  type="Y+" tipoReverse="0">
      <Input  id=4  type="Y-" tipoReverse="0">
      <Input  id=5  type="X+" tipoReverse="1">
      <Input  id=6  type="X-" tipoReverse="1">
      <Input  id=7  type="Y+" tipoReverse="1">
      <Input  id=8  type="Y-" tipoReverse="1">
      <Input  id=9  type="Node" tipoReverse="0">
      <Output id=1  type="X+" tipoReverse="0">
      <Output id=2  type="X-" tipoReverse="0">
      <Output id=3  type="Y+" tipoReverse="0">
      <Output id=4  type="Y-" tipoReverse="0">
      <Output id=5  type="X+" tipoReverse="1">
      <Output id=6  type="X-" tipoReverse="1">
      <Output id=7  type="Y+" tipoReverse="1">
      <Output id=8  type="Y-" tipoReverse="1">
      <Output id=9  type="Node" tipoReverse="0">
   </SimpleRouter>
   
   <Connection id="C01" source="INJ" destiny="ROUTER.9">
   <Connection id="C02" source="ROUTER.9" destiny="CONS">

   <Input id="1" type="X+"   wrapper="ROUTER.1">
   <Input id="2" type="X-"   wrapper="ROUTER.2">
   <Input id="3" type="Y+"   wrapper="ROUTER.3">
   <Input id="4" type="Y-"   wrapper="ROUTER.4">
   <Input id="5" type="X+"   wrapper="ROUTER.5">
   <Input id="6" type="X-"   wrapper="ROUTER.6">
   <Input id="7" type="Y+"   wrapper="ROUTER.7">
   <Input id="8" type="Y-"   wrapper="ROUTER.8">
   
   <Output id="1" type="X+"   wrapper="ROUTER.1">
   <Output id="2" type="X-"   wrapper="ROUTER.2">
   <Output id="3" type="Y+"   wrapper="ROUTER.3">
   <Output id="4" type="Y-"   wrapper="ROUTER.4">
   <Output id="5" type="X+"   wrapper="ROUTER.5">
   <Output id="6" type="X-"   wrapper="ROUTER.6">
   <Output id="7" type="Y+"   wrapper="ROUTER.7">
   <Output id="8" type="Y-"   wrapper="ROUTER.8">
</Router>
```

# Details #
<p align='justify'>
This router architecture is only available as a <i>Simple Router</i>. TOPAZ does not implement links able to change working direction, so this behavior requires some tricky coding to work. Two links with opposite directions exist between two neighbor router (notice the number of router inputs is 8, not 4, for a bidimensional network), but we only allow the utilization of one at a time. This is a simple way to simulate this kind of links with minimal code modifications.<br>
</p>
<p align='justify'>
Each bidirectional link requires a master (tipoReverse=0) and slave (tipoReverse=1) input and output. If a packet is travelling from router A to router B through the slave(reverse) link, no transmissions are allowed in opposite direction through the master link. Understanding router behavior through its sgml is not trivial in this case, so it is better to explore source code in order to obtain an idea of the router operation.<br>
</p>