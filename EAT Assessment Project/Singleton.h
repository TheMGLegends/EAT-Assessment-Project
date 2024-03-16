#pragma once

template <typename T>
class Singleton
{
public:
	// INFO: Delete the Copy Constructor and Assignment Operator for each class that 
	// derives from singleton, so that you can't  accidentally create more than one 
	// instance of the class
	Singleton(const T&) = delete;
	void operator=(const T&) = delete;

	// INFO: Method called to retrieve the instance
	inline static T* Instance() { return instance != nullptr ? instance : instance = new T(); }

	// INFO: Generic method for cleaning up during the termination of the program
	virtual void Clean() = 0;

protected:
	Singleton() {}
	~Singleton() {}

	static T* instance;
};
