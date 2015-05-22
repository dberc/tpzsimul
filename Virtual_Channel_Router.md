# Introduction #
<p align='justify'>
This router represents the baseline configuration of most of the router microarchitecture proposals performed for on-Chip networks. In this router, port buffering is divided into multiple channels which are independently allocated to crossbar resources. This way, active messages are able to pass blocked messages. This <i>Flow Control</i> was originally proposed <a href='http://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=127260'>here</a>. As well as the formulation of the flow control, a canonical (general model) architecture for routers employing this flow control was presented <a href='http://cva.stanford.edu/publications/2001/specmodel.pdf'>here</a>. The five-stage pipeline router with Virtual Channel flow control represents the starting point architecture for most of the proposals performed in the on-chip environment. Below, the sgml description of such a router can be found.<br>
</p>
```
<Router id="VC-2CH-2MT" inputs=4 outputs=4 bufferSize=10 bufferControl=WH routingControl="DOR">
   <Injector id="INJ" numHeaders=1>
   <Consumer id="CONS">
   
   <Buffer id="BUF111" type="X+"   dataDelay=1>
   <Buffer id="BUF112" type="X+"   dataDelay=1>
   <Buffer id="BUF121" type="X+"   dataDelay=1>
   <Buffer id="BUF122" type="X+"   dataDelay=1>
   
   <Buffer id="BUF211" type="X-"   dataDelay=1>
   <Buffer id="BUF212" type="X-"   dataDelay=1>
   <Buffer id="BUF221" type="X-"   dataDelay=1>
   <Buffer id="BUF222" type="X-"   dataDelay=1>
   
   <Buffer id="BUF311" type="Y+"   dataDelay=1>
   <Buffer id="BUF312" type="Y+"   dataDelay=1>
   <Buffer id="BUF321" type="Y+"   dataDelay=1>
   <Buffer id="BUF322" type="Y+"   dataDelay=1>
   
   <Buffer id="BUF411" type="Y-"   dataDelay=1>
   <Buffer id="BUF412" type="Y-"   dataDelay=1>
   <Buffer id="BUF421" type="Y-"   dataDelay=1>
   <Buffer id="BUF422" type="Y-"   dataDelay=1>
   
   <Buffer id="BUF5"  type="Node" dataDelay=1>
   
   <Crossbar id="CROSSBAR" inputs="17" outputs="5" type="VC" mux="4" NumMT="2" NumVC="2" routingDelay=1 vcarbDelay=1 swarbDelay=1>
      <Input  id=1  type="X+" channel=1>
      <Input  id=2  type="X+" channel=2>
      <Input  id=3  type="X+" channel=3>
      <Input  id=4  type="X+" channel=4>
      <Input  id=5  type="X-" channel=1>
      <Input  id=6  type="X-" channel=2>
      <Input  id=7  type="X-" channel=3>
      <Input  id=8  type="X-" channel=4>
      <Input  id=9  type="Y+" channel=1>
      <Input  id=10 type="Y+" channel=2>
      <Input  id=11 type="Y+" channel=3>
      <Input  id=12 type="Y+" channel=4>
      <Input  id=13 type="Y-" channel=1>
      <Input  id=14 type="Y-" channel=2>
      <Input  id=15 type="Y-" channel=3>
      <Input  id=16 type="Y-" channel=4>
      <Input  id=17  type="Node">
      
      <Output id=1  type="X+">
      <Output id=2  type="X-">
      <Output id=3  type="Y+">
      <Output id=4  type="Y-">
      <Output id=5  type="Node">
   </Crossbar>
   
   <Connection id="C01" source="INJ" destiny="BUF5">
   <Connection id="C02" source="CROSSBAR.5" destiny="CONS">
   
   <Connection id="C03" source="BUF5" destiny="CROSSBAR.17">
   
   <Connection id="C04" source="BUF111" destiny="CROSSBAR.1">
   <Connection id="C05" source="BUF112" destiny="CROSSBAR.2">
   <Connection id="C06" source="BUF121" destiny="CROSSBAR.3">
   <Connection id="C07" source="BUF122" destiny="CROSSBAR.4">
   
   <Connection id="C08" source="BUF211" destiny="CROSSBAR.5">
   <Connection id="C09" source="BUF212" destiny="CROSSBAR.6">
   <Connection id="C10" source="BUF221" destiny="CROSSBAR.7">
   <Connection id="C11" source="BUF222" destiny="CROSSBAR.8">
   
   <Connection id="C12" source="BUF311" destiny="CROSSBAR.9">
   <Connection id="C13" source="BUF312" destiny="CROSSBAR.10">
   <Connection id="C14" source="BUF321" destiny="CROSSBAR.11">
   <Connection id="C15" source="BUF322" destiny="CROSSBAR.12">
   
   <Connection id="C16" source="BUF411" destiny="CROSSBAR.13">
   <Connection id="C17" source="BUF412" destiny="CROSSBAR.14">
   <Connection id="C18" source="BUF421" destiny="CROSSBAR.15">
   <Connection id="C19" source="BUF422" destiny="CROSSBAR.16">
   
   <Input id="1"  type="X+"   wrapper="BUF111,BUF112,BUF121,BUF122">
   <Input id="2"  type="X-"   wrapper="BUF211,BUF212,BUF221,BUF222">
   <Input id="3"  type="Y+"   wrapper="BUF311,BUF312,BUF321,BUF322">
   <Input id="4"  type="Y-"   wrapper="BUF411,BUF412,BUF421,BUF422">

   <Output id="1"  type="X+"   wrapper="CROSSBAR.1">
   <Output id="2"  type="X-"   wrapper="CROSSBAR.2">
   <Output id="3"  type="Y+"   wrapper="CROSSBAR.3">
   <Output id="4"  type="Y-"   wrapper="CROSSBAR.4">   
</Router>
```

