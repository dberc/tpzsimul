# Introduction #
<p align='justify'>
This router represents a <i>Flow Control</i> proposal for torus networks which avoids deadlock problems without making use of virtual channels. The original definition and basic theorems of this flow control can be found <a href='http://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=634510&userType=&tag=1'>here</a>. The proposal is based on injection restrictions rather than on the restriction of routing possibilities. <i>Flow control</i> is performed at packet level (Virtual Cut-Through) and a minimum buffer space of two packets is required.<br>
</p>

```
<Router id="BUB-DOR" inputs=4 outputs=4 bufferSize=21 bufferControl=CT injControl=VNET routingControl="DOR-MUX-BUBBLE">
   <Injector id="INJ1" numHeaders=1 typeInj="CT-UC" numMessTypes=4>
   <Injector id="INJ2" numHeaders=1 typeInj="CT-UC" numMessTypes=4>
   <Injector id="INJ3" numHeaders=1 typeInj="CT-UC" numMessTypes=4>
   <Injector id="INJ4" numHeaders=1 typeInj="CT-UC" numMessTypes=4>
     
   <Consumer id="CONS">
      
   <Buffer id="BUF111" type="X+"   dataDelay=2>
   <Buffer id="BUF112" type="X+"   dataDelay=2>
   <Buffer id="BUF113" type="X+"   dataDelay=2>
   <Buffer id="BUF114" type="X+"   dataDelay=2>
      
   <Buffer id="BUF211" type="X-"   dataDelay=2>
   <Buffer id="BUF212" type="X-"   dataDelay=2>
   <Buffer id="BUF213" type="X-"   dataDelay=2>
   <Buffer id="BUF214" type="X-"   dataDelay=2>
   
   <Buffer id="BUF311" type="Y+"   dataDelay=2>
   <Buffer id="BUF312" type="Y+"   dataDelay=2>
   <Buffer id="BUF313" type="Y+"   dataDelay=2>
   <Buffer id="BUF314" type="Y+"   dataDelay=2>
   
   <Buffer id="BUF411" type="Y-"   dataDelay=2>
   <Buffer id="BUF412" type="Y-"   dataDelay=2>
   <Buffer id="BUF413" type="Y-"   dataDelay=2>
   <Buffer id="BUF414" type="Y-"   dataDelay=2>
   
   <Buffer id="BUF511" type="Node" dataDelay=2>
   <Buffer id="BUF512" type="Node" dataDelay=2>
   <Buffer id="BUF513" type="Node" dataDelay=2>
   <Buffer id="BUF514" type="Node" dataDelay=2>
      
   <RoutingMuxed id="RTG1" type="X+"    channel=1 inputs="4" headerDelay=2 dataDelay=0>
   <RoutingMuxed id="RTG2" type="X-"    channel=1 inputs="4" headerDelay=2 dataDelay=0>   
   <RoutingMuxed id="RTG3" type="Y+"    channel=1 inputs="4" headerDelay=2 dataDelay=0>   
   <RoutingMuxed id="RTG4" type="Y-"    channel=1 inputs="4" headerDelay=2 dataDelay=0>
   <RoutingMuxed id="RTG5" type="Node"  channel=1 inputs="4" headerDelay=2 dataDelay=0>
      
   <Crossbar id="CROSSBAR" inputs="5" outputs="5" type="MUX-CT" mux="4" headerDelay=0 dataDelay=1>
      <Input  id=1  type="X+" channel=1>
      <Input  id=2  type="X-" channel=1>
      <Input  id=3  type="Y+" channel=1>
      <Input  id=4  type="Y-" channel=1>
      <Input  id=5  type="Node">
      
      <Output id=1  type="X+">
      <Output id=2  type="X-">
      <Output id=3  type="Y+">
      <Output id=4  type="Y-">
      <Output id=5  type="Node">
   </Crossbar>

   <Connection id="C01a" source="INJ1" destiny="BUF511">
   <Connection id="C01b" source="INJ2" destiny="BUF512">
   <Connection id="C01c" source="INJ3" destiny="BUF513">
   <Connection id="C01d" source="INJ4" destiny="BUF514">
      
   <Connection id="C02" source="CROSSBAR.5" destiny="CONS">

   <Connection id="C11" source="RTG1" destiny="CROSSBAR.1">
   <Connection id="C12" source="RTG2" destiny="CROSSBAR.2">
   <Connection id="C13" source="RTG3" destiny="CROSSBAR.3">
   <Connection id="C14" source="RTG4" destiny="CROSSBAR.4">
   <Connection id="C15" source="RTG5" destiny="CROSSBAR.5">

   <Connection id="C21" source="BUF111" destiny="RTG1.1">
   <Connection id="C22" source="BUF112" destiny="RTG1.2">
   <Connection id="C23" source="BUF113" destiny="RTG1.3">
   <Connection id="C24" source="BUF114" destiny="RTG1.4">
   
   <Connection id="C31" source="BUF211" destiny="RTG2.1">
   <Connection id="C32" source="BUF212" destiny="RTG2.2">
   <Connection id="C33" source="BUF213" destiny="RTG2.3">
   <Connection id="C34" source="BUF214" destiny="RTG2.4">
   
   <Connection id="C41" source="BUF311" destiny="RTG3.1">
   <Connection id="C42" source="BUF312" destiny="RTG3.2">
   <Connection id="C43" source="BUF313" destiny="RTG3.3">
   <Connection id="C44" source="BUF314" destiny="RTG3.4">
   
   <Connection id="C51" source="BUF411" destiny="RTG4.1">
   <Connection id="C52" source="BUF412" destiny="RTG4.2">
   <Connection id="C53" source="BUF413" destiny="RTG4.3">
   <Connection id="C54" source="BUF414" destiny="RTG4.4">
   
   <Connection id="C61" source="BUF511" destiny="RTG5.1">
   <Connection id="C62" source="BUF512" destiny="RTG5.2">
   <Connection id="C63" source="BUF513" destiny="RTG5.3">
   <Connection id="C64" source="BUF514" destiny="RTG5.4">
   
   <Input id="1"  type="X+"   wrapper="BUF111,BUF112,BUF113,BUF114">
   <Input id="2"  type="X-"   wrapper="BUF211,BUF212,BUF213,BUF214">
   <Input id="3"  type="Y+"   wrapper="BUF311,BUF312,BUF313,BUF314">
   <Input id="4"  type="Y-"   wrapper="BUF411,BUF412,BUF413,BUF414">

   <Output id="1"  type="X+"   wrapper="CROSSBAR.1">
   <Output id="2"  type="X-"   wrapper="CROSSBAR.2">
   <Output id="3"  type="Y+"   wrapper="CROSSBAR.3">
   <Output id="4"  type="Y-"   wrapper="CROSSBAR.4">
      
</Router>
```

# Details #
<p align='justify'>
As well as the sgml description provided here, this router can also be found in TOPAZ described as a <i>simple router</i> (see <a href='simplerouterSGML.md'>simple router</a>). This allows faster simulations in the early stages of design process.<br>
This router and the <a href='Adaptive_Bubble.md'>Adaptive Bubble router</a> present great similarities. In fact, the flow control presented through this router is the one employed in the escape channels of the adaptive bubble router.<br>
The sgml restrictions of this router are the following:<br>
<ul><li>Only CT bufferControl can be employed in this router.<br>
</li><li>Buffer names must follow strict rules (see corresponding cpp file for further explanation)<br>
</li><li>A minimum of two buffers is required for each direction and dimension.<br>
</p>