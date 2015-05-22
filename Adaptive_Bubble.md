# Introduction #
<p align='justify'>
A link to the paper describing this router can be found <a href='http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.24.2281'>here</a>. The main characteristics of this router are its packet-level flow control and its deadlock avoidance mechanism. Based on injection restrictions, this router is able to preform <b>fully adaptive</b> routing in a torus topology with only two virtual channels per message type. Flow control in this router is applied at packet level (Cut-Through), so buffer sizes must always be multiple of packet size.<br>
</p>

```
<Router id="BUB-ADAP" inputs=4 outputs=4 bufferSize=21 bufferControl=CT injControl=VNET routingControl="ADAP-MUX-BUBBLE">
   <Injector id="INJ1" numHeaders=1 typeInj="CT-UC" numMessTypes=4>
   <Injector id="INJ2" numHeaders=1 typeInj="CT-UC" numMessTypes=4>
   <Injector id="INJ3" numHeaders=1 typeInj="CT-UC" numMessTypes=4>
   <Injector id="INJ4" numHeaders=1 typeInj="CT-UC" numMessTypes=4>
     
   <Consumer id="CONS">
      
   <Buffer id="BUF111" type="X+"   dataDelay=2>
   <Buffer id="BUF121" type="X+"   dataDelay=2>
   <Buffer id="BUF112" type="X+"   dataDelay=2>
   <Buffer id="BUF122" type="X+"   dataDelay=2>
   <Buffer id="BUF113" type="X+"   dataDelay=2>
   <Buffer id="BUF123" type="X+"   dataDelay=2>
   <Buffer id="BUF114" type="X+"   dataDelay=2>
   <Buffer id="BUF124" type="X+"   dataDelay=2>
      
   <Buffer id="BUF211" type="X-"   dataDelay=2>
   <Buffer id="BUF221" type="X-"   dataDelay=2>
   <Buffer id="BUF212" type="X-"   dataDelay=2>
   <Buffer id="BUF222" type="X-"   dataDelay=2>
   <Buffer id="BUF213" type="X-"   dataDelay=2>
   <Buffer id="BUF223" type="X-"   dataDelay=2>
   <Buffer id="BUF214" type="X-"   dataDelay=2>
   <Buffer id="BUF224" type="X-"   dataDelay=2>
   
   <Buffer id="BUF311" type="Y+"   dataDelay=2>
   <Buffer id="BUF321" type="Y+"   dataDelay=2>
   <Buffer id="BUF312" type="Y+"   dataDelay=2>
   <Buffer id="BUF322" type="Y+"   dataDelay=2>
   <Buffer id="BUF313" type="Y+"   dataDelay=2>
   <Buffer id="BUF323" type="Y+"   dataDelay=2>
   <Buffer id="BUF314" type="Y+"   dataDelay=2>
   <Buffer id="BUF324" type="Y+"   dataDelay=2>
   
   <Buffer id="BUF411" type="Y-"   dataDelay=2>
   <Buffer id="BUF421" type="Y-"   dataDelay=2>
   <Buffer id="BUF412" type="Y-"   dataDelay=2>
   <Buffer id="BUF422" type="Y-"   dataDelay=2>
   <Buffer id="BUF413" type="Y-"   dataDelay=2>
   <Buffer id="BUF423" type="Y-"   dataDelay=2>
   <Buffer id="BUF414" type="Y-"   dataDelay=2>
   <Buffer id="BUF424" type="Y-"   dataDelay=2>
   
   <Buffer id="BUF511" type="Node" dataDelay=2>
   <Buffer id="BUF512" type="Node" dataDelay=2>
   <Buffer id="BUF513" type="Node" dataDelay=2>
   <Buffer id="BUF514" type="Node" dataDelay=2>
      
   <RoutingMuxed id="RTG1" type="X+"    channel=1 inputs="8" headerDelay=2 dataDelay=0>
   <RoutingMuxed id="RTG2" type="X-"    channel=1 inputs="8" headerDelay=2 dataDelay=0>   
   <RoutingMuxed id="RTG3" type="Y+"    channel=1 inputs="8" headerDelay=2 dataDelay=0>   
   <RoutingMuxed id="RTG4" type="Y-"    channel=1 inputs="8" headerDelay=2 dataDelay=0>
   <RoutingMuxed id="RTG5" type="Node"  channel=1 inputs="4" headerDelay=2 dataDelay=0>
      
   <Crossbar id="CROSSBAR" inputs="5" outputs="5" type="MUX-CT" mux="8" headerDelay=0 dataDelay=1>
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
   <Connection id="C22" source="BUF121" destiny="RTG1.2">
   <Connection id="C23" source="BUF112" destiny="RTG1.3">
   <Connection id="C24" source="BUF122" destiny="RTG1.4">
   <Connection id="C25" source="BUF113" destiny="RTG1.5">
   <Connection id="C26" source="BUF123" destiny="RTG1.6">
   <Connection id="C27" source="BUF114" destiny="RTG1.7">
   <Connection id="C28" source="BUF124" destiny="RTG1.8">
   
   <Connection id="C31" source="BUF211" destiny="RTG2.1">
   <Connection id="C32" source="BUF221" destiny="RTG2.2">
   <Connection id="C33" source="BUF212" destiny="RTG2.3">
   <Connection id="C34" source="BUF222" destiny="RTG2.4">
   <Connection id="C35" source="BUF213" destiny="RTG2.5">
   <Connection id="C36" source="BUF223" destiny="RTG2.6">
   <Connection id="C37" source="BUF214" destiny="RTG2.7">
   <Connection id="C38" source="BUF224" destiny="RTG2.8">
   
   <Connection id="C41" source="BUF311" destiny="RTG3.1">
   <Connection id="C42" source="BUF321" destiny="RTG3.2">
   <Connection id="C43" source="BUF312" destiny="RTG3.3">
   <Connection id="C44" source="BUF322" destiny="RTG3.4">
   <Connection id="C45" source="BUF313" destiny="RTG3.5">
   <Connection id="C46" source="BUF323" destiny="RTG3.6">
   <Connection id="C47" source="BUF314" destiny="RTG3.7">
   <Connection id="C48" source="BUF324" destiny="RTG3.8">
   
   <Connection id="C51" source="BUF411" destiny="RTG4.1">
   <Connection id="C52" source="BUF421" destiny="RTG4.2">
   <Connection id="C53" source="BUF412" destiny="RTG4.3">
   <Connection id="C54" source="BUF422" destiny="RTG4.4">
   <Connection id="C55" source="BUF413" destiny="RTG4.5">
   <Connection id="C56" source="BUF423" destiny="RTG4.6">
   <Connection id="C57" source="BUF414" destiny="RTG4.7">
   <Connection id="C58" source="BUF424" destiny="RTG4.8">
   
   <Connection id="C61" source="BUF511" destiny="RTG5.1">
   <Connection id="C62" source="BUF512" destiny="RTG5.2">
   <Connection id="C63" source="BUF513" destiny="RTG5.3">
   <Connection id="C64" source="BUF514" destiny="RTG5.4">
   
   <Input id="1"  type="X+"   wrapper="BUF111,BUF121,BUF112,BUF122,BUF113,BUF123,BUF114,BUF124">
   <Input id="2"  type="X-"   wrapper="BUF211,BUF221,BUF212,BUF222,BUF213,BUF223,BUF214,BUF224">
   <Input id="3"  type="Y+"   wrapper="BUF311,BUF321,BUF312,BUF322,BUF313,BUF323,BUF314,BUF324">
   <Input id="4"  type="Y-"   wrapper="BUF411,BUF421,BUF412,BUF422,BUF413,BUF423,BUF414,BUF424">

   <Output id="1"  type="X+"   wrapper="CROSSBAR.1">
   <Output id="2"  type="X-"   wrapper="CROSSBAR.2">
   <Output id="3"  type="Y+"   wrapper="CROSSBAR.3">
   <Output id="4"  type="Y-"   wrapper="CROSSBAR.4">
      
</Router>
```
# Details #
<p align='justify'>
The sgml restrictions of this router are the following:<br>
<ul><li>Only CT <i>bufferControl</i> can be employed in this router.<br>
</li><li>Buffer names must follow strict rules (see corresponding cpp file for further explanation)<br>
</li><li>A minimum of two buffers is required for each direction and dimension.<br>
</p>