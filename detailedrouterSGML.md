# Introduction #
<p align='justify'>In the case of a <i>Detailed</i> description of a router, every internal router component is defined with its own tag in the Router.sgml file. TOPAZ provides a large amount of different components, and not all of them are present at each router definition. In fact, some components are only employed in a few specific router microarchitectures. Below we provide a typical router description, which employs many components available. We will explain the components of this example in first place, but we will also provide information about the remaining components available.<br>
<br>
<p align='justify'>Router components are not freely interchangeable. This means, for example, that not all Buffer configurations work properly with any Crossbar available. When possible, we will notify which of these conflicts are present in TOPAZ.<br>
</p>
<pre><code>&lt;Router id="PRUEBA-MUXED-DOR" inputs=4 outputs=4 bufferSize=21 bufferControl=CT injControl=VNET routingControl="DOR-MUX"&gt;<br>
   &lt;Injector id="INJ1" numHeaders=1 typeInj="CT-UC" numMessTypes=4&gt;<br>
   &lt;Injector id="INJ2" numHeaders=1 typeInj="CT-UC" numMessTypes=4&gt;<br>
   &lt;Injector id="INJ3" numHeaders=1 typeInj="CT-UC" numMessTypes=4&gt;<br>
   &lt;Injector id="INJ4" numHeaders=1 typeInj="CT-UC" numMessTypes=4&gt;<br>
     <br>
   &lt;Consumer id="CONS"&gt;<br>
      <br>
   &lt;Buffer id="BUF111" type="X+"   dataDelay=2&gt;<br>
   &lt;Buffer id="BUF112" type="X+"   dataDelay=2&gt;<br>
   &lt;Buffer id="BUF113" type="X+"   dataDelay=2&gt;<br>
   &lt;Buffer id="BUF114" type="X+"   dataDelay=2&gt;<br>
      <br>
   &lt;Buffer id="BUF211" type="X-"   dataDelay=2&gt;<br>
   &lt;Buffer id="BUF212" type="X-"   dataDelay=2&gt;<br>
   &lt;Buffer id="BUF213" type="X-"   dataDelay=2&gt;<br>
   &lt;Buffer id="BUF214" type="X-"   dataDelay=2&gt;<br>
   <br>
   &lt;Buffer id="BUF311" type="Y+"   dataDelay=2&gt;<br>
   &lt;Buffer id="BUF312" type="Y+"   dataDelay=2&gt;<br>
   &lt;Buffer id="BUF313" type="Y+"   dataDelay=2&gt;<br>
   &lt;Buffer id="BUF314" type="Y+"   dataDelay=2&gt;<br>
   <br>
   &lt;Buffer id="BUF411" type="Y-"   dataDelay=2&gt;<br>
   &lt;Buffer id="BUF412" type="Y-"   dataDelay=2&gt;<br>
   &lt;Buffer id="BUF413" type="Y-"   dataDelay=2&gt;<br>
   &lt;Buffer id="BUF414" type="Y-"   dataDelay=2&gt;<br>
   <br>
   &lt;Buffer id="BUF511" type="Node" dataDelay=2&gt;<br>
   &lt;Buffer id="BUF512" type="Node" dataDelay=2&gt;<br>
   &lt;Buffer id="BUF513" type="Node" dataDelay=2&gt;<br>
   &lt;Buffer id="BUF514" type="Node" dataDelay=2&gt;<br>
      <br>
   &lt;RoutingMuxed id="RTG1" type="X+"    channel=1 inputs="4" headerDelay=2 dataDelay=0&gt;<br>
   &lt;RoutingMuxed id="RTG2" type="X-"    channel=1 inputs="4" headerDelay=2 dataDelay=0&gt;   <br>
   &lt;RoutingMuxed id="RTG3" type="Y+"    channel=1 inputs="4" headerDelay=2 dataDelay=0&gt;   <br>
   &lt;RoutingMuxed id="RTG4" type="Y-"    channel=1 inputs="4" headerDelay=2 dataDelay=0&gt;<br>
   &lt;RoutingMuxed id="RTG5" type="Node"  channel=1 inputs="4" headerDelay=2 dataDelay=0&gt;<br>
      <br>
   &lt;Crossbar id="CROSSBAR" inputs="5" outputs="5" type="MUX-CT" mux="4" headerDelay=0 dataDelay=1&gt;<br>
      &lt;Input  id=1  type="X+" channel=1&gt;<br>
      &lt;Input  id=2  type="X-" channel=1&gt;<br>
      &lt;Input  id=3  type="Y+" channel=1&gt;<br>
      &lt;Input  id=4  type="Y-" channel=1&gt;<br>
      &lt;Input  id=5  type="Node"&gt;<br>
      <br>
      &lt;Output id=1  type="X+"&gt;<br>
      &lt;Output id=2  type="X-"&gt;<br>
      &lt;Output id=3  type="Y+"&gt;<br>
      &lt;Output id=4  type="Y-"&gt;<br>
      &lt;Output id=5  type="Node"&gt;<br>
   &lt;/Crossbar&gt;<br>
