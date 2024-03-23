#include "Program.h"
#include "TimeManager.h"

#include "MemoryLeakDetector.h"




// TEST: INCLUDES
#include <iostream>
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"




int main(int argc, char* argv[])
{
	// INFO: Detection Flags for Memory Leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Program::Instance()->Initialize("Engine Architecture and Tools Assessment Project");
	



	// TEST: INSTANTIATION
	Rectangle rect{ 5, 5, 100, 200 };
	Square square{ 1, 1, 20 };
	Circle circle{ 5, 5, 1200 };

	std::cout << "Rectangle ID: " << rect.GetID() << std::endl;
	std::cout << "Square ID: " << square.GetID() << std::endl;
	std::cout << "Circle ID: " << circle.GetID() << std::endl;




	while (Program::Instance()->IsRunning())
	{
		// INFO: Calculate deltaTime at the beginning of the loop
		TimeManager::Instance()->Tick();

		Program::Instance()->HandleInput();
		Program::Instance()->ProcessEvents();
		Program::Instance()->Update(TimeManager::Instance()->DeltaTime());
		Program::Instance()->Draw();
	}

	// INFO: Clean Program Class Before Exit
	Program::Instance()->Clean();




	// TEST: CLEANING
	rect.Clean();
	square.Clean();
	circle.Clean();




	return 0;
}