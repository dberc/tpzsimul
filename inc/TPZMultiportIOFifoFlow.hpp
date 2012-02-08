//
//   Copyright (C) 1998-2011 by Galerna Project, the University of
//   Cantabria, Spain.
//
//   This file is part of the TOPAZ network simulator, originallty developed
//   at the Unviersity of Cantabria
//
//   TOPAZ shares a large proportion of code with SICOSYS which was 
//   developed by V.Puente and J.M.Prellezo
//
//   TOPAZ has been developed by P.Abad, L.G.Menezo, P.Prieto and
//   V.Puente
// 
//  --------------------------------------------------------------------
//
//  If your use of this software contributes to a published paper, we
//  request that you (1) cite our summary paper that appears on our
//  website (http://www.atc.unican.es/topaz/) and (2) e-mail a citation
//  for your published paper to topaz@atc.unican.es
//  
//  If you redistribute derivatives of this software, we request that
//  you notify us and either (1) ask people to register with us at our
//  website (http://www.atc.unican.es/topaz/) or (2) collect registration
//  information and periodically send it to us.
//  
//   --------------------------------------------------------------------
//
//   TOPAZ is free software; you can redistribute it and/or
//   modify it under the terms of version 2 of the GNU General Public
//   License as published by the Free Software Foundation.
//
//   TOPAZ is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//   General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with the TOPAZ simulator; if not, write to the Free Software
//   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
//   02111-1307, USA
//
//   The GNU General Public License is contained in the file LICENSE.
//
// 	
//*************************************************************************
//:
//    File: TPZMultiportIOFifoFlow.hpp
//
//    Class: 
//
//    Inherited from: 
// :
//*************************************************************************
//end of header


#ifndef __TPZMultiportIOFifoFlow_HPP__
#define __TPZMultiportIOFifoFlow_HPP__

//*************************************************************************

   #include <TPZFlow.hpp>
   
   #ifndef __TPZMessage_HPP__
   #include <TPZMessage.hpp>
   #endif
   
   #ifndef __TPZMessage_HPP__
   #include <TPZMessage.hpp>
   #endif  
   
   #ifndef __TPZQueue_HPP__ 
   #include <TPZQueue.hpp>
   #endif 
   
//*************************************************************************

typedef TPZQueue<TPZMessage*> QueueFlits;

   class TPZMultiportIOFifoFlow : public TPZFlow
   {
      typedef TPZFlow Inhereited;

   public:
      TPZMultiportIOFifoFlow( TPZComponent& component);
      virtual ~TPZMultiportIOFifoFlow();
      
      virtual void initialize();
      virtual void postInitialize();

      virtual Boolean inputReading();
      virtual Boolean stateChange();
      virtual Boolean outputWriting();
      
      virtual Boolean controlAlgoritm(Boolean data, int delta)
      {return true;}
      virtual Boolean onStopUp(unsigned interfaz, unsigned cv);
      virtual Boolean onStopDown(unsigned interfaz, unsigned cv);
      //Added VPV
      virtual Boolean bubbleReady() const;   
      void setBufferSize(unsigned size)
      { m_Size = size; }
  
      // Run time information
      DEFINE_RTTI(TPZMultiportIOFifoFlow);
      
      unsigned bufferElements() const;
      
      unsigned bufferSize() const
      { return m_Size; }
      


      unsigned bufferHoles() const
      { return m_Size - bufferElements(); }   
      
                   

   protected:
      virtual void    sendFlit(TPZMessage* msg, unsigned ointerfaz);
      unsigned    m_Size;
      unsigned    m_inputs;
      unsigned    m_outputs;      
      Boolean     m_SendStop;
      QueueFlits *m_memory;
      unsigned   *m_InputIndex;
      unsigned   *m_OutputIndex;
      unsigned   *m_payload;
      unsigned    m_wideOfMemory; //must be greater than or = m_lpack
      unsigned    m_lpack;  //is equal to the memory bandwidth
      int m_flitsStored;
   private:
      virtual Boolean propagateStop();

      

      
};

//*************************************************************************


#endif


// end of file
