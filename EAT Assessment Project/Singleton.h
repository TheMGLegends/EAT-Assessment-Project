/*
#pragma once

/// <summary>
/// Defines the singleton base class that other singletons can derive from
/// </summary>
/// <typeparam name="T">: The type of singleton</typeparam>
template <typename T>
class Singleton
{
public:
	// INFO: Delete the Copy Constructor and Assignment Operator for each class that 
	// derives from singleton, so that you can't accidentally create more than one 
	// instance of the class

	Singleton(const T&) = delete;
	void operator=(const T&) = delete;

	/// <summary>
	/// Allows access to the singleton by returning it or creating one if one doesn't
	/// yet exist
	/// </summary>
	/// <returns>Returns a pointer to the instance of the class </returns>
	inline static T* Instance() { return instance != nullptr ? instance : instance = new T(); }

	/// <summary>
	/// Generic method for cleaning up during the termination of the program
	/// </summary>
	virtual void Clean() = 0;

protected:
	Singleton() {}
	~Singleton() {}

	static T* instance;
};
*/

