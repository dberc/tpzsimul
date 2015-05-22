# How it works #

<p align='justify'>This page describes how GEMS memory simulator has been connected to topaz, and how to use it in your simulations. The approach used keeps both simulators fully is<br>
olated. TOPAZ is designed with an "agnostic" interface, to make it work within any full-system symulator. Actually TOPAZ has been successfully connected to <a href='http://rsim.cs.illinois.edu/rsim/'>RSIM</a>, SimOS, <a href='http://www.cs.wisc.edu/gems/'>GEMS</a>, and <a href='http://www.gem5.org/'>GEM5</a>.<br>
<br>
<p align='justify'>The idea is simple, every time Full-system simulator tries to send a message to the network, a TOPAZ message is created and a pointer to the intended message is appended as externalInfo. This message is injected in TOPAZ and full system simulator will be notified with the sent message at destination. In the case of ruby, we need a interface to perform such actions. This interface is located at <code>ruby/network/simple/PerfectSwitch.C</code> and a simplified sketch is:<br>
<br>
<pre><code><br>
//<br>
// Every time a event for a PerfectSwith object reach the head of ruby event queue this is executed<br>
//<br>
<br>
void PerfectSwitch::wakeup() <br>
{<br>
 if(TOPAZ_IS_ENABLED)<br>
   //in_queue connects the switch to the coherency controller <br>
   gems_message = peekMessageFrom(in_queue); <br>
   //Copies gems_message contents in topaz message<br>
   topaz_message = topaz.createMessage(gems_message);   <br>
   //Send the message to topaz<br>
   topaz.sendMessage( topaz_message);       <br>
   <br>
   if ( PerfectSwitch.id() == 0)<br>
   {<br>
       //Clock edge is sent to topaz<br>
       schedule(this-&gt;wakeUpTopaz(),1);    <br>
   } <br>
   else<br>
   {<br>
      //We can use simultaneously both simulators<br>
      Simple_network_perfect_switch_wakeup;<br>
   }<br>
<br>
}<br>
<br>
void  PerfectSwitch::WakeUpTopaz()<br>
{<br>
<br>
  if(ruby_clock*ruby_topaz_clock_ratio &lt; topaz.clock)<br>
  {<br>
    //Topaz simulation is run for the predefined clock ratio<br>
     //runs in a separate thread in MTOPAZ<br>
     topaz.run(ruby_topaz_clock_ratio);  <br>
  }<br>
   <br>
   //We grab all potential messages received at TOPAZ consumers (Exlusive in MTOPAZ)<br>
   out_queue = topaz-&gt;getMessagesReceived(); <br>
<br>
   //If there are messages inside TOPAZ we schedule next clock edge <br>
   if( topaz.PerfectSwitch.id() == 0 &amp;&amp; topaz.anyMessageInNetwork() != 0)<br>
   {<br>
       schedule(this-&gt;wakeUpTopaz(),1);<br>
   }<br>
}<br>
<br>
</code></pre>