# Details #
<p align='justify'>
Before describing sgml limitations for this router, some peculiarities must be exposed. First, the TOPAZ model for VC router includes support for end-to-end deadlock avoidance through the reservation of a different set of input buffers for each different message type. The number of <i>message types</i> and <i>virtual channels per type</i> can be configured with values from 1 to N. This way, the router of the example, which has two message types and two VCs per message type, requires four buffers per input port to work properly.<br>
</p>
<p align='justify'>
Despite the crossbar tag says the crossbar of this router has 17 inputs, this is not really true. Internally, the crossbar multiplexes all the buffers from the same input port, behaving in reality as a conventional 5x5 crossbar. This is true independently of the number of <i>virtual channels</i> and <i>message types</i>. Additionally, crossbar tag <i>mux</i> variable must always be equal to the product of <i>NumMT</i> and <i>NumVC</i>. Finally, the delay of each pipeline stage can be configured, with values from 1 to N. If we want to fuse some pipeline stages, a zero delay on the earlier pipeline stage will do this work.<br>
</p>
<p align='justify'>
Concerning sgml and TOPAZ, these are the limitations and considerations when working with this router:<br>
<ul><li>The only <i>bufferControl</i> policies allowed are flit-level ones, WH and DAMQ. DAMQ policy emulates the functionality of a single buffer with multiple VCs like the one employed <a href='here.md'>here</a>.<br>
</li><li>The minimal buffer size is imposed by round trip delay. The larger the delay at the link, the larger buffer size required.<br>
</li><li>The only routing policy allowed is Dimension Ordered Routing. Alternative policies such as turn model, odd-even etc are easily implementable and external help with this is welcome.<br>
</li><li>Multiple injectors are supported<br>
</li><li>In the crossbar definition, the order of <i>input</i> and <i>output</i> tags is strict. First all X+ inputs, then X-, etc. The last inputs are allways reserved for injectors. Similar with outputs.<br>
</p>