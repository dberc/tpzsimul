# Introduction #

Add your content here.
```
<Router id="ROTARY" inputs=4 outputs=4 bufferSize=21 bufferControl=CT routingControl="DOR" >
   <Injector id="INJ" numHeaders=1 typeInj="CT-UC" numMessTypes=4>
   <Consumer id="CONS" >
        
   <InputStage id="IS1" type="X+" outputs=2 dataDelay=1 size=11>
   <InputStage id="IS2" type="Y+" outputs=2 dataDelay=1 size=11>
   <InputStage id="IS3" type="X-" outputs=2 dataDelay=1 size=11>
   <InputStage id="IS4" type="Y-" outputs=2 dataDelay=1 size=11>
   <InputStage id="IS5" type="Node" outputs=2 dataDelay=1 size=11>

   <OutputStage id="OS1" type="X+" inputs=2 size=21 dataDelay=0>
   <OutputStage id="OS2" type="Y+" inputs=2 size=21 dataDelay=0>
   <OutputStage id="OS3" type="X-" inputs=2 size=21 dataDelay=0>
   <OutputStage id="OS4" type="Y-" inputs=2 size=21 dataDelay=0>
   <OutputStage id="OS5" type="Node" inputs=2 size=21 dataDelay=0>
   
   <MPIOBuffer id="MPR1" type="X+" inputs=2 outputs=2 size=21 dataDelay=1>
   <MPIOBuffer id="MPR2" type="Y+" inputs=2 outputs=2 size=21 dataDelay=1>
   <MPIOBuffer id="MPR3" type="X-" inputs=2 outputs=2 size=21 dataDelay=1>
   <MPIOBuffer id="MPR4" type="Y-" inputs=2 outputs=2 size=21 dataDelay=1>
   <MPIOBuffer id="MPR5" type="Node" inputs=2 outputs=2 size=21 dataDelay=1>
   
   <MPIOBuffer id="MPL1" type="X+" inputs=2 outputs=2 size=21 dataDelay=1>
   <MPIOBuffer id="MPL2" type="Y+" inputs=2 outputs=2 size=21 dataDelay=1>
   <MPIOBuffer id="MPL3" type="X-" inputs=2 outputs=2 size=21 dataDelay=1>
   <MPIOBuffer id="MPL4" type="Y-" inputs=2 outputs=2 size=21 dataDelay=1>
   <MPIOBuffer id="MPL5" type="Node" inputs=2 outputs=2 size=21 dataDelay=1>
   
      
   <Connection id="C01" source="INJ" destiny="IS5">
   <Connection id="C02" source="OS5" destiny="CONS">
         
   <Connection id="C11" source="IS1.1" destiny="MPR5.1">
   <Connection id="C12" source="IS2.1" destiny="MPR1.1">
   <Connection id="C13" source="IS3.1" destiny="MPR2.1">
   <Connection id="C14" source="IS4.1" destiny="MPR3.1">
   <Connection id="C15" source="IS5.1" destiny="MPR4.1">
   
   <Connection id="C21" source="IS1.2" destiny="MPL2.1">
   <Connection id="C22" source="IS2.2" destiny="MPL5.1">
   <Connection id="C23" source="IS3.2" destiny="MPL4.1">
   <Connection id="C24" source="IS4.2" destiny="MPL1.1">
   <Connection id="C25" source="IS5.2" destiny="MPL3.1">
   
   <Connection id="C31" source="MPR5.2" destiny="MPR4.2">
   <Connection id="C32" source="MPR4.2" destiny="MPR1.2">
   <Connection id="C33" source="MPR1.2" destiny="MPR2.2">
   <Connection id="C34" source="MPR2.2" destiny="MPR3.2">
   <Connection id="C35" source="MPR3.2" destiny="MPR5.2">
   
   <Connection id="C41" source="MPL5.2" destiny="MPL3.2">
   <Connection id="C42" source="MPL3.2" destiny="MPL2.2">
   <Connection id="C43" source="MPL2.2" destiny="MPL1.2">
   <Connection id="C44" source="MPL1.2" destiny="MPL4.2">
   <Connection id="C45" source="MPL4.2" destiny="MPL5.2">
   
   <Connection id="C51" source="MPR1.1" destiny="OS1.1">
   <Connection id="C52" source="MPR2.1" destiny="OS2.1">
   <Connection id="C53" source="MPR3.1" destiny="OS3.1">
   <Connection id="C54" source="MPR4.1" destiny="OS4.1">
   <Connection id="C55" source="MPR5.1" destiny="OS5.1">
   
   <Connection id="C61" source="MPL1.1" destiny="OS1.2">
   <Connection id="C62" source="MPL2.1" destiny="OS2.2">
   <Connection id="C63" source="MPL3.1" destiny="OS3.2">
   <Connection id="C64" source="MPL4.1" destiny="OS4.2">
   <Connection id="C65" source="MPL5.1" destiny="OS5.2">
   
   
   
   <Input id="1" type="X+" wrapper="IS1">
   <Input id="2" type="Y+" wrapper="IS2">
   <Input id="3" type="X-" wrapper="IS3">
   <Input id="4" type="Y-" wrapper="IS4">
   
   <Output id="1" type="X+" wrapper="OS1">
   <Output id="2" type="Y+" wrapper="OS2">
   <Output id="3" type="X-" wrapper="OS3">
   <Output id="4" type="Y-" wrapper="OS4">
   
</Router>
```

# Details #

Add your content here.  Format your content with:
  * Text in **bold** or _italic_
  * Headings, paragraphs, and lists
  * Automatic links to other wiki pages