#include "Pi_in.h"
#include "piproxy.h"
#include "iomanager.h"
#include <iostream>
#include <vector>

Pi_Input::Pi_Input(Io_manager &Io_manager, bool initial_state, int pin_num):Io_manager_{ Io_manager },indicator_state_{ initial_state }, pin_num_{ pin_num }
{
	if (Io_manager_.check(pin_num_))//Schaun ob pin belegt ist
	{
		std::cout << "ERROR PIN BEREITS BELEGT!!" << std::endl;
		return;
	}
	else
	{
		Io_manager_.reserve(pin_num_);
		pinMode(pin_num_, INPUT);
		pullUpDnControl(pin_num_, PUD_DOWN);
	}
}

bool Pi_Input::get_state() const
{
	return digitalRead(pin_num_);
}
