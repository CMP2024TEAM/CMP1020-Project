#include "Save.h"
#include<fstream>
#include "..\Components\Connection.h"
#include "..\Components\LED.h"
#include "..\Components\Switch.h"
void Save::save_gates(Component** y, int t)
{
	Component** array_connections,**the_gates;
	int the_num_connections=0;
	ofstream the_added_component;
	the_added_component.open("file format.txt");
	the_added_component << t << endl;
	for (int i = 0; i < t; i++)
	{
		Connection* p = dynamic_cast<Connection*>(y[i]);
		if (p == NULL)
		{
			y[i]->save(i+1);
		}
		else
			the_num_connections++;
	}
	the_added_component.close();
	array_connections = new Component * [the_num_connections];
	the_gates = new Component * [t - the_num_connections];
	int j = 0; int w = 0;
	for (int i = 0; i < t; i++)
	{
		Connection* t = dynamic_cast<Connection*>(y[i]);
		if (t != NULL)
		{
			array_connections[j] = y[i];
			j++;
		}
		else {
			the_gates[w] = y[i];
			w++;
		}
	}
	Component** the_source, **the_des;
	the_source = new Component * [j];
	the_des = new Component * [j];
	the_added_component.open("file format.txt",ios::app);
	the_added_component << endl << "the connections" << endl;
	for (int i = 0; i < j; i++)
		for (int k = 0; k < w; k++)
		{
			Gate* the_gate = dynamic_cast<Gate*>(the_gates[k]);
			if (the_gate != NULL)
			{
				for (int g = 0; g < (the_gate->getm_Inputs()); g++)
				{
					if (((Connection*)array_connections[i])->getDestPin() == the_gate->getinputpin(g))
					{
						the_des[j] = the_gates[k];
					}
					else
					{
						if (((Connection*)array_connections[i])->getSourcePin() == the_gate->getoutputpin())
							the_source[j] = the_gates[k];
					}
				}
			}
			else
			{
				LED* the_lamb = dynamic_cast<LED*>(the_gates[k]);
				if (the_lamb != NULL)
				{
					if (the_lamb->getinputpin() == ((Connection*)array_connections[i])->getDestPin())
						the_des[k] = the_gates[k];

				}
				else
				{
					if (((Switch*)the_gates[k])->getoutputpin() == ((Connection*)array_connections[i])->getSourcePin())
						the_source[k] = the_gates[k];
				}
			}
		}
	int* p = new int[j]; 
	int*k = new int[j];
	for (int i = 0; i < j; i++)
	{
		k[i] = 0;
		p[i] = 0;
	}
	for (int i = 0; i < j; i++)
	{
		for (int a = 1; a <= t; a++)
		{
			if (the_source[i] == y[a-1])
				k[i] = a;
			else if (the_des[i] == y[a-1])
				p[i] = a;
		}
	}
	for (int i = 0; i < j; i++)
	{
		((Connection*)array_connections[i])->save(k[i], p[i], 1);
	}
}





