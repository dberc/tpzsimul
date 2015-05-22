# Introduction #
<p align='justify'>
The messages generated to evaluate a network proposal can have different sources. They can be generated according to communication patterns usually found in parallel numerical algorithms. Messages can also be generated through profiling tools able to extract all the characteristics of communications in a specific application. Finally, network messages can be directly generated at another simulation tool connected to TOPAZ, running both in parallel.<br>
<br>
<p align='justify'>
TOPAZ is able to work with any of the sources of network traffic described here. Fastest results are provided by simulations driven by synthetic traffic patterns, but conclusions from network results are not always valid at system leve. The tradeoff between simulation speed and accuracy is clear in this case, being user's decission the utilization of the most appropriate solution according to its requirements.<br>
<br>
<hr />
<h1>Synthetic Traffic Patterns</h1>
Here you can find the general shape of the tag corresponding to traffic description in simulation.sgml file.<br>
<br>
<pre><code>&lt;TrafficPattern     id="MULTICAST" type=RANDOM numMessTypes=4 probMulticast=1 lengthMulticast=8&gt;<br>
</code></pre>
<p align='justify'>
Some values, such as <b>id</b>, <b>type</b> or <b>numMessTypes</b> are employed in every traffic generated, while others are specific of the traffic model selected (like probMulticast and lengthMulticast for MULTICAST model). The numMessTypes variable defines the number of different message types that are going to be generated.<br>
<br>
<h3>Models</h3>
<p align='justify'>
The <b>id</b> variable from the tag identifies a set of characteristics only available in the <i>traffic model</i> selected. The ones available in TOPAZ at this moment are:<br>
<ul><li><p align='justify'><b>MODAL:</b> This could be considered the baseline configuration. Plain traffic generation, all the messages have the same length and a single destination. No additional variables are needed to define it.</li></ul>

<ul><li><p align='justify'><b>BIMODAL:</b> This traffic model generates packets of two different lengths. The fraction and length of the second kind of messages must be defined through two additional variables that must be included in the traffic tag. <b>prob</b> defined the probability of generating one message of the length defined in <b>numMsg</b>. It must be noticed that this mixture of message sizes is the usual shape of communication, where data requests have usually a small size while replies carrying the data require a larger number of bytes.</li></ul>

<ul><li><p align='justify'><b>MULTICAST:</b> In this model, messages with multiple destinations are mixed with messages with a single destination. Again, the fraction of multicast messages, and the number of destinations of each one is defined through two variables that must be included in the tag, <b>probMulticast</b> adn <b>lengthMulticast</b>. See the <a href='Multicast.md'>section</a> for more details about this.</li></ul>

<ul><li><p align='justify'><b>REACTIVE:</b> In the previous models, the generation of a message is not related to any network event. This is not the common case, where some message generate as a consequence of the arrival of previous ones. To model this behavior, we propose this kind of traffic, where injectors only generate the firts messages in the dependency chain (messType=1). The rest of message types are generated as a consequence of the consumption of another message. For this new message generated, the destination is selected as the source node of the previous message.</li></ul>

<h3>Patterns</h3>
<p align='justify'>
As explained before, the distribution of sources and destinations for the messages generated corresponds to communication patterns in numerical algorithms. The <b>id</b> variable determines which is the pattern selected for the simulation. Any traffic model described in previous section can make use of all the traffic patterns. The only peculiarity to take into account is that in MULTICAST model, those messages with multiple destinations always correspond to uniform distributions. The patterns available in TOPAZ are:<br>
<br>
<ul><li><p align='justify'><b>RANDOM:</b> (also known as uniform) In this kind of pattern, source and destination is selected randomly for each message generated.</li></ul>

<ul><li><p align='justify'><b>BIT REVERSAL:</b> Fixed source-destination pair for every message. The node with binary value a<sub>n-1</sub>, a<sub>n-2</sub>,..., a<sub>1</sub>, a<sub>0</sub> communicates with the node a<sub>0</sub>, a<sub>1</sub>,..., a<sub>n-2</sub>, a<sub>n-1</sub>.</li></ul>

