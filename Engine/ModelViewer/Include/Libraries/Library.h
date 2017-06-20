#pragma once
#include <string>
#include <unordered_map>

class Library
{
public:
	Library(std::string const& name, Library* parent = nullptr);
	virtual ~Library();

	std::string GetName() const { return m_Name; }

	virtual void Initialize() = 0;
	virtual void Shutdown();
	void AddSubLibrary(Library* newLib);

	virtual void Update();

protected:
	std::unordered_map <std::string, Library*> m_SubLibraries;

	Library* m_Parent = nullptr;

	std::string const m_Name;
};