<br>
   &lt;Connection id="C01a" source="INJ1" destiny="BUF511"&gt;<br>
   &lt;Connection id="C01b" source="INJ2" destiny="BUF512"&gt;<br>
   &lt;Connection id="C01c" source="INJ3" destiny="BUF513"&gt;<br>
   &lt;Connection id="C01d" source="INJ4" destiny="BUF514"&gt;<br>
      <br>
   &lt;Connection id="C02" source="CROSSBAR.5" destiny="CONS"&gt;<br>
<br>
   &lt;Connection id="C11" source="RTG1" destiny="CROSSBAR.1"&gt;<br>
   &lt;Connection id="C12" source="RTG2" destiny="CROSSBAR.2"&gt;<br>
   &lt;Connection id="C13" source="RTG3" destiny="CROSSBAR.3"&gt;<br>
   &lt;Connection id="C14" source="RTG4" destiny="CROSSBAR.4"&gt;<br>
   &lt;Connection id="C15" source="RTG5" destiny="CROSSBAR.5"&gt;<br>
<br>
   &lt;Connection id="C21" source="BUF111" destiny="RTG1.1"&gt;<br>
   &lt;Connection id="C22" source="BUF112" destiny="RTG1.2"&gt;<br>
   &lt;Connection id="C23" source="BUF113" destiny="RTG1.3"&gt;<br>
   &lt;Connection id="C24" source="BUF114" destiny="RTG1.4"&gt;<br>
   <br>
   &lt;Connection id="C31" source="BUF211" destiny="RTG2.1"&gt;<br>
   &lt;Connection id="C32" source="BUF212" destiny="RTG2.2"&gt;<br>
   &lt;Connection id="C33" source="BUF213" destiny="RTG2.3"&gt;<br>
   &lt;Connection id="C34" source="BUF214" destiny="RTG2.4"&gt;<br>
   <br>
   &lt;Connection id="C41" source="BUF311" destiny="RTG3.1"&gt;<br>
   &lt;Connection id="C42" source="BUF312" destiny="RTG3.2"&gt;<br>
   &lt;Connection id="C43" source="BUF313" destiny="RTG3.3"&gt;<br>
   &lt;Connection id="C44" source="BUF314" destiny="RTG3.4"&gt;<br>
   <br>
   &lt;Connection id="C51" source="BUF411" destiny="RTG4.1"&gt;<br>
   &lt;Connection id="C52" source="BUF412" destiny="RTG4.2"&gt;<br>
   &lt;Connection id="C53" source="BUF413" destiny="RTG4.3"&gt;<br>
   &lt;Connection id="C54" source="BUF414" destiny="RTG4.4"&gt;<br>
   <br>
   &lt;Connection id="C61" source="BUF511" destiny="RTG5.1"&gt;<br>
   &lt;Connection id="C62" source="BUF512" destiny="RTG5.2"&gt;<br>
   &lt;Connection id="C63" source="BUF513" destiny="RTG5.3"&gt;<br>
   &lt;Connection id="C64" source="BUF514" destiny="RTG5.4"&gt;<br>
   <br>
   &lt;Input id="1"  type="X+"   wrapper="BUF111,BUF112,BUF113,BUF114"&gt;<br>
   &lt;Input id="2"  type="X-"   wrapper="BUF211,BUF212,BUF213,BUF214"&gt;<br>
   &lt;Input id="3"  type="Y+"   wrapper="BUF311,BUF312,BUF313,BUF314"&gt;<br>
   &lt;Input id="4"  type="Y-"   wrapper="BUF411,BUF412,BUF413,BUF414"&gt;<br>
<br>
   &lt;Output id="1"  type="X+"   wrapper="CROSSBAR.1"&gt;<br>
   &lt;Output id="2"  type="X-"   wrapper="CROSSBAR.2"&gt;<br>
   &lt;Output id="3"  type="Y+"   wrapper="CROSSBAR.3"&gt;<br>
   &lt;Output id="4"  type="Y-"   wrapper="CROSSBAR.4"&gt;<br>
      <br>
&lt;/Router&gt;<br>
</code></pre>

<p align='justify'>As it can be seen, the information required to build a single router is much larger than in the case of <a href='simplerouterSGML.md'>Simple Router descriptions</a>. It might seem useless to define, for example, each <b>Buffer</b> individually, taking into account that they share most of the parameters. However, this fact provides high flexibility to evaluate, for example, different delays depending on the Dimension. This can be a really interesting feature for On-chip 3D topologies exploration.<br>
<br>
<p align='justify'>Next we will describe the components present in the example configuration.<br>
<br>
<br>
<hr />
<h1>Components</h1>

