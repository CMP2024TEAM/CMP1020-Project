#include "Connection.h"
#include<fstream>
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
	int ThePinNum;
	for (int i = 0; i < DstCmpnt->getm_Inputs(); i++)
	{
		if(DstPin==(((Gate*) DstCmpnt)->getinputpin(i)));
		ThePinNum = i;
	}
	ofstream the_added_connection;
	the_added_connection.open("file format.txt", ios::app);
	the_added_connection << endl << SrcCmpnt->GetId() << "     " << DstCmpnt->GetId() << "     " << ThePinNum << "     " << endl;
}



