#pragma once
#include <string>

/*
                                 MIT License

                           Copyright (c) 2024 xdenlz
                           https://github.com/xidenlz
      Permission is hereby granted, free of charge, to any person obtaining a copy
      of this software and associated documentation files (the "Software"), to deal
      in the Software without restriction, including without limitation the rights
      to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
      copies of the Software, and to permit persons to whom the Software is
      furnished to do so, subject to the following conditions:

      The above copyright notice and this permission notice shall be included in all
      copies or substantial portions of the Software.

      Kindly do not remove the copyright notice from any copies of the Software.

      THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
      IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
      FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
      AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
      LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
      OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
      SOFTWARE.

*/



/*
* Usage: https://github.com/xidenlz/CFG-Library/tree/main?tab=readme-ov-file#usage
* Github: https://github.com/xidenlz/CFG-Library
*/



// Place holder 
struct ImColor
{
	float R; 
	float G; 
	float B; 
	float A; 


	ImColor(float Red = 0.0f, float Green = 0.0f, float Blue = 0.0f, float Alpha = 1.0f)
		: R(Red), G(Green), B(Blue), A(Alpha) {}
};


// Vars 
bool C_Boolean = false;
float C_Float = 15.f;
int C_Int = 0;
ImColor C_ImColor(255.f, 255.f, 255.f, 255.f);
std::string  C_String = "Default";
