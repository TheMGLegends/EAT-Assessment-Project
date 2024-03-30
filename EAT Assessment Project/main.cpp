#include "Program.h"
#include "TimeManager.h"

#include <ctime>

#include "MemoryLeakDetector.h"

int main(int argc, char* argv[])
{
	// INFO: Detection Flags for Memory Leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// INFO: Specify Line at which to break at for memory leak detection
	//_CrtSetBreakAlloc(LINE NUMBER)

	// INFO: Seed for RNG
	srand((unsigned int)time(NULL));

	Program::Instance()->Initialize("Engine Architecture and Tools Assessment Project");
	TimeManager::Initialize();

	// INFO: Program Loop
	while (Program::Instance()->IsRunning())
	{
		// INFO: Calculate deltaTime at the beginning of the loop
		TimeManager::Tick();

		Program::Instance()->HandleInput();
		Program::Instance()->Update(TimeManager::DeltaTime());
		Program::Instance()->Draw();
	}

	// INFO: Clean Program Class Before Exit
	Program::Instance()->Clean();

	return 0;
}