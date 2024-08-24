#pragma once
#include "Singleton.h"

namespace Globals
{
	class Vars : public Singleton<Vars>
	{
	public:
		bool C_Aimbot = false;
		float C_Smooth = 15.f;
		float C_Color[3] = { 0.f, 0.f, 0.f };
		int C_BoxSelection = 0;
	};
#define Vars Globals::Vars::Get()
}