<h3>Injector</h3>
<p align='justify'>This component generates the messages that will be injected into the network, adjusting message charactersitics to the synthetic traffic configuration or to the requirements imposed by a <b>trace file</b> or by an <b>external simulation tool</b>.<br>
<br>
<p align='justify'>The number of flits required to store header information can be set to 1 or 2 through the <b>numHeaders</b> parameter. NoCs usually employ 1-flit headers, while some Off-chip networks with limited bandwidth might require 2-flit headers.The amount of message types must also be defined at each injector through the <b>numMessTypes</b> variable. This value must coincide with the one assigned at traffic definition in Simulation.sgml file.<br>
<br>
<p align='justify'>In those routers with multiple injectors, the one selected for each generated message is selected according to the specifications in <b>injControl</b>. The available choices are:<br>
<br>
<ul><li><p align='justify'><b>RANDOM:</b> a random injector is selected.</li></ul>

<ul><li><p align='justify'><b>RROBIN:</b> the injector is selected in Round Robin order.</li></ul>

<ul><li><p align='justify'><b>VNET:</b> Each message type has its own exclusive injector.</li></ul>

<p align='justify'>According to its internal behavior, different types of injectors can be defined through the <b>typeInj</b> variable:<br>
<br>
<ul><li><p align='justify'><b>CT-UC:</b> Injector for routers with Cut-Through Flow Control and without multicast support.</li></ul>

<ul><li><p align='justify'><b>WH-UC:</b> Injector for routers with Wormhole Flow Control and without multicast support.</li></ul>

<ul><li><p align='justify'><b>CT-MCAST:</b> Injector for routers with Cut-Through Flow Control and with multicast support.</li></ul>

<ul><li><p align='justify'><b>WH-MCAST:</b> Injector for routers with Wormhole Flow Control and with multicast support.</li></ul>

<h3>Consumer</h3>
<p align='justify'>This component retires the messages from the network when they reach destination. At each router, only one consumer can be defined. For the moment, support for multiple consumers is not provided. Despite not being present in the example above, different consumers are available through the <b>typeCons</b> variable:<br>
<br>
<ul><li><p align='justify'><b>CT:</b> Packet-level flow control at the consumer. Once the header flit is at the consumer, the remaining message flits must arrive prior to a new message. This consumer is employed in WH networks to avoid deadlocks produced by packet interleaving at consumption.</li></ul>

<ul><li><p align='justify'><b>BLESS:</b> For bufferless routers, this consumer is in charge of re-assembling message flits (only when all message flits reach consumer the transmission is considered as finished).</li></ul>

<ul><li><p align='justify'><b>REACT:</b> This consumer is employed in reactive traffic patterns to decide the generation of messages as a consequence of the consumption of previous ones.</li></ul>

<h3>Buffer</h3>
<p align='justify'>Each tag starting with this name defines a FIFO buffer present at the router. This component has a single read port and a single write port, which means that only one read and one write operations are possible on each simulated cycle.<br>
<br>
<p align='justify'>Buffer length is defined in flits and can be chosen through two different methods. If we want to define the same size for every router buffer, the <b>bufferSize</b> variable at <b>Router</b> tag will force the size of every <b>Buffer</b> defined. In contrast, to give each Buffer a different value, the <b>size</b> variable could be added to each buffer tag with uneven values.<br>
<br>
<p align='justify'>The delay through each buffer can be also different for each component defined, through the <b>dataDelay</b> parameter. Finally, according to the <i>Flow Control</i> selected for the router, different buffer behaviors can be simulated for every buffer through the <b>bufferControl</b> variable:<br>
<br>
<ul><li><p align='justify'><b>CT:</b> Packet Level (Virtual Cut Through) flow control. Only header flits respond to stop signals.</li></ul>

<ul><li><p align='justify'><b>CT-MCAST:</b> VCT with support to multi-destination messages.</li></ul>

<ul><li><p align='justify'><b>WH:</b> Flit level (Wormhole) flow control.</li></ul>

<ul><li><p align='justify'><b>WH-MCAST:</b> Flit level flow control with multicast support.</li></ul>

<ul><li><p align='justify'><b>DAMQ:</b> Special Flit level flow control, where all the buffers from an input port emulate the behavior of a shared buffer with dynamically allocated Virtual Channels.</li></ul>

