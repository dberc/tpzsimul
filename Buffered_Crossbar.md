# Introduction #
<p align='justify'>
The only intention of this router is to show the high flexibility of TOPAZ. Simply connecting available basic structures in a different way, we are able to implement a first approach to a router with buffered crossbar. A deep understanding of this kind of crossbar can be found <a href='.md'>here</a>. In this case, simplicity has guided some design decissions which make this structure slightly different form the one proposed in the previous link. This example provides a baseline structure to those interested in the exploration of buffered crossbars.<br>
</p>

```
<Router id="CT-BUFFERED-XBAR" inputs=4 outputs=4 bufferSize=11 bufferControl=CT routingControl="DOR">
   <Injector id="INJ" numHeaders=1>
   <Consumer id="CONS">
   
   <Buffer id="INBUF1" type="X+"   dataDelay=1>
   <Buffer id="INBUF2" type="X-"   dataDelay=1>
   <Buffer id="INBUF3" type="Y+"   dataDelay=1>
   <Buffer id="INBUF4" type="Y-"   dataDelay=1>
   <Buffer id="INBUF5" type="Node"   dataDelay=1>
   
   <Demultiplexor id="DEMUX1" type="X+" outputs=5 DemuxControl=CT headerDelay=0 dataDelay=0>
   <Demultiplexor id="DEMUX2" type="X-" outputs=5 DemuxControl=CT headerDelay=0 dataDelay=0>
   <Demultiplexor id="DEMUX3" type="Y+" outputs=5 DemuxControl=CT headerDelay=0 dataDelay=0>
   <Demultiplexor id="DEMUX4" type="Y-" outputs=5 DemuxControl=CT headerDelay=0 dataDelay=0>
   <Demultiplexor id="DEMUX5" type="Node" outputs=5 DemuxControl=CT headerDelay=0 dataDelay=0>
      
   <Buffer id="MIDBUF11" type="X+"   dataDelay=1>
   <Buffer id="MIDBUF12" type="X+"   dataDelay=1>
   <Buffer id="MIDBUF13" type="X+"   dataDelay=1>
   <Buffer id="MIDBUF14" type="X+"   dataDelay=1>
   <Buffer id="MIDBUF15" type="X+"   dataDelay=1>
   
   <Multiplexor id="MUX1" type="X+" inputs=5 MuxControl=CT headerDelay=0 dataDelay=0>
   
   <Buffer id="MIDBUF21" type="X-"   dataDelay=1>
   <Buffer id="MIDBUF22" type="X-"   dataDelay=1>
   <Buffer id="MIDBUF23" type="X-"   dataDelay=1>
   <Buffer id="MIDBUF24" type="X-"   dataDelay=1>
   <Buffer id="MIDBUF25" type="X-"   dataDelay=1>
   
   <Multiplexor id="MUX2" type="X-" inputs=5 MuxControl=CT headerDelay=0 dataDelay=0>
   
   <Buffer id="MIDBUF31" type="Y+"   dataDelay=1>
   <Buffer id="MIDBUF32" type="Y+"   dataDelay=1>
   <Buffer id="MIDBUF33" type="Y+"   dataDelay=1>
   <Buffer id="MIDBUF34" type="Y+"   dataDelay=1>
   <Buffer id="MIDBUF35" type="Y+"   dataDelay=1>
   
   <Multiplexor id="MUX3" type="Y+" inputs=5 MuxControl=CT headerDelay=0 dataDelay=0>
   
   <Buffer id="MIDBUF41" type="Y-"   dataDelay=1>
   <Buffer id="MIDBUF42" type="Y-"   dataDelay=1>
   <Buffer id="MIDBUF43" type="Y-"   dataDelay=1>
   <Buffer id="MIDBUF44" type="Y-"   dataDelay=1>
   <Buffer id="MIDBUF45" type="Y-"   dataDelay=1>
   
   <Multiplexor id="MUX4" type="Y-" inputs=5 MuxControl=CT headerDelay=0 dataDelay=0>
   
   <Buffer id="MIDBUF51" type="Node"   dataDelay=1>
   <Buffer id="MIDBUF52" type="Node"   dataDelay=1>
   <Buffer id="MIDBUF53" type="Node"   dataDelay=1>
   <Buffer id="MIDBUF54" type="Node"   dataDelay=1>
   <Buffer id="MIDBUF55" type="Node"   dataDelay=1>
   
   <Multiplexor id="MUX5" type="Node" inputs=5 MuxControl=CT headerDelay=0 dataDelay=0>
   
   <Connection id="Cin01" source="INJ" destiny="INBUF5">
   <Connection id="Cin02" source="MUX5" destiny="CONS">
   
   <Connection id="Cin03" source="INBUF1" destiny="DEMUX1">
   <Connection id="Cin04" source="INBUF2" destiny="DEMUX2">
   <Connection id="Cin05" source="INBUF3" destiny="DEMUX3">
   <Connection id="Cin06" source="INBUF4" destiny="DEMUX4">
   <Connection id="Cin07" source="INBUF5" destiny="DEMUX5">
   
   <Connection id="Cmid11" source="DEMUX1.1" destiny="MIDBUF11">
   <Connection id="Cmid12" source="DEMUX1.2" destiny="MIDBUF21">
   <Connection id="Cmid13" source="DEMUX1.3" destiny="MIDBUF31">
   <Connection id="Cmid14" source="DEMUX1.4" destiny="MIDBUF41">
   <Connection id="Cmid15" source="DEMUX1.5" destiny="MIDBUF51">
   
   <Connection id="Cmid21" source="DEMUX2.1" destiny="MIDBUF12">
   <Connection id="Cmid22" source="DEMUX2.2" destiny="MIDBUF22">
   <Connection id="Cmid23" source="DEMUX2.3" destiny="MIDBUF32">
   <Connection id="Cmid24" source="DEMUX2.4" destiny="MIDBUF42">
   <Connection id="Cmid25" source="DEMUX2.5" destiny="MIDBUF52">
   
   <Connection id="Cmid31" source="DEMUX3.1" destiny="MIDBUF13">
   <Connection id="Cmid32" source="DEMUX3.2" destiny="MIDBUF23">
   <Connection id="Cmid33" source="DEMUX3.3" destiny="MIDBUF33">
   <Connection id="Cmid34" source="DEMUX3.4" destiny="MIDBUF43">
   <Connection id="Cmid35" source="DEMUX3.5" destiny="MIDBUF53">
   
   <Connection id="Cmid41" source="DEMUX4.1" destiny="MIDBUF14">
   <Connection id="Cmid42" source="DEMUX4.2" destiny="MIDBUF24">
   <Connection id="Cmid43" source="DEMUX4.3" destiny="MIDBUF34">
   <Connection id="Cmid44" source="DEMUX4.4" destiny="MIDBUF44">
   <Connection id="Cmid45" source="DEMUX4.5" destiny="MIDBUF54">
   
   <Connection id="Cmid51" source="DEMUX5.1" destiny="MIDBUF15">
   <Connection id="Cmid52" source="DEMUX5.2" destiny="MIDBUF25">
   <Connection id="Cmid53" source="DEMUX5.3" destiny="MIDBUF35">
   <Connection id="Cmid54" source="DEMUX5.4" destiny="MIDBUF45">
   <Connection id="Cmid55" source="DEMUX5.5" destiny="MIDBUF55">
   
   <Connection id="Cout11" source="MIDBUF11" destiny="MUX1.1">
   <Connection id="Cout12" source="MIDBUF12" destiny="MUX1.2">
   <Connection id="Cout13" source="MIDBUF13" destiny="MUX1.3">
   <Connection id="Cout14" source="MIDBUF14" destiny="MUX1.4">
   <Connection id="Cout15" source="MIDBUF15" destiny="MUX1.5">
   
   <Connection id="Cout21" source="MIDBUF21" destiny="MUX2.1">
   <Connection id="Cout22" source="MIDBUF22" destiny="MUX2.2">
   <Connection id="Cout23" source="MIDBUF23" destiny="MUX2.3">
   <Connection id="Cout24" source="MIDBUF24" destiny="MUX2.4">
   <Connection id="Cout25" source="MIDBUF25" destiny="MUX2.5">
   
   <Connection id="Cout31" source="MIDBUF31" destiny="MUX3.1">
   <Connection id="Cout32" source="MIDBUF32" destiny="MUX3.2">
   <Connection id="Cout33" source="MIDBUF33" destiny="MUX3.3">
   <Connection id="Cout34" source="MIDBUF34" destiny="MUX3.4">
   <Connection id="Cout35" source="MIDBUF35" destiny="MUX3.5">
   
   <Connection id="Cout41" source="MIDBUF41" destiny="MUX4.1">
   <Connection id="Cout42" source="MIDBUF42" destiny="MUX4.2">
   <Connection id="Cout43" source="MIDBUF43" destiny="MUX4.3">
   <Connection id="Cout44" source="MIDBUF44" destiny="MUX4.4">
   <Connection id="Cout45" source="MIDBUF45" destiny="MUX4.5">
   
   <Connection id="Cout51" source="MIDBUF51" destiny="MUX5.1">
   <Connection id="Cout52" source="MIDBUF52" destiny="MUX5.2">
   <Connection id="Cout53" source="MIDBUF53" destiny="MUX5.3">
   <Connection id="Cout54" source="MIDBUF54" destiny="MUX5.4">
   <Connection id="Cout55" source="MIDBUF55" destiny="MUX5.5">
   
   <Input id="1"  type="X+"   wrapper="INBUF1">
   <Input id="2"  type="X-"   wrapper="INBUF2">
   <Input id="3"  type="Y+"   wrapper="INBUF3">
   <Input id="4"  type="Y-"   wrapper="INBUF4">

   <Output id="1"  type="X+"   wrapper="MUX1">
   <Output id="2"  type="X-"   wrapper="MUX2">
   <Output id="3"  type="Y+"   wrapper="MUX3">
   <Output id="4"  type="Y-"   wrapper="MUX4">   
</Router>
```

# Details #
<p align='justify'>
Only a few considerations to work with this router. For the moment functionality is very limited, and features such as multiple virtual channels or flit-level flow control are not implemented. The structure of the sgml file is clear. An Input buffer per router port, and a "mid Buffer" per crossbar crosspoint. Crossbar is implemented with multiplexers and demultiplexers.<br>
</p>