<ul><li><p align='justify'><b>PERFECT SHUFFLE:</b> Fixed source-destination pair for every message. The node with binary value a<sub>n-1</sub>, a<sub>n-2</sub>, ..., a<sub>1</sub>, a<sub>0</sub> communicates with the node a<sub>n-2</sub>, a<sub>n-3</sub>, ..., a<sub>0</sub>, a<sub>n-1</sub> (rotate left 1 bit).</li></ul>

<ul><li><p align='justify'><b>TRANSPOSE MATRIX:</b> Fixed source-destination pair for every message. The node with binary value a<sub>n-1</sub>, a<sub>n-2</sub>, ..., a<sub>1</sub>, a<sub>0</sub> communicates with the node a<sub>n/2-1</sub>,..., a<sub>0</sub>, a<sub>,n-1</sub>, ..., a<sub>n/2</sub>.</li></ul>

<ul><li><p align='justify'><b>TORNADO:</b> Fixed source-destination pair for every message. The node with decimal coordinates [x,y] (bi-dimensional), communicates with the node [(x+(k/2-1)) mod k, (y+(k/2-1)) mod k], where k represents the size of the network in both x and y dimensions.</li></ul>

<ul><li><p align='justify'><b>LOCAL:</b> Source node is generated randomly for every message. Destination is also generated randomly, but an additional condition must be accomplished. Destination has to be at a maximum distance of <b>sigma</b> from source node, being sigma a value that must be defined in the traffic tag.</li></ul>

<ul><li><p align='justify'><b>HOT SPOT:</b></li></ul>

The traffic tag which should be applied either in the simulation .sgm file or in the command option is shown below:<br>
<br>
<table><thead><th> Traffic Pattern </th><th> Associated Tag </th></thead><tbody>
<tr><td> Random          </td><td> RANDOM         </td></tr>
<tr><td> Bit Reversal    </td><td> BIT-REVERSAL   </td></tr>
<tr><td> Perfect Shuffle </td><td> PERFECT-SUFFLE </td></tr>
<tr><td> Transpose Matrix </td><td> PERMUTATION    </td></tr>
<tr><td> Tornado         </td><td> TORNADO        </td></tr>
<tr><td> Local           </td><td> LOCAL          </td></tr></tbody></table>

<hr />
<h1>Trace Driven Simulations</h1>

<p align='justify'>
TOPAZ is able to run simulations where message generation is peformed according to a file that is dynamically read as simulation time advances. The traffic pattern tag employed in this case is shown below:<br>
<br>
<pre><code>&lt;TrafficPattern     id="MODAL" type=TRACE traceFile="prueba.trace" numMessTypes=5&gt;<br>
</code></pre>
<p align='justify'>
As can be seen, <b>type</b> variable must be set to TRACE value, and the name of the file must be added to the tag. Trace file is expected to be found in the same directory as the TOPAZ executable. For the moment, an extremely simple format of trace file is implemented, but its modification to accept different file formats is rather easy. Inside a trace file you will find something similar to this:<br>
<br>
<pre><code>10 3 3 0 0 0 0 1<br>
20 2 2 0 1 1 0 1<br>
30 1 1 0 2 2 0 1<br>
40 2 1 0 1 2 0 1<br>
</code></pre>

The meaning of each column is the following (first line as example):<br>
<br>
<table><thead><th>  </th><th>  </th><th> Source </th><th> </th><th> </th><th> Dest </th><th> </th><th> </th></thead><tbody>
<tr><td> Generation Time </td><td> X coord </td><td> Y coord </td><td> Z coord </td><td> X coord </td><td> Y coord </td><td> Z coord </td><td> Size </td></tr>
<tr><td> 10 </td><td> 3 </td><td> 3      </td><td> 0 </td><td> 0 </td><td> 0    </td><td> 0 </td><td> 1 </td></tr></tbody></table>

<hr />
<h1>Full System Simulation</h1>

<p align='justify'>
When network traffic is generated by a different simulation tool running in parallel with TOPAZ, we only have to make sure that no messages are generated internally by TOPAZ. To do so, we always must ensure that the <b>type</b> variable in traffic tag is set to EMPTY value. An example of this configuration is shown below.<br>
<br>
<pre><code>&lt;TrafficPattern     id="MODAL" type=EMPTY numMessTypes=4&gt;<br>
</code></pre>