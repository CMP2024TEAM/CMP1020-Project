#include "Connection.h"
#include<fstream>
#include"LED.h"
#include"Switch.h"
int Connection:: TheNumberOfconnection = 0;
Connection::Connection(const GraphicsInfo& r_GfxInfo, OutputPin* pSrcPin, InputPin* pDstPin) :Component(r_GfxInfo)

{
	TheNumberOfconnection++;
	SrcPin = pSrcPin;
	DstPin = pDstPin;
}
Connection::~Connection()
{
	TheNumberOfconnection--;
	SrcPin->DisconnectConnection(this);
	
}
void Connection::setSourcePin(OutputPin* pSrcPin)
{
	SrcPin = pSrcPin;
}

OutputPin* Connection::getSourcePin()
{
	return SrcPin;
}


void Connection::setDestPin(InputPin* pDstPin)
{
	DstPin = pDstPin;
}

InputPin* Connection::getDestPin()
{
	return DstPin;
}
void Connection::setSourceCmpnt(Component* pSrcCmpnt)
{
	SrcCmpnt = pSrcCmpnt;
}

void Connection::setDestCmpnt(Component* pDstCmpnt,int n,int j)
{
	DstCmpnt = pDstCmpnt;
	DstPinNum = j;
	DstPins = n;
}

void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut, bool selected)
{
	GraphicsInfo GInfo;
	//Get Center point of the Gate
	int Cx1, Cy1, Cx2, Cy2;

	GInfo = SrcCmpnt->GetLocation();//get gfxinfo
	Cx1 = (GInfo.x1 + GInfo.x2) / 2;
	Cy1 = (GInfo.y1 + GInfo.y2) / 2;

	GInfo = DstCmpnt->GetLocation();//get gfxinfo
	Cx2 = (GInfo.x1 + GInfo.x2) / 2;
	Cy2 = (GInfo.y1 + GInfo.y2) / 2;
	//Calculate the rectangle Corners

	//validation of the drawconnection true start and end point
	if (DstPins == 3)
	{
		if (DstPinNum == 1)// pin 1
		{
			GInfo.y2 = Cy2 - 5;
			
		}
		else if (DstPinNum == 2)// pin 2
		{

			GInfo.y2 = Cy2;
			
		}
		else if (DstPinNum == 3)// pin 3
		{

			GInfo.y2 = Cy2 + 4;
			
		}
	}
	if (DstPins == 2)
	{
		if (DstPinNum ==  1) //pin 1
		{
			GInfo.y2 = Cy2 - 4.5;
			
		}
		else if (DstPinNum==2) // pin 2
		{
			GInfo.y2 = Cy2 + 4.5;
			
		}
	}
	if (DstPins == 1)
	{
		GInfo.y2 = Cy2;
	}
	if (DstPins == 0)
	{
		GInfo.y2 = Cy2 + 25;
		Cx2 += 10;
	}

	GInfo.x2 = Cx2 - 20;
	GInfo.x1 = Cx1 + 20;
	GInfo.y1 = Cy1 - 0.5;
	m_GfxInfo = GInfo;
	pOut->DrawConnection(m_GfxInfo, selected);
	DrawLabel(pOut);
}
void Connection::DrawLabel(Output* pOut)
{
	if (this->GetLabel() != "")
	{
		GraphicsInfo GI;
		GI.x1 = ((m_GfxInfo.x1 + m_GfxInfo.x2) / 2) + 5;
		GI.y1 = m_GfxInfo.y2;
		pOut->Print(this->GetLabel(), GI);
	}
}
int Connection::GetTheNumberOfconnection()
{
	return TheNumberOfconnection;
}

void Connection::load(int x, int y, string label, int u)
{
}

void Connection::load(Component* thes, Component* theds,Output* outp,int InputPinNumber, GraphicsInfo& GInfo)
{
	int Cx1, Cy1, Cx2, Cy2;	//Center point of the srcgate dstgate
	int x1, y1, x2, y2;
	SrcCmpnt = thes;
	DstCmpnt = theds;
    GInfo = thes->GetLocation();//get gfxinfo
	Cx1 = (GInfo.x1 + GInfo.x2) / 2;
	Cy1 = (GInfo.y1 + GInfo.y2) / 2;
	GInfo = theds->GetLocation();//get gfxinfo
	Cx2 = (GInfo.x1 + GInfo.x2) / 2;
	Cy2 = (GInfo.y1 + GInfo.y2) / 2;
	//Calculate the rectangle Corners
	int k = InputPinNumber;
	int n, j;
	//if (isp2Gate)
	n = theds->getm_Inputs();
	Gate* gate1 = dynamic_cast<Gate*>(thes);
	if (gate1 != NULL)
	{
		SrcPin = gate1->getoutputpin();
	}
	Switch* SWITCH = dynamic_cast<Switch*>(thes);
	if (SWITCH != NULL)
	{
		SrcPin = SWITCH->getoutputpin();
	}
	if (n == 3)
	{
		if (InputPinNumber ==1)// pin 1
		{
			GInfo.y2 = Cy2 - 5;
			j = 1;
		}
		else if (InputPinNumber == 2)// pin 2
		{

			GInfo.y2 = Cy2;
			j = 2;
		}
		else if (InputPinNumber == 3)// pin 3
		{

			GInfo.y2 = Cy2 + 4;
			j = 3;
		}
	}
	if (n == 2)
	{
		if (InputPinNumber == 1) //pin 1
		{
			GInfo.y2 = Cy2 - 4.5;
			j = 1;
		}
		else if (InputPinNumber == 2) // pin 2
		{
			GInfo.y2 = Cy2 + 4.5;
			j = 2;
		}
	}
	if (n == 1)
	{
		GInfo.y2 = Cy2;
		j = 1;
	}
	if (n == 0)
	{
		GInfo.y2 = Cy2 + 25;
		Cx2 += 10;
		j = 1;
	}
	Gate* gate2 = dynamic_cast<Gate*>(theds);
	if (gate2 != NULL)
	{
		DstPin = gate2->getinputpin(j - 1);
	}
	LED* Led = dynamic_cast<LED*>(theds);
	if (Led != NULL)
	{
		DstPin = Led->getinputpin();
	}
	GInfo.x2 = Cx2 - 20;
	GInfo.x1 = Cx1 + 20;
	GInfo.y1 = Cy1 - 0.5;	
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

int Connection::getm_Inputs()
{
	return  0;
}

void Connection::save()
{
	int ThePinNum=0;
	for (int i = 0; i < DstCmpnt->getm_Inputs(); i++)
	{
		if(DstPin==(((Gate*) DstCmpnt)->getinputpin(i)))
		ThePinNum = i+1;
	}
	ofstream the_added_connection;
	the_added_connection.open("file format.txt", ios::app);
	the_added_connection << SrcCmpnt->getid() << "     " << DstCmpnt->getid() << "     " << ThePinNum << "     " << endl;
}