<h3>Routing Muxed</h3>
<p align='justify'>This unit performs two different tasks. First it performs routing operations, deciding which router ports can be requested by each message. Second, this component performs a first phase of arbitration, granting access to the crossbar port connected to only a single buffer each cycle (separated allocators). From the buffer granted, a request to a crossbar output port is generated, and only after winning this request the message can advance.<br>
<br>
<p align='justify'>The arbitration of the different virtual channels at each input port can be based on different policies. TOPAZ only implements a priority-based one, necessary to prevent end-to-end deadlocks. However, different policies are easily implementable for this component.<br>
<br>
<p align='justify'>It must be noticed that for the moment this component only works properly for routers with Cut Through Flow control.<br>
<br>
<p align='justify'>This component can simulate different routing policies, according to the <b>routingControl</b> variable.<br>
<ul><li><p align='justify'><b>DOR-MUX:</b> Dimension Ordered Routing with a priority policy based on message type (higher type -> higher priority).</li></ul>

<ul><li><p align='justify'><b>DOR-MUX-BUBBLE:</b> DOR with occupation restrictions (Bubble Flow control).</li></ul>

<ul><li><p align='justify'><b>DOR-MUX-ADAP:</b> Fully Adaptive Routing, following always minimal routes. Also implements Bubble flow control.</li></ul>

<h3>Crossbar</h3>
<p align='justify'>This unit is in charge of emulating physical crossbar and in most cases arbitration units (both Virtual Channel arbitration and Switch arbitration). In some cases it will also be in charge of performing routing operations (when no routing units are present in the sgml router description). This component dictates how the router behaves, being for this reason the one with more available types. Here, only a brief description of the main characteristics of each type is provided.<br>
<br>
<ul><li><p align='justify'><b>WH:</b> Crossbar structure for a simple router with flit-level flow control and without virtual channels. It does not perform routing, therefore it requires routing units connected to crossbar inputs.</li></ul>

<ul><li><p align='justify'><b>WH-RTG:</b> Wormhole crossbar which includes routing logic. In this case, input buffers are directly connected to crossbar ports.</li></ul>

<ul><li><p align='justify'><b>CT:</b> Crossbar with Cut-Through flow control. Inputs to the crossbar are not multiplexed, so each buffer is connected to a single routing unit, and each routing unit to a single port.</li></ul>

<ul><li><p align='justify'><b>CTM:</b> Same as previous one, but in this case the inputs to the crossbar are multiplexed.</li></ul>

<ul><li><p align='justify'><b>VC:</b> Virtual Channel router with flit-level flow control. It incorporates routing, VC arbitration and SW arbitration (no routing units needed). Input from the same physical port are not multiplexed (larger crossbar).</li></ul>

<ul><li><p align='justify'><b>VC-OPT:</b> Same as previous one, but with pipeline optimizations. Prepared to emulate 1-cycle router bypassed under a certain set of conditions.</li></ul>

<ul><li><p align='justify'><b>VC-MUX:</b> Same as VC, but input buffers from the same port are multiplexed. Two buffers from the same port are not allowed to make use of the crossbar simultaneously.</li></ul>

<ul><li><p align='justify'><b>VC-MUX-OPT:</b> Previous one with pipeline optimizations.</li></ul>

<ul><li><p align='justify'><b>VC-TORUS:</b> This Virtual Channel router is prepared to work in Torus topologies. It requires a minimum of two virtual channels per message type to avoid deadlock through dally's mechanism.</li></ul>

<ul><li><p align='justify'><b>VC-TORUS-MUX:</b> VC-TORUS with multiplexed inputs from each input port.</li></ul>

<ul><li><p align='justify'><b>MUX-CT:</b> This crossbar is employed with multiplexed routing units. No routing is required and only output port access is arbitrated at the crossbar.</li></ul>


<hr />
<h1>Other Components</h1>

<h3>Routing</h3>
<p align='justify'>This is a routing unit with a single input port. This means that one unit per input buffer is required in those routers using it. It is only available to implement Dimension Ordered Routing without (DOR) or with Bubble flow control (DOR-BU). Buffering flow control must be performed at packet level when making use of this component.<br>
<br>
<h3>MPBuffer</h3>
<p align='justify'>This component represent a buffer with a variable number of write ports and a single read port. This kind of buffer is only available for CT flow control. The order followed to read messages from the buffer is based on strict priority, extracted from the message type value. Different policies are easily implementable.<br>
<br>
<h3>Multiplexor/Demultiplexor</h3>
<p align='justify'>Extremely simple components whose behavior may be easily deduced from component name. Currently they are limited to packet-level flow control, and follow strict Round-Robin policies to grant next input/output.<br>
<br>
<br>
<p align='justify'><b>Remaining components are still in revision period. In a few weeks their final version will be available and these sections completed</b>
<h3>InputStage</h3>

<h3>OutputStage</h3>

<h3>MPIOBuffer</h3>