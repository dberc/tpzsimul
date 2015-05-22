# Introduction #
<p align='justify'>
This router represents a bufferless solution similar to the one proposed <a href='http://www.ece.cmu.edu/~omutlu/pub/bless_isca09.pdf'>here</a>. The correctness of this router relies on the possibility to perform deflection routing and injection-restriction policies. A detailed description of router behavior can be found in the previous reference. The router can work under both Mesh and Torus topologies; the example below shows the sgml description for the Torus case.<br>
</p>
```
<Router id="BLESS" inputs=4 outputs=4 bufferSize=1 bufferControl=NIL routingControl="TORUS-BLESS">
   <Injector id="INJ" numHeaders=1 typeInj="WH-UC" numMessTypes=4>
   <Consumer id="CONS" typeCons="BLESS" >
   
   <SimpleRouter id="ROUTER" inputs="5" outputs="5" headerDelay=0 dataDelay=0 vnets=1>
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

# Details #
<p align='justify'>
The flexibility to configure this router is very low, and many parameters cannot be modified in this case. No virtual channels are allowed for this router, making necessary the utilization of separate physical networks to avoid end-to-end deadlock. Multicast traffic is not allowed, because in-network replication can harm network correctness (deadlock). Finally, in-order delivery cannot be guaranteed for this router, due to deflection routing policy.<br>
</p>
<p align='justify'>
These restrictions translate into the following sgml limitations:<br>
<ul><li><i>bufferControl</i> and <i>routingControl</i> at <b>Router</b> tag have fixed values<br>
</li><li><b>Injector</b> can only have the following type; WH-UC.<br>
</li><li>The only <b>Consumer</b> able to consider packet re-assembly is BLESS. Please, use this consumer for comparison purposes·<br>
</li><li>A single vnet is supported in <b>SimpleRouter</b> tag.<br>
